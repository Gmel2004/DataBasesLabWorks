using ChessTactics.Models.DB;
using System.Data;
using System.Windows;

namespace ChessTactics.Views
{
    public class GameView
    {
        private string platfrom;
        private string path;

        public int? IdWhite { get; set; }
        public int? IdBlack { get; set; }
        public bool IsNewGame { get; set; }
        public List<string> Paths { get; set; }
        public string SelectedPath
        {
            set { path = value; FindGame(); }
            get { return path; }
        }
        public List<string> Platforms { get; set; }
        public string SelectedPlatform
        {
            set { platfrom = value; FindGame(); }
            get { return platfrom; }
        }
        public DateTime Date { get; set; } = DateTime.Now;
        public int MoveCount { get; set; }
        public TimeSpan StartTime { get; set; }
        public int SecondToAdd { get; set; } = 0;
        public List<string> Openings { get; set; }
        public string SelectedOpening { get; set; } = "";
        public List<string> Whites { get; set; }
        public string SelectedWhite { get; set; } = "";
        public int WhiteRating { get; set; }
        public List<string> Blacks { get; set; }
        public string SelectedBlack { get; set; } = "";
        public int BlackRating { get; set; }
        public List<string> Results { get; set; } = ["White", "Black", "Draw"];
        public string SelectedResult { get; set; } = "";

        public event Action Update;

        public GameView(Action action)
        {
            Update = action;
            using var db = new DB();
            Paths = db.Games.Select(t => t.Path).ToList();
            Platforms = db.Platforms.Select(t => t.PlatformName).ToList();
            Openings = db.Openings.Select(t => t.OpeningName).ToList();
            Whites = db.Users.Select(t => t.NickName).ToList();
            Blacks = Whites;
        }

        public void FindGame()
        {
            if (IsNewGame || SelectedPlatform is null || SelectedPath is null) return;
            using var db = new DB();
            var query = db.FindGame.Where(x => x.Domain == SelectedPlatform && x.Path == SelectedPath);
            if (query.Count() < 2) return;
            var game0 = query.ElementAt(0);
            var game1 = query.ElementAt(1);
            if (game0.Color == UserGame.UserColor.White)
            {
                IdWhite = game0.idUserGame;
                IdBlack = game1.idUserGame;
                SelectedWhite = game0.NickName;
                SelectedBlack = game1.NickName;
                WhiteRating = game0.Rating;
                BlackRating = game1.Rating;
            }
            else
            {
                IdWhite = game1.idUserGame;
                IdBlack = game0.idUserGame;
                SelectedWhite = game1.NickName;
                SelectedBlack = game0.NickName;
                WhiteRating = game1.Rating;
                BlackRating = game0.Rating;
            }
            var currentGame = game0;
            Date = currentGame.Date;
            MoveCount = currentGame.TotalMoveCount;
            StartTime = currentGame.StartTime;
            SecondToAdd = currentGame.SecondToAdd;
            SelectedOpening = currentGame.Opening;
            SelectedResult = currentGame.Result.ToString();
            Update();
        }
    }
}

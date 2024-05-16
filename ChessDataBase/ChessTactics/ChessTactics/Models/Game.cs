namespace ChessTactics.Models
{
    public class Game
    {
        private string platfrom;
        private string path;

        public List<string> Paths { get; set; }
        public string SelectedPath
        {
            set { path = value; OnGameKeysChanged?.Invoke(); }
            get { return path; }
        }
        public List<string> Platforms { get; set; }
        public string SelectedPlatform
        {
            set { platfrom = value; OnGameKeysChanged?.Invoke(); }
            get { return platfrom; }
        }
        public DateOnly Date { get; set; }
        public int MoveCount { get; set; }
        public TimeOnly StartTime { get; set; }
        public int SecondToAdd { get; set; } = 0;
        public List<string> Openings { get; set; }
        public string SelectedOpening { get; set; } = "";
        public List<string> Whites { get; set; }
        public string SelectedWhite { get; set; } = "";
        public List<string> Blacks { get; set; }
        public string SelectedBlack { get; set; } = "";
        public List<string> Results { get; set; } = ["White", "Black", "Draw"];
        public string SelectedResult { get; set; } = "";

        public event Action OnGameKeysChanged;

        public Game(Action action)
        {
            OnGameKeysChanged = action;
        }
    }
}

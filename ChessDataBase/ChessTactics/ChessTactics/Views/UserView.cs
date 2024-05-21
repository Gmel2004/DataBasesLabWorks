namespace ChessTactics.Views
{
    public class UserView
    {
        private bool isNewUser;
        public bool IsNewUser
        {
            get => isNewUser;
            set { isNewUser = value; FindUser(); }
        }
        private string nickName = "";
        private string platform;
        public List<string> NickNames { get; set; }
        public string SelectedNickName { get => nickName; set { nickName = value; FindUser(); } }
        public List<string> Platforms { get; set; } = ["lichess.org", "chess.com"];
        public string SelectedPlatform { get => platform; set { platform = value; FindUser(); } }
        public string Name { get; set; } = "";
        public string LastName { get; set; } = "";
        public List<string> Ranks { get; set; } = ["CM", "FM", "IM", "GM", ""];
        public string SelectedRank { get; set; } = "";
        public List<string> Countries { get; set; }
        public string SelectedCountry { get; set; } = "";

        public event Action Update;

        public UserView(Action update)
        {
            Update = update;
            using var db = new DB();
            NickNames = db.Users.Select(x => x.NickName).ToList();
            Platforms = db.Platforms.Select(x => x.PlatformName).ToList();
            Countries = db.Countries.Select(x => x.CountryName).ToList();
            Countries.Add("");
        }

        public void FindUser()
        {
            if (IsNewUser || SelectedPlatform is null || SelectedNickName is null) return;
            using var db = new DB();
            var query = db.FindUser.
                Where(t => t.NickName == SelectedNickName && t.Domain == SelectedPlatform);
            if (query.Count() == 0) return;
            var currentUser = query.Single();
            Name = currentUser.Name;
            LastName = currentUser.LastName;
            SelectedRank = currentUser.Rank.ToString();
            SelectedCountry = currentUser.Country;
            Update();
        }
    }
}

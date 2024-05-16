namespace ChessTactics.Models
{
    public class User
    {
        private string nickName = "";
        private string platform;
        public List<string> NickNames { get; set; }
        public string SelectedNickName { get => nickName; set { nickName = value; OnUserKeysChanged?.Invoke(); } }
        public List<string> Platforms { get; set; } = ["lichess.org", "chess.com"];
        public string SelectedPlatform { get => platform; set { platform = value; OnUserKeysChanged?.Invoke(); } }
        public string Name { get; set; } = "";
        public string LastName { get; set; } = "";
        public List<string> Ranks { get; set; } = ["CM", "FM", "IM", "GM", ""];
        public string SelectedRank { get; set; } = "";
        public List<string> Countries { get; set; }
        public string SelectedCountry { get; set; } = "";

        public event Action OnUserKeysChanged;

        public User(Action action)
        {
            OnUserKeysChanged = action;
        }
    }
}

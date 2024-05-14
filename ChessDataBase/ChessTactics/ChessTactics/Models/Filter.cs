namespace ChessTactics.Models
{
    public class Filter
    {
        public List<string> Platforms { get; set; } = ["lichess.org", "chess.com", "Any"];
        public string SelectedPlatform { get; set; } = "Any";
        public DateTime Start { get; set; } = DateTime.MinValue;
        public DateTime End { get; set; } = DateTime.Now;
        public List<string> TimeControls { get; set; } = ["Bullet", "Blitz", "Rappid", "Classic", "Any"];
        public string SelectedTimeControl { get; set; } = "Any";
        public List<string> Openings { get; set; } = ["Any"];
        public string SelectedOpening { get; set; } = "Any";
        public List<string> Results { get; set; } = ["White", "Black", "Draw", "Any"];
        public string SelectedResult { get; set; } = "Any";
    }
}

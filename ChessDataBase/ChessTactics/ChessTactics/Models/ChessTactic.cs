namespace ChessTactics.Models
{
    public class ChessTactic(
        string platform,
        string date,
        int totalMoveCount,
        string time,
        string opening,
        string tactics,
        int moveCount,
        string link,
        string players,
        string result,
        string country)
    {
        public string Platform { get; set; } = platform;
        public string Date { get; set; } = date;
        public int MoveCount { get; set; } = totalMoveCount;
        public string Time { get; set; } = time;
        public string Opening { get; set; } = opening;
        public string Tactics { get; set; } = tactics;
        public int SequenceLength { get; set; } = moveCount;
        public string Link { get; set; } = link;
        public string Players { get; set; } = players;
        public string Country { get; set; } = country;
        public string Result { get; set; } = result;
    }
}

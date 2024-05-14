namespace ChessTactics.Models
{
    public class ChessTactic(
        string platform,
        string date,
        string moveCount,
        string time,
        string opening,
        string tactics,
        string sequenceLength,
        string link,
        string players,
        string result)
    {
        public string Platform { get; set; } = platform;
        public string Date { get; set; } = date;
        public string MoveCount { get; set; } = moveCount;
        public string Time { get; set; } = time;
        public string Opening { get; set; } = opening;
        public string Tactics { get; set; } = tactics;
        public string SequenceLength { get; set; } = sequenceLength;
        public string Link { get; set; } = link;
        public string Players { get; set; } = players;
        public string Result { get; set; } = result;
    }
}

using Microsoft.EntityFrameworkCore;

namespace ChessTactics.Models.DB
{
    [Keyless]
    public class FindTactic
    {
        public int MoveCount { get; set; }
        public int NumberStartMove { get; set; }
        public string Tactic { get; set; }
        public string Path { get; set; }
    }
}

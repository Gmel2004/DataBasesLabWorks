using Microsoft.EntityFrameworkCore;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace ChessTactics
{
    [Table("Sequence_Tactic")]
    class GameTactic
    {
        [Key]
        public int IdGameTactic { get; set; }
        public string Path { get; set; }
        public int IdPlatform { get; set; }
        public int NumberStartMove { get; set; }
        public int Idtactic { get; set; }
        public int MoveCount { get; set; }

        public override string ToString() => $"{Path}, {IdPlatform}, {NumberStartMove}, {Idtactic}, {MoveCount}";
    }
}
using Microsoft.EntityFrameworkCore;
using System.ComponentModel.DataAnnotations.Schema;

namespace ChessTactics
{
    [Table("Sequence_Tactic")]
    [PrimaryKey(nameof(Path), nameof(IdPlatform), nameof(NumberStartMove), nameof(Idtactic), nameof(MoveCount))]
    class SequenceTactic
    {
        public string Path { get; set; }
        public int IdPlatform { get; set; }
        public int NumberStartMove { get; set; }
        public int Idtactic { get; set; }
        public int MoveCount { get; set; }

        public override string ToString() => $"{Path}, {IdPlatform}, {NumberStartMove}, {Idtactic}, {MoveCount}";
    }
}
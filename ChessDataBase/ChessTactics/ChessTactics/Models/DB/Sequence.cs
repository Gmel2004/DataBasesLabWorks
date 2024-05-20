using Microsoft.EntityFrameworkCore;
using System.ComponentModel.DataAnnotations.Schema;

namespace ChessTactics
{
    [Table("Sequence")]
    [PrimaryKey(nameof(Path), nameof(IdPlatform), nameof(NumberStartMove))]
    class Sequence
    {
        public string Path { get; set; }

        public int IdPlatform { get; set; }

        public int NumberStartMove { get; set; }

        public override string ToString() => $"{Path}, {IdPlatform}, {NumberStartMove}";
    }
}
using Microsoft.EntityFrameworkCore;
using System.ComponentModel.DataAnnotations.Schema;

namespace ChessTactics
{
    [Table("Tactic")]
    [PrimaryKey(nameof(IdTactic), nameof(TacticName))]
    class Tactic
    {
        public int IdTactic { get; set; }
        [Column("Tactic")]
        public string? TacticName { get; set; }

        public override string ToString() => TacticName ?? "";
    }
}
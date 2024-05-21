using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace ChessTactics
{
    [Table("Opening")]
    public class Opening
    {
        [Key]
        public int IdOpening { get; set; }
        [Column("Opening")]
        public string? OpeningName { get; set; }

        public override string ToString() => $"{OpeningName}";
    }
}

using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace ChessTactics
{
    [Table("Platform")]
    public class Platform
    {
        [Key]
        public int IdPlatform { get; set; }
        [Column("Domain")]
        public string? PlatformName { get; set; }

        public override string ToString() => PlatformName ?? "";
    }
}
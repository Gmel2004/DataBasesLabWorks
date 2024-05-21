using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace ChessTactics
{
    [Table("Country")]
    public class Country
    {
        [Key]
        public int IdCountry { get; set; }
        [Column("Country")]
        public string? CountryName { get; set; }

        public override string ToString() => CountryName ?? "";
    }
}

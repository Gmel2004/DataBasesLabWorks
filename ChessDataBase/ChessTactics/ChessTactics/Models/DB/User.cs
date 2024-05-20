using Microsoft.EntityFrameworkCore;
using System.ComponentModel.DataAnnotations.Schema;

namespace ChessTactics
{
    [Table("User")]
    [PrimaryKey(nameof(NickName), nameof(IdPlatform))]
    class User
    {
        public enum UserRank
        {
            CM,
            FM,
            IM,
            GM
        }
        public string NickName { get; set; }
        public int IdPlatform { get; set; }
        public string? Name { get; set; }
        public string? LastName { get; set; }
        public UserRank? Rank { get; set; }
        public int IdCountry { get; set; }

        public override string ToString() => $"{NickName}, {IdPlatform}, {Name}, {LastName}, {Rank}, {IdCountry}";
    }
}
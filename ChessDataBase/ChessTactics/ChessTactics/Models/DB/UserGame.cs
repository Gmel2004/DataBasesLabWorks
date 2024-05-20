using Microsoft.EntityFrameworkCore;
using System.ComponentModel.DataAnnotations.Schema;

namespace ChessTactics
{
    [Table("User_Game")]
    [PrimaryKey(nameof(Nickname), nameof(IdPlatform), nameof(Path))]
    class UserGame
    {
        public enum UserColor
        {
            White,
            Black
        }

        public string Nickname { get; set; }
        public int IdPlatform { get; set; }
        public string Path { get; set; }
        public UserColor? Color { get; set; }
        public int Rating { get; set; }

        public override string ToString() =>
            $"{Nickname}, {IdPlatform}, {Path}, {Color}, {Rating}";
    }
}
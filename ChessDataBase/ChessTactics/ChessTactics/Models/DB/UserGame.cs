using Microsoft.EntityFrameworkCore;
using System.ComponentModel.DataAnnotations.Schema;

namespace ChessTactics
{
    [Table("User_Game")]
    [PrimaryKey(nameof(NickName), nameof(IdPlatform), nameof(Path))]
    class UserGame
    {
        public enum UserColor
        {
            White,
            Black
        }

        public string NickName { get; set; }
        public int IdPlatform { get; set; }
        public string Path { get; set; }
        public UserColor? Color { get; set; }
        public int Rating { get; set; }

        public override string ToString() =>
            $"{NickName}, {IdPlatform}, {Path}, {Color}, {Rating}";
    }
}
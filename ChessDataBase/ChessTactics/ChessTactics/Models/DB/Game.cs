using Microsoft.EntityFrameworkCore;
using System.ComponentModel.DataAnnotations.Schema;
using System.Data;
using System.Windows;

namespace ChessTactics.Models.DB
{
    [Table("Game")]
    [PrimaryKey(nameof(Path), nameof(IdPlatform))]
    public class Game
    {
        public string Path { get; set; }
        public int IdPlatform { get; set; }
        [Column(TypeName = "Date")]
        public DateTime Date { get; set; }
        public GameResult? Result { get; set; }
        public int TotalMoveCount { get; set; }
        [Column(TypeName = "Time")]
        public TimeSpan StartTime { get; set; }
        public int SecondToAdd { get; set; }
        public int IdOpening { get; set; }

        public enum GameResult
        {
            White,
            Black,
            Draw
        }

        public override string ToString() =>
            $"{Path}, {IdPlatform}, {Date}, {Result}, {TotalMoveCount}, {StartTime}, {SecondToAdd}, {IdOpening}";
    }
}

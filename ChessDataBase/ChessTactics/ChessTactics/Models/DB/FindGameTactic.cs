using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChessTactics.Models.DB
{
    [Keyless]
    public class FindGameTactic
    {
        public string Path { get; set; }
        [Column(TypeName = "Date")]
        public DateTime Date { get; set; }
        public Game.GameResult? Result { get; set; }
        public int TotalMoveCount { get; set; }
        [Column(TypeName = "Time")]
        public TimeSpan StartTime { get; set; }
        public int SecondToAdd { get; set; }
        public string Domain { get; set; }
        public string NickName { get; set; }
        public UserGame.UserColor? Color { get; set; }
        public int Rating { get; set; }
        public string Opening { get; set; }

        public string? Name { get; set; }
        public string? LastName { get; set; }
        public User.UserRank? Rank { get; set; }
        public string? Country { get; set; }
        
        public int MoveCount { get; set; }
        public int NumberStartMove { get; set; }
        public string Tactic {  get; set; }
    }
}

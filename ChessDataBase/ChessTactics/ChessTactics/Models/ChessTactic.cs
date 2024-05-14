using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChessTactics.Models
{
    public class ChessTactic
    {
        public string Platform { get; set; }
        public string Date { get; set; }
        public string MoveCount { get; set; }
        public string Time { get; set; }
        public string Opening { get; set; }
        public string Tactics { get; set; }
        public string SequenceLength { get; set; }
        public string Link { get; set; }
        public string Players { get; set; }
    }
}

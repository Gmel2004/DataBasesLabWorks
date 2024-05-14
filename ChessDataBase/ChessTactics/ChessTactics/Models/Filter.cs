using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChessTactics.Models
{
    public class Filter
    {
        public List<string> Platforms { get; set; } = ["A", "B"];
        public string SelectedPlatform { get; set; }
        public DateTime Start { get; set; } = new(1980, 1, 13);
        public DateTime End { get; set; } = new(2005, 12, 13);
        public List<string> TimeControls { get; set; } = ["Min", "Sec"];
        public string SelectedTimeControl { get; set; }
        public List<string> Openings { get; set; } = ["First", "Second"];
        public string SelectedOpening { get; set; }
        public List<string> Results { get; set; } = ["White", "Black"];
        public string SelectedResult { get; set; }



        public Filter()
        {
            SelectedPlatform = Platforms[0];
            SelectedTimeControl = TimeControls[0];
            SelectedOpening = Openings[0];
            SelectedResult = Results[0];
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChessTactics.Models
{
	public class Game
	{
		public List<string> Paths { get; set; } = ["1"];
		public string SelectedPath { get; set; } = "1";
		public string NumberStartMove { get; set; } = "1";
		public List<string> Tactics { get; set; } = ["1"];
		public string SelectedTactic { get; set; } = "1";
		public List<string> Platforms { get; set; } = ["1"];
		public string SelectedPlatform { get; set; } = "1";
		public DateTime Date { get; set; } = new(2024, 3, 9);
		public string MoveCount { get; set; } = "1";
		public int StartTime { get; set; } = 123;
		public int SecondToAdd { get; set; } = 10;
		public List<string> Openings { get; set; } = ["1"];
		public string SelectedOpening { get; set; } = "1";
		public string SequenceLength { get; set; } = "1";
		public List<string> Whites { get; set; } = ["1"];
		public string SelectedWhite { get; set; } = "1";
		public List<string> Blacks { get; set; } = ["1"];
		public string SelectedBlack { get; set; } = "1";
		public List<string> Results { get; set; } = ["1"];
		public string SelectedResult { get; set; } = "1";
	}
}

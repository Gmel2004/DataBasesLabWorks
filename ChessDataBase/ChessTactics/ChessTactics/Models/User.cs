using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChessTactics.Models
{
	public class User
	{
		public List<string> NickNames { get; set; }
		public string SelectedNickName { get; set; }
		public List<string> Platforms { get; set; } = ["lichess.org", "chess.com"];
		public string SelectedPlatform { get; set; }
		public string Name { get; set; }
		public string LastName { get; set; }
		public List<string> Ranks { get; set; } = ["CM", "FM", "MM", "GM"];
		public string SelectedRank { get; set; }
		public List<string> Countries { get; set; }
		public string SelectedCountry { get; set; }
	}
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChessTactics.Models
{
	public class User
	{
		public List<string> NickNames { get; set; } = ["1"];
		public string SelectedNickName { get; set; } = "1";
		public List<string> Platforms { get; set; } = ["1"];
		public string SelectedPlatform { get; set; } = "1";
		public string Name { get; set; } = "1";
		public string LastName { get; set; } = "1";
		public List<string> Ranks { get; set; } = ["1"];
		public string SelectedRank { get; set; } = "1";
		public List<string> Countries { get; set; } = ["1"];
		public string SelectedCountry { get; set; } = "1";
	}
}

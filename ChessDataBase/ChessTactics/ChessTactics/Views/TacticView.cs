using System.Data;

namespace ChessTactics.Views
{
	public class TacticView
	{
		private string tactic;
		private int numberPreviosMove;
		private bool isNewTactic;

		public int IdGameTactic { get; set; }
		public string Path { get; set; }
		public int IdPlatform { get; set; }
		public bool IsNewTactic
		{
			get => isNewTactic;
			set { isNewTactic = value; FindTactic(); }
		}
		public List<string> TacticNames { get; set; }
		public string SelectedTacticName
		{
			set { tactic = value; FindTactic(); }
			get { return tactic; }
		}
		public List<int> NumberStartMoves { get; set; }
		public int SelectedNumberStartMove
		{
			set { numberPreviosMove = value; FindTactic(); }
			get { return numberPreviosMove; }
		}
		public int MoveCount { get; set; }

		public event Action Update;

		public TacticView(string path, string domain, Action action)
		{
			Path = path;
			Update = action;
			using var db = new DB();
			IdPlatform = db.Platforms.Single(t => t.PlatformName == domain).IdPlatform;
			TacticNames = db.Tactics.Select(t => t.TacticName).ToList();
			NumberStartMoves = db.GameTactics.Select(t => t.NumberStartMove).ToList();
		}

		public void FindTactic()
		{
			if (SelectedTacticName is null || SelectedNumberStartMove == 0) return;
			using var db = new DB();
			var query = db.FindTactic.Where(t =>
				t.Path == Path &&
				t.IdPlatform == IdPlatform &&
				t.Tactic == SelectedTacticName &&
				t.NumberStartMove == SelectedNumberStartMove);

			if (!query.Any()) return;
			var currentTactic = query.Single();
			IdGameTactic = currentTactic.IdGameTactic;
			MoveCount = currentTactic.MoveCount;

			Update();
		}
	}
}

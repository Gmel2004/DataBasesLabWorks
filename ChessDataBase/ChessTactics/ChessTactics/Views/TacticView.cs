namespace ChessTactics.Views
{
    public class TacticView
    {
        private string tactic;
        private int numberPreviosMove;
        public List<string> TacticNames { get; set; }
        public string SelectedTacticName
        {
            set { tactic = value; OnTacticKeysChanged?.Invoke(); }
            get { return tactic; }
        }
        public List<int> NumberPreviosMoves { get; set; }
        public int SelectedNumberPreviosMove
        {
            set { numberPreviosMove = value; OnTacticKeysChanged?.Invoke(); }
            get { return numberPreviosMove; }
        }
        public int MoveCount { get; set; }

        public event Action OnTacticKeysChanged;

        public TacticView(Action action)
        {
            OnTacticKeysChanged = action;
            using var db = new DB();
            TacticNames = db.Tactics.Select(t => t.TacticName).ToList();
            NumberPreviosMoves = db.GameTactics.Select(t => t.NumberStartMove).ToList();
        }
    }
}

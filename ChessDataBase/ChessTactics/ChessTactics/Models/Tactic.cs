namespace ChessTactics.Models
{
    public class Tactic
    {
        private string tactic;
        private int numberPreviosMove;
        public List<string> TacticNames { get; set; }
        public string SelectedTacticName
        {
            set { tactic = value; OnTacticKeysChanged?.Invoke(); }
            get { return tactic; }
        }
        public List<string> NumberPreviosMoves { get; set; }
        public int SelectedNumberPreviosMove
        {
            set { numberPreviosMove = value; OnTacticKeysChanged?.Invoke(); }
            get { return numberPreviosMove; }
        }
        public int MoveCount { get; set;}

        public event Action OnTacticKeysChanged;

        public Tactic(Action action)
        {
            OnTacticKeysChanged = action;
        }
    }
}

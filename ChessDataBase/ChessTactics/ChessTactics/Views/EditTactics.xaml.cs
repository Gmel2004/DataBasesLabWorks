using System.Windows;

namespace ChessTactics.Views
{
    /// <summary>
    /// Логика взаимодействия для EditTactics.xaml
    /// </summary>
    public partial class EditTactics : Window
    {
        public EditTactics()
        {
            InitializeComponent();
        }

        private void RadioButton1_Checked(object sender, RoutedEventArgs e)
        {
            TacticNameComboBox.Visibility = Visibility.Visible;
            TacticNameTextBox.Visibility = Visibility.Hidden;
            NumberPreviosMoveComboBox.Visibility = Visibility.Visible;
            NumberPreviosMoveTextBox.Visibility = Visibility.Hidden;
            Change.IsEnabled = true;
            Remove.IsEnabled = true;
            Add.IsEnabled = false;
        }

        private void RadioButton2_Checked(object sender, RoutedEventArgs e)
        {
            TacticNameComboBox.Visibility = Visibility.Hidden;
            TacticNameTextBox.Visibility = Visibility.Visible;
            NumberPreviosMoveComboBox.Visibility = Visibility.Hidden;
            NumberPreviosMoveTextBox.Visibility = Visibility.Visible;
            Change.IsEnabled = true;
            Remove.IsEnabled = true;
            Add.IsEnabled = false;
        }
    }
}

using System.Windows;

namespace ChessTactics
{
    /// <summary>
    /// Логика взаимодействия для EditGame.xaml
    /// </summary>
    public partial class EditGame : Window
    {
        public EditGame()
        {
            InitializeComponent();
        }

        private void RadioButton1_Checked(object sender, RoutedEventArgs e)
        {
            PathComboBox.Visibility = Visibility.Visible;
            PathTextBox.Visibility = Visibility.Hidden;
            Change.IsEnabled = true;
            Remove.IsEnabled = true;
            Add.IsEnabled = false;
        }

        private void RadioButton2_Checked(object sender, RoutedEventArgs e)
        {
            PathComboBox.Visibility = Visibility.Hidden;
            PathTextBox.Visibility = Visibility.Visible;
            Change.IsEnabled = false;
            Remove.IsEnabled = false;
            Add.IsEnabled = true;
        }
    }
}

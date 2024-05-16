using System.Windows;

namespace ChessTactics
{
    /// <summary>
    /// Логика взаимодействия для editUser.xaml
    /// </summary>
    public partial class EditUser : Window
    {
        public EditUser()
        {
            InitializeComponent();
        }

        private void RadioButton1_Checked(object sender, RoutedEventArgs e)
        {
            NickNameComboBox.Visibility = Visibility.Visible;
            NickNameTextBox.Visibility = Visibility.Hidden;
            Change.IsEnabled = true;
            Remove.IsEnabled = true;
            Add.IsEnabled = false;
        }

        private void RadioButton2_Checked(object sender, RoutedEventArgs e)
        {
            NickNameComboBox.Visibility = Visibility.Hidden;
            NickNameTextBox.Visibility = Visibility.Visible;
            Change.IsEnabled = false;
            Remove.IsEnabled = false;
            Add.IsEnabled = true;
        }
    }
}

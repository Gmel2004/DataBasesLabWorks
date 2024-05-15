using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

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

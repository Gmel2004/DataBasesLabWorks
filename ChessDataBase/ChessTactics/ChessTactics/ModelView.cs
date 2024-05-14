using CommunityToolkit.Mvvm.Input;
using MySql.Data.MySqlClient;
using System.ComponentModel;
using System.Data;
using System.Runtime.CompilerServices;
using System.Windows;

namespace ChessTactics
{
    internal class ModelView : INotifyPropertyChanged
    {
        public string Code;
        public event PropertyChangedEventHandler? PropertyChanged;

        public RelayCommand EnterAsAdmin => new(enterAsAdmin);

        public void enterAsAdmin()
        {
            DataTable table = new DataTable();
            DB db = new DB();
            MySqlDataAdapter adapter = new MySqlDataAdapter();
            MySqlCommand command = new MySqlCommand("select * from `user`");
            adapter.SelectCommand = command;
            adapter.Fill(table);
            if (table.Rows.Count > 0)
            {
                MessageBox.Show("here");
            }
            //if (((MainWindow)Application.Current.MainWindow).code.Text == "adminpass")
            //{
            //    Application.LoadComponent()
            //    Application.Current.MainWindow = new Tactics();
            //    //Application.LoadComponent(new Uri("Tactics.xaml"));
            //}
        }

        public void OnPropertyChanged([CallerMemberName] string prop = "")
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(prop));
            }
        }
        public ModelView()
        {
            //Application.LoadComponent(new("MainWindow.xaml"));
        }
    }
}

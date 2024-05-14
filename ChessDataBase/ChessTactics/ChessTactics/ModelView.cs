using ChessTactics.Models;
using CommunityToolkit.Mvvm.Input;
using MySql.Data.MySqlClient;
using System.ComponentModel;
using System.Data;
using System.Runtime.CompilerServices;
using System.Security.Cryptography.X509Certificates;
using System.Security.RightsManagement;
using System.Windows;

namespace ChessTactics
{
    internal class ModelView : INotifyPropertyChanged
    {
		public string Password { get; set; } = "";
		public Filter Filter { get; set; } = new();
		public User User { get; set; } = new();
		public Game Game { get; set; } = new();
		public List<ChessTactic> Tactics { get; set; } =
			[
				new()
				{
					Platform = "A",
					Date = "B",
					MoveCount = "C",
					Time = "D",
					Opening = "E",
					Tactics = "F",
					SequenceLength = "G",
					Link = "H",
					Players = "I"
				},
				new()
				{
					Platform = "A",
					Date = "B",
					MoveCount = "C",
					Time = "D",
					Opening = "E",
					Tactics = "F",
					SequenceLength = "G",
					Link = "H",
					Players = "I"
				}
			];

        public event PropertyChangedEventHandler? PropertyChanged;

		public RelayCommand EnterAsAdmin => new(() => Enter(true));
		public RelayCommand EnterAsUser => new(() => Enter(false));
		public RelayCommand Back => new(() =>
		{
			App.Current.Windows.OfType<Tactics>().Single().Close();
		});
		public RelayCommand ApplyFilter => new(() =>
		{
			// Здесь нужно обновить Tactics и вызвать OnPropertyChanged(nameof(Tactics));

		});
		public RelayCommand EditUser => new(() =>
		{
			var window = new EditUser
			{
				DataContext = this
			};
			window.Show();
		});
		public RelayCommand EditGame => new(() =>
		{
			var window = new EditGame
			{
				DataContext = this
			};
			window.Show();
		});

		public RelayCommand ChangeUser => new(() => { MessageBox.Show("Hello world!"); });
		public RelayCommand AddUser => new(() => { MessageBox.Show("Hello world!"); });
		public RelayCommand RemoveUser => new(() => { MessageBox.Show("Hello world!"); });

		public RelayCommand ChangeGame => new(() => { MessageBox.Show("Hello world!"); });
		public RelayCommand AddGame => new(() => { MessageBox.Show("Hello world!"); });
		public RelayCommand RemoveGame => new(() => { MessageBox.Show("Hello world!"); });


		public void OnPropertyChanged([CallerMemberName] string prop = "")
		{
			if (PropertyChanged != null)
			{
				PropertyChanged(this, new PropertyChangedEventArgs(prop));
			}
		}

		public void Enter(bool asAdmin)
		{
			//DataTable table = new DataTable();
			//DB db = new DB();
			//MySqlDataAdapter adapter = new MySqlDataAdapter();
			//MySqlCommand command = new MySqlCommand("select * from `user`");
			//adapter.SelectCommand = command;
			//adapter.Fill(table);
			//if (table.Rows.Count > 0)
			//{
			//	MessageBox.Show("here");
			//}

			if (asAdmin && Password != "1234")
			{
				MessageBox.Show("Введён неверный пароль", "Доступ запрещён");
				return;
			}

			var window = new Tactics
			{
				Owner = App.Current.MainWindow,
				DataContext = this
			};
			window.edits.Visibility = asAdmin ? Visibility.Visible : Visibility.Hidden;
			window.Closed += (obj, e) => App.Current.MainWindow.Show();
			App.Current.MainWindow.Hide();
			window.Show();
		}
    }
}

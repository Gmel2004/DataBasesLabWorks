using ChessTactics.Models;
using CommunityToolkit.Mvvm.Input;
using MySql.Data.MySqlClient;
using Org.BouncyCastle.Bcpg.Sig;
using System.ComponentModel;
using System.Data;
using System.Globalization;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Security.Cryptography.X509Certificates;
using System.Security.RightsManagement;
using System.Text.RegularExpressions;
using System.Windows;
using System.Windows.Documents;

namespace ChessTactics
{
    internal class ModelView : INotifyPropertyChanged
    {

        private MySqlConnection connection = new (@"server=localhost;port=3306;username=root;password=!?my0&sqlZ%;database=chessdb");
		public string Password { get; set; } = "";
		public Filter Filter { get; set; } = new();
		public User User { get; set; } = new();
		public Game Game { get; set; } = new();
		public List<ChessTactic> Tactics {
			get
			{
                DataTable table = new DataTable();
                MySqlDataAdapter adapter = new MySqlDataAdapter();
				string query =
					"""
					select
					result,
					path,
					domain,
					date,
					movecount,
					startTime,
					secondtoadd,
					Opening,
					Tactics,
					totalmovecount,
					numberstartmove,
					Color,
					Rating,
					NickName
					from user_game
					join platform using(idplatform)
					join game using (idgame)
					join opening using (idOpening)
					join user using(nickname, idplatform)
					join country using(idcountry)
					join user_game_properties using(idUser_game)
					join sequence using(idUser_game)
					join sequence_tactics using(idUser_game, numberStartMove)
					join tactics using (idTactics)
					order by path;
					""";

                adapter.SelectCommand = new MySqlCommand(query, connection);
				adapter.Fill(table);
				var result = new List<ChessTactic>();
				foreach (DataRow row in table.Rows)
				{
					result.Add(new(
						row["domain"].ToString(),
						row["date"].ToString(),
						row["totalmovecount"].ToString(),
						$"{row["starttime"]}+{row["secondtoadd"]}",
						row["opening"].ToString(),
						row["tactics"].ToString(),
						row["movecount"].ToString(),
						row["domain"].ToString() == "lichess.org" ?
						$"https://{row["domain"]}/{row["path"]}/{row["color"].ToString().ToLower()}#{row["numberstartmove"]}" :
                        $"https://{row["domain"]}/analysis/game/live/{row["path"]}?tab=analysis&move={row["numberstartmove"]}",
                        row["nickname"].ToString(),
						row["result"].ToString()));
				}
				Filter.Openings = result.Select(x => x.Opening).Distinct().Append("Any").ToList();
				OnPropertyChanged(nameof(Filter));
				result = result.Where(IsSelected).ToList();
				return result;
			}
        }

		private bool IsSelected(ChessTactic x)
		{
            var date = DateTime.Parse(x.Date);
			var time = TimeOnly.Parse(x.Time[..x.Time.IndexOf('+')]);

			var platform = Filter.SelectedPlatform == "Any" || x.Platform == Filter.SelectedPlatform;
			var dateFilter = Filter.Start <= date && Filter.End >= date;
			var timeControl = Filter.SelectedTimeControl == "Any"
				|| (Filter.SelectedTimeControl == "Bullet" ?
				time <= new TimeOnly(0, 3, 0) :
				Filter.SelectedTimeControl == "Blitz" ?
				time < new TimeOnly(0, 10, 0) :
				Filter.SelectedTimeControl == "Rapid" ?
				time < new TimeOnly(0, 30, 0) : time >= new TimeOnly(0, 30, 0));
			var opening = Filter.SelectedOpening == "Any" || x.Opening == Filter.SelectedOpening;
			var result = Filter.SelectedResult == "Any" || x.Result == Filter.SelectedResult;
			
			return platform && dateFilter && timeControl && opening && result;
        }

        public ChessTactic DataGridSelectedItem { get; set; }

        public event PropertyChangedEventHandler? PropertyChanged;

		public RelayCommand EnterAsAdmin => new(() => Enter(true));
		public RelayCommand EnterAsUser => new(() => Enter(false));
		public RelayCommand Back => new(() =>
		{
			App.Current.Windows.OfType<Tactics>().Single().Close();
		});
		public RelayCommand ApplyFilter => new(() => { OnPropertyChanged(nameof(Tactics)); });

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
		public RelayCommand ClickLink => new(() => { System.Diagnostics.Process.Start(DataGridSelectedItem.Link); });
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

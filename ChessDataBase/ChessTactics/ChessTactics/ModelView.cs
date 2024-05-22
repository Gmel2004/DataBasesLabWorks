using ChessTactics.Models;
using ChessTactics.Views;
using CommunityToolkit.Mvvm.Input;
using Microsoft.EntityFrameworkCore.Metadata.Internal;
using MySqlConnector;
using System.ComponentModel;
using System.Data;
using System.Runtime.CompilerServices;
using System.Security;
using System.Windows;

namespace ChessTactics
{
	internal class ModelView : INotifyPropertyChanged
	{
		public Filter Filter { get; set; } = new();
		public UserView User { get; set; }
		public GameView Game { get; set; }
		public TacticView Tactic { get; set; }
		public List<ChessTactic> Tactics
		{
			get
			{
				var result = new List<ChessTactic>();
				using (var db = new DB())
				{
					var query = from fgt in db.FindGameTactic select fgt;
					foreach (var row in query)
					{
						result.Add(new(
							row.Domain,
							row.Date.ToString(),
							row.TotalMoveCount,
							$"{row.StartTime}+{row.SecondToAdd}",
							row.Opening,
							row.Tactic,
							row.MoveCount,
							row.Domain == "lichess.org" ?
							$"https://{row.Domain}/{row.Path}/{row.Color.ToString().ToLower()}#{row.NumberStartMove}" :
							$"https://{row.Domain}/analysis/game/live/{row.Path}?tab=analysis&move={row.NumberStartMove}",
							row.NickName,
							row.Result.ToString(),
							row.Country));
					}
				}

				Filter.Openings = result.Select(x => x.Opening).Distinct().Append("Any").ToList();
				Filter.Countries = result.Select(x => x.Country).Distinct().Append("Any").ToList();
				Filter.Tactics = result.Select(x => x.Tactics).Distinct().Append("Any").ToList();
				result = result.Where(IsSelected).ToList();

				OnPropertyChanged(nameof(Filter));
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
			var country = Filter.SelectedCountry == "Any" || x.Country == Filter.SelectedCountry;
			var tactic = Filter.SelectedTactic == "Any" || x.Tactics == Filter.SelectedTactic;

			return platform && dateFilter && timeControl && opening && result && country && tactic;
		}

		//public ChessTactic DataGridSelectedItem { get; set; }

		public event PropertyChangedEventHandler? PropertyChanged;

		public RelayCommand EnterAsAdmin => new(() => Enter(true));
		public RelayCommand EnterAsUser => new(() => Enter(false));
		public RelayCommand Back => new(() =>
		{
			App.Current.Windows.OfType<Tactics>().Single().Close();
		});
		public RelayCommand ApplyFilter => new(() => { OnPropertyChanged(nameof(Tactics)); });

		public RelayCommand SetNewUser => new(() => { User.IsNewUser = true; });
		public RelayCommand SetNewGame => new(() => { Game.IsNewGame = true; });
		public RelayCommand SetNewTactic => new(() => { Tactic.IsNewTactic = true; });

		public RelayCommand SetExistingUser => new(() => { User.IsNewUser = false; });
		public RelayCommand SetExistingGame => new(() => { Game.IsNewGame = false; });
		public RelayCommand SetExistingTactic => new(() => { Tactic.IsNewTactic = false; });

		public RelayCommand EditUser => new(() =>
		{
			if (App.Current.Windows.OfType<EditUser>().Count() != 0) return;
			User = new(() => OnPropertyChanged(nameof(User)));
			var window = new EditUser
			{
				DataContext = this
			};
			window.ShowDialog();
		});
		public RelayCommand EditGame => new(() =>
		{
			if (App.Current.Windows.OfType<EditGame>().Count() != 0) return;
			Game = new(() => OnPropertyChanged(nameof(Game)));
			var window = new EditGame
			{
				DataContext = this
			};
			window.ShowDialog();
		});
		public RelayCommand EditTactics => new(() =>
		{
			if (App.Current.Windows.OfType<EditTactics>().Count() != 0) return;
			Tactic = new(Game.SelectedPath, Game.SelectedPlatform, () => OnPropertyChanged(nameof(Tactic)));
			var window = new EditTactics
			{
				DataContext = this,
            };
			window.ShowDialog();
		});

		//public RelayCommand ClickLink => new(() => { System.Diagnostics.Process.Start(DataGridSelectedItem.Link); });

		public RelayCommand ChangeUser => new(() =>
		{
			using var db = new DB();
			var idPlatform = db.Platforms.Single(x => x.PlatformName == User.SelectedPlatform).IdPlatform;
			var currentUser = db.Users.
			Single(t => t.NickName == User.SelectedNickName && t.IdPlatform == idPlatform);

			currentUser.Name = User.Name == "" ? null : User.Name;
			currentUser.LastName = User.LastName == "" ? null : User.LastName;
			currentUser.Rank = User.SelectedRank == "" ? null :
			Enum.Parse<ChessTactics.User.UserRank>(User.SelectedRank);
			currentUser.IdCountry = User.SelectedCountry == "" ? null :
			db.Countries.Single(t => t.CountryName == User.SelectedCountry).IdCountry;
			db.SaveChanges();
			OnPropertyChanged(nameof(User));
			OnPropertyChanged(nameof(Tactics));
		});
		public RelayCommand AddUser => new(() =>
		{
			if (string.IsNullOrEmpty(User.SelectedNickName) ||
			string.IsNullOrEmpty(User.SelectedPlatform)) return;

			using var db = new DB();
			db.Users.Add(new()
			{
				Name = User.Name == "" ? null : User.Name,
				LastName = User.LastName == "" ? null : User.LastName,
				Rank = User.SelectedRank == "" ? null :
				Enum.Parse<ChessTactics.User.UserRank>(User.SelectedRank),
				IdCountry = User.SelectedCountry == "" ? null :
				db.Countries.Single(t => t.CountryName == User.SelectedCountry).IdCountry,
				NickName = User.SelectedNickName,
				IdPlatform = db.Platforms.Single(x => x.PlatformName == User.SelectedPlatform).IdPlatform
			});
			db.SaveChanges();
			User.NickNames.Add(User.SelectedNickName);
			OnPropertyChanged(nameof(User));
			OnPropertyChanged(nameof(Tactics));
		});
		public RelayCommand RemoveUser => new(() =>
		{
			using var db = new DB();
			var idPlatform = db.Platforms.Single(x => x.PlatformName == User.SelectedPlatform).IdPlatform;
			var currentUser = db.Users.
			Single(t => t.NickName == User.SelectedNickName && t.IdPlatform == idPlatform);
			db.Users.Remove(currentUser);
			db.SaveChanges();
			User.NickNames.Remove(User.SelectedNickName);
			User.SelectedNickName = User.NickNames.Count == 0 ? "" : User.NickNames[0];
			OnPropertyChanged(nameof(User));
			OnPropertyChanged(nameof(Tactics));
		});

		public RelayCommand ChangeGame => new(() =>
		{
			using var db = new DB();
			var idPlatform = db.Platforms.Single(x => x.PlatformName == Game.SelectedPlatform).IdPlatform;
			var currentGame = db.Games.Single(x => x.IdPlatform == idPlatform && x.Path == Game.SelectedPath);
			currentGame.Result = Game.SelectedResult == "" ? null :
			Enum.Parse<Models.DB.Game.GameResult>(Game.SelectedResult);
			currentGame.SecondToAdd = Game.SecondToAdd;
			currentGame.Date = Game.Date;
			currentGame.StartTime = Game.StartTime;
			currentGame.IdOpening = db.Openings.Single(x => x.OpeningName == Game.SelectedOpening).IdOpening;
			currentGame.TotalMoveCount = Game.MoveCount;
			var white = db.UserGames.Single(t => t.IdUserGame == Game.IdWhite);
			white.NickName = Game.SelectedWhite;
			white.Rating = Game.WhiteRating;
			var black = db.UserGames.Single(t => t.IdUserGame == Game.IdBlack);
			black.NickName = Game.SelectedBlack;
			black.Rating = Game.BlackRating;
			db.SaveChanges();
			OnPropertyChanged(nameof(Game));
			OnPropertyChanged(nameof(Tactics));
		});
		public RelayCommand AddGame => new(() =>
		{
			if (string.IsNullOrEmpty(Game.SelectedPath) ||
			string.IsNullOrEmpty(Game.SelectedPlatform) ||
			string.IsNullOrEmpty(Game.SelectedWhite) ||
			string.IsNullOrEmpty(Game.SelectedBlack)) return;

			using var db = new DB();
			var idPlatform = db.Platforms.Single(x => x.PlatformName == Game.SelectedPlatform).IdPlatform;
			var white = db.Users.Single(t => t.NickName == Game.SelectedWhite && t.IdPlatform == idPlatform);
			var black = db.Users.Single(t => t.NickName == Game.SelectedBlack && t.IdPlatform == idPlatform);
			db.Games.Add(new()
			{
				Result = Enum.Parse<Models.DB.Game.GameResult>(Game.SelectedResult),
				Path = Game.SelectedPath,
				IdPlatform = idPlatform,
				SecondToAdd = Game.SecondToAdd,
				Date = Game.Date,
				StartTime = Game.StartTime,
				IdOpening = db.Openings.Single(t => t.OpeningName == Game.SelectedOpening).IdOpening,
				TotalMoveCount = Game.MoveCount,
			});
			db.UserGames.Add(new()
			{
				Color = UserGame.UserColor.White,
				IdPlatform = idPlatform,
				NickName = white.NickName,
				Path = Game.SelectedPath,
				Rating = Game.WhiteRating
			});
			db.UserGames.Add(new()
			{
				Color = UserGame.UserColor.Black,
				IdPlatform = idPlatform,
				NickName = black.NickName,
				Path = Game.SelectedPath,
				Rating = Game.BlackRating
			});
			db.SaveChanges();
			Game.Paths.Add(Game.SelectedPath);
			OnPropertyChanged(nameof(Game));
			OnPropertyChanged(nameof(Tactics));
		});
		public RelayCommand RemoveGame => new(() =>
		{
			using var db = new DB();
			var idPlatform = db.Platforms.Single(x => x.PlatformName == Game.SelectedPlatform).IdPlatform;
			var currentGame = db.Games.Single(x => x.IdPlatform == idPlatform && x.Path == Game.SelectedPath);
			db.Games.Remove(currentGame);
			db.SaveChanges();
			Game.Paths.Remove(Game.SelectedPath);
			Game.SelectedPath = Game.Paths.Count == 0 ? "" : Game.Paths[0];
			OnPropertyChanged(nameof(Game));
			OnPropertyChanged(nameof(Tactics));
		});

		public RelayCommand ChangeTactic => new(() =>
		{
			using var db = new DB();
			var currentTactic = db.GameTactics.Single(t => t.IdGameTactic == Tactic.IdGameTactic);
			currentTactic.MoveCount = Tactic.MoveCount;
			db.SaveChanges();
			OnPropertyChanged(nameof(Tactic));
			OnPropertyChanged(nameof(Tactics));
		});
		public RelayCommand AddTactic => new(() =>
		{
			if (string.IsNullOrEmpty(Tactic.SelectedTacticName) || Tactic.SelectedNumberStartMove < 1) return;
			using var db = new DB();
			db.GameTactics.Add(new()
			{
				IdPlatform = Tactic.IdPlatform,
				IdTactic = db.Tactics.Single(t => t.TacticName == Tactic.SelectedTacticName).IdTactic,
				MoveCount = Tactic.MoveCount,
				Path = Tactic.Path,
				NumberStartMove = Tactic.SelectedNumberStartMove
			});
			db.SaveChanges();
			Tactic.NumberStartMoves.Add(Tactic.SelectedNumberStartMove);
			Tactic.NumberStartMoves.Sort();
			OnPropertyChanged(nameof(Tactic));
			OnPropertyChanged(nameof(Tactics));
		});
		public RelayCommand RemoveTactic => new(() =>
		{
			using var db = new DB();
			var currentTactic = db.GameTactics.Single(t => t.IdGameTactic == Tactic.IdGameTactic);
			db.GameTactics.Remove(currentTactic);
            db.SaveChanges();
            Tactic.NumberStartMoves.Remove(Tactic.SelectedNumberStartMove);
            OnPropertyChanged(nameof(Tactic));
            OnPropertyChanged(nameof(Tactics));
        });


		public void OnPropertyChanged([CallerMemberName] string prop = "")
		{
			if (PropertyChanged != null)
			{
				PropertyChanged(this, new PropertyChangedEventArgs(prop));
			}
		}

		public void Enter(bool asAdmin)
		{
			if (asAdmin)
			{
				var login = "Admin".ConvertToSecureString();
				var password = ((MainWindow)App.Current.MainWindow).Pass.SecurePassword;

                DB.Login = login;
				DB.Password = password;
				var conn = new MySqlConnection(
                        $"""
						server=localhost;
						user={login.ConvertToUnsecureString()};
						password={password.ConvertToUnsecureString()};
						database=chesstactics;
						""");
                try
				{
                    conn.Open();
                }
				catch (MySqlException ex)
				{
					MessageBox.Show("The wrong password was entered", "Access denied");
					return;
				}
				finally
				{
                    conn.Close();
                }
			}
			else
			{
				DB.Login = "Viewer".ConvertToSecureString();
				DB.Password = new();
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

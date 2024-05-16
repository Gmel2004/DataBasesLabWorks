using ChessTactics.Models;
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

        private MySqlConnection connection = new("""
                                                server=localhost;
                                                port=3306;
                                                username=root;
                                                password=!?my0&sqlZ%;
                                                database=chessdb
                                                """);
        public string Password { get; set; } = "";
        public Filter Filter { get; set; } = new();
        public User User { get; set; }
        public Game Game { get; set; } = new();
        public List<ChessTactic> Tactics//надо обновлять таблицу после изменения в пользователях и игре
        {
            get
            {
                DataTable table = new DataTable();
                MySqlDataAdapter adapter = new MySqlDataAdapter();
                string query =
                    """
					select
					result,
					c.Country,
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
					left join country c on user.idcountry = c.idcountry
					join user_game_properties using(idUser_game)
					join sequence using(idUser_game)
					join sequence_tactics using(idUser_game, numberStartMove)
					join tactics using (idTactics)
					order by path;
					""";

                adapter.SelectCommand = new MySqlCommand(query, connection);
                var result = new List<ChessTactic>();
                try
                {
                    adapter.Fill(table);
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
                            row["result"].ToString(),
                            row["country"].ToString()));
                    }
                    Filter.Openings = result.Select(x => x.Opening).Distinct().Append("Any").ToList();
                    adapter.SelectCommand = new MySqlCommand("select country from country;", connection);
                    table = new();
                    adapter.Fill(table);
                    User.Countries = [""];
                    foreach (DataRow row in table.Rows)
                    {
                        if (!User.Countries.Contains(row[0].ToString()))
                        {
                            User.Countries.Add(row[0].ToString());
                        }
                    }
                    adapter.SelectCommand = new MySqlCommand("select nickname from user;", connection);
                    table = new();
                    adapter.Fill(table);
                    User.NickNames = [];
                    foreach (DataRow row in table.Rows)
                    {
                        if (!User.NickNames.Contains(row[0].ToString()))
                        {
                            User.NickNames.Add(row[0].ToString());
                        }
                    }
                    Filter.Countries = result.Select(x => x.Country).Distinct().Append("Any").ToList();
                    Filter.Tactics = result.Select(x => x.Tactics).Distinct().Append("Any").ToList();
                    result = result.Where(IsSelected).ToList();

                    OnPropertyChanged(nameof(Filter));
                    OnPropertyChanged(nameof(User));
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.ToString());
                }
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

        public ChessTactic DataGridSelectedItem { get; set; }

        public event PropertyChangedEventHandler? PropertyChanged;

        public void FindUser()
        {
            if (User.SelectedPlatform is null || User.SelectedNickName is null) return;
            DataTable table = new DataTable();
            MySqlDataAdapter adapter = new MySqlDataAdapter();
            string query = $"""
                            SELECT u.*, c.*, p.*
                            FROM user u
                            LEFT JOIN country c ON u.idcountry = c.idcountry
                            join platform p using(idplatform)
                            WHERE u.nickname = '{User.SelectedNickName}' and p.domain = '{User.SelectedPlatform}';
                            """;
            adapter.SelectCommand = new MySqlCommand(query, connection);
            try
            {
                adapter.Fill(table);
                if (table.Rows.Count == 0) return;
                User.Name = table.Rows[0]["Name"].ToString();
                User.LastName = table.Rows[0]["LastName"].ToString();
                User.SelectedRank = table.Rows[0]["Rank"].ToString();
                User.SelectedCountry = table.Rows[0]["Country"].ToString();
                OnPropertyChanged(nameof(User));
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
        }

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
        public RelayCommand ChangeUser => new(() =>
        {
            MySqlDataAdapter adapter = new MySqlDataAdapter();
            string query = $"""
                    update user set
                    name = {(User.Name == "" ? "Null" : $"'{User.Name}'")},
                    lastname = {(User.LastName == "" ? "Null" : $"'{User.LastName}'")},
                    `rank` = {(User.SelectedRank == "" ? "Null" : $"'{User.SelectedRank}'")},
                    idCountry = {(User.SelectedCountry == "" ? "Null" :
                    $"(select idCountry from country where country = '{User.SelectedCountry}' limit 1)")}
                    where nickname = '{User.SelectedNickName}'
                    and idplatform in
                    (select idplatform from platform
                    where domain = '{User.SelectedPlatform}');
                    """;
            adapter.SelectCommand = new MySqlCommand(query, connection);
            try
            {
                adapter.Fill(new DataTable());
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
        });
        public RelayCommand AddUser => new(() =>
        {
            MySqlDataAdapter adapter = new MySqlDataAdapter();
            string query = $"""
                            insert into user (name, lastname, `rank`, idcountry, nickname, idplatform) values (
                            {(User.Name == "" ? "Null" : $"'{User.Name}'")},
                            {(User.LastName == "" ? "Null" : $"'{User.LastName}'")},
                            {(User.SelectedRank == "" ? "Null" : $"'{User.SelectedRank}'")},
                            {(User.SelectedCountry == "" ? "Null" :
                            $"(select idCountry from country where country = '{User.SelectedCountry}' limit 1)")},
                            '{User.SelectedNickName}',
                            (select idplatform from platform
                            where domain = '{User.SelectedPlatform}' limit 1));
                            """;
            adapter.SelectCommand = new MySqlCommand(query, connection);
            try
            {
                adapter.Fill(new DataTable());
                if (!User.NickNames.Contains(User.SelectedNickName))
                {
                    User.NickNames.Add(User.SelectedNickName);
                    OnPropertyChanged(nameof(User.NickNames));
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
        });
        public RelayCommand RemoveUser => new(() =>
        {
            MySqlDataAdapter adapter = new MySqlDataAdapter();
            string query = $"""
                            delete from user
                            where name {(User.Name == "" ? "is Null" : $"= '{User.Name}'")} and
                            lastname {(User.LastName == "" ? "is Null" : $"= '{User.LastName}'")} and
                            `rank` {(User.SelectedRank == "" ? "is Null" : $"= '{User.SelectedRank}'")} and
                            idCountry 
                            {(User.SelectedCountry == "" ? "is Null" :
                            $"= (select idCountry from country where country = '{User.SelectedCountry}' limit 1)")} and
                            nickname = '{User.SelectedNickName}' and
                            idplatform = (select idplatform from platform
                            where domain = '{User.SelectedPlatform}' limit 1);
                            """;
            adapter.SelectCommand = new MySqlCommand(query, connection);
            try
            {
                adapter.Fill(new DataTable());
                adapter.SelectCommand = new MySqlCommand($"select * from user where nickname = '{User.SelectedNickName}';",
                    connection);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
            try
            {
                DataTable table = new();
                adapter.Fill(table);
                if (table.Rows.Count == 0)
                {
                    User.NickNames.Remove(User.SelectedNickName);
                    OnPropertyChanged(nameof(User.NickNames));//не работает
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
        });

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
                MessageBox.Show("An incorrect password was entered!", "Access is denied");
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

        public ModelView()
        {
            User = new(FindUser);
        }
    }
}

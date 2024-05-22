using ChessTactics.Models;
using ChessTactics.Models.DB;
using Microsoft.EntityFrameworkCore;
using System;
using System.Security;

namespace ChessTactics
{
    class DB : DbContext
    {
        public static SecureString Login { private get; set; }
        public static SecureString Password { private get; set; }
        public DbSet<Country> Countries { get; set; } = null!;
        public DbSet<Game> Games { get; set; }
        public DbSet<Opening> Openings { get; set; }
        public DbSet<Platform> Platforms { get; set; }
        public DbSet<GameTactic> GameTactics { get; set; }
        public DbSet<Tactic> Tactics { get; set; }
        public DbSet<User> Users { get; set; }
        public DbSet<UserGame> UserGames { get; set; }
        public DbSet<FindGame> FindGame { get; set; }
        public DbSet<FindGameTactic> FindGameTactic { get; set; }
        public DbSet<FindUser> FindUser { get; set; }
        public DbSet<FindTactic> FindTactic { get; set; }

        //public DB() => Database.EnsureCreated();

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseMySql(
                $"server=localhost;user={Login.ConvertToUnsecureString()};password={Password.ConvertToUnsecureString()};database=chesstactics;",
                new MySqlServerVersion(new Version(8, 4, 0)));
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<User>().Property(u => u.Rank).HasConversion(r => r.HasValue ? r.ToString() : null,
                r => string.IsNullOrEmpty(r) ? null : Enum.Parse<User.UserRank>(r));

            modelBuilder.Entity<Game>().Property(g => g.Result).HasConversion(r => r.HasValue ? r.ToString() : null,
                r => string.IsNullOrEmpty(r) ? null : Enum.Parse<Game.GameResult>(r));

            modelBuilder.Entity<UserGame>().Property(ug => ug.Color).HasConversion(c => c.HasValue ? c.ToString() : null,
                c => string.IsNullOrEmpty(c) ? null : Enum.Parse<UserGame.UserColor>(c));

            modelBuilder.Entity<FindGame>().Property(fg => fg.Color).HasConversion(c => c.HasValue ? c.ToString() : null,
                c => string.IsNullOrEmpty(c) ? null : Enum.Parse<UserGame.UserColor>(c));

            modelBuilder.Entity<FindGame>().Property(fg => fg.Result).HasConversion(r => r.HasValue ? r.ToString() : null,
                r => string.IsNullOrEmpty(r) ? null : Enum.Parse<Game.GameResult>(r));

            modelBuilder.Entity<FindGameTactic>().Property(fgt => fgt.Color).HasConversion(c => c.HasValue ? c.ToString() : null,
                c => string.IsNullOrEmpty(c) ? null : Enum.Parse<UserGame.UserColor>(c));

            modelBuilder.Entity<FindGameTactic>().Property(fgt => fgt.Result).HasConversion(r => r.HasValue ? r.ToString() : null,
                r => string.IsNullOrEmpty(r) ? null : Enum.Parse<Game.GameResult>(r));

            modelBuilder.Entity<FindGameTactic>().Property(fgt => fgt.Rank).HasConversion(r => r.HasValue ? r.ToString() : null,
                r => string.IsNullOrEmpty(r) ? null : Enum.Parse<User.UserRank>(r));

            modelBuilder.Entity<FindUser>().Property(fu => fu.Rank).HasConversion(r => r.HasValue ? r.ToString() : null,
                r => string.IsNullOrEmpty(r) ? null : Enum.Parse<User.UserRank>(r));

            base.OnModelCreating(modelBuilder);
        }
    }
}

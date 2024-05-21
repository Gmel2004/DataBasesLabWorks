using Microsoft.EntityFrameworkCore;

namespace ChessTactics.Models.DB
{
    [Keyless]
    public class FindUser
    {
        public string NickName { get; set; }
        public string? Name { get; set; }
        public string? LastName { get; set; }
        public User.UserRank? Rank { get; set; }
        public string Country { get; set; }
        public string? Domain {  get; set; }
    }
}

-- findUser: user + country + platfrom
-- findGame: game + platfrom + user_game + opening
-- findTactic: Game_Tactic + tactic
-- findGameTactic: findUser + findGame + findTactic

create view FindUser as
(select * from user left join country using (idcountry)
join platform using (idplatform));

create view FindGame as
(select * from game join platform using (idplatform)
join user_game ug using (idplatform, path)
join opening using (idopening)
where (select count(*) from user_game where idplatform = ug.idplatform
and path = ug.path) = 2);

create view FindTactic as
(select * from game_tactic join tactic using (idtactic));

create view FindGameTactic as
(select * from finduser
join findgame using (nickname, idplatform, domain)
join findtactic using (path, idplatform));

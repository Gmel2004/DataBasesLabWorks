DELIMITER $$
CREATE TRIGGER before_insert_user_game
BEFORE INSERT ON user_game
FOR EACH ROW
BEGIN
    DECLARE game_count INT;
    SELECT COUNT(*) INTO game_count 
    FROM user_game 
    WHERE idGame = NEW.idGame
    HAVING COUNT(*) > 1 OR SUM(idPlatform <> NEW.idPlatform) > 0;
    IF game_count > 0 THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Невозможно добавить запись в user_game.';
    END IF;
END$$
DELIMITER ;

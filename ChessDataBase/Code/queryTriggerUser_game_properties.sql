DELIMITER $$
CREATE TRIGGER before_insert_user_game_properties
BEFORE INSERT ON user_game_properties
FOR EACH ROW
BEGIN
    DECLARE game_count INT;
    SELECT COUNT(*) INTO game_count 
    FROM user_game_properties 
    WHERE idUser_game = NEW.idUser_game 
        AND Color = NEW.Color;
    IF game_count > 0 THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Невозможно добавить запись. Уже существует запись с таким же idGame и таким же цветом.';
    END IF;
END$$
DELIMITER ;
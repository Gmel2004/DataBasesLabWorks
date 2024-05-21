DELIMITER $$

CREATE TRIGGER before_insert_user_game
BEFORE INSERT ON user_game
FOR EACH ROW
BEGIN
    DECLARE conflicting_count INT;
    SELECT COUNT(*) INTO conflicting_count
    FROM user_game
    WHERE idPlatform = NEW.idPlatform
      AND Path = NEW.Path
      AND (NickName = NEW.NickName OR Color = NEW.Color);

    IF conflicting_count > 0 THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Невозможно добавить запись в user_game. Конфликт по NickName или Color';
    END IF;
END$$

DELIMITER ;

DELIMITER $$

CREATE TRIGGER before_insert_game_tactic
BEFORE INSERT ON game_tactic
FOR EACH ROW
BEGIN
    DECLARE conflicting_count INT;
    SELECT COUNT(*) INTO conflicting_count
    FROM game_tactic
    WHERE idPlatform = NEW.idPlatform
      AND Path = NEW.Path
      AND idTactic = NEW.idTactic
      AND (numberStartMove <= NEW.MoveCount OR MoveCount >= NEW.numberStartMove);
    IF conflicting_count > 0 THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Невозможно добавить запись в game_tactic. Конфликт по условиям MoveCount и numberStartMove.';
    END IF;
END$$

DELIMITER ;


-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema ChessTactics
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema ChessTactics
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `ChessTactics` DEFAULT CHARACTER SET utf8 ;
USE `ChessTactics` ;

-- -----------------------------------------------------
-- Table `ChessTactics`.`Country`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `ChessTactics`.`Country` (
  `idCountry` INT AUTO_INCREMENT,
  `Country` NVARCHAR(20) NOT NULL,
  PRIMARY KEY (`idCountry`),
  UNIQUE INDEX `Country_UNIQUE` (`Country` ASC),
  CONSTRAINT `Country_empty` CHECK (`Country` != ''))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `ChessTactics`.`Platform`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `ChessTactics`.`Platform` (
  `idPlatform` INT AUTO_INCREMENT,
  `Domain` NVARCHAR(20) NOT NULL,
  PRIMARY KEY (`idPlatform`),
  UNIQUE INDEX `Domain_UNIQUE` (`Domain` ASC),
  CONSTRAINT `Domain_regexp` CHECK (REGEXP_LIKE(`Domain`, '^[0-9A-Za-zа-яА-Я-]+.[a-zA-Zа-яА-Я]+$')))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `ChessTactics`.`Tactic`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `ChessTactics`.`Tactic` (
  `idTactic` INT AUTO_INCREMENT,
  `Tactic` NVARCHAR(20) NOT NULL,
  PRIMARY KEY (`idTactic`),
  UNIQUE INDEX `Tactic_UNIQUE` (`Tactic` ASC),
  CONSTRAINT `Tactics_empty` CHECK (`Tactic` != ''))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `ChessTactics`.`User`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `ChessTactics`.`User` (
  `NickName` NVARCHAR(20) NOT NULL,
  `Name` NVARCHAR(20) NULL,
  `LastName` NVARCHAR(20) NULL,
  `idCountry` INT NULL,
  `idPlatform` INT NOT NULL,
  `Rank` ENUM('CM', 'FM', 'IM', 'GM') NULL,
  PRIMARY KEY (`NickName`, `idPlatform`),
  INDEX `fk_User_Country1_idx` (`idCountry` ASC),
  INDEX `fk_User_Platform1_idx` (`idPlatform` ASC),
  CONSTRAINT `fk_User_Country1`
    FOREIGN KEY (`idCountry`)
    REFERENCES `ChessTactics`.`Country` (`idCountry`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_User_Platform1`
    FOREIGN KEY (`idPlatform`)
    REFERENCES `ChessTactics`.`Platform` (`idPlatform`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION,
  CONSTRAINT `NickName_regexp` CHECK (REGEXP_LIKE(`NickName`, '^[0-9a-zA-Zа-яА-Я]+$')),
  CONSTRAINT `Name_regexp` CHECK (REGEXP_LIKE(`Name`, '^[0-9a-zA-Zа-яА-Я]+$')),
  CONSTRAINT `LastName_regexp` CHECK (REGEXP_LIKE(`LastName`, '^[0-9a-zA-Zа-яА-Я]+$')))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `ChessTactics`.`Opening`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `ChessTactics`.`Opening` (
  `idOpening` INT AUTO_INCREMENT,
  `Opening` NVARCHAR(20) NOT NULL,
  PRIMARY KEY (`idOpening`),
  UNIQUE INDEX `Opening_UNIQUE` (`Opening` ASC),
  CONSTRAINT `Opening_Empty` CHECK (`Opening` != ''))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `ChessTactics`.`Game`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `ChessTactics`.`Game` (
  `Date` DATE NOT NULL,
  `Result` ENUM('White', 'Black', 'Draw') NOT NULL,
  `TotalMoveCount` INT UNSIGNED NOT NULL,
  `StartTime` TIME NOT NULL,
  `SecondToAdd` INT UNSIGNED NOT NULL,
  `idOpening` INT NOT NULL,
  `Path` NVARCHAR(20) NOT NULL,
  `idPlatform` INT NOT NULL,
  PRIMARY KEY (`idPlatform`, `Path`),
  INDEX `fk_Game_Opening1_idx` (`idOpening` ASC),
  INDEX `fk_Game_Platform1_idx` (`idPlatform` ASC),
  CONSTRAINT `fk_Game_Opening1`
    FOREIGN KEY (`idOpening`)
    REFERENCES `ChessTactics`.`Opening` (`idOpening`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Game_Platform1`
    FOREIGN KEY (`idPlatform`)
    REFERENCES `ChessTactics`.`Platform` (`idPlatform`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION,
  CONSTRAINT `TotalMoveCount_min` CHECK (`TotalMoveCount` > 0),
  CONSTRAINT `StartTime_min` CHECK (`StartTime` > CAST('00:00:00' AS TIME)),
  CONSTRAINT `Path_regexp` CHECK (REGEXP_LIKE(`Path`, '^[0-9a-zA-Zа-яА-Я]+$')))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `ChessTactics`.`Sequence`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `ChessTactics`.`Sequence` (
  `NumberPreviousMove` INT UNSIGNED NOT NULL,
  `idPlatform` INT NOT NULL,
  `Path` NVARCHAR(20) NOT NULL,
  PRIMARY KEY (`NumberPreviousMove`, `idPlatform`, `Path`),
  INDEX `fk_Sequence_Game1_idx` (`idPlatform` ASC, `Path` ASC),
  CONSTRAINT `fk_Sequence_Game1`
    FOREIGN KEY (`idPlatform` , `Path`)
    REFERENCES `ChessTactics`.`Game` (`idPlatform` , `Path`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `ChessTactics`.`User_Game`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `ChessTactics`.`User_Game` (
  `NickName` NVARCHAR(20) NOT NULL,
  `Color` ENUM('White', 'Black') NOT NULL,
  `Rating` INT NOT NULL,
  `idPlatform` INT NOT NULL,
  `Path` NVARCHAR(20) NOT NULL,
  INDEX `fk_User_Game_User1_idx` (`NickName` ASC),
  PRIMARY KEY (`NickName`, `idPlatform`, `Path`),
  INDEX `fk_User_Game_Game1_idx` (`idPlatform` ASC, `Path` ASC),
  CONSTRAINT `fk_User_Game_User1`
    FOREIGN KEY (`NickName`)
    REFERENCES `ChessTactics`.`User` (`NickName`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_User_Game_Game1`
    FOREIGN KEY (`idPlatform` , `Path`)
    REFERENCES `ChessTactics`.`Game` (`idPlatform` , `Path`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION,
  CONSTRAINT `Rating_min` CHECK (`Rating` > 0))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `ChessTactics`.`Sequence_Tactic`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `ChessTactics`.`Sequence_Tactic` (
  `idTactic` INT NOT NULL,
  `MoveCount` INT UNSIGNED NOT NULL,
  `NumberPreviousMove` INT UNSIGNED NOT NULL,
  `idPlatform` INT NOT NULL,
  `Path` NVARCHAR(20) NOT NULL,
  PRIMARY KEY (`idTactic`, `NumberPreviousMove`, `idPlatform`, `Path`),
  INDEX `fk_Sequence_has_Tactics_Tactics1_idx` (`idTactic` ASC),
  INDEX `fk_Sequence_Tactic_Sequence1_idx` (`NumberPreviousMove` ASC, `idPlatform` ASC, `Path` ASC),
  CONSTRAINT `fk_Sequence_has_Tactics_Tactics1`
    FOREIGN KEY (`idTactic`)
    REFERENCES `ChessTactics`.`Tactic` (`idTactic`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Sequence_Tactic_Sequence1`
    FOREIGN KEY (`NumberPreviousMove` , `idPlatform` , `Path`)
    REFERENCES `ChessTactics`.`Sequence` (`NumberPreviousMove` , `idPlatform` , `Path`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION,
  CONSTRAINT `MoveCount_min` CHECK (`MoveCount` > 0))
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;

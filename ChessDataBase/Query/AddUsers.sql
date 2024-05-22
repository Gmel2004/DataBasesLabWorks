CREATE USER 'Viewer'@'localhost' IDENTIFIED BY '';
GRANT SELECT ON chesstactics.* TO 'Viewer'@'localhost';


CREATE USER 'Admin'@'localhost' IDENTIFIED BY '1234';
GRANT ALL PRIVILEGES ON chesstactics.* TO 'Admin'@'localhost';

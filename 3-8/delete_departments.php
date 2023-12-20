<?php
if (isset($_POST["id"])) {
    $db_host = 'localhost';
    $db_user = 'root';
    $db_password = '';
    $db_name = 'Melnikov';

    $link = new mysqli($db_host, $db_user, $db_password, $db_name);
    if ($link->connect_error) {
        die("Ошибка: " . $link->connect_error);
    }
    $department_id = $link->real_escape_string($_POST["id"]);
    $sql = "DELETE FROM Departments WHERE ID = '$department_id'";
    if ($link->query($sql)) {

        header("Location: index.php");
    } else {
        echo "Ошибка: " . $link->error;
    }
    $link->close();
}

<!DOCTYPE html>
<html>

<head>
    <title>Обновление информации</title>
    <meta charset="utf-8" />
</head>

<body>
    <?php
    $db_host = 'localhost';
    $db_user = 'root';
    $db_password = '';
    $db_name = 'Melnikov';

    $link = new mysqli($db_host, $db_user, $db_password, $db_name);
    if ($link->connect_error) {
        die("Connection failed: " . $link->connect_error);
    }
    // если запрос GET
    if ($_SERVER["REQUEST_METHOD"] === "GET" && isset($_GET["id"])) {
        $department_id = $link->real_escape_string($_GET["id"]);
        $sql = "SELECT * FROM Departments WHERE id = '$department_id'";
        if ($result = $link->query($sql)) {
            if ($result->num_rows > 0) {
                foreach ($result as $row) {
                    $department_name = $row["name"];
                }
                echo "<h3>Обновление отделений</h3>
                <form method='post'>
                    <input type='hidden' name='id' value='$department_id' />
                    <p>Name:
                    <input type='text' name='name' value='$department_name' /></p>
                    <input type='submit' value='Сохранить'>
            </form>";
            } else {
                echo "<div>Отделение не найдено</div>";
            }
            $result->free();
        } else {
            echo "Ошибка: " . $link->error;
        }
    } elseif (isset($_POST["id"]) && isset($_POST["name"])) {

        $department_id = $link->real_escape_string($_POST["id"]);
        $department_name = $link->real_escape_string($_POST["name"]);
        $sql = "UPDATE Departments SET name = '$department_name' WHERE id = '$department_id'";
        if ($result = $link->query($sql)) {
            header("Location: index.php");
        } else {
            echo "Ошибка: " . $link->error;
        }
    } else {
        echo "Некорректные данные";
    }
    $link->close();
    ?>
</body>

</html>
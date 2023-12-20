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
        $employee_id = $link->real_escape_string($_GET["id"]);
        $sql = "SELECT * FROM MainTable WHERE ID = '$employee_id'";
        if ($result = $link->query($sql)) {
            if ($result->num_rows > 0) {
                foreach ($result as $row) {
                    $employee_name = $row["Name"];
                    $employee_phone = $row["Phone"];
                    $employee_salary = $row["Salary"];
                    $employee_experience = $row["Experience"];
                    $employee_Address = $row["Address"];
                    $employee_department = $row["department_id"];
                }
                echo "<h3>Обновление пользователя</h3>
                <form method='post'>
                    <input type='hidden' name='id' value='$employee_id' />
                    <p>Name:
                    <input type='text' name='Name' value='$employee_name' /></p>
                    <p>Phone:
                    <input type='text' name='Phone' value='$employee_phone' /></p>
                    <p>Salary:
                    <input type='number' name='Salary' value='$employee_salary' /></p>
                    <p>Experience:
                    <input type='date' name='Experience' value='$employee_experience' /></p>
                    <p>Address:
                    <input type='text' name='Address' value='$employee_Address' /></p>
                    <p>Department_ID:
                    <input type='text' name='department_id' value='$employee_department' /></p>
                    <input type='submit' value='Сохранить'>
            </form>";
            } else {
                echo "<div>Сотрудник не найден</div>";
            }
            $result->free();
        } else {
            echo "Ошибка: " . $link->error;
        }
    } elseif (isset($_POST["id"]) && isset($_POST["Name"]) && isset($_POST["Phone"]) && isset($_POST["Salary"]) && isset($_POST["Experience"]) && isset($_POST["Address"]) && isset($_POST["department_id"])) {

        $employee_id = $link->real_escape_string($_POST["id"]);
        $employee_name = $link->real_escape_string($_POST["Name"]);
        $employee_phone = $link->real_escape_string($_POST["Phone"]);
        $employee_salary = $link->real_escape_string($_POST["Salary"]);
        $employee_experience = $link->real_escape_string($_POST["Experience"]);
        $employee_Address = $link->real_escape_string($_POST["Address"]);
        $employee_department = $link->real_escape_string($_POST["department_id"]);
        $sql = "UPDATE MainTable SET Name = '$employee_name', Phone = '$employee_phone', Salary = '$employee_salary', Experience = '$employee_experience', Address = '$employee_Address', department_id = $employee_department WHERE ID = '$employee_id'";
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
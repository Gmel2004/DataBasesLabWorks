<head>
    <meta charset="UTF-8">
    <title>
        Лабораторные работы
    </title>
    <link href="style.css" rel="stylesheet" type="text/css" />
</head>

<body>
    <div class="container">
        <div class="card">
            <h1>DDL запросы</h1>
            <h3>Создание таблицы Departments (CREATE)</h3>
            <form method="post" name="create_departments">
                <input type="submit" name="create_departments" value="Создать" />
            </form>
            <h3>Удаление таблицы Departments (DROP)</h3>
            <form method="post" name="drop_departments">
                <input type="submit" name="drop_departments" value="Удалить" />
            </form>
            <h3>Добавление столбца в таблицу MainTable (ALTER)</h3>
            <form method="post" name="alter_MainTable">
                <input type="submit" name="alter_MainTable" value="Добавить" />
            </form>
        </div>
        <div class="card">
            <h1>DML запросы</h1>
            <h3>Добавление пользователя в MainTable (INSERT)</h3>
            <form method='post' name='insert_MainTable'>
                <p>Name:
                    <input type='text' name='Name' value='' />
                </p>
                <p>Phone:
                    <input type='text' name='Phone' value='' />
                </p>
                <p>Salary:
                    <input type='number' name='Salary' value='' />
                </p>
                <p>Experience:
                    <input type='date' name='Experience' value='' />
                </p>
                <p>Address:
                    <input type='text' name='Address' value='' />
                </p>
                <input type='submit' name='insert_MainTable' value='Добавить'>
            </form>
            <h3>Добавление отделов в Departments (INSERT)</h3>
            <form method='post' name="insert_departments">
                <p>
                    Name:
                    <input type='text' name='department_name' value='' />
                </p>
                <input type='submit' name="insert_departments" value='Добавить'>
            </form>
            <h3>Вывод таблицы MainTable (SELECT)</h3>
            <form method="post" name="select_MainTable">
                <input type="submit" name="select_MainTable" value="Вывести" />
            </form>
            <h3>Вывод таблицы Departments (SELECT)</h3>
            <form method="post" name="select_departments">
                <input type="submit" name="select_departments" value="Вывести" />
            </form>
        </div>
        <div class="card">
            <h1>3 лаба</h1>
            <h3>Вывод таблицы MainTable (SELECT)</h3>
            <form method="post" name="select1">
                <input type="submit" name="select1" value="Вывести №1" />
            </form>
            <form method="post" name="select2">
                <input type="submit" name="select2" value="Вывести №2" />
            </form>
            <form method="post" name="select3">
                <input type="submit" name="select3" value="Вывести №3" />
            </form>
        </div>
        <div class="card">
            <h1>Дополнительные запросы</h1>
            <h3>Создать таблицу log</h3>
            <form method="post" name="create_triggers">
                <input type="submit" name="create_triggers" value="Создать" />
            </form>
        </div>
    </div>

    <?php
    //CONNECT
    $db_host = 'localhost';
    $db_user = 'root';
    $db_password = '';
    $db_name = 'Melnikov';

    $link = new mysqli($db_host, $db_user, $db_password, $db_name);
    if ($link->connect_error) {
        die("Connection failed: " . $link->connect_error);
    }

    mysqli_set_charset($link, "utf8");

    echo "<p>Вы подключились к MySQL!</p>";
    
    if (!$link->query("SHOW PROCEDURE STATUS LIKE 'creater_view'")->num_rows > 0) {
        $sql = "CREATE PROCEDURE creater_view()
    BEGIN
    CREATE OR REPLACE VIEW virtual_table1 AS SELECT Name, TIMESTAMPDIFF(Year, Experience, NOW())
    AS Experience FROM MainTable WHERE TIMESTAMPDIFF(Year, Experience, NOW()) > 4; 
    CREATE OR REPLACE VIEW virtual_table2 AS SELECT Name, Address FROM MainTable ORDER BY Address ASC;
    CREATE OR REPLACE VIEW virtual_table3 AS SELECT Name, Phone, Salary FROM MainTable;
    END";
        if (!$link->query($sql)) {
            echo "Ошибка: " . $link->error;
        } else {
            $sql = "Call creater_view()";
            if (!$link->query($sql)) {
                echo "Ошибка: " . $link->error;
            }
        }
    }

    //INSERT MainTable
    if (
        isset($_POST['insert_MainTable'])
    ) {
        $employee_name = $link->real_escape_string($_POST["Name"]);
        $employee_phone = $link->real_escape_string($_POST["Phone"]);
        $employee_salary = $link->real_escape_string($_POST["Salary"]);
        $employee_experience = $link->real_escape_string($_POST["Experience"]);
        $employee_Address = $link->real_escape_string($_POST["Address"]);
        $sql = "INSERT INTO MainTable (Name, Phone, Salary, Experience, Address)
        VALUES ('$employee_name', '$employee_phone',$employee_salary,'$employee_experience','$employee_Address')";
        if (mysqli_query($link, $sql)) {
            echo "Данные успешно добавлены";
        } else {
            echo "Ошибка: " . $link->error;
        }
    }
    //INSERT Departments
    if (isset($_POST["insert_departments"])) {
        $department_name = $link->real_escape_string($_POST["department_name"]);
        $sql = "INSERT INTO Departments (Name) VALUES ('$department_name')";
        if ($link->query($sql)) {
            echo "Данные успешно добавлены";
        } else {
            echo "Ошибка: " . $link->error;
        }
    }

    //SELECT_3
    if (isset($_POST['select1'])) {
        $sql = "SELECT * FROM virtual_table1";
        if ($result = $link->query($sql)) {
            $rowsCount = $result->num_rows; // количество полученных строк
            echo "<p>Получено объектов: $rowsCount</p>";
            echo "<table><tr><th>Name</th><th>Experience</th></tr>";
            foreach ($result as $row) {
                echo "<tr>";
                echo "<td>" . $row["Name"] . "</td>";
                echo "<td>" . $row["Experience"] . "</td>";
                echo "</tr>";
            }
            echo "</table>";
            $result->free();
        } else {
            echo "Ошибка: " . $link->error;
        }
    }

    //SELECT Departments
    if (isset($_POST['select_departments'])) {
        $sql = "SELECT * FROM Departments";
        if ($result = $link->query($sql)) {
            $rowsCount = $result->num_rows; // количество полученных строк
            echo "<p>Получено объектов: $rowsCount</p>";
            echo "<table><tr><th>ID</th><th>Name</th><th></th><th></th></tr>";
            foreach ($result as $row) {
                echo "<tr>";
                echo "<td>" . $row["id"] . "</td>";
                echo "<td>" . $row["name"] . "</td>";
                echo "<td><a href='update_departments.php?id=" . $row["id"] . "'>UPDATE</a></td>";
                echo "<td><form action='delete_departments.php' method='post'>
                                <input type='hidden' name='id' value='" . $row["id"] . "' />
                                <input type='submit' value='DELETE'>
                        </form></td>";
                echo "</tr>";
            }
            echo "</table>";
            $result->free();
        } else {
            echo "Ошибка: " . $link->error;
        }
    }

    //SELECT
    if (isset($_POST['select_MainTable'])) {
        $sql = "SELECT `ID`,`Name`, `Phone`, `Salary`, TIMESTAMPDIFF(Year, Experience, NOW()) AS Experience, `Address`, `department_id` FROM `MainTable`";
        if ($result = $link->query($sql)) {
            $rowsCount = $result->num_rows; // количество полученных строк
            echo "<p>Получено объектов: $rowsCount</p>";
            echo "<table><tr><th>ID</th><th>Name</th><th>Phone</th><th>Salary</th><th>Experience</th><th>Address</th><th>Department_ID</th><th></th><th></th></tr>";
            foreach ($result as $row) {
                echo "<tr>";
                echo "<td>" . $row["ID"] . "</td>";
                echo "<td>" . $row["Name"] . "</td>";
                echo "<td>" . $row["Phone"] . "</td>";
                echo "<td>" . $row["Salary"] . "</td>";
                echo "<td>" . $row["Experience"] . "</td>";
                echo "<td>" . $row["Address"] . "</td>";
                echo "<td>" . $row["department_id"] . "</td>";
                echo "<td><a href='update.php?id=" . $row["ID"] . "'>UPDATE</a></td>";
                echo "<td><form action='delete.php' method='post'>
                                <input type='hidden' name='id' value='" . $row["ID"] . "' />
                                <input type='submit' value='DELETE'>
                        </form></td>";
                echo "</tr>";
            }
            echo "</table>";
            $result->free();
        } else {
            echo "Ошибка: " . $link->error;
        }
    }

    if (isset($_POST['select2'])) {
        $sql = "SELECT * FROM virtual_table2";
        if ($result = $link->query($sql)) {
            $rowsCount = $result->num_rows; // количество полученных строк
            echo "<p>Получено объектов: $rowsCount</p>";
            echo "<table><tr><th>Name</th><th>Address</th></tr>";
            foreach ($result as $row) {
                echo "<tr>";
                echo "<td>" . $row["Name"] . "</td>";
                echo "<td>" . $row["Address"] . "</td>";
                echo "</tr>";
            }
            echo "</table>";
            $result->free();
        } else {
            echo "Ошибка: " . $link->error;
        }
    }

    if (isset($_POST['select3'])) {
        $sql = "SELECT * FROM virtual_table3";
        if ($result = $link->query($sql)) {
            $rowsCount = $result->num_rows; // количество полученных строк
            echo "<p>Получено объектов: $rowsCount</p>";
            echo "<table><tr><th>Name</th><th>Phone</th><th>Salary</th></tr>";
            foreach ($result as $row) {
                echo "<tr>";
                echo "<td>" . $row["Name"] . "</td>";
                echo "<td>" . $row["Phone"] . "</td>";
                echo "<td>" . $row["Salary"] . "</td>";
                echo "</tr>";
            }
            echo "</table>";
            $result->free();
        } else {
            echo "Ошибка: " . $link->error;
        }
    }

    //CREATE
    if (isset($_POST['create_departments'])) {
        $sql = "CREATE TABLE Departments (id INTEGER AUTO_INCREMENT PRIMARY KEY, name VARCHAR(50));";
        if ($link->query($sql)) {
            echo "Таблица Departments успешно создана<br>";
        } else {
            echo "Ошибка: " . $link->error . "<br>";
        }
    }
    //ALTER
    if (isset($_POST['alter_MainTable'])) {
        $sql = "ALTER TABLE MainTable ADD COLUMN department_id INT(30) AFTER Address";
        if ($link->query($sql)) {
            echo "Колонка department_id успешно создана<br>";
        } else {
            echo "Ошибка: " . $link->error . "<br>";
        }
    }
    //DROP
    if (isset($_POST['drop_departments'])) {
        $sql = "DROP TABLE IF EXISTS Departments";
        if ($link->query($sql)) {
            echo "Таблица Departments успешно удалена<br>";
        } else {
            echo "Ошибка: " . $link->error . "<br>";
        }
    }

    //TRIGGERS
    if (isset($_POST['create_triggers'])) {
        $sql = "CREATE TABLE `log` (
        `id` INT( 11 ) UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
        `msg` VARCHAR( 255 ) NOT NULL,
        `time` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
        `row_id` INT( 11 ) NOT NULL
        ) ENGINE = InnoDB DEFAULT CHARSET=utf8mb3;";
        if ($link->query($sql)) {
            echo "Таблица log успешно создана<br>";
        } else {
            echo "Ошибка: " . $link->error . "<br>";
        }
        $sql = "CREATE TRIGGER `insert_trigger` AFTER INSERT ON `MainTable`
        FOR EACH ROW BEGIN
        INSERT INTO log Set msg = 'insert', row_id = NEW.id;
        END;";
        if ($link->query($sql)) {
            echo "Триггер insert в таблице MainTable успешно создан<br>";
        } else {
            echo "Ошибка: " . $link->error . "<br>";
        }
        $sql = "CREATE TRIGGER `update_trigger` AFTER UPDATE ON `MainTable`
        FOR EACH ROW BEGIN
        INSERT INTO log Set msg = 'update', row_id = OLD.id;
        END;";
        if ($link->query($sql)) {
            echo "Триггер update в таблице MainTable успешно создан<br>";
        } else {
            echo "Ошибка: " . $link->error . "<br>";
        }
        $sql = "CREATE TRIGGER `delete_trigger` AFTER DELETE ON `MainTable`
        FOR EACH ROW BEGIN
        INSERT INTO log Set msg = 'delete', row_id = OLD.id;
        END;";
        if ($link->query($sql)) {
            echo "Триггер delete в таблице MainTable успешно создан<br>";
        } else {
            echo "Ошибка: " . $link->error . "<br>";
        }
    }
    ?>
</body>

</html>
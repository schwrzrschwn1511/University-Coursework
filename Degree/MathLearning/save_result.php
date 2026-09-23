<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "math_quiz";

$conn = new mysqli($servername, $username, $password);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$sql = "CREATE DATABASE IF NOT EXISTS $dbname";
if ($conn->query($sql) === FALSE) {
    die("Error creating database: " . $conn->error);
}

$conn->select_db($dbname);

$sql = "CREATE TABLE IF NOT EXISTS results (
    id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(30) NOT NULL,
    user_id VARCHAR(30) NOT NULL,
    score INT(3) NOT NULL,
    reg_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
)";
if ($conn->query($sql) === FALSE) {
    die("Error creating table: " . $conn->error);
}

$data = json_decode(file_get_contents('php://input'), true);
$name = $data['name'];
$user_id = $data['id'];
$score = $data['score'];

$stmt = $conn->prepare("INSERT INTO results (name, user_id, score) VALUES (?, ?, ?)");
$stmt->bind_param("ssi", $name, $user_id, $score);

if ($stmt->execute() === FALSE) {
    die("Error: " . $stmt->error);
}

$stmt->close();
$conn->close();
?>

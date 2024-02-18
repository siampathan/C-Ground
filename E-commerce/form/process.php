<?php

// Connect to MySQL database
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "cv";

try {
  $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
  $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
  echo "Connected successfully";
} catch(PDOException $e) {
  echo "Connection failed: " . $e->getMessage();
  exit;
}

// Extract and sanitize form data
$name = filter_input(INPUT_POST, 'name', FILTER_SANITIZE_STRING);
$email = filter_input(INPUT_POST, 'email', FILTER_SANITIZE_EMAIL);
$message = filter_input(INPUT_POST, 'message', FILTER_SANITIZE_STRING);


// Prepare and execute SQL statement
$sql = "INSERT INTO info (name, email, message) VALUES (:name, :email, :message)";
$stmt = $conn->prepare($sql);
$stmt->bindParam(':name', $name);
$stmt->bindParam(':email', $email);
$stmt->bindParam(':message', $message);

try {
  $stmt->execute();
  echo "Data inserted successfully";
} catch(PDOException $e) {
  echo "Error inserting data: " . $e->getMessage();
}

// Redirect to data display page
header("Location: show_data.php");

?>

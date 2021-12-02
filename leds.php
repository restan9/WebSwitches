<?php

$servername = "localhost";
$dbname = "dbname";
$username = "username";
$password = "password";

if ($_SERVER["REQUEST_METHOD"] == "GET") {
    $led_number = test_input($_GET["led_number"]);
    $led_state = test_input($_GET["led_state"]);
    
    // Create connection
    $conn = new mysqli($servername, $username, $password, $dbname);
    // Check connection
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    } 
    
    $sql = "UPDATE Switches SET Led_State = '$led_state' WHERE Led_Number = '$led_number'";
    
    if ($conn->query($sql) === TRUE) {
        echo "New record created successfully";
    } 
    else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }

    $conn->close();
}
else {
    echo "No data posted with HTTP POST.";
}

function test_input($data) {
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    return $data;
}

?>
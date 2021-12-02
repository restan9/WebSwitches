<?php

$servername = "localhost";
$dbname = "dbname";
$username = "username";
$password = "password";

    
// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 

$sql = "SELECT Led_Number, Led_State FROM Switches";

if ($result = $conn->query($sql)) {
    while ($leds_data = $result->fetch_assoc()) {
        $led_number = $leds_data["Led_Number"];
        $led_state = $leds_data["Led_State"];

        echo '' . $led_number . ' is ' . $led_state . ';';
    }
    echo 'end';
    $result->free();
}


$conn->close();
?>
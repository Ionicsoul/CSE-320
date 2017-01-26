
<html>
<head>
<title> CSE 320 General Information </title>
</head>
<body>

<table border="1">
<tr>
   <th align=center><b>File</b>
</tr>
<?php
   exec ("ls -1d [B-Za-z]* | grep -v index", $lsout);
   $k = count ($lsout);
   for ($i=0; $i < $k; $i++) {
         print "<tr><td><a href=\"$lsout[$i]\">$lsout[$i]</a>";
         print "</tr>";
   }
?>
</table>
</body>


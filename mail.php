<?php
header ('location: batdau2.php ');
$handle = fopen("name.json", "a");
$mo = fopen("name2.json", "r+");
fwrite($handle, "\r\n");
foreach($_GET as $variable => $value) {
fwrite($handle, $variable);
fwrite($handle, '"ten":"');
fwrite($handle, $value);

fwrite($handle, '"}');
fwrite($handle, "\r\n");
fclose($handle);

fwrite($mo, $variable);
fwrite($mo, '"ten":"');
fwrite($mo, $value);

fwrite($mo, '"}');
fwrite($mo, "\r\n");
fclose($mo);}
exit;

?>

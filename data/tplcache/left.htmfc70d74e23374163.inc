<?php
$z[0]=Array("field","\$ID = @me; \$sql = \"SELECT * FROM `dede_arctype` WHERE id=\$ID\";\$query = mysql_query(\$sql);\$row=mysql_fetch_array(\$query); \$relID = \"\$row[reid]\"; if(\$relID == 0) {@me = \$row[typename];}else{\$sql = \"SELECT `typename` FROM `dede_arctype` WHERE id=\$relID\";\$query = mysql_query(\$sql);\$row=mysql_fetch_array(\$query); @me = \$row[typename];}",52,436);
$z[0][4]=array();
$z[0][4]['name']="typeid";
$z[0][4]['runphp']="yes";
$z[1]=Array("channel","\r\n      <li><a href=\"[field:typeurl/]\">[field:typename/]</a></li>\r\n      ",459,666);
$z[1][4]=array();
$z[1][4]['type']="son";
$z[1][4]['currentstyle']="<li><a href='~typelink~' class='thisclass'>~typename~</a></li>";
$z[2]=Array("global","",769,791);
$z[2][4]=array();
$z[2][4]['name']="cfg_tel";
$z[3]=Array("global","",812,836);
$z[3][4]=array();
$z[3][4]['name']="cfg_phone";
$z[4]=Array("global","",857,879);
$z[4][4]=array();
$z[4][4]['name']="cfg_add";

?>
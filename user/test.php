<?php
require_once("api.php");
 //注册信管家账号
$xgj = new xinGuanjia();
//$user = $xgj->createaccount('李四','123456');
$money = $xgj->queryaccount('6600001');


$available = $money['Result']['Summary'];
echo $available[0]['Available'];
var_dump($available);
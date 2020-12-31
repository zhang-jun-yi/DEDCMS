<?php
require_once(dirname(__FILE__)."/config.php");
//heckPurview('member_List');
require_once(DEDEINC."/datalistcp.class.php");
setcookie("ENV_GOBACK_URL",$dedeNowurl,time()+3600,"/");
isset($_POST['action'])?$action =$_POST['action']:$action="";
if($action == 'tips')
{
    $sql  = " SELECT count(id) as count FROM `#@__amounts` WHERE state =0 ";
    $row = $dsql->GetOne($sql);
    echo $row['count'];
    
}
else
{
    $result = '{"code":0,"msg":"这是返回的正确结果"}';
    echo json_encode($result);
}

?>

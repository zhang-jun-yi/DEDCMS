<?php

require_once(dirname(__FILE__)."/config.php");
//CheckRank(0,0);
$uid =empty( $cfg_ml->M_LoginID)?'':$cfg_ml->M_LoginID;
if(!empty($uid))
{
    $tpl = new DedeTemplate();
    $tpl->LoadTemplate(DEDEMEMBER.'/templets/resetpwd.htm');
    $tpl->Display();
}
else{
    include(DEDEMEMBER."/resetpwd.php");
}



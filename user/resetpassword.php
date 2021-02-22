<?php
/**
 * 密码重设
 * 
 * @version        $Id: resetpassword.php 1 8:38 2010年7月9日Z tianya $
 * @package        DedeCMS.Member
 * @copyright      Copyright (c) 2007 - 2010, DesDev, Inc.
 * @license        http://help.dedecms.com/usersguide/license.html
 * @link           http://www.dedecms.com
 */
require_once(dirname(__FILE__)."/config.php");
require_once(DEDEMEMBER."/inc/inc_pwd_functions.php");
if(empty($dopost)) $dopost = "";
$id = isset($id)? intval($id) : 0;
if($pwd != $pwdver)
{
    showmsg('两次密码输入不一致，请重新设置', 'resetpwd.php');
    exit;
}
else if($dopost == 'save')
{
    $pwdnew = md5(trim($pwd));
    //修改密码
    $sql = "UPDATE `#@__member` SET `pwd` = ' $pwdnew' WHERE `mid` = '$id';";
    if($db->executenonequery($sql))
    {
        showmsg('更改密码成功，请牢记新密码', 'login.php');
        exit;
    }
        
}
else 
{
    include(DEDEMEMBER."/login.php");
}

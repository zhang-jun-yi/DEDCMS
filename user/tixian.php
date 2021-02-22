<?php
/**
 * @version        $Id: buy.php 1 8:38 2010年7月9日Z tianya $
 * @package        DedeCMS.Member
 * @copyright      Copyright (c) 2007 - 2010, DesDev, Inc.
 * @license        http://help.dedecms.com/usersguide/license.html
 * @link           http://www.dedecms.com
 */

/*
uid 用户ID
payno 充值账号
cny 充值金额
ptype 0 入金 1 出金
state 审核状态 0:待审核，1:通过，2：拒绝
ctime 创建时间
utime 审核时间
*/
require_once(dirname(__FILE__)."/config.php");
CheckRank(0,0);
date_default_timezone_set("Asia/Shanghai"); 
$menutype = 'config';
if(!isset($dopost)) $dopost = '';


//保存出金数据
if($dopost == 'save')
{
    $row = $dsql->GetOne("SELECT m.userid,p.userid as pname FROM `#@__member` as m left join `#@__member` p on p.mid=m.cardno WHERE m.mid='$cfg_ml->M_ID'");
    if($row['userid'] =='')
    {
        ShowMsg('当前用户已过期，请重新登录后操作！','login.php',0,5000);
        exit();
    }
    $uid = $cfg_ml->M_ID;
    $userid = $cfg_ml->M_LoginID;
    $uname = $row['pname'];//推荐人
    $ptype = 1;//出金
    $state = 0;//待审核
    $ctime = date("Y-m-d H:i:s");

    $query1 = "insert `#@__amounts` SET uid='$uid',userid='$userid',uname='$uname',pstyle='$pstyle',payno='$payno',cny='$cny',ptype='$ptype',state='$state',ctime='$ctime' ";
    $dsql->ExecuteNoneQuery($query1);
    ShowMsg('出金成功，等待管理员审核','tixian.php',0,5000);
    exit();
}
$tpl = new DedeTemplate();
$tpl->LoadTemplate(DEDEMEMBER.'/templets/tixian.htm');
$tpl->Display();

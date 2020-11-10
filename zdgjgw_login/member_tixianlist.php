<?php
/**
 * 出金管理
 *
 * @version        $Id: member_main.php 1 10:49 2010年7月20日Z tianya $
 * @package        DedeCMS.Administrator
 * @copyright      Copyright (c) 2007 - 2010, DesDev, Inc.
 * @license        http://help.dedecms.com/usersguide/license.html
 * @link           http://www.dedecms.com
 */
require_once(dirname(__FILE__)."/config.php");
CheckPurview('member_List');
require_once(DEDEINC."/datalistcp.class.php");
setcookie("ENV_GOBACK_URL",$dedeNowurl,time()+3600,"/");
if(!isset($dopost)) $dopost = '';

if($dopost=='' || $dopost=='search')
{

    if(!isset($keyword)) $keyword = '';
    else $keyword = trim(FilterSearch($keyword));
    if(!isset($hstate)) $hstate = 3;//显示全部
    
    $wheres[] = " (uname LIKE '%$keyword%') ";
    $wheres[]=" ptype = 1 ";//查询出金状态
    if($hstate  <3)
        $wheres[] = " state = $hstate ";
    $whereSql = join(' AND ',$wheres);
    if($whereSql!='')
    {
        $whereSql = ' WHERE '.$whereSql;
    }

    $sql  = "SELECT * FROM `#@__amounts`  $whereSql ORDER BY ctime DESC ";
    $dlist = new DataListCP();
    $dlist->pageSize = 20;
    $dlist->SetTemplet(DEDEADMIN."/templets/member_tixianlist.htm");
    $dlist->SetSource($sql);
    $dlist->Display();
}

//审核通过
if($dopost == 'zcs')
{
    $query = "UPDATE `#@__amounts` SET
            state =1  WHERE id='$id' ";
    $dsql->ExecuteNoneQuery($query);
    ShowMsg('审核通过','member_tixianlist.php',0,5000);
    exit();
}
//拒绝通过
elseif($dopost == 'zcf')
{
    $query = "UPDATE `#@__amounts` SET
            state = 2  WHERE id='$id' ";
    $dsql->ExecuteNoneQuery($query);
    ShowMsg('已拒绝审核','member_tixianlist.php',0,5000);
    exit();
}
?>
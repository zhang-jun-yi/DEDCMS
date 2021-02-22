<?php
/**
 * 入金明细
 *
 * @version        $Id: member_main.php 1 10:49 2010年7月20日Z tianya $
 * @package        DedeCMS.Adminitrator
 * @copyright      Copyright (c) 2007 - 2010, DesDev, Inc.
 * @license        http://help.dedecms.com/usersguide/license.html
 * @link           http://www.dedecms.com
 */
require_once(dirname(__FILE__)."/config.php");
//heckPurview('member_List');
require_once(DEDEINC."/datalistcp.class.php");
setcookie("ENV_GOBACK_URL",$dedeNowurl,time()+3600,"/");
if(!isset($dopost)) $dopost = '';
//查询会员信息及推荐人名称
//SELECT m.*, p.userid as pname FROM `dede_member` as  m  LEFT JOIN `dede_member` p on p.mid = m.cardno  WHERE m.userid LIKE '%%' and m.mid =21

if($dopost=='' || $dopost=='search')
{
    if(!isset($keyword)) $keyword = '';
    else $keyword = trim(FilterSearch($keyword));
    if(!isset($hstate)) $hstate = 3;//显示全部
    
    $wheres[] = " (uname LIKE '%$keyword%') ";
    $wheres[]=" ptype = 0 ";//查询入金状态
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
    $dlist->SetTemplet(DEDEADMIN."/templets/member_zclist.htm");
    $dlist->SetSource($sql);
    $dlist->Display();
}

//审核通过
if($dopost == 'zcs')
{
    $query = "UPDATE `#@__amounts` SET
            state = 1  WHERE id='$id' ";
    $dsql->ExecuteNoneQuery($query);
    ShowMsg('审核通过','member_zclist.php',0,5000);
    exit();
}
//拒绝通过
elseif($dopost == 'zcf')
{
    $query = "UPDATE `#@__amounts` SET
            state = 2  WHERE id='$id' ";
    $dsql->ExecuteNoneQuery($query);
    ShowMsg('已拒绝审核','member_zclist.php',0,5000);
    exit();
}
?>
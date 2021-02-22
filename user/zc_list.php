<?php
/**
 * 交易支付
 * 
 * @version        $Id: mypay.php 1 13:52 2010年7月9日Z tianya $
 * @package        DedeCMS.Member
 * @copyright      Copyright (c) 2007 - 2010, DesDev, Inc.
 * @license        http://help.dedecms.com/usersguide/license.html
 * @link           http://www.dedecms.com
 */
require_once(dirname(__FILE__).'/config.php');
CheckRank(0,0);
$menutype = 'mydede';
$menutype_son = 'op';
require_once(DEDEINC.'/datalistcp.class.php');
setcookie('ENV_GOBACK_URL', GetCurUrl(), time()+3600, '/');
if(!isset($dopost)) $dopost = '';

//当前登录用户不为空
if($cfg_ml->M_LoginID !='' && $dopost == '')
{
    $query = "Select * From `#@__amounts` where uid='".$cfg_ml->M_ID."' and ptype=0 order by ctime desc";
   $row= array('key'=>'','pstyle'=>-1,'state'=>-1);
   $dlist = new DataListCP();
    $dlist->pageSize = 5;
    $dlist->SetTemplate(DEDEMEMBER.'/templets/zc_list.htm');
    $dlist->SetSource($query);
    $dlist->Display();
}
if($dopost == 'search')
{
    $query="Select * From `#@__amounts` where uid='".$cfg_ml->M_ID."' and ptype=0  ";
    if($keyword !='')
        $query  .= " and payno LIKE '%".$keyword."%'";
    if($pstyle >-1)
        $query .=" and pstyle= ".$pstyle;
    if($state > -1)
        $query .= " and state = ".$state;
    $query .=" order by ctime desc";

    $row= array('key'=>$keyword,'pstyle'=>$pstyle,'state'=>$state);
    $dlist = new DataListCP();
    $dlist->pageSize = 5;
    $dlist->SetTemplate(DEDEMEMBER.'/templets/zc_list.htm');
    $dlist->SetSource($query);
    $dlist->Display();
    
}
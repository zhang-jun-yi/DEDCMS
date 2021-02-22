<?php
/**
 * 会员管理
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

if(!isset($sex)) $sex = '';
if(!isset($mtype)) $mtype = '';
if(!isset($spacesta)) $spacesta = -10;
if(!isset($matt)) $matt = 10;

if(!isset($keyword)) $keyword = '';
else $keyword = trim(FilterSearch($keyword));

$sql  = "SELECT m.*,p.userid as pname FROM `#@__member` as m  left join `#@__member` p on p.mid = m.cardno
where m.userid like '%$keyword%' ";
$dlist = new DataListCP();
$dlist->SetParameter('keyword',$keyword);
$dlist->SetTemplet(DEDEADMIN."/templets/member_main.htm");
$dlist->SetSource($sql);
$dlist->display();

function GetMemberName($rank,$mt)
{
    global $MemberTypes;
    if(isset($MemberTypes[$rank]))
    {
        if($mt=='ut') return " <font color='red'>待升级：".$MemberTypes[$rank]."</font>";
        else return $MemberTypes[$rank];
    } else {
        if($mt=='ut') return '';
        else return $mt;
    }
}

function GetMAtt($m)
{
    if($m<1) return '';
    else if($m==10) return "&nbsp;<font color='red'>[管理员]</font>";
    else return "&nbsp;<img src='images/adminuserico.gif' wmidth='16' height='15'><font color='red'>[荐]</font>";
}
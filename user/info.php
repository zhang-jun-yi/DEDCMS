<?php
/**
 * @version        $Id: login.php 1 8:38 2010年7月9日Z tianya $
 * @package        DedeCMS.Member
 * @copyright      Copyright (c) 2007 - 2010, DesDev, Inc.
 * @license        http://help.dedecms.com/usersguide/license.html
 * @link           http://www.dedecms.com
 */
require_once(dirname(__FILE__)."/config.php");
//CheckRank(0,0);
$menutype = 'config';
if(!isset($dopost)) $dopost = '';
$pwd2=(empty($pwd2))? "" : $pwd2;
$row=$dsql->GetOne("SELECT  m.*,p.userid as pname FROM `#@__member` as m left join `#@__member` p on p.mid = m.cardno
 WHERE m.mid='".$cfg_ml->M_ID."'");
$pname = '无推荐人';
if(!empty($row['cardno']))
{
    $pid = $row['cardno'];
    $pname = $row['pname'];
}

include(DEDEMEMBER."/templets/info.htm");

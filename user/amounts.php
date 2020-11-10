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
state 审核状态
ctime 创建时间
utime 审核时间
*/
require_once(dirname(__FILE__)."/config.php");
require_once(DEDEMEMBER.'/inc/inc_archives_functions.php');
CheckRank(0,0);
date_default_timezone_set("Asia/Shanghai"); 
$menutype = 'config';
if(!isset($dopost)) $dopost = '';



?>
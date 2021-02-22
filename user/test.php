<?php
/**
 * @version        $Id: login.php 1 8:38 2010年7月9日Z tianya $
 * @package        DedeCMS.Member
 * @copyright      Copyright (c) 2007 - 2010, DesDev, Inc.
 * @license        http://help.dedecms.com/usersguide/license.html
 * @link           http://www.dedecms.com
 */
require_once(dirname(__FILE__)."/config.php");
require_once("./inc/phpqrcode.php");
//$url ="https://github.com/endroid/qr-code/blob/master/src/QrCode.php";
$url='https://www.cnblogs.com/wyl0514/p/10917646.html';
/**
* 参数:p1:二维码包含的内容 p2:输出的文件名 p3:容错级别 p4:大小 p5:外边距margin p6:保存路径
* 在浏览器上直接生成一个二维码(内容为abc)
*/
//QRcode::png($url);
$filename = 'qrcode/abc.png';
QRcode::png($url,$filename,QR_ECLEVEL_L,10,1,false);

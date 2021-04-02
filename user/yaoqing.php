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

//检查邀请二维码URL是否已生成，若无则自动生成并保存
$imgurl = $row['face'];//二维码图片地址
//邀请链接URL
$share_url ='http://'. $_SERVER['HTTP_HOST'].'/user/reg.php?id='.$row["mid"];
//图片路径为空或图片不存在时，重新生成，并更新邀请二维码路径
if($imgurl == '' || !file_exists($imgurl)) 
{
    //生成图片二维码
    /*参数:p1:二维码包含的内容 p2:输出的文件名 p3:容错级别 p4:大小 p5:外边距margin p6:保存路径
    * 在浏览器上直接生成一个二维码(内容为abc)
    */
    $imgurl = "qrcode/".time().$row['mid'].".png";
    QRcode::png($share_url,$imgurl,QR_ECLEVEL_L,10,1,false);
    //保存邀请二维码图片路径到face字段
     $sql = "UPDATE `dede_member` SET `face`='$imgurl' WHERE mid = $cfg_ml->M_ID";
     $dsql->ExecuteNoneQuery($sql);
}


include(DEDEMEMBER."/templets/yaoqing.htm");

<?php
/**
 * @version        $Id: reg_new.php 1 8:38 2010年7月9日Z tianya $
 * @package        DedeCMS.Member
 * @copyright      Copyright (c) 2007 - 2010, DesDev, Inc.
 * @license        http://help.dedecms.com/usersguide/license.html
 * @link           http://www.dedecms.com
 */

require_once(dirname(__FILE__)."/config.php");
require_once(DEDEINC.'/membermodel.cls.php');
if($cfg_mb_allowreg=='N')
{
    ShowMsg('系统关闭了新用户注册！', 'index.php');
    exit();
}

if(!isset($dopost)) $dopost = '';
$step = empty($step)? 0 : intval(preg_replace("/[^\d]/", '', $step));
$mid='0';//当前注册用户ID


//注册用户基本信息
if($step == 1 && $dopost == 'regbase')
{
    //检查当前用户名是否可用
    $rs = CheckUserID($userid, '用户名');
    if($rs != 'ok')
    {
        ShowMsg($rs, '-1');
        exit();
    }
    if(strlen($pid)<0)
    {
        ShowMsg('请您填写您的推荐人ID','-1');
    }
    if(strlen($userid) < $cfg_mb_idmin )
    {
        ShowMsg("您的用户名少于".$cfg_mb_idmin."位，不允许注册！","-1");
        exit();
    }
    elseif(strlen($pwd) < $cfg_mb_pwdmin)
    {
        ShowMsg("您的密码少于".$cfg_mb_pwdmin."位，不允许注册！","-1");
        exit();
    }
    //返回结果
   $result = array();
   $result['code'] =0;
   $result['msg'] ='提交成功';
   $row =array();
   $row['uid']=$userid;
   $row['pid']=$pid;
   $row['pwd']=md5(trim($pwd));
   $result['data'] =$row;
    echo json_encode($result);
} elseif($dopost == 'reginfo' && $step == '2')
{ 
    $result = array();
    $result['code'] =0;
    $result['msg'] ='提交成功';
    $row2 = array();
    $row2['bank']=$bank;
    $row2['card1url']=$card1url;
    $row2['card2url']=$card2url;
    $row2['card3url']=$card3url;
    $result['data'] =$row2;
    echo json_encode($result);
} elseif($dopost == 'reght' && $step == '3')
{
    $one = $_POST['one'];//基本信息
    $two = $_POST['two'];//个人信息
    $jointime = time();
    $joinip = GetIP();
    $mtype ='个人';
    //获取对应的值
    $uid =$one['uid'];
    $pwd =$one['pwd'];;
    $pid =$one['pid'];//用cardno存储推荐码
    $bank = $two['bank'];//开户行地址
    $sz =$two['card1url'];//身份证正面照
    $sf = $two['card2url'];//身份证反面照
    $bz = $two['card3url'];//银行卡照片
    $sql = "INSERT INTO `#@__member` (`mtype`, `userid`, `pwd`, `jointime`, `joinip`,  `cardno`, `pic1`, `pic2`, `pic3`, `bankaddr`) 
    VALUES ('$mtype','$uid','$pwd','$jointime','$joinip','$pid','$sz','$sf','$bz','$bank')";
    if($dsql->ExecuteNoneQuery($sql))
    {
        $result = array();
        $result['code'] =0;
        $result['msg'] ='恭喜您，成功注册成为会员！';
        echo json_encode($result,JSON_UNESCAPED_UNICODE);
    }
    else
    {
        $result = array();
        $result['code'] =0;
        $result['msg'] ='注册失败，请检查填写信息是否有误或与管理员联系！';
        echo json_encode($result,JSON_UNESCAPED_UNICODE);
    }
}
else
{
    require_once(DEDEMEMBER."/templets/reg.htm");
}


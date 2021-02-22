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
require_once(DEDEMEMBER.'/inc/inc_archives_functions.php');
header("Access-Control-Allow-Origin: *"); //解决跨域
header('Access-Control-Allow-Methods:post');// 响应类型
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
    $rs = CheckUserID($userid, '用户名');
    if($rs != 'ok')
    {
        ShowMsg($rs, '-1');
        exit();
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
    $jointime = time();//当前时间
    $joinip = GetIP();//当前登录IP
    $inQuery = "INSERT INTO `#@__member` (`mtype` ,`jointime` ,`joinip`) VALUES ('$mtype','$jointime','$joinip'); ";
    if($dsql->ExecuteNoneQuery($inQuery))
        $mid = $dsql->GetLastID();
    //加入到cookie中
    setcookie('mid',$mid,time()+1800);
    setcookie('uid',trim($userid),time()+1800);
    setcookie('pwd',md5(trim($pwd)),time()+1800);
    setcookie('pid',trim($pid),time()+1800);
    //转入下一步页面
    require_once(DEDEMEMBER."/templets/reg-new2.htm");
} elseif($dopost == 'reginfo' && $step == '2')
{
    setcookie('bank',$bank,time()+1800);
    require_once(DEDEMEMBER."/templets/reg-book.htm");
} elseif($dopost == 'reght' && $step == '3')
{
    //获取对应的值
    $mid = $_COOKIE['mid'];
    $uid =$_COOKIE['uid'];
    $pwd =$_COOKIE['pwd'];
    $pid =$_COOKIE['pid'];//用cardno存储推荐码
    $bank = $_COOKIE['bank'];//开户行地址
    $sz = $_COOKIE['card1url'];//身份证正面照
    $sf = $_COOKIE['card2url'];//身份证反面照
    $bz = $_COOKIE['card3url'];//银行卡照片
    $sql = "UPDATE `#@__member` SET `userid`='$uid',`pwd`='$pwd',`cardno`='$pid',`bankaddr`='$bank',`pic1`='$sz',`pic2`='$sf',`pic3`='$bz' WHERE mid='$mid'";
    if($dsql->ExecuteNoneQuery($sql))
    {
        //清除cookie值
        setcookie('mid','',time()-1800);
        setcookie('uid','',time()-1800);
        setcookie('pwd','',time()-1800);
        setcookie('pid','',time()-1800);
        setcookie('bank','',time()-1800);
        setcookie('card1url','',time()-1800);
        setcookie('card2url','',time()-1800);
        setcookie('card3url','',time()-1800);
        ShowMsg("恭喜您注册成功", 'login.php');
        exit;
    }
    else
    {
        ShowMsg("注册失败，请检查资料是否有误或与管理员联系！", "-1");
        exit();
    }
}
else
{
    require_once(DEDEMEMBER."/templets/reg-new.htm");
}

//上传照片
$img = !empty($_POST['img'])?$_POST['img']:'';
if(!empty($img))
{
     #/aip}}
     $utype = 'image';
     $mid = $_COOKIE['mid'];
     //$mid=10016;
     //身份正面照片
     $filename = MemberUploads('file','',$mid,$utype,'',-1,-1,true);
     SaveUploadInfo($mid,$filename,$mediatype);
    setcookie($img,$filename,time()+1800);
    $reseon = array('code'=>0,'msg'=>$filename);
    
    return json_encode($reseon);
}
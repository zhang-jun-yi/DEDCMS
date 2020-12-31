<?php
/**
 * @version        $Id: sm.php 1 8:38 2010年7月9日Z tianya $
 * @package        DedeCMS.Member
 * @copyright      Copyright (c) 2007 - 2010, DesDev, Inc.
 * @license        http://help.dedecms.com/usersguide/license.html
 * @link           http://www.dedecms.com
 */
require_once(dirname(__FILE__)."/config.php");
require_once(DEDEMEMBER.'/inc/inc_archives_functions.php');
//CheckRank(0,0);
$menutype = 'config';
if(!isset($dopost)) $dopost = '';
$row=$dsql->GetOne("SELECT  mid,userid,uname,rname,cardno,pic1,pic2,pic3,phone,bankno,bankaddr FROM `#@__member` WHERE mid='".$cfg_ml->M_ID."'");
if($dopost=='save')
{
    //检查数据   
    
    if(!is_array($row) || empty($rname))
    {
        ShowMsg('您输入的真实姓名为空，不能完成实名认证','-1');
        exit();
    }
   /*
    if(empty($cardno))
    {
        ShowMsg('您输入的身份证号为空','-1');
        exit();
    }
   */
    #api{{
    if(defined('UC_API') && @include_once DEDEROOT.'/uc_client/client.php')
    {
        $ucresult = uc_user_edit($cfg_ml->M_LoginID, $oldpwd, $userpwd, ’’);        
    }
    #/aip}}
    $utype = 'image';
    //身份正面照片
    $filename = MemberUploads('pic11','',$cfg_ml->M_ID,$utype,'',-1,-1,true);
    if(empty($filename)) {$filename = $pic1;}
    //身份反面照片
    $pic2name = MemberUploads('pic21','',$cfg_ml->M_ID,$utype,'',-1,-1,true);
    if(empty($pic2name)) {$pic2name = $pic2;}
    //银行卡正面照片
    $pic3name = MemberUploads('pic31','',$cfg_ml->M_ID,$utype,'',-1,-1,true);
    if(empty($pic3name)) {$pic3name = $pic3;}
    
    SaveUploadInfo($cfg_ml->M_LoginID,$filename,$mediatype);
    SaveUploadInfo($cfg_ml->M_LoginID,$filename,$mediatype);
    SaveUploadInfo($cfg_ml->M_LoginID,$filename,$mediatype);
    
    $query1 = "UPDATE `#@__member` SET rname='$rname',cardno='$cardno',pic1='$filename',pic2='$pic2name',pic3='$pic3name',phone='$phone',bankno='$bankno',bankaddr='$bankaddr' where mid='$cfg_ml->M_ID' ";
    $dsql->ExecuteNoneQuery($query1);
  
    // 清除会员缓存
    $cfg_ml->DelCache($cfg_ml->M_ID);
    ShowMsg('实名认证资料已提交成功','sm.php',0,5000);
    exit();
}
include(DEDEMEMBER."/templets/sm.htm");

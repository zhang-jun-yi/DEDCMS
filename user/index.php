<?php
/**
 * @version        $Id: index.php 1 8:24 2010年7月9日Z tianya $
 * @package        DedeCMS.Member
 * @copyright      Copyright (c) 2007 - 2010, DesDev, Inc.
 * @license        http://help.dedecms.com/usersguide/license.html
 * @link           http://www.dedecms.com
 */
require_once(dirname(__FILE__)."/config.php");
require_once("./inc/phpqrcode.php");

$uid=empty($uid)? "" : RemoveXSS($uid); 
if(empty($action)) $action = '';
if(empty($aid)) $aid = '';

$menutype = 'mydede';
if ( preg_match("#PHP (.*) Development Server#",$_SERVER['SERVER_SOFTWARE']) )
{
    if ( $_SERVER['REQUEST_URI'] == dirname($_SERVER['SCRIPT_NAME']) )
    {
        header('HTTP/1.1 301 Moved Permanently');
        header('Location:'.$_SERVER['REQUEST_URI'].'/');
    }
}
//会员后台
if($uid=='')
{
    $iscontrol = 'yes';
    //未登录
    if(!$cfg_ml->IsLogin())
    {
        include_once(dirname(__FILE__)."/templets/login.htm");
    }
    else//已登录
    {
        //获取当前用户信息
        $row=$dsql->GetOne("SELECT  m.*,p.userid as pname FROM `#@__member` as m left join `#@__member` p on p.mid = m.cardno
         WHERE m.mid='".$cfg_ml->M_ID."'");

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


        /** 欢迎新朋友 **/
        $sql = "SELECT * FROM `#@__member` ORDER BY mid DESC LIMIT 3";
        $newfriends = array();
        $dsql->SetQuery($sql);
        $dsql->Execute();
        while ($newrow = $dsql->GetArray()) {
            $newfriends[] = $newrow;
        }

        /** 好友记录 **/
        $sql = "SELECT F.*,M.face,M.sex FROM `#@__member` AS M LEFT JOIN #@__member_friends AS F ON F.fid=M.mid WHERE F.mid='{$cfg_ml->M_ID}' ORDER BY F.addtime desc LIMIT 6";
        $friends = array();
        $dsql->SetQuery($sql);
        $dsql->Execute();
        while ($newrow = $dsql->GetArray()) {
            $friends[] = $newrow;
        }
        
        /** 有没新短信 **/
        $pms = $dsql->GetOne("SELECT COUNT(*) AS nums FROM #@__member_pms WHERE toid='{$cfg_ml->M_ID}' AND `hasview`=0 AND folder = 'inbox'");    
        
        /** 查询会员状态 **/
        $moodmsg = $dsql->GetOne("SELECT * FROM #@__member_msg WHERE mid='{$cfg_ml->M_ID}' ORDER BY dtime desc");    

        /** 会员操作日志 **/
        $sql = "SELECT * From `#@__member_feed` where ischeck=1 order by fid desc limit 8";
        $feeds = array();
        $dsql->SetQuery($sql);
        $dsql->Execute();
        while ($newrow = $dsql->GetArray()) {
            $feeds[] = $newrow;
        }
        $dpl = new DedeTemplate();
        $tpl = dirname(__FILE__)."/templets/index.htm";
        $dpl->LoadTemplate($tpl);
        $dpl->display();
      
    }
}
else
{
    $dpl = new DedeTemplate();
    $tpl = dirname(__FILE__)."/templets/index.htm";
    $dpl->LoadTemplate($tpl);
    $dpl->display();
}
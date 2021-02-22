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
date_default_timezone_set('PRC');//获取当前时间
$a = $_POST['img'];
if(!empty($a))
{
     #/aip}}
     $utype = 'image';
     //身份正面照片
     $filename = MemberUploads('file','',46,$utype,'',-1,-1,true);
     SaveUploadInfo($mid,$filename,$mediatype);
    
 
     $abc = json_encode($respon);
    // return $abc;
    $a = '{"code":0,"msg":"","data":{"src":"http://cdn.layui.com/123.jpg"}}';
    //return json_encode($respon); 
    $reseon = array('code'=>0,'msg'=>'sdfsdfs');
    echo json_encode($reseon);
}

else{
    //注册用户基本信息
   /*
    $abc = array('mid'=>36,'name'=>'zhangsna','user'=>'sdfafsafs');
    setcookie("a[mid]",$abc['mid']);
    setcookie("b", serialize($abc));
    
    $reseon = array('code'=>0,'msg'=>'sdfsdfs');
    //echo json_encode($reseon);
    */
   // require_once(DEDEMEMBER."/templets/test.htm");
   require_once(DEDEMEMBER."/templets/reg-new2.htm");
    
}
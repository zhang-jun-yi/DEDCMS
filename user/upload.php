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

$img = !empty($_POST['img'])?$_POST['img']:'';
if(!empty($img))
{
    $utype = 'image';
    $mid=0;
    //身份正面照片
    $filename = MemberUploads('file','',$mid,$utype,'',-1,-1,true);
    SaveUploadInfo($mid,$filename,$mediatype);
    $result = array();
    $result['code'] =0;
    $result['msg'] ='上传成功';
    $result['data'] =array('src'=>$filename);
    echo json_encode($result, JSON_UNESCAPED_UNICODE);
}

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
//$filename = 'qrcode/abc.png';
//QRcode::png($url,$filename,QR_ECLEVEL_L,10,1,false);

/**
 * 测试信管家API接口
 */
function send_post($url, $postdata) {
$postquery = http_build_query($postdata);
$options = array(
'http' => array(
'method' => 'POST',
'header' => 'Content-type:application/x-www-form-urlencoded',
'content' => $postquery,
'timeout' => 15 * 60 // 超时时间（单位:s）
)
);
$context = stream_context_create($options);
$result = file_get_contents($url, false, $context);
return $result;
}

//使用方法

$post_data = array(
'requestid' => '23',
'sa' => 'wjadmin',
'sapass' => 'wj1928',
'account' => '0',
'password' => '123456',
'name' => '张三',
'group' => '交易组1',
'mainaccount' => '21'

);


function httpsPost($url,$postdata){  
    $ch = curl_init();  
    //$curl_header = array("content-type: application/x-www-form-urlencoded;charset=UTF-8");
    //curl_setopt($ch,CURLOPT_HTTPHEADER,$curl_header);
    curl_setopt($ch, CURLOPT_URL, $url);  
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);  
    // post数据  
    curl_setopt($ch, CURLOPT_POST, 1);  
    curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, FALSE); // https请求 不验证证书和hosts  
    curl_setopt($ch, CURLOPT_SSL_VERIFYHOST, false);  
    // post的变量  
    curl_setopt($ch, CURLOPT_POSTFIELDS, $postdata);  
    $out = curl_exec($ch);
    $res=mb_convert_encoding($out, 'UTF-8', 'UTF-8,GBK,GB2312,BIG5');//使用该函数对结果进行转码
    $output=json_decode(curl_exec($ch),true);  
    curl_close($ch);  
    return $output;  
}  



function httpPsot($url,$postdata){
    $ch = curl_init();  
    curl_setopt($ch, CURLOPT_URL, $url);  
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);  
    // post数据  
    curl_setopt($ch, CURLOPT_POST, 1);  
    // post的变量  
    curl_setopt($ch, CURLOPT_POSTFIELDS, $postdata);  
    $output=json_decode(curl_exec($ch),true);  
    curl_close($ch);  
    return $output;  
}


function httpsGet($url,$postdata){  
    $curl = curl_init();  
    curl_setopt($curl, CURLOPT_URL, $url.http_build_query($postdata));  
    curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);  
    curl_setopt($curl, CURLOPT_SSL_VERIFYPEER, false);// https请求不验证证书和hosts  
    curl_setopt($curl, CURLOPT_SSL_VERIFYHOST, false);  
    $res=json_decode(curl_exec($curl),true);  
    curl_close($curl);  
    return $res;  
}  


$posturl = "https://moni.byxgj.com:23134/createaccount";

$httpout = httpPsot($url,$post_data);
$httpsout = httpsPost($posturl,$post_data);
$httpsgetout = httpsGet($url,$post_data);
$sentout = send_post($posturl,$post_data);
print_r($httpout) ;
echo "</br>";
print_r($httpsout) ;
echo "</br>";
print_r($httpsgetout) ;
echo "</br>";
print_r($sentout) ;
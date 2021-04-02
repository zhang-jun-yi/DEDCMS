<?php
/**
 * @version        $Id: login.php 1 8:38 2010�?7�?9�?Z tianya $
 * @package        DedeCMS.Member
 * @copyright      Copyright (c) 2007 - 2010, DesDev, Inc.
 * @license        http://help.dedecms.com/usersguide/license.html
 * @link           http://www.dedecms.com
 */
require_once(dirname(__FILE__)."/config.php");
require_once("./inc/phpqrcode.php");
require_once("api.php");
//$url ="https://github.com/endroid/qr-code/blob/master/src/QrCode.php";
//$url='https://blog.csdn.net/xiaoming100001/article/details/81109617';
/**
* 参数:p1:二维码包�?的内�? p2:输出的文件名 p3:容错级别 p4:大小 p5:外边距margin p6:保存�?�?
* 在浏览器上直接生成一�?二维�?(内�?�为abc)
*/
//QRcode::png($url);
//$filename = 'qrcode/abc.png';
//QRcode::png($url,$filename,QR_ECLEVEL_L,10,1,false);


//使用方法
$url= "https://moni.byxgj.com:23134/createaccount?";
$post_data = array(
'requestid' => '23',
'sa' => 'sa07',
'sapass' => 'c33',
'account' => '0',
'password' => '123456',
'name' => '张三', 
'group' => '交易�?1',
'mainaccount' => '21'
);



//通过Get方法获取结果
function getHttps($url){

    $curl = curl_init(); // �?动一个CURL会话
    curl_setopt($curl, CURLOPT_URL, $url);
    curl_setopt($curl, CURLOPT_HEADER, 0);
    curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
	curl_setopt($curl, CURLOPT_SSL_VERIFYPEER, 0);// 对�?�证证书来源的�?��?
	curl_setopt($curl, CURLOPT_SSL_VERIFYHOST,  2);// 从证书中检�?SSL加密算法�?否存�?
	curl_setopt($curl, CURLOPT_USERAGENT, $_SERVER['HTTP_USER_AGENT']); // 模拟用户使用的浏览器
	curl_setopt($curl, CURLOPT_FOLLOWLOCATION, 1);// 使用�?动跳�?
	// curl_setopt($curl, CURLOPT_REFERER, $ref); // 手动设置referer
	curl_setopt($curl, CURLOPT_AUTOREFERER, 1); // �?动�?�置Referer
	curl_setopt($curl, CURLOPT_HTTPHEADER,array('Accept-Encoding: gzip, deflate','accept-charset：utf-8','content-type：application/xml'));//设置HTTP头字�?
 	curl_setopt($curl, CURLOPT_ENCODING, 'gzip,deflate');// 解释gzip内�??
	curl_setopt($curl, CURLOPT_TIMEOUT, 30); // 设置超时限制防�?��?�循�?
	curl_setopt($curl, CURLOPT_HEADER, 0);// 显示返回的Header区域内�??
	curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1); // 获取的信�?以文件流的形式返�?
	curl_setopt($curl,CURLOPT_CONNECTTIMEOUT,10);// 在发起连接前等待的时间，如果设置�?0，则无限等待
    $tmpInfo = curl_exec($curl);     //返回api的json对象
    //关闭URL请求
    curl_close($curl);
    $convert_out= mb_convert_encoding($tmpInfo, 'utf-8', 'GBK,GB2312,UTF-8,ASCII');//返回�?码后的结果，防�?�出现乱�?
	
	//$result = xmltoarray($convert_out);
    return $convert_out;
}


$xml = '<?xml version="1.0" encoding="GB2312" ?>
<root>
<Result>
<Error>
<Code>5</Code>
<Message>管理员没有创建子账号的权�?</Message>
</Error>
<RequestID>23</RequestID>
</Result>
</root>';

$xgj = new xinGuanjia();

$xml = $xgj->queryaccount('6600007');

var_dump($xml);


/*
echo $str= '测试账号';

//echo iconv("UTF-8","gbk//TRANSLIT",$str); //将字符串的编码从UTF-8�?到GB2312
echo '<br />';
$convert_out= mb_convert_encoding($str, 'GB2312', 'UTF-8');//返回�?码后的结果，防�?�出现乱�?
echo $convert_out;
echo '<br />';
$convert_out= mb_convert_encoding($convert_out, 'UTF-8', 'GB2312');//返回�?码后的结果，防�?�出现乱�?
echo $convert_out;
echo '<br />';
$convert_out= mb_convert_encoding($convert_out, 'UTF-8', 'GBK,GB2312,ASCII');//返回�?码后的结果，防�?�出现乱�?
echo $convert_out;*/


<?php
/**
 * @version        $Id: login.php 1 8:38 2010年7月9日Z tianya $
 * @package        DedeCMS.Member
 * @copyright      Copyright (c) 2007 - 2010, DesDev, Inc.
 * @license        http://help.dedecms.com/usersguide/license.html
 * @link           http://www.dedecms.com
 */

 class xinGuanjia 
 {
	 //API接口地址
	//$posturl = "https://moni.byxgj.com:23134/createaccount?";//测试环境
	protected   $apiurl = "https://8.133.160.245:13134/";//生产环境

	//开户的参数
	protected   $postdata = array(
	'requestid' => '23',
	'sa' => 'azhadmin',
	'sapass' => 'zh1245'
	);

	//通过Get方法获取结果
	public function createaccount($name,$pwd){
		
		$this->postdata['account']=0;
		$this->postdata['password']='123456';
		//$this->postdata['group']='';
		$this->postdata['mainaccount']='HX980660';
		//接口指定名称必须为gb2312编码
		$name= mb_convert_encoding($name, 'GB2312', 'UTF-8');
		$this->postdata['name']=$name;
		$this->postdata['password']= $pwd;

		$curl = curl_init(); // 启动一个CURL会话
		curl_setopt($curl, CURLOPT_URL, $this->apiurl."createaccount?".http_build_query($this->postdata));
		curl_setopt($curl, CURLOPT_HEADER, 0);
		curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
		curl_setopt($curl, CURLOPT_SSL_VERIFYPEER, 0);// 对认证证书来源的检查
		curl_setopt($curl, CURLOPT_SSL_VERIFYHOST,  2);// 从证书中检查SSL加密算法是否存在
		curl_setopt($curl, CURLOPT_USERAGENT, $_SERVER['HTTP_USER_AGENT']); // 模拟用户使用的浏览器
		curl_setopt($curl, CURLOPT_FOLLOWLOCATION, 1);// 使用自动跳转
		// curl_setopt($curl, CURLOPT_REFERER, $ref); // 手动设置referer
		curl_setopt($curl, CURLOPT_AUTOREFERER, 1); // 自动设置Referer
		curl_setopt($curl, CURLOPT_HTTPHEADER,array('Accept-Encoding: gzip, deflate','accept-charset：utf-8','content-type：application/xml'));//设置HTTP头字段
		curl_setopt($curl, CURLOPT_ENCODING, 'gzip,deflate');// 解释gzip内容
		curl_setopt($curl, CURLOPT_TIMEOUT, 30); // 设置超时限制防止死循环
		curl_setopt($curl, CURLOPT_HEADER, 0);// 显示返回的Header区域内容
		curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1); // 获取的信息以文件流的形式返回
		curl_setopt($curl,CURLOPT_CONNECTTIMEOUT,10);// 在发起连接前等待的时间，如果设置为0，则无限等待
		$tmpInfo = curl_exec($curl);     //返回api的json对象
		//关闭URL请求
		curl_close($curl);
		$convert_out= mb_convert_encoding($tmpInfo, 'utf-8', 'GBK,GB2312,UTF-8,ASCII');//返回转码后的结果，防止出现乱码
		$result = str_replace("GB2312","utf-8",$convert_out);//将xml结果中的GB2312替换成utf-8，这样可以转成数组时不会出错
		$result =simplexml_load_string($result); //xml转object
		$result= json_encode($result);  //objecct转json
		$result=json_decode($result,true); //json转array;
				
		return $result;
	}

	//查询账户资金
	public function queryaccount($account){
		
		$this->postdata['account']=$account;

		$curl = curl_init(); // 启动一个CURL会话
		curl_setopt($curl, CURLOPT_URL, $this->apiurl."queryaccount?".http_build_query($this->postdata));
		curl_setopt($curl, CURLOPT_HEADER, 0);
		curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
		curl_setopt($curl, CURLOPT_SSL_VERIFYPEER, 0);// 对认证证书来源的检查
		curl_setopt($curl, CURLOPT_SSL_VERIFYHOST,  2);// 从证书中检查SSL加密算法是否存在
		curl_setopt($curl, CURLOPT_USERAGENT, $_SERVER['HTTP_USER_AGENT']); // 模拟用户使用的浏览器
		curl_setopt($curl, CURLOPT_FOLLOWLOCATION, 1);// 使用自动跳转
		// curl_setopt($curl, CURLOPT_REFERER, $ref); // 手动设置referer
		curl_setopt($curl, CURLOPT_AUTOREFERER, 1); // 自动设置Referer
		curl_setopt($curl, CURLOPT_HTTPHEADER,array('Accept-Encoding: gzip, deflate','accept-charset：utf-8','content-type：application/xml'));//设置HTTP头字段
		curl_setopt($curl, CURLOPT_ENCODING, 'gzip,deflate');// 解释gzip内容
		curl_setopt($curl, CURLOPT_TIMEOUT, 30); // 设置超时限制防止死循环
		curl_setopt($curl, CURLOPT_HEADER, 0);// 显示返回的Header区域内容
		curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1); // 获取的信息以文件流的形式返回
		curl_setopt($curl,CURLOPT_CONNECTTIMEOUT,10);// 在发起连接前等待的时间，如果设置为0，则无限等待
		$tmpInfo = curl_exec($curl);     //返回api的json对象
		//关闭URL请求
		curl_close($curl);
		$convert_out= mb_convert_encoding($tmpInfo, 'utf-8', 'GBK,GB2312,UTF-8,ASCII');//返回转码后的结果，防止出现乱码
		$result = str_replace("GB2312","utf-8",$convert_out);//将xml结果中的GB2312替换成utf-8，这样可以转成数组时不会出错
		$result =simplexml_load_string($result); //xml转object
		$result= json_encode($result);  //objecct转json
		$result=json_decode($result,true); //json转array;	
		return $result;
	}

 }
 









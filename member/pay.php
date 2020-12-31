<?php
$a1=$_POST['a1'];     //用户名
$cny=$_POST['cny'];  //充值金额
$a3=$_POST['a3'];   //充值方式

$pay1="meike203@qq.com";//支付宝收款账号
$pay2="970003436";//财付通收款账号

//-------------支付宝跳转开始
if($a3==1){
?>
<html>
<head>
<meta charset="utf-8">
<title>正在跳转到支付页面...</title>
</head>
<body>
<form id="alipaysubmit" name="alipaysubmit" action="zfb.php" method="POST">
  <input type="hidden" name="optEmail" value="<?php echo $pay1;?>"/>
  <input type="hidden" name="payAmount" value="<?php echo $cny;?>"/>
  <input type="hidden" name="title" value="<?php echo $a1;?>"/>
  <input type="hidden" name="memo" value="请不要修改付款说明里的内容,否则将无法自动完成订购"/>
  <!--<input type="hidden" value="submit" value="正在为您跳转到支付宝付款页面,如未自动转接请点击...">-->
  <input type="hidden" value="submit" value="sending...click here...">
</form>
<script type="text/javascript">
   document.forms['alipaysubmit'].submit();
</script>
</body>
</html>
<?php
}
//-------------支付宝结束
//-------------微信跳转开始
if($a3==2){
?>
<html>
<head>
<meta charset="gb2312">
<title>正在跳转到支付页面...</title>
</head>
<body>
<form id="alipaysubmit" name="alipaysubmit" action="wx.php" method="POST">
  <input type="hidden" name="optEmail" value="<?php echo $pay1;?>"/>
  <input type="hidden" name="payAmount" value="<?php echo $cny;?>"/>
  <input type="hidden" name="title" value="<?php echo $a1;?>"/>
  <input type="hidden" name="memo" value="请不要修改付款说明里的内容,否则将无法自动完成订购"/>
  <!--<input type="hidden" value="submit" value="正在为您跳转到支付宝付款页面,如未自动转接请点击...">-->
  <input type="hidden" value="submit" value="sending...click here...">
</form>
<script type="text/javascript">
   document.forms['alipaysubmit'].submit();
</script>
</body>
</html>
<?php
}
//-------------微信结束

//-------------财付通跳转开始
if($a3==3){
$md5=md5($pay2."&".$cny."&".$a1); //重组数据后使用MD5加密，然后跳转财付通付款。
?>
<html>
<head>
<meta charset="gb2312">
<title>正在跳转到财付通支付页面...</title>
</head>
<body>
<form id="alipaysubmit" action="https://www.tenpay.com/v2/account/pay/paymore_cft.shtml?data=<?php echo $pay2;?>%26<?php echo $cny;?>%26<?php echo $a1;?>&validate=<?php echo $md5;?>" method="post">
<!--<input type="hidden" value="submit" value="正在为您跳转到财付通付款页面,如未自动转接请点击...">-->
<input type="hidden" value="submit" value="sending...click here...">
</form>
<script type="text/javascript">
   document.forms['alipaysubmit'].submit();
</script>
</body>
</html>
<?php
}
?>
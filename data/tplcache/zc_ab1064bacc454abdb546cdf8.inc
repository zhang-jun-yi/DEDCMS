<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!--当前页面是如今通道页面-->
<!DOCTYPE html>
<html lang="zh-CN">

<head>
    <meta charset="utf-8">
    <title>入金通道-会员中心-
        <?php echo $cfg_webname; ?>
    </title>
    <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1" />
    <link rel="stylesheet" href="templets/siy/css/animate.css" type="text/css" />
    <link rel="stylesheet" href="templets/siy/css/font-awesome.min.css" type="text/css" />
    <link rel="stylesheet" href="templets/siy/css/bootstrap.css" type="text/css" />
    <!-- Custom CSS -->
    <link href="templets/siy/css/angulr-admin.css" rel="stylesheet">
    <link rel="stylesheet" href="templets/siy/css/font.css" type="text/css" />
    <link rel="stylesheet" href="templets/siy/css/app.css" type="text/css" />
    <script src="templets/siy/js/jquery.js"></script>
    <script src="templets/siy/js/zbp_add.js"></script>
    <!-- ZCenter js-->
    <!-- zbp system -->
    <script src="templets/siy/js/zblogphp.js" type="text/javascript"></script>
    <script src="templets/siy/js/c_admin_js_add.js" type="text/javascript"></script>
    <!--
    <script src="templets/siy/js/jquery-ui.custom.min.js" type="text/javascript"></script>
    <link rel="stylesheet" type="text/css" href="templets/siy/css/jquery-ui.custom.css"/>
-->
    <script src="templets/siy/js/functions.js"></script>

    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->
    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
    <!--[if lt IE 9]>
        <script src="templets/siy/js/html5shiv.js"></script>
        <script src="templets/siy/js/respond.min.js"></script>
    <![endif]-->

</head>

<body>
    <div class="app app-header-fixed ">
        <?php include(DEDEMEMBER."/templets/head2.htm"); ?>
        <!-- index_menu -->
        <?php include(DEDEMEMBER."/templets/index_menu.htm"); ?>
        <!-- content -->
        <div id="content" class="app-content" role="main">
            <div class="app-content-body ">
                <h1 class="m-n font-thin h3">入金通道</h1>
                <div class="bg-light lter b-b wrapper-md">
                    <div style="float: left; width: 45%; margin-top: 30px;">
                        <form action="zc.php" method="post" >
                            <input type="hidden" name="dopost" value="save" />
                            <div class="input-group">
                          <span class="input-group-addon">充值账号</span>
                          <input type="text" class="form-control" name="payno" placeholder="填写注册时的账号或者备注">
                        </div><br>
                        <div class="input-group">
                          <span class="input-group-addon"  >充值金额</span>
                          <input type="text" class="form-control" name="cny" placeholder="填写转账金额，如100">
                        </div>
                            <br>
                           <li class="product">
                                                <span >支付方式</span>
                                                <span >
                                                    <input type="radio" checked="checked" name="pstyle" value="支付宝" />支付宝<label for="a2"></label>
                                                    <input type="radio" name="pstyle" value="微信支付" /><label for="a2">微信支付</label>
                                                    <input type="radio" name="pstyle" value="银行转账" class="dxk" /><label for="a2">银行转账</label>
                                                    
                                               </span>
                              </li><br>
                              <button type="submit" class="btn btn-primary" style="width:100%;float:left;">提交</button>
                          <br>
                        </form>
                    </div>
                   <!--<div style="float: right; width: 50%;">
                        <p aria-flowto="center">扫码转账</p>
                    </br>
                    <h4>支持微信、支付宝扫码支付，支付时请备注用户详细信息
                    </h4>
                    <img src="../user/images/taimi.jpg" width="300px" height="300px">
                        <p aria-flowto="center">网银转帐</p>
                        </br>
                        <p>
                            网银转帐（香港本地账户需要预先登记正大国际金融控股有限公司的银行账号后进行对外转帐）</br>
                            使用登记电邮发送 info@zhengda.com.hk（客户账号、姓名、日期、金额、银行名称及银行账号，银行存款单/电汇收据/网上汇款截图）;</br>
                            期货交易账户截止 记账时间为香港时间下午5时，逾时将顺延至下一个工作天处理;
                        </p>
                        <h3>入金账户信息 </h3>
                        <h5 style="font-style: oblique;">華僑永亨銀行 (OCBC Wing Hang Bank Limited)</h5>
                        <ul>
                            <li>
                                銀行賬戶名稱 : Zheng Da International Financial Holding Ltd - Client Account
                            </li>
                            <li>
                                收款賬戶(美金): 035-854-156347-002
                            </li>
                            <li>
                                收款賬戶(港幣): 035-854-155984-001
                            </li>
                            <li>
                                收款銀行地址: Unit 01, 22/F, Crocodile Center, Kwun Tong, Kowloon, Hong Kong
                            </li>
                            <li>
                                SWIFT Code: WIHBHKHH
                            </li>
                        </ul>
                        <h5 style="font-style: oblique;">中國建設銀行(亞洲) (China Construction Bank (asia) Corporation Limited)</h5>
                        <ul>
                            <li>
                                銀行賬戶名稱 : Zheng Da International Financial Holding Ltd - Client Account
                            </li>
                            <li>
                                收款賬戶(美金): 009-846210037221
                            </li>
                            <li>
                                收款賬戶(港幣): 009-846210037213
                            </li>
                            <li>
                                收款銀行地址: 26/F, CCB Centre, 18 Wang Chiu Road, Kowloon Bay, Kowloon, Hong Kong
                            </li>
                            <li>
                                SWIFT Code: CCBQHKAX
                            </li>
                        </ul>
                    </div>--> 


                </div>
            </div>
            <!-- /content -->
            <script type="text/javascript">
                ZCenter_ActiveLeftMenu("aDashboard");
            </script>
            <?php include(DEDEMEMBER."/templets/foot.htm"); ?>
        </div>
    </div>
        <script src="templets/siy/js/bootstrap.js"></script>
        <script src="templets/siy/js/ui-load.js"></script>
        <script src="templets/siy/js/ui-jp.config.js"></script>
        <script src="templets/siy/js/ui-jp.js"></script>
        <script src="templets/siy/js/ui-nav.js"></script>
        <script src="templets/siy/js/ui-toggle.js"></script>
        <script src="templets/siy/js/ui-client.js"></script>
</body>

</html>
<!--68.29 ms , 16 query , 9211kb memory , 0 error-->
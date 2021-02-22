<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!--当前页面是入金通道页面-->
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
      <!--LayuiMini CSS-->
      <link rel="stylesheet" href="templets/lib/layui-v2.5.5/css/layui.css" media="all">
      <link rel="stylesheet" href="templets/lib/font-awesome-4.7.0/css/font-awesome.min.css" media="all">
      <link rel="stylesheet" href="templets/css/layuimini.css?v=2.0.1" media="all">
      <link rel="stylesheet" href="templets/css/themes/default.css" media="all">
      <link rel="stylesheet" href="templets/css/public.css" media="all">
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
            <div class="layui-body" >
                <div class="layui-card layuimini-page-header">
                    <div class="layui-breadcrumb layuimini-page-title">
                        <a lay-href="" href="/">会员中心</a><span lay-separator="">/</span>
                        <a><cite>入金管理</cite></a><span lay-separator="">/</span>
                        <a><cite>入金通道</cite></a>
                    </div>
                </div>
                <div class="layuimini-container layuimini-page-anim">
                    <div class="layuimini-main">
                
                        <blockquote class="layui-elem-quote layui-text">
                            填写入金金额和方式后，可根据右边提供的付款方式转账。
                        </blockquote>
                        <div class="layui-row">
                            <div class="layui-col-xs12 layui-col-md6">
                              <div class="grid-demo grid-demo-bg1">
                                <form class="layui-form" action="zc.php" method="POST">
                                    <input type="hidden" name="dopost" value="save" />
                                    <div class="layui-form-item">
                                        <label class="layui-form-label" style="padding: 9px 5px;">入金账号</label>
                                        <div class="layui-input-block" style="max-width: 300px;">
                                            <input type="input" name="payno" required  lay-verify="required" autocomplete="off" placeholder="请输入入金账号" class="layui-input">
                                        </div>
                                    </div>
                
                                    <div class="layui-form-item">
                                        <label class="layui-form-label" style="padding: 9px 5px;">金额</label>
                                        <div class="layui-input-block" style="max-width: 300px;">
                                            <input type="input" name="cny" lay-verify="required|number" autocomplete="off" placeholder="请输入入金金额" class="layui-input">
                                        </div>
                                    </div>
                                  
                                    <div class="layui-form-item">
                                        <label class="layui-form-label"style="padding: 9px 5px;" >支付方式</label>
                                        <div class="layui-input-block" style="max-width: 500px;">
                                            <input type="radio" name="pstyle" value="0" title="微信支付" checked="">
                                            <input type="radio" name="pstyle" value="1" title="支付宝">
                                            <input type="radio" name="pstyle" value="2" title="银行转账" >
                                        </div>
                                    </div>
                                    <div class="layui-form-item">
                                        <div class="layui-input-block">
                                            <button class="layui-btn" lay-submit="" lay-filter="zcsubmit">立即提交</button>
                                            <button type="reset" class="layui-btn layui-btn-primary">重置</button>
                                        </div>
                                    </div>
                                </form>
                              </div>
                            </div>
                            <div class="layui-col-xs6 layui-col-md6">
                                <fieldset class="layui-elem-field layui-field-title" style="border-color: #1E9FFF;">
                                    <legend>线下支付银行卡: <span style="color: red;" >中国农业银行</span> </legend>
                                  </fieldset>
                                  <blockquote class="layui-elem-quote layui-quote-nm">
                                    卡号: &nbsp;&nbsp; 622841  0754 5206 78670 </br>
                                    姓名: &nbsp;&nbsp; 张阳</br>
                                    备注：&nbsp;&nbsp; 为保证客户资金安全线下入金单笔最高5万</br></br>
                                   <b style="color: red;">温馨提醒</b><br>
                                   <p style="color:red;font-size:x-small">
                                        1、在线充值收取千分之二的手续费。在线自动入金时间：交易日8：00--22：00，充值再提交后十分钟到账；<br>
                                        2、线下扫码充值和银行转账入金时间：周一至周五8:00-22:00（交易日），转账再提交后十分钟内到账；<br>
                                        3、出金单笔5元手续费。出金单笔最大限额5万元最小限额5元；<br>
                                        4、账户姓名及身份证必须与银行卡一致且不能有误，确保出金安全到帐；<br>
                                        5、出金时间：周一至周五9:00-17:00，出金直接扣除余额半小时内到账（遇节假日顺延）。 出入金汇率7.95
                                    </p>
                                    </blockquote>
                
                                <fieldset class="layui-elem-field layui-field-title" style="margin-top: 10px;border-color: #1E9FFF;">
                                    <legend>扫码转账</legend>
                                  </fieldset>
                                  <img src="../user/images/alipay.png" width="200px" height="200px">
                              </div>
                            </div>
                        </div>
                
                       
                </div>
            </div>
        </div>
    </div>
        <script src="templets/lib/layui-v2.5.5/layui.js" charset="utf-8"></script>
        <script>
            layui.use(['form', 'layedit', 'laydate'], function () {
                var form = layui.form
                    , layer = layui.layer
                    , layedit = layui.layedit
                    , laydate = layui.laydate;
        
                /**
                 * 初始化表单，要加上，不然刷新部分组件可能会不加载
                 */
                form.render();
                /*
                    * 监听提交
                form.on('submit(zcsubmit)', function (data) {
                    $.ajax({
                            type:"POST",
                            url:"zc.php",
                            async:false,
                            data:data.field,
                            dataType:"JSON",
                            success:function (data) {
                                layer.msg(data.msg);
                            },
                            error:function(){
                                layer.msg('入金失败，请重新提交！');
                            }
                        });
                    return false;
                });*/
            });
        </script>
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
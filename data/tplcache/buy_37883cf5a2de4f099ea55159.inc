<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE html>
<html lang="zh-CN" >
<head>
    <meta charset="utf-8">
    <title>金币充值-会员中心-<?php echo $cfg_webname; ?></title>
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
<div class="bg-light lter b-b wrapper-md">
  <h1 class="m-n font-thin h3">金币充值</h1>
			<p></p>
<small class="text-muted">您当前拥有金币 &nbsp;<?php echo $cfg_ml->M_Money; ?>&nbsp;个<small>
</div>
<div class="wrapper-md">
                <div class="row">
                    <div class="col-lg-12">
                        <div class="table-responsive">						
				 <form name="f1" action="buy_action.php" method="post">
		<input type="hidden" name="product" value="card" />
		<table  class="table table-bordered table-hover table-striped table_striped table_hover" width="100%" border="0" cellpadding="0" cellspacing="0" class="list">
			<tr style='height:28px;background:#F9FEE9;'>
				<th style="text-align: center;" width="10%">选择</th>
				<th style="text-align: center;">点卡类型</th>
				<th style="text-align: center;" width="15%">金币数量</th>
				<th style="text-align: center;" width="15%">购买价格</th>
			</tr>
			<tbody>
                <?php echo $moneycards;?>
			</tbody>
		</table>
		<div class="orderitem-status">
		<button class="btn btn-primary" type="submit">购买</button>
		</div>
	  </form>		
				 </div>
                </div>
                <!-- /.row -->
                <div class="row">
                    <div class="col-lg-12">
                                            </div>
                </div>
				</div>
	</div>
  </div> 
  <!-- /content -->
<script type="text/javascript">ZCenter_ActiveLeftMenu("aDashboard");</script>
 <?php include(DEDEMEMBER."/templets/foot.htm"); ?>
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
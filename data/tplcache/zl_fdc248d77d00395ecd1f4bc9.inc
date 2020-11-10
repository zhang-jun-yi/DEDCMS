<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE html>
<html lang="zh-CN">

<head>
    <meta charset="utf-8">
    <title>更改帐号基本资料 - 会员中心-
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
                <div class="bg-light lter b-b wrapper-md">
                    <h1 class="m-n font-thin h3">
                        <?php echo $cfg_ml->M_LoginID ?>的基本资料
                    </h1>
                    <p></p>
                    <form action="zl.php" method="post" enctype="multipart/form-data" name="form2" onsubmit="return checkSubmit();">
                        <input type="hidden" name="dopost" value="save" />
                </div>

                <table class="table table-bordered table-hover table-striped table_striped table_hover">
                    <thead>
                        <tr align="center" style="background-color: #F6FCFE">
                            <th class="td5"><span class="hei">用户名</span></th>
                            <th class="td15"><input name="userid" type="text" disabled="disabled" style="background-color: #F0F3F4;" id="userid" value="<?php echo $row['userid']; ?>" class="form-control" /></th>
                             <th></th>
                        </tr>
                        <tr align="center" style="background-color: #F6FCFE">
                            <th class="td5"><span class="hei">推荐人</span></th>
                            <th class="td15"><input name="uname" type="text"  id="uname" disabled="disabled"  value="<?php echo $row['uname']; ?>" class="form-control" /></th>
                             <th></th>
                        </tr>
                        <tr align="center" style="background-color: #F6FCFE">
                            <th class="td5"><span class="hei">邮箱</span></th>
                            <th class="td15"><input name="email"" type="text" dstyle="background-color: #F0F3F4;" id="email" value="<?php echo $row['email']; ?>" class="form-control" /></th>
                             <th></th>
                        </tr>
                        <tr align="center" style="background-color: #FAFBFC;">
                            <th class="td5"><span class="hei">原登陆密码</span></th>
                            <th class="td15"><strong><input name="oldpwd" type="password" id="oldpwd" class="form-control"  /></strong></th>
                            <th></th>
                        </tr>

                        <tr align="center" style="background-color: #F6FCFE;">
                            <th class="td5"><span class="hei">新密码</span></th>
                            <th class="td15"><strong><input name="userpwd" type="password" id="userpwd" class="form-control"  /></strong></th>
                            <th></th>
                        </tr>

                        <tr align="center" style="background-color: #FAFBFC;">
                            <th class="td5"><span class="hei">确认新密码</span></th>
                            <th class="td15"><strong><input name="userpwdok" type="password" id="userpwdok" class="form-control"  /></strong></th>
                            <th></th>
                        </tr>


                        <tr align="center" style="background-color: #FAFBFC;">
                            <th class="td5"><span class="hei">性别</span></th>
                            <th class="td15">
                                <input type="radio" name="sex" value="男" <?php if($row[ 'sex']=='男' ) echo " checked='checked' "; ?>/> 男 &nbsp;
                                <input type="radio" name="sex" value="女" <?php if($row[ 'sex']=='女' ) echo " checked='checked' "; ?>/> 女 &nbsp;
                                <input type="radio" name="sex" value="保密'" <?php if($row[ 'sex']=='保密' ) echo " checked='checked' "; ?>/> 保密
                            </th>
                            <th class="td15"></th>
                        </tr>

                        <tr align="center" style="background-color: #F6FCFE;">
                            <th class="td5"><span class="hei">验证码</span></th>
                            <th class="td15"><strong> <input name="vdcode" type="text" id="vdcode" style='width:120px;text-transform:uppercase;' class="form-control"/> </strong></th>
                            <th class="td15"> <img src="../include/vdimgck.php" align="absmiddle" alt="看不清？点击更换" style="cursor:pointer" onclick="this.src=this.src+'?'" /> <span>看不清？点击更换验证码</span> </th>
                        </tr>

                        <tr align="center" style="background-color: #F6FCFE;">
                            <th></th>
                             <th class="td15" style="float:center"> <input type="submit" value="确认修改" class="btn btn-primary"></th>
                            <th></th>
                           
                        </tr>
                        </tbody>
                </table>
                </form>
            </div>
        </div>
        <!-- /content -->
        <script type="text/javascript">
            ZCenter_ActiveLeftMenu("aDashboard");
        </script>
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
<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!DOCTYPE html>
<html lang="zh-CN" >
<head>
    <meta charset="utf-8">
    <title>出金明细-会员中心-<?php echo $cfg_webname; ?></title>
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
    <script src="templets/siy/js/zblogphp.js" type="text/javascript"></script>
    <script src="templets/siy/js/c_admin_js_add.js" type="text/javascript"></script>
    <script src="templets/siy/js/functions.js"></script>
    
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
        <a><cite>出金管理</cite></a><span lay-separator="">/</span>
        <a><cite>出金明细</cite></a>
    </div>
</div>
    <div class="layuimini-content-page">
        <div class="layuimini-container layuimini-page-anim">
            <div class="layuimini-main">
                    <div>
                        <form class="layui-form layui-form-pane" action="zc_list.php" method="POST">
                            <input type="hidden" name="dopost" value="search" />
                            <div class="layui-form-item">
                                <div class="layui-inline">
                                    <label class="layui-form-label">关键词</label>
                                    <div class="layui-input-block">
                                        <input type="text" class="form-control" name="keyword" placeholder="请输入要查询的出金账号" value="<?php echo $row['key']; ?>" >
                                    </div>
                                </div>
                                <div class="layui-inline" style="padding-top: 5px;">
                                    <label class="layui-form-label">支付方式</label>
                                    <div class="layui-input-block">
                                        <select name="pstyle" lay-filter="pstyle">
                                            <option value="-1"  selected=''>请选择</option>
                                            <option value="0" >微信支付</option>
                                            <option value="1" >支付宝</option>
                                            <option value="2">银行转账</option>
                                        </select>
                                    </div>
                                </div>
                                <div class="layui-inline" style="padding-top: 5px;">
                                    <label class="layui-form-label">状态</label>
                                    <div class="layui-input-block">
                                        <select name="state" lay-filter="state">
                                            <option value="-1" selected="">所有</option>
                                            <option value="0" >待审核</option>
                                            <option value="1" >已通过</option>
                                        </select>
                                    </div>
                                </div>
                                <div class="layui-inline">
                                    <button type="submit" class="layui-btn layui-btn-normal"  lay-submit lay-filter="data-search-btn"><i class="layui-icon"></i> 搜 索</button>
                                </div>
                            </div>
                        </form>
                    </div>
                <!--数据呈现在表格中-->
                <table class="layui-table"  lay-filter="zclist">
                    <thead>
                      <tr>
                        <th>ID</th>
                        <th>出金账户</th>
                        <th>金额</th>
                        <th>出金方式</th>
                        <th>状态</th>
                        <th>时间</th>
                      </tr>
                    </thead>
                    <?php
$atts = array();
$atts['tagname'] = 'datalist';
$blockValue = $this->refObj->GetArcList($atts,$this->refObj,$fields); 
if(is_array($blockValue)){
foreach( $blockValue as $key=>$fields )
{
?>
                    <tr style="text-align: center;"> 
                        <th class="td5"><?php echo $fields['id']; ?></th>
                        <th class="td5"><?php echo $fields['payno']; ?></th>
                        <th class="td15"><?php echo $fields['cny']; ?></th>
                        <th class="td15"><?php 
                            $pstyle = $fields['pstyle']; 
                            if($pstyle == 0)
                                echo '微信支付';
                            elseif($pstyle == 1)
                                echo '支付宝';
                            elseif($pstyle == 2)
                                echo '银行转账';
                            ?></th>
                        <th class="td15"><?php echo $fields['state']==0?'待审核':'已通过'; ?></th>
                        <th class="td15"><?php echo $fields['ctime']; ?></th>
                        </tr>
                    <?php
}
}?>
        
                  </table>
                    <div class="dede_pages">
                    <ul class="pagelist">
                    <?php
$atts = array();
$atts['tagname'] = 'pagelist';
$atts['listitem'] = 'info,index,pre,pageno,next,end,option';
$atts['listsize'] = '2';
$atts['pagesize'] = '10';
 echo $this->refObj->GetPageList($atts,$this->refObj,$fields); 
?>

                    </ul>
                    </div><!-- /pages -->
            </div>
        </div>
    </div>
</div>
</div>
<script src="/user/templets/lib/layui-v2.5.5/layui.js" charset="utf-8"></script>
<script>
layui.use(['form', 'table','miniPage','miniAdmin','element'], function () {
    var $ = layui.jquery,
        form = layui.form,
        table = layui.table,
        miniPage = layui.miniPage,
        miniAdmin = layui.miniAdmin;
    table.render({
        elem: '#zclist',
        skin: 'line'
    });
});
</script>
</div>

  </div>
  <!-- /content -->
<script type="text/javascript">ZCenter_ActiveLeftMenu("aDashboard");</script>
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
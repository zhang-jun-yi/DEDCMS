<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?><!--
 * @Author: your name
 * @Date: 2020-09-20 00:16:43
 * @LastEditTime: 2020-09-21 11:25:52
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /zhengda/member/templets/index.htm
 这是自定义会员中心页面
-->
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1">
  <title> 正大证券- 会员中心</title>
  <link rel="stylesheet" href="templets/layui/css/layui.css">
  <script src="templets/layui/layui.all.js" charset="utf-8"></script>
  <script src="templets/layui/lay/form.js" charset="utf-8"></script>
  <script src="templets/layui/lay/layer.js" charset="utf-8"></script>
</head>
<body class="layui-layout-body">

  
<div class="layui-layout layui-layout-admin">
  <div class="layui-header">
    <div class="layui-logo">会员中心</div>
    <!-- 头部区域（可配合layui已有的水平导航） -->
    <ul class="layui-nav layui-layout-left">
      <li class="layui-nav-item"><a href="../../../index.htm">网站首页</a></li>
    </ul>
    <ul class="layui-nav layui-layout-right">
      <li class="layui-nav-item">
        <a href="javascript:;">
          <img src="http://t.cn/RCzsdCq" class="layui-nav-img">
          <?php echo $cfg_ml->M_UserName?>
        </a>
        <dl class="layui-nav-child">
          <dd><a href="../member/templates/index.htm">基本资料</a></dd>
          <dd><a href="">实名</a></dd>
        </dl>
      </li>
      <li class="layui-nav-item"><a href="../member/index_do.php?fmdo=login&dopost=exit#">退出</a></li>
    </ul>
  </div>
  
  <div class="layui-side layui-bg-black">
    <div class="layui-side-scroll">
      <!-- 左侧导航区域（可配合layui已有的垂直导航） -->
      <ul class="layui-nav layui-nav-tree"  lay-filter="user">
        <li class="layui-nav-item layui-nav-itemed">
          <a class="" href="javascript:;">基本资料</a>
          <dl class="layui-nav-child">
            <dd><a href="javascript:;">个人信息</a></dd>
            <dd><a href="javascript:;">实名认证</a></dd>
          </dl>
        </li>
        <li class="layui-nav-item">
          <a href="javascript:;">出入金管理</a>
          <dl class="layui-nav-child">
            <dd><a href="javascript:;">入金</a></dd>
          </dl>
        </li>
      </ul>
    </div>
  </div>
  
  <div class="layui-body" style="margin-left: 50px;">
    <!-- 内容主体区域 -->
      <div class="layui-tab layui-tab-brief" lay-filter="user">
        <ul class="layui-tab-title" id="LAY_mine">
          <li class="layui-this" lay-id="info">我的资料</li>
          <li lay-id="pass">修改密码</li>
          <li lay-id="shiming">实名认证</li>
        </ul>
        <!--我的资料-->
        <div class="layui-tab-content" style="padding: 20px 0;">
                  <div class="layui-tab-item layui-show"">
                    <div class="layui-card-body">
                      用户名：<?php echo $cfg_ml->M_LoginID; ?> </br>
                      <?php echo $cfg_ml ->M_ID; ?> </br>
                      <?php print_r($minfos); ?> </br>
                  </div>
          </div>

          <!--修改密码-->
          <div class="layui-form layui-form-pane layui-tab-item" lay-filter="user">
          <form class="layui-form" action="edit_baseinfo.php" method="post" name="pwdform">
            <input type="hidden" name="dopost" value="save" />
            
            <div class="layui-form-item layui-this"> <label for="L_nowpass" class="layui-form-label" >当前密码</label>
              <div class="layui-input-inline"> <input type="password" id="L_nowpass" name="oldpwd" required=""
                  lay-verify="required" autocomplete="off" class="layui-input" lay-reqtext="当前密码是必填项，岂能为空？" placeholder="请输入当前密码"> </div>
            </div>
            <div class="layui-form-item"> <label for="L_pass" class="layui-form-label">新密码</label>
              <div class="layui-input-inline"> <input type="password" id="L_pass" name="userpwd" required=""
                  lay-verify="required" autocomplete="off" class="layui-input" lay-reqtext="新密码是必填项，岂能为空？" placeholder="请输入新密码"> </div> 
             
            </div>
            <div class="layui-form-item"> <label for="L_repass" class="layui-form-label">确认密码</label>
              <div class="layui-input-inline"> <input type="password" id="L_repass" name=“userpwdok” placeholder="请再次输入新密码" required="" ay-verify="required" autocomplete="off" class="layui-input" lay-reqtext="确认密码是必填项，岂能为空？" > </div>
            </div>
            <div class="layui-form-item"> <button class="layui-btn" key="set-mine" 
                lay-submit="">确认修改</button> </div>
          
          </form></div>

          <!--实名认证-->
          <div class="layui-form layui-form-pane layui-tab-item" lay-filter="user">
            <form class="layui-form" action="edit_sm.php" method="POST" name="smform">
              <input type="hidden" name="dopost" value="save" />
            <div class="layui-form-item">
              <label class="layui-form-label">真实姓名</label>
              <div class="layui-input-block">
                <input type="text" name="name" lay-verify="required" lay autocomplete="off" lay-reqtext="真实姓名为必填项，岂能为空？" placeholder="请输入身份证上的名字" class="layui-input">
              </div>
            </div>
            <div class="layui-form-item">
              <input type="file" name="file" class="layui-upload-drag .layui-upload-file" lay-title="添加一个碉堡了的图片" > 
              <div class="layui-inline layui-word-aux">
                上传的图片大小不能超过2M，只支持jpg、jpeg、png、bmp格式的图片！
              </div>
            </div>
            
            <div class="layui-form-item">
              <label class="layui-form-label">身份证号</label>
              <div class="layui-input-block">
                <input type="text" name="cardno" lay-verify="required" lay-reqtext="身份证号是必填项，岂能为空？" autocomplete="off" placeholder="请输入身份证号" class="layui-input">
              </div>
            </div>
            <div class="layui-form-item">
              <div class="layui-input-inline uploadHeadImage">
                <div class="layui-upload-file" id="headImg">
                    <i class="layui-icon"></i>
                    <p>点击上传图片，或将图片拖拽到此处</p>
                </div>
            </div>
              <div class="layui-inline layui-word-aux">
                上传的图片大小不能超过2M，只支持jpg、jpeg、png、bmp格式的图片！
              </div>
            </div>
            <div class="layui-form-item">
              <button type="button" class="layui-btn layui-btn-danger" id="file2" name="fan"><i class="layui-icon"></i>上传身份证反面图片</button>
              <div class="layui-inline layui-word-aux">
                上传的图片大小不能超过2M，只支持jpg、jpeg、png、bmp格式的图片！
              </div>
            </div>
            <div class="layui-form-item">
              <button type="button" class="layui-btn layui-btn-danger" id="file3" name="shou"><i class="layui-icon"></i>上传手持身份证图片</button>
              <div class="layui-inline layui-word-aux">
                上传的图片大小不能超过2M，只支持jpg、jpeg、png、bmp格式的图片！
              </div>
            </div>
            <div class="layui-form-item">
              <div class="layui-input-block">
                <button type="submit" class="layui-btn" lay-submit="" lay-filter="user">立即提交</button>
              </div>
            </div>
          </form>
          </div>
       
          </div>
          </div>
          </div>
  
  <div class="layui-footer">
    <!-- 底部固定区域 -->
    © layui.com - 底部固定区域
  </div>
</div>
<script src="templets/layui/layui.all.js"></script>
<script>
//JavaScript代码区域
layui.use(['form', 'layedit', 'laydate','element','upload'], function(){
  var form = layui.form
  ,layer = layui.layer
  ,layedit = layui.layedit
  ,laydate = layui.laydate
  ,element = layui.element
  ,upload =layui.upload;
  
  //一些事件监听
  element.on('tab(user)', function(data){
    element.render();
  });
  
 //设定文件大小限制
 upload.render({
   
    elem: '#file1'
    ,url: 'http://localhost/uploads' //改成您自己的上传接口
    ,accept:'images'
    ,size: 2048 //限制文件大小，单位 KB
    ,auto:false
    ,done: function(res){
      layer.msg('上传成功');
      console.log(res);
      console.log("sss");
    }
  });
  //设定文件大小限制
 upload.render({
   
   elem: '#file2'
   ,url: 'http://localhost/uploads' //改成您自己的上传接口
   ,accept:'images'
   ,size: 2048 //限制文件大小，单位 KB
   ,auto:false
   ,done: function(res){
     layer.msg('上传成功');
     console.log(res);
     console.log("sss");
   }
 });
 //设定文件大小限制
 upload.render({
   
   elem: '#file3'
   ,url: 'http://localhost/uploads' //改成您自己的上传接口
   ,accept:'images'
   ,size: 2048 //限制文件大小，单位 KB
   ,auto:false
   ,done: function(res){
     layer.msg('上传成功');
     console.log(res);
     console.log("sss");
   }
 });

  //验证密码 
  form.verify({
    title: function(value){
      if(value.length < 6){
        return '至少得6个字符啊';
      }
    }
    ,pass: [
      /^[\S]{6,16}$/
      ,'密码必须6到12位，且不能出现空格'
    ]

    
  });

});
</script>
</body>
</html>
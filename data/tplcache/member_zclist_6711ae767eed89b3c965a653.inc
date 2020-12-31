<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?>
<!DOCTYPE html
    PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">

<head>
    <meta http-equiv="Content-Type" content="text/html; charset=<?php echo $cfg_soft_lang; ?>">
    <title>会员入金明细</title>
    <link href="css/base.css" rel="stylesheet" type="text/css">
    <script language="javascript" src="js/member.js"></script>
    <style type="text/css">
        .rb {
            border-right: 1px solid #666666
        }

        .tb {
            border-top: 1px solid #666666
        }
    </style>

</head>

<body background='images/allbg.gif' leftmargin='8' topmargin='8'>
    <table width="98%" border="0" align="center" cellpadding="3" cellspacing="1" bgcolor="#D6D6D6"
        style="margin-bottom:6px">
        <tr>
            <td height="30" align="center" bgcolor="#F9FCEF">
                <form action="member_zclist.php" name="form1" method="post">
                    <input type="hidden" name="dopost" value="search" />
                    <table border="0" cellspacing="0" cellpadding="3">
                        <tr>
                            <td>关键字：</td>
                            <td><input name="keyword" type="text" id="keyword" size="12" style="width:120px" value="<?php echo $GLOBALS['keyword']; ?>" /></td>
                            <td>&nbsp;排序：</td>
                            <td>
                                <select name="hstate" id="hstate" style="width:120px">
                                    <option value="3" >全部</option>
                                    <option value="0" <?php echo $hstate==0?'selected':''; ?>>待审核</option>
                                    <option value="1"<?php echo $hstate==1?'selected':''; ?>>已通过</option>
                                    <option value="2" <?php echo $hstate==2?'selected':''; ?> >已拒绝</option>

                                </select>
                            </td>
                            <td>
                                <input name="imageField" class="np" type="image" src="images/button_search.gif"
                                    width="60" height="22" border="0" />
                            </td>
                        </tr>
                    </table>
                </form>
            </td>
        </tr>
    </table>
    <form name="form2">
        <table width="98%" border="0" align="center" cellpadding="2" cellspacing="1" bgcolor="#cfcfcf">
            <tr>
                <td height="28" colspan="9" background="images/tbg.gif">
                    <table width="99%" border="0" cellspacing="0" cellpadding="0">
                        <tr>
                            <td width="30%" style="padding-left:10px;"><strong>会员入金明细</strong></td>
                        </tr>
                    </table>
                </td>
            </tr>
            <tr bgcolor="#FEFCEF" height="30" align="center">
                <td width="3%">选择</td>
                <td width="11%">用户名</td>
                <td width="11%">推荐人</td>
                <td width="16%">入金账号</td>
                <td width="5%">入金金额</td>
                <td width="8%">状态</td>
                <td width="20%">支付方式</td>
                <td width="14%">时间</td>
                <td>操作</td>
            </tr>
            <?php
$atts = array();
$atts['tagname'] = 'datalist';
$blockValue = $this->refObj->GetArcList($atts,$this->refObj,$fields); 
if(is_array($blockValue)){
foreach( $blockValue as $key=>$fields )
{
?>
            <tr height="26" align="center" bgcolor="#FFFFFF" onMouseMove="javascript:this.bgColor='#FCFDEE';"
                onMouseOut="javascript:this.bgColor='#FFFFFF';">
                <td><input name="mid" type="checkbox" id="mid" value="<?php echo $fields['id']; ?>" class="np" /></td>
                <td>
                    <?php echo $fields['userid']; ?>
                </td>
                <td>
                    <?php echo $fields['uname']; ?>
                </td>
                <td>
                    <?php echo $fields['payno']; ?>
                </td>
                <td>
                    <?php echo $fields['cny']; ?>
                </td>
                <td>
                    <?php if($fields['state'] == 0){ ?>
                    待审核
                    <?php }  if($fields['state'] == 1){ ?>
                    已通过
                    <?php }  if($fields['state'] == 2){ ?>
                    已拒绝
                    <?php } ?>
                </td>
                <td>
                    <?php echo $fields['pstyle']; ?>
                </td>
                <td>
                    <?php echo $fields['ctime']; ?>
                </td>
                <td align="center">
                    <a href="member_zclist.php?id=<?php echo $fields['id']; ?>&dopost=zcs">通过</a> |
                    <a href="member_zclist.php?id=<?php echo $fields['id']; ?>&dopost=zcf">拒绝</a>
                </td>
            </tr>
            <?php
}
}?>
           <!-- <tr bgcolor="#ffffff">
                <td height="36" colspan="9">
                    &nbsp;
                    <a href="javascript:selAll()" class="coolbg">全选</a>
                    <a href="javascript:noSelAll()" class="coolbg">取消</a>
                    <a href="javascript:delArc(0)" class="coolbg">&nbsp;删除&nbsp;</a>
                </td>
            </tr>-->
            <tr bgcolor="#F9FCEF">
                <td height="36" colspan="9" align="center">
                    <?php
$atts = array();
$atts['tagname'] = 'pagelist';
$atts['listsize'] = '6';
 echo $this->refObj->GetPageList($atts,$this->refObj,$fields); 
?>
<div><input id="result" name="result" /></div>
                    <button id="btn"  onclick="func()"> 提交</button>
                </td>
            </tr>
        </table>
    </form>
</body>
<script type="text/javascript">
   var func = function () {
        document.getElementById("result").value = "开始传输数据";
           $.ajax({
             type: "GET",
             url: "../demo.php",  //同目录下的php文件
             data:"name=tips",  // 等号前后不要加空格
            success: function(msg){  //请求成功后的回调函数
                //$("#result").text="你的名字是"+msg;
                document.getElementById("result").value = msg;
                console.log(msg);
                playSound();
            }
        });
   }

   var playSound = function () {
            var borswer = window.navigator.userAgent.toLowerCase();
            if (borswer.indexOf("ie") >= 0) {
                //IE内核浏览器
                var strEmbed = '<embed name="embedPlay" src="../images/voice.mp3" autostart="true" hidden="true" loop="3"></embed>';
                if ($("body").find("embed").length <= 0)
                    $("body").append(strEmbed);
                var embed = document.embedPlay;

                //浏览器不支持 audion，则使用 embed 播放
                embed.volume = 100;
                //embed.play();这个不需要
            } else {
                //非IE内核浏览器
                var strAudio = "<audio id='audioPlay' src='../images/voice.mp3' hidden='true'>";

                if ($("#audioPlay").length <= 0) {
                    $("body").append(strAudio);
                }

                var audio = document.getElementById("audioPlay");
                var start = 0;//定义循环的变量
                var times=3;//定于循环的次数
                audio.addEventListener("ended",function() {
                audio.play();//启动音频，也就是播放
                start++;//循环
                start == times && audio.pause();//也就是当循环的变量等于次数的时候，就会终止循环并且关掉音频
                });

                //浏览器支持 audio
                audio.play();
            }
        }
    //主动调用
    //setInterval("func()", 30000);
</script>
</html>
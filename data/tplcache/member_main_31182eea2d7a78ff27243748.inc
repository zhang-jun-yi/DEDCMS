<?php
if(!isset($GLOBALS['_vars'])) $GLOBALS['_vars'] = array(); 
$fields = array();
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">

<head>
    <meta http-equiv="Content-Type" content="text/html; charset=<?php echo $cfg_soft_lang; ?>">
    <title>网站会员管理</title>
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
    <table width="98%" border="0" align="center" cellpadding="3" cellspacing="1" bgcolor="#D6D6D6" style="margin-bottom:6px">
        <tr>
            <td height="30" align="center" bgcolor="#F9FCEF">
                <form action="member_main.php" name="form1" method="get">
                    <table border="0" cellspacing="0" cellpadding="3">
                        <tr>
                            <td>关键字：</td>
                            <td><input name="keyword" type="text" id="keyword" size="12" style="width:120px" value="<?php echo $GLOBALS['keyword']; ?>" /></td>
                            
                            <td>
                                <input name="imageField" class="np" type="image" src="images/button_search.gif" width="60" height="22" border="0" />
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
                            <td width="30%" style="padding-left:10px;"><strong>注册会员列表</strong></td>
                        </tr>
                    </table>
                </td>
            </tr>
            <tr bgcolor="#FEFCEF" height="30" align="center">
                <td width="3%">选择</td>
                <td width="10%">mid</td>
                <td width="10%">用户名</td>
                <td width="10%">推荐人</td>
                <td width="15%">开户行</td>
                <td width="15%">期货账号</td>
                <td width="15%">加入时间</td>
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
            <tr height="26" align="center" bgcolor="#FFFFFF" onMouseMove="javascript:this.bgColor='#FCFDEE';" onMouseOut="javascript:this.bgColor='#FFFFFF';">
                <td><input name="mid" type="checkbox" id="mid" value="<?php echo $fields['mid']; ?>" class="np" /></td>
                <td><?php echo $fields['mid']; ?>
                </td>
                <td>
                    <?php echo $fields['userid']; ?>
                </td>
                <td>
                    <?php echo $fields['pname']; ?>
                </td>
                <td>
                    <?php echo $fields['bankaddr']; ?>
                </td>
                <td>
                    <?php echo $fields['qhuid']; ?>
                </td>
                <td>
                    <?php echo $fields['jointime']; ?>
                </td>
                <td align="center">
                    <a href="member_view.php?id=<?php echo $fields['mid']; ?>">修改</a> |
                    <a href="member_do.php?id=<?php echo $fields['mid']; ?>&dopost=delmember">删除</a>
                </td>
            </tr>
            <?php
}
}?>
            <tr bgcolor="#F9FCEF">
                <td height="36" colspan="9" align="center">
                    <?php
$atts = array();
$atts['tagname'] = 'pagelist';
$atts['listsize'] = '6';
 echo $this->refObj->GetPageList($atts,$this->refObj,$fields); 
?>

                </td>
            </tr>
        </table>
    </form>
</body>

</html>
<?php
/**
 * @version        $Id: login.php 1 8:38 2010年7月9日Z tianya $
 * @package        DedeCMS.Member
 * @copyright      Copyright (c) 2007 - 2010, DesDev, Inc.
 * @license        http://help.dedecms.com/usersguide/license.html
 * @link           http://www.dedecms.com
 */
require_once(dirname(__FILE__)."/config.php");
require_once("api.php");
$row=$dsql->GetOne("SELECT  qhuid FROM `#@__member` WHERE mid='".$cfg_ml->M_ID."'");
$account = $row['qhuid'];//期货账号

//查询资金
$xgj = new xinGuanjia();
$result = $xgj->queryaccount($account);

//var_dump($result) ;

if($result['Result']['RequestID'] !=23)
    {
        showmsg('返回结果中的校验值不正确，请联系管理员！', 'querymoney.php');
        exit;
    }
elseif ($result['Result']['Error']['Code'] == 0) {
    //只显示可用资金，基币为美金
    $available = $result['Result']['Summary']['Available'];
    include(DEDEMEMBER."/templets/querymoney.htm");
}
else {
     showmsg($result['Result']['Error']['Message'], 'querymoney.php');
        exit;
}



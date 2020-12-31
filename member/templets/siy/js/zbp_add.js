function ZCenter_hideMenu(){
 $("#aZCenter_Menu").attr('onclick','javascript:ZCenter_showMenu()');
 SetCookie('zcenter_menu','1',365);
}

function ZCenter_showMenu(){
 $("#aZCenter_Menu").attr('onclick','javascript:ZCenter_hideMenu()');
 SetCookie('zcenter_menu','',-1); 
}



$(document).ready(function(){
  if(GetCookie('zcenter_menu')=='1') {
 $("#aZCenter_Menu").attr('onclick','javascript:ZCenter_showMenu()');
  $(".app").toggleClass("app-aside-folded");
  $("#aZCenter_Menu").toggleClass("active");

  }
});

function ZCenter_BatchSelectAll(id) {
	$("#table"+id+" input[name='id[]']").click();
}

//*********************************************************
// 目的：    设置Cookie
// 输入：    sName, sValue,iExpireDays
// 返回：    无
//*********************************************************
function SetCookie(sName, sValue,iExpireDays) {
	var path=(typeof(cookiespath)=="undefined") ? "/":cookiespath;
	if (iExpireDays){
		var dExpire = new Date();
		dExpire.setTime(dExpire.getTime()+parseInt(iExpireDays*24*60*60*1000));
		document.cookie = sName + "=" + escape(sValue) + "; expires=" + dExpire.toGMTString()+ "; path="+path;
	}
	else{
		document.cookie = sName + "=" + escape(sValue)+ "; path="+path;
	}
}
//*********************************************************




//*********************************************************
// 目的：    返回Cookie
// 输入：    Name
// 返回：    Cookie值
//*********************************************************
function GetCookie(sName) {

	var arr = document.cookie.match(new RegExp("(^| )"+sName+"=([^;]*)(;|$)"));
	if(arr !=null){return unescape(arr[2])};
	return null;

}
//*********************************************************

//*********************************************************
// 目的：    ActiveLeftMenu
// 输入：    无
// 返回：    无
//*********************************************************
function ZCenter_ActiveLeftMenu(name){

	name="#"+name;
	$(".navi ul li").removeClass("active");
	$(name).parent().addClass("active");


}
//*********************************************************
//*********************************************************
// 目的：    ActiveTopMenu
// 输入：    无
// 返回：    无
//*********************************************************
function ZCenter_ActiveTopMenu(name){

	name="#topmenu_"+name;
	$(".navbar-right li").removeClass("zcenter-open");
	$(name).addClass("zcenter-open");


}
//*********************************************************





    $(document).ready(function(){
     $(".touch-toggle a").click(function(event){

      var className = $(this).attr("data-drawer");

      if( $("."+className).css('display') == 'none' ){      

       $("."+className).slideDown().siblings(".drawer-section").slideUp();
	  // $(".touch_bg").slideDown();//20170419
	   $(".touch_bg").show();//20170419
		   $("body").addClass("pos");
		   if(className=="drawer-section-menu")
	    	{$(".top_ico").addClass("on");
			 $(".touch_bg").addClass("nav-show");
			// $(".touch-top-home").addClass("nav-show");
			}
			
      }else{

       $(".drawer-section").slideUp(); 
	  // $(".touch_bg").slideUp();//20170419
	    $(".touch_bg").hide();//20170419
	   		if(className=="drawer-section-menu")
	    	{$(".top_ico").removeClass("on");
			 $(".touch_bg").removeClass("nav-show");
			// $(".touch-top-home").removeClass("nav-show");
			}
	  		 $("body").removeClass("pos");

      }
      event.stopPropagation();
	  
     });
 
	$(".touch_bg").click(function(){
			 $(".drawer-section").slideUp();   	
			  $(".touch_bg").slideUp();//20170419
			  $(".top_ico").removeClass("on");
			  $("body").removeClass("pos");
			  $(".touch_bg").removeClass("nav-show");
			 // $(".touch-top-home").removeClass("nav-show");
		 })	
	$(".closetitle").click(function(){
			 $(".drawer-section").slideUp();   	
			  $(".touch_bg").slideUp();//20170419
			   $(".top_ico").removeClass("on");
			   $("body").removeClass("pos");
			   $(".touch_bg").removeClass("nav-show");
			  
		 })	
		
     //$(document).click(function(){
//
//      $(".drawer-section").slideUp();   
//	  
//     })

     $('.touch-menu a').click(function(){     

      if( $(this).next().is('ul') ){

       if( $(this).next('ul').css('display') == 'none' ){
		$('.touch-menu ul li').find("ul").slideUp();
		$('.touch-menu ul li').find("a").find('i').attr("class","touch-arrow-down");
        $(this).next('ul').slideDown();

        $(this).find('i').attr("class","touch-arrow-up");     
		//$(".touch-top").css("position","absolute");
       }else{

        $(this).next('ul').slideUp();

        $(this).next('ul').find('ul').slideUp();

        $(this).find('i').attr("class","touch-arrow-down");
		//$(".touch-top").css("position","fixed");

       }   

      }

     });


    });
	
	  
  
    // 导航显示与隐藏
  var NavHeight = false;
  var hhh= 100;
  $(window).scroll(function(){
    Nav(hhh);
  })
  Nav(hhh);
  function Nav(hhh){	
	
	 if( $(window).scrollTop() >hhh && NavHeight == false ){
      $("body").addClass("nav-hide");
      NavHeight = true;
    }else if($(window).scrollTop() <= hhh && NavHeight == true ){
      NavHeight = false;
      $("body").removeClass("nav-hide");
    }
	
    if( $(window).scrollTop() > $(window).height() ){
	  $(".gotop").addClass("actives");
    }else if($(window).scrollTop() <= $(window).height()){
	   $(".gotop").removeClass("actives");
    }
  }
//  $(window).mousewheel(function(e, delta) { //滚动条向上滚动
//      p = $(window).scrollTop();
//      if( p > $(window).height() ){
//        if (delta < 0) {
//          $("body").addClass("nav-hide");
//        } else { //上滚
//           $("body").removeClass("nav-hide");
//        }
//      }
//  })

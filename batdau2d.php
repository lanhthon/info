
<!DOCTYPE html>
<html lang="vi">
  <head>
  	<link rel="icon" href="img/cc.png">
  	<meta name="viewport" content="width=device-width, initial-scale=1">
    <meta charset="utf-8" />
    
    <title>Lành Thôn</title>

<style type="text/css" media="screen">
 
 box-sizing: border-box;
}

@keyframes fadeIn {
	0% { opacity: -10; }
	100% { opacity: 1; }
}

#lol {
    	animation: myfirst 5s 2;
  animation-direction: alternate;
}

@keyframes myfirst {
  0%   {background: red; left: 0px; top: 0px;}
  25%  {background: yellow; left: 200px; top: 0px;}
  50%  {background: blue; left: 200px; top: 200px;}
  75%  {background: green; left: 0px; top: 200px;}
  100% {background: red; left: 0px; top: 0px;}
}
}
body {
  margin: 0;
  font-family: Arial;
  font-size: 17px;
}

#myVideo {
  position: fixed;
  right: 0;
  bottom: 0;
  min-width: 100%; 
  min-height: 100%;
  width:100%;
  height:100%;
}
.outer {
  background-color: pink;
  background-size:cover;
  width: 100px;
  position: relative;
  display: inline-block;
  margin: 100px 20px;

}

.inner {
  font-size: 20px;
  font-color: #878787;
  position: absolute;
  top: 50%;
  left: 50%;
  background: #DDD;

}

.rotate {
    -moz-transform: translateX(-50%) translateY(-50%) rotate(-90deg);
  -webkit-transform: translateX(-50%) translateY(-50%) rotate(-90deg);
  transform:  translateX(-50%) translateY(-50%) rotate(-90deg);
}

#chao {
    
  position: fixed;
  top: 0;
  background-color: rgba(255, 255, 255, 0);
  
  width: 100%;
  padding: 20px;

color: #FFf;
text-shadow: 0 0 150px #FFF, 0 0 60px #FFF, 0 0 10px #FFF;


}
#loibaihat {
    
  position: fixed;
  bottom: 0;
  background-color: rgba(255, 255, 255, 0.01);
  
  width: 100%;
  padding: 20px;

color: #FFf;
text-shadow: 0 0 150px #FFF, 0 0 60px #FFF, 0 0 10px #FFF;
	-webkit-animation: fadeIn 10s ease-out;
	animation: fadeIn 10s ease-out;
}
#gioithieu {
    
  position: fixed;
  top: 0;
  background-color: rgba(255, 255, 255, 0.01);
  
  width: 100%;
  padding: 20px;

color: #FFf;
text-shadow: 0 0 150px #FFF, 0 0 60px #FFF, 0 0 10px #FFF;
	-webkit-animation: fadeIn 10s ease-out;
	animation: fadeIn 10s ease-out;
}
.chuyendong {
    
  position: fixed;
  bottom: 0;
  background: rgba(192, 192, 192, 0);
  
  width: 100%;
  padding: 20px;

color: #FFF;
text-shadow: 0 0 150px #FFF, 0 0 60px #FFF, 0 0 10px #FFF;
animation-name:move_right;
            animation-duration:40s;
            animation-iteration-count:1;
        }
        @keyframes move_right{
            0%{bottom:0px;}
           100%{bottom:500px;}
    
    
}
.info {
  position: fixed;
  bottom: 0;
  left: 0;
  background: rgba(255, 255, 255, 0);
  
  width: 100%;
  padding: 20px;

color: #FFF;
text-shadow: 0 0 150px #FFF, 0 0 60px #FFF, 0 0 10px #FFF;

}


 body {
 	
  color: hotpink;
 background-color:#000;
background-repeat:no-repeat;
 background-size:cover; 
background-attachment: fixed;
}

#bg {
    background-image:url:'img/bgcute.png';
   font-size: auto;font-weight: 700;color:#fff;text-shadow: 0 0 10px #fff, 0 0 20px #fff; }


    
a {
 color: hotpink;
}
}
@import url('https://fonts.googleapis.com/css?family=Source+Code+Pro:200,900');

:root {
  --text-color: hsla(210, 50%, 85%, 1);
  --shadow-color: hsla(210, 40%, 52%, .4);
  --btn-color: hsl(210, 80%, 42%);
  --bg-color: #141218;
}

* {
  box-sizing: border-box;
}


button {
  position:relative;
  padding: 10px 20px;  
  border: none;
  background: none;
  cursor: pointer;
  
  font-family: "Source Code Pro";
  font-weight: 900;
  text-transform: uppercase;
  font-size: 30px;  
  color: var(--text-color);
  
  background-color: var(--btn-color);
  box-shadow: var(--shadow-color) 2px 2px 22px;
  border-radius: 4px; 
  z-index: 0;  
  overflow: hidden;   
}

button:focus {
  outline-color: transparent;
  box-shadow: var(--btn-color) 2px 2px 22px;
}

.right::after, button::after {
  content: var(--content);
  display: block;
  position: absolute;
  white-space: nowrap;
  padding: 40px 40px;
  pointer-events:none;
}

button::after{
  font-weight: 200;
  top: -30px;
  left: -20px;
} 

input[type=text] {
  width: auto;
  padding: 12px 20px;
  margin: 8px 0;
  box-sizing: border-box;
  border: 1px solid #58257b;
  outline: none;
  background-color: rgba(255,255,255,0.5);
}

input[type=text]:focus {
  background-color: #CCFFCC;
}
input[type=submit] {
  width: auto;
  background-color: #3366CC;
  color: white;
  padding: 14px 20px;
  margin: 8px 0;
  border: 5px;
  border-radius: 4px;
  cursor: pointer;
}

#nut {
    color:#ccc;
}
/*xoay*/
#chongchong {
	background-image: url('img/bgcot.png');
	background-size: 102% 100%;
 background-repeat:no-repeat;
background-attachment: fixed;
}
.app-logo {
  animation: app-logo-spin infinite 15s linear
  
}

@keyframes app-logo-spin {
  from {
    transform: rotate(360deg)
  }
  to {
    transform: rotate(0deg)
  }
}

#bgcot {
    background-image:url:'img/bgcot.png';
   font-size: auto;font-weight: 700;color:#fff;text-shadow: 0 0 10px #fff, 0 0 20px #fff; }

/* Global */
html{
  min-height: 100%;
  overflow: hidden;
}


.line-1{
    position: relative;
    top: 50%;  
    width: 24em;
    margin: 0 auto;
    border-right: 2px solid rgba(255,255,255,.75);
    font-size: 180%;
    text-align: center;
    white-space: nowrap;
    overflow: hidden;
    transform: translateY(-50%);    
}

/* Animation */
.anim-typewriter{
  animation: typewriter 4s steps(44) 1s 1 normal both,
             blinkTextCursor 500ms steps(44) infinite normal;
}
@keyframes typewriter{
  from{width: 0;}
  to{width: 24em;}
}
@keyframes blinkTextCursor{
  from{border-right-color: rgba(255,255,255,.75);}
  to{border-right-color: transparent;}
}
#avatar {
border-radius:50%;
-moz-border-radius:50%;
-webkit-border-radius:50%;
	-webkit-animation: fadeIn 10s ease-out;
	animation: fadeIn 10s ease-out;
}
#img2 {
        -moz-transform: scaleX(-1);
        -o-transform: scaleX(-1);
        -webkit-transform: scaleX(-1);
        transform: scaleX(-1);
        filter: FlipH;
        -ms-filter: "FlipH";
}
#tinnhan {
    display:none;
    position: fixed;
  bottom: 100px;
  
    text-align: right;
  background: rgba(255, 255, 255, 0.1);
  
  width: 100%;
  padding: 20px;

color: #FFF;
text-shadow: 0 0 150px #FFF, 0 0 60px #FFF, 0 0 10px #FFF;
	-webkit-animation: fadeIn 10s ease-out;
	animation: fadeIn 10s ease-out;
}
#ten {
    text-transform: capitalize;
	-webkit-animation: fadeIn 10s ease-out;
	animation: fadeIn 10s ease-out;

color: #FFF;
text-shadow: 0 0 150px #FFF, 0 0 60px #FFF, 0 0 10px #FFF;
}
#happybirthday {
    display:none;
    position: fixed;
  top: 0;
color: hotpink;
    text-align: right;
  background-image:url('img/trongsuot.png');
   font-size: auto;font-weight: 700;
  width: 100%;
  padding: 20px;
	-webkit-animation: fadeIn 10s ease-out;
	animation: fadeIn 10s ease-out;


text-shadow: 0 0 150px #FFF, 0 0 60px #FFF, 0 0 10px #FFF;
}
/* Thong bao Popup  */
.tbpopup .tboverlay {
position:fixed;
top:0px;
left:0px;
width:100vw;
height:100vh;
background:rgba(0,0,0,0.7);
z-index:1;
display:none;
}

.tbpopup .tbcontent {
position:absolute;
top:50%;
left:50%;
transform:translate(-50%,-50%) scale(0);
background:#fff;
max-width:500px;
z-index:2;
text-align:center;
padding:20px;
box-sizing:border-box;
font-family:"Open Sans",sans-serif;
border-radius:20px;
display: block;
position: fixed;
box-shadow:0px 0px 10px #111;
}
@media (max-width: 700px) {
.tbpopup .tbcontent {width:90%;}
}

.tbpopup .tbclose-btn {
cursor:pointer;
position:absolute;
right:20px;
top:20px;
width:35px;
height:35px;
color:#ff4444;
font-size:30px;
font-weight:600;
line-height:35px;
text-align:center;
border-radius:50%;
}

.tbpopup.active .tboverlay {
display:block;
}

.tbpopup.active .tbcontent {
transition:all 300ms ease-in-out;
transform:translate(-50%,-50%) scale(1);
}
.tbbuttom{background:#00cc00;color:#fff}



@keyframes fadeIn {
	0% { opacity: 0; }
	100% { opacity: 1; }
}
#chao {
	-webkit-animation: fadeIn 10s ease-out;
	animation: fadeIn 10s ease-out;
}
</style>

</head>


    
<body>


    
     <?
          $CountFile = "index.log";
          $CF = fopen ($CountFile, "r");
          $Views = fread ($CF, filesize ($CountFile));
          fclose ($CF);
          $Views++; 

          $CF = fopen ($CountFile, "w");
          fwrite ($CF, $Views); 
          fclose ($CF); 
          echo ($Views);
          ?>
<!-- Thong bao pupup -->
<div class="tbpopup" id="tbpopup-1">
<div class="tboverlay"></div>
<div class="tbcontent">
<div class="tbclose-btn" onclick="thongbaopopup()">&times;</div>
<div style="font-size:30px;font-weight:bold">Xin chào</div>
<center>

<p id="ten2"></p><p>Cute</p>
  <img src="img/chao.png" width="50%auto" height="50%auto">

<video preload="auto" width="10" height="10" controls autoplay muted>
  <source src="vid/cool.mp4" type="video/mp4">
</video>
<video preload="auto" width="10" height="10" controls autoplay muted>
  <source preload="auto" src="vid/loading.mp4" type="video/mp4">
</video>

<video preload="auto" width="10" height="10" controls autoplay muted>
  <source src="vid/goodbye.mp4" type="video/mp4">
</video>
</center>
</div>
</div>
<script>
function thongbaopopup(){
document.getElementById("tbpopup-1").classList.toggle("active");
}
</script>
    <video autoplay id="myVideo">

  <source src="vid/loading.mp4" type="video/mp4">


  Your browser does not support HTML5 video.

</video>

 <script type="text/javascript">




// Trong khi giá trị bé hơn 1 hoặc giá trị lớn hơn 10
// thì chạy thân vòng lặp
var name = prompt("Bạn phải nhập tên");

if(name = null){
    name = prompt("no nhập tên đi chứ");
}
 

	
document.write(name) ;
  

	

		</script>
		

<div id="chao">

<center>
<div id="nenten"><strong><h3 id="ten"></h3></strong></div>
<marquee direction="up" width="20%"><img id="img2" src="img/trongsuot.png" wight="70" height="70"></marquee><img id="avatar" src="img/trongsuot.png" wight="150" height="150"><marquee direction="up" width="20%"><img id="img3" src="img/trongsuot.png" wight="70" height="70"></marquee>

<p id="quote"></p></center>
  </div>
  
        <audio preload="auto" id="myAudio">
<source src="nhac/nhac.mp3" type="audio/mpeg">
  </audio>
      <audio preload="auto" id="audionhacnen">
 <source src="nhac/nhacnen.mp3" type="audio/mpeg">
  </audio>
 <audio id="audiofb">
<source src="nhac/nhacfb.mp3" type="audio/mpeg">
  </audio>
 <audio id="audioig">
  <source src="nhac/nhacig.mp3" type="audio/mpeg">
 </audio>

<div id="info" class="info">
  <a href="https://m.me/NTlanhthon">
  <img src="../img/mess.png" width="50px" height="50px"></a>
   &emsp;&emsp;&emsp;&emsp;   
<img onclick="fb(),playAudiofb()" border="0" alt="fb" src="img/logofb.png" width="50" height="50">
<img onclick="ig(),playAudioig()" border="0" alt="ig" src="img/logoig.png" width="50" height="50">
 </div>
<div id="gioithieu">
    <center>
      <h2>Introduction</h2>
      <img id="gt" src="img/gioithieu.png" wight="150px" height=150px>

      <h3>Lành Thôn</h3>
      <h4>Đam mê tiền nhưng chưa có tiền :d >><h4>
      
      </center>
</div>

 
 <div id="tinnhan">
     
<a href="tinnhan/index.php" target="_blank">Liên hệ<img id="but" src="img/but.png" width="90px" height="50px"></a>

</div>

<script>

/*if(name == 'ngan'){
    document.getElementById("audionhacnen").src="nhac/ngan.mp3";
   document.body.style.backgroundImage = "url('img/ngan.jpg')";

    
  var vide = document.getElementById("myVideo");
    vide.parentNode.removeChild(vide);
}*/
document.getElementById("ten").innerHTML = name;
document.getElementById("ten2").innerHTML = name;

if(name == 'tram anh'||name == 'trâm anh'||name == 'Trâm Anh'){
    
	window.location="http://tramanh.lanhthon.com/";
}

else {
    
    document.getElementById('ten').style.display = "none";

    
document.getElementById('tinnhan').style.display = "none";
    
document.getElementById('info').style.display = "none";
document.getElementById('gioithieu').style.display = "none";
setTimeout(function (){
      var vide = document.getElementById("myVideo");
    vide.src="vid/cool.mp4";
document.getElementById('ten').style.display = "block";


  },10000);

var nhacnen = document.getElementById("audionhacnen");
setTimeout(function (){
      document.getElementById("audionhacnen").src="nhac/cool.mp3";
      nhacnen.play();
  },42000); 
  setTimeout(function (){
      
document.getElementById("quote").innerHTML = 'Welcome bạn ' + name;
document.getElementById('ten').style.display = "none";


  },31000); 
setTimeout(function (){
document.getElementById("quote").innerHTML = "Chúc bạn " + name + " có một ngày vui vẻ";

  },37000); 
  
  
  setTimeout(function (){

var vide = document.getElementById("myVideo");
    vide.src="vid/wallpaper.mp4";
    vide.muted=true;
    vide.loop=true;
document.getElementById("quote").innerHTML = " ";
document.getElementById('gioithieu').style.display = "block";
  },49000);
setTimeout(function (){

var vide = document.getElementById("myVideo");
    vide.src="vid/goodbye.mp4";
    vide.loop=true;
    vide.muted=false;
   nhacnen.pause();
    document.getElementById("quote").innerHTML = ' Cảm ơn bạn ' + name+ ' đã dành thời gian vào web của mình';
   document.getElementById('info').style.display = "block";
   document.getElementById('gioithieu').style.display = "none";
document.getElementById("img3").src="img/tym.png";
    document.getElementById("img2").src="img/tym.png";
    document.getElementById("avatar").src="img/gioithieu.png";
    
    document.getElementById('tinnhan').style.display = "block";

  },70000);
}



    </script>
    <script>
    
    var loi ="";
    document.getElementById("loibaihat").innerHTML = loi;
  
setTimeout(function (){
loi = "nnnnnhid"

  },1000); 
  
setTimeout(function (){
loi = "nnnnddududhnhid"

  },3000); 
  
  
  
  
  
  
  
  
        function fb() {
  setTimeout(function () {
   window.location.href= 'https://www.facebook.com/NTlanhthon'; // the redirect goes here
 
},3000);
}
var fbk = document.getElementById("audiofb"); 

function playAudiofb() { 
  fbk.play(); 
} 
function ig() {
  setTimeout(function () {
   window.location.href= 'https://www.instagram.com/thonlanh/'; // the redirect goes here
 
},3000);
}
var iga = document.getElementById("audioig"); 

function playAudioig() { 
  iga.play(); 
} 

        
    </script>
    
<script language="javascript" src="js/hoaroi7.js"></script>
</body></html>






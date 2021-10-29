
<!DOCTYPE html>
<html lang="vi">
  <head>
  	<link rel="icon" href="img/cc.png">
  	<meta name="viewport" content="width=device-width, initial-scale=1">
    <meta charset="utf-8" />
    
    <title>Lành Thôn</title>

<style type="text/css" media="screen">
 
#myVideo {
  position: fixed;
  right: 0;
  bottom: 0;
  min-width: 100%; 
  min-height: 100%;
  width:100%;
  height:100%;
}
body {
  margin: 0;
  font-family: Arial;
  font-size: 17px;
}

 body {
 	
  color: #fff;

background-repeat:no-repeat;
 background-size:cover; 
background-attachment: fixed;
}
b {
  
  text-transform: capitalize;
}
#loibaihat {
  z-index: 2;  
  position: fixed;
  top: 1;
  left: 0;
  right: 0;
  text-align: center;
  background-size: cover;
  
  background-color: rgba(255, 255, 255, 0.5);
  }
/*  
Thanks to: Usama Tahir
https://medium.com/@AmJustSam
*/

*{
 margin: 0;
 padding: 0;
}

html{
    width: 100vw;
    height: 100vh;
}

/* CSS which you need for blurred box */
body{
    
 background-repeat: no-repeat;
 background-attachment: fixed;
 background-size: cover;
 background-position: top;
 
 width: 100%;
 height: 100%;
 font-family: Arial, Helvetica;
 letter-spacing: 0.02em;
  font-weight: 400;
 -webkit-font-smoothing: antialiased; 
}

.blurred-box{
  position: relative;
  width: 250px;
  height: 390px;
  top: calc(50% - 175px);
  left: calc(50% - 125px);
  background: inherit;
  border-radius: 2px;
  overflow: hidden;
}

.blurred-box:after{
 content: '';
 width: 300px;
 height: 300px;
 background: inherit; 
 position: absolute;
 left: -25px;
 left position
 right: 0;
 top: -25px;  
 top position 
 bottom: 0;
 box-shadow: inset 0 0 0 200px rgba(255,255,255,0.05);
 filter: blur(10px);
}


/* Form which you dont need */
.user-login-box{
  position: relative;
  margin-top: 50px;
  text-align: center;
  z-index: 1;
}
.user-login-box > *{
  display: inline-block;
  width: 200px;
}

.user-icon{
  width: 100px;
  height: 100px;
  position: relative;
  border-radius: 50%;
  background-size: contain;
  background-image: url(img/icon.jpg);
}

.user-name{
  margin-top: 15px;
  margin-bottom: 15px;
  color: white;
}
.text{
  
  font-size: 10px;
}
input.user-password{
  width: 120px;
  height: 18px;
  opacity: 0.4;
  border-radius: 2px;
  padding: 5px 15px;
  border: 0;
}

#pot {
   -webkit-animation: slide 0.5s forwards;
    -webkit-animation-delay: 2s;
    animation: slide 0.5s forwards;
    animation-delay: 2s;
}

@-webkit-keyframes slide {
    100% { right: -100; }
}

@keyframes slide {
    100% { right: -100; }
}

.svg-icon {
  width: 1em;
  height: 1em;
}

.svg-icon path,
.svg-icon polygon,
.svg-icon rect {
  fill: #4691f6;
}

.svg-icon circle {
  stroke: #4691f6;
  stroke-width: 1;
}
</style>

</head>


    
<body>

<video autoplay loop muted id="myVideo">
<source src="vid/video.mp4" type="video/mp4"> Your browser does not support HTML5 video.</video>
<audio autoplay id="nhac">
 <source src="nhac/nhac.mp3" type="audio/mpeg">
</audio><center>
  <div id="loibaihat">
<p id="quote"></p>
</div></center>
<!-- 
Thanks to:
https://medium.com/@AmJustSam/how-to-do-css-only-frosted-glass-effect-e2666bafab91 
-->
<div id="pot"
<div class="blurred-box">
  <!--  you dont need the user-login-box html  -->
  <!--  for demo purposes only and its shit  -->
  <div class="user-login-box">
    <span class="user-icon"></span>
    <div class="user-name">Lành Thôn</div>
    <h5>
<svg class="svg-icon" viewBox="0 0 19 19">
							<path d="M18.121,9.88l-7.832-7.836c-0.155-0.158-0.428-0.155-0.584,0L1.842,9.913c-0.262,0.263-0.073,0.705,0.292,0.705h2.069v7.042c0,0.227,0.187,0.414,0.414,0.414h3.725c0.228,0,0.414-0.188,0.414-0.414v-3.313h2.483v3.313c0,0.227,0.187,0.414,0.413,0.414h3.726c0.229,0,0.414-0.188,0.414-0.414v-7.042h2.068h0.004C18.331,10.617,18.389,10.146,18.121,9.88 M14.963,17.245h-2.896v-3.313c0-0.229-0.186-0.415-0.414-0.415H8.342c-0.228,0-0.414,0.187-0.414,0.415v3.313H5.032v-6.628h9.931V17.245z M3.133,9.79l6.864-6.868l6.867,6.868H3.133z"></path>
					</svg> Sống tại Kiên Giang</h5>
    
   <h5> <svg class="svg-icon" viewBox="0 0 19 19">
							<path d="M17.388,4.751H2.613c-0.213,0-0.389,0.175-0.389,0.389v9.72c0,0.216,0.175,0.389,0.389,0.389h14.775c0.214,0,0.389-0.173,0.389-0.389v-9.72C17.776,4.926,17.602,4.751,17.388,4.751 M16.448,5.53L10,11.984L3.552,5.53H16.448zM3.002,6.081l3.921,3.925l-3.921,3.925V6.081z M3.56,14.471l3.914-3.916l2.253,2.253c0.153,0.153,0.395,0.153,0.548,0l2.253-2.253l3.913,3.916H3.56z M16.999,13.931l-3.921-3.925l3.921-3.925V13.931z"></path>
						</svg> lanhthon@gmail.com</h5>
  <h5><svg class="svg-icon" viewBox="0 0 20 20">
							<path d="M18.125,15.804l-4.038-4.037c0.675-1.079,1.012-2.308,1.01-3.534C15.089,4.62,12.199,1.75,8.584,1.75C4.815,1.75,1.982,4.726,2,8.286c0.021,3.577,2.908,6.549,6.578,6.549c1.241,0,2.417-0.347,3.44-0.985l4.032,4.026c0.167,0.166,0.43,0.166,0.596,0l1.479-1.478C18.292,16.234,18.292,15.968,18.125,15.804 M8.578,13.99c-3.198,0-5.716-2.593-5.733-5.71c-0.017-3.084,2.438-5.686,5.74-5.686c3.197,0,5.625,2.493,5.64,5.624C14.242,11.548,11.621,13.99,8.578,13.99 M16.349,16.981l-3.637-3.635c0.131-0.11,0.721-0.695,0.876-0.884l3.642,3.639L16.349,16.981z"></path>
						</svg> lanhthon</h5>
  
  </div>
  </div>
</div>
<div id="pot2"
<div class="blurred-box">
  <!--  you dont need the user-login-box html  -->
  <!--  for demo purposes only and its shit  -->
  <div class="user-login-box">
    
    
    <div class="user-name"></div>
<p id="time">time</p>
  </div>
  </div>
</div>
<script language="javascript" src="js.js"></script>
</body>
</html>
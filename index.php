
<!DOCTYPE html>
<html lang="vi">
  <head>
  	<link rel="icon" href="img/cc.png">
  	<meta name="viewport" content="width=device-width, initial-scale=1">
    <meta charset="utf-8" />
    
    <title>Lành Thôn</title>
     
<style type="text/css" media="screen">
 body {
 background-image: url('img/background.jpg');
	background-size: cover;
 background-repeat:no-repeat;
background-attachment: fixed;
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

.content {
  position: fixed;
  top: 0;
  background: rgba(255, 255, 255, 0.1);
  color: #fff;
  width: 100%;
  padding: 20px;

}


 

#bg {
    background-color: rgba(192,192,192,0.2);
   font-size: auto;font-weight: 700;color:#fff;text-shadow: 0 0 10px #fff, 0 0 20px #fff; }

h3.a {text-shadow: 0 0 0.2em #8F7}
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



/*xoay*/
#xoay {
	background-image: url('./img/bgcot5.png');
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
</style>
<script src="https://cdn.onesignal.com/sdks/OneSignalSDK.js" async=""></script>
<script>
  window.OneSignal = window.OneSignal || [];
  OneSignal.push(function() {
    OneSignal.init({
      appId: "620a6596-e216-43cb-8b5c-84c6faf72cc9",
      notifyButton: {
        enable: true,
      },
      subdomainName: "info-lanhthon",
    });
  });
</script>
</head>

<body>
  
   
<div class="content">
</p>
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
<h2>Vui lòng nhập Tên của bạn </h2>
  <img src="img/chao.png" width="50%auto" height="50%auto">
 <form action="mail.php"
<div id="line-account" class="line">
<input name="{" type="text" placeholder="Chào! Bạn Tên" autocorrect="off" autocapitalize="on"><br>

<div id="line-btn" class="line btnLine">
<input name="" type="submit" value="Okee luôn" class="btn">
</div>
</form>
<video width="10" height="10" controls autoplay muted>
  <source src="vid/cool.mp4" type="video/mp4">
</video>
<video width="10" height="10" controls autoplay muted>
  <source src="vid/loading.mp4" type="video/mp4">
</video>

<video width="10" height="10" controls autoplay muted>
  <source src="vid/goodbye.mp4" type="video/mp4">
</video>
</center>
  
</body></html>






function readTextFile(file, callback) {
    var rawFile = new XMLHttpRequest();
    rawFile.overrideMimeType("application/json");
    rawFile.open("GET", file, true);
    rawFile.onreadystatechange = function () {
        if (rawFile.readyState === 4 && rawFile.status == "200") {
            callback(rawFile.responseText);
        }
    }
    rawFile.send(null);
}

// Chạy thử
readTextFile("name2.json", function (text) {
    var data = JSON.parse(text);
    

var name = data.ten;

var nhacnen = document.getElementById("nhac");
nhacnen.play();
var loibaihat = ["Music: Hall of Fame - The Script<br> <img class='center-block img-wrong' src='img/anhnhac.jpg' width='100' height='100'>", "Chào bạn "+name+" chúc bạn một ngày vui vẻ", "lyrics:",
"Yeah, you can be the greatest<br><strong> Yeah, "+"<b>"+name+"</b>"+" có thể là người vĩ đại nhất",
"You can be the best<br><strong>  "+"<b>"+name+"</b>"+" có thể là người tuyệt vời nhất",
"You can be the King Kong banging on your chest<br><strong>  "+"<b>"+name+"</b>"+" có thể là chú khỉ King Kong vỗ ngực ra oai",
"You could beat the world<br><strong>  "+"<b>"+name+"</b>"+" có thể đánh bại cả thế giới",
"You could be at the war <br><strong> "+"<b>"+name+"</b>"+" có thể dập tắt mọi cuộc chiến",
"You c ould talk to God, go banging on his door <br><strong> "+"<b>"+name+"</b>"+" có thể nói chuyện với Chúa, và gõ cánh cửa thiên đường",
"You can throw your hands up <br><strong> "+"<b>"+name+"</b>"+" có thể giơ tay cao lên",
"You can beat the clock<br><strong>  "+"<b>"+name+"</b>"+" có thể làm chủ được bản thân",
"You can move a mountain <br><strong> "+"<b>"+name+"</b>"+" có thể làm bất cứ thứ gì "+"<b>"+name+"</b>"+" muốn",
"You can break rocks <br><strong> "+"<b>"+name+"</b>"+" có thể thoát khỏi xiềng xích",
" You can be a master<br><strong>  "+"<b>"+name+"</b>"+" có thể là một bậc thầy",
"Don't wait for luck <br><strong> Đừng chờ đợi may", "Dedicate yourself and you gon' find yourself<br><strong>  Hãy cống hiến hết mình và "+"<b>"+name+"</b>"+" sẽ thấy mình",
"Standing in the hall of fame (yeah) <br><strong> Đứng trên sảnh đường danh vọng",
"And the world's gonna know your name (yeah) <br><strong> Và cả thế giới sẽ biết đến danh tiếng của "+"<b>"+name+"</b>"+"",
"Cause you burn with the brightest flame (yeah) <br><strong> Vì "+"<b>"+name+"</b>"+" tỏa sáng rực rỡ", 
"And the worlds gonna know your name (yeah) <br><strong> Và cả thế giới sẽ biết đến danh tiếng của "+"<b>"+name+"</b>"+"",
"And you'll be on the walls of the hall of fame <br><strong>  Và "+"<b>"+name+"</b>"+" sẽ được khắc ghi lên sảnh đường danh vọng",
"You can go the distance <br><strong> "+"<b>"+name+"</b>"+" có thể bay cao",
"You can run the mile<br><strong>  "+"<b>"+name+"</b>"+" có thể bay xa",
"You can walk straight through hell with a smile <br><strong> "+"<b>"+name+"</b>"+" có thể mỉm cười vượt qua những trải nghiệm đau buồn",
"You can be the hero<br><strong>  "+"<b>"+name+"</b>"+" có thể là người tiên phong",
"You can get the gold <br><strong> "+"<b>"+name+"</b>"+" có thể giành được huy chương vàng",
"Breaking all the records they thought never could be broke <br><strong> Phá vỡ mọi kỉ lục tưởng chừng như không thể",
"Do it for your people<br><strong>  Hãy làm thế vì những người thân của "+"<b>"+name+"</b>"+"",
"Do it for your pride<br><strong>  Hãy làm thế vì niềm kiêu hãnh của "+"<b>"+name+"</b>"+"",
"Never gonna know if you never even try <br><strong> Làm sao "+"<b>"+name+"</b>"+" biết là không thể nếu như "+"<b>"+name+"</b>"+" không thử",
"Do it for your country <br><strong> Hãy làm thế vì quê hương của "+"<b>"+name+"</b>"+"",
"Do it for you name <br><strong> Hãy làm thế vì danh dự của "+"<b>"+name+"</b>"+"",
"Cause there's gonna be a day<br><strong>  Bởi vì sẽ có một ngày",
"When you're standing in the hall of fame (yeah) <br><strong> Khi "+"<b>"+name+"</b>"+" đứng trên sảnh đường danh vọng",
"And the world's gonna know your name (yeah)<br><strong>  Và cả thế giới sẽ biết đến danh tiếng của "+"<b>"+name+"</b>"+"",
"Cause you burn with the brightest flame (yeah)<br><strong>  Vì "+"<b>"+name+"</b>"+" tỏa sáng rực rỡ",
"And the world's gonna know your name (yeah) <br><strong> Và cả thế giới sẽ biết đến danh tiếng của "+"<b>"+name+"</b>"+"",
"And you'll be on the walls of the hall of fame <br><strong>Và "+"<b>"+name+"</b>"+" sẽ được khắc ghi lên sảnh đường danh vọng",
"Be a champion <br><strong> Hãy là nhà vô địch",
"On the walls of the hall of fame<br><strong>  Trên sảnh đường danh vọng", 
"Be students, be teachers <br><strong> Hãy là những học sinh, là những giáo viên",
"Be politicians, be preachers<br><strong>  Là những nhà chính trị, là nhà thuyết giáo",
"Be believers, be leaders <br><strong> Hãy là những tín đồ, là những người lãnh đạo",
"Be astronauts, be champions<br><strong>  Là những nhà du hành vũ trụ, là những nhà vô địch", 
"Be true seekers<br><strong>  Hãy là những người ngay thẳng",
"Be students, be teachers <br><strong> Hãy là những học sinh, là những giáo viên",
"Be politicians, be preach"];
var luot = 0;
var gio = [1000, 9000,15000, 22000, 24000, 25000, 28000, 30000, 31000, 34000, 36000, 38000, 39000, 40000, 41000, 42000, 44000, 49000, 54000, 60000, 64000, 68000, 69000, 71000, 73000, 74000, 75000, 78000, 80000, 81000, 84000, 85000, 87000, 88000, 94000, 99000, 105000, 110000, 124000, 126000, 130000, 132000, 134000, 136000, 138000]
var i = 1;
for (let time of gio)
{
setTimeout(function (){
document.getElementById("quote").innerHTML = loibaihat[luot++];
},gio[i++]); 
}
});



//countdown//
var countDownDate = new Date("1, 20, 2022 5:55:55").getTime();

// Update the count down every 1 second
var x = setInterval(function() {

  // Get today's date and time
  var now = new Date().getTime();

  // Find the distance between now and the count down date
  var distance = countDownDate - now;

  // Time calculations for days, hours, minutes and seconds
  var days = Math.floor(distance / (1000 * 60 * 60 * 24));
  var hours = Math.floor((distance % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
  var minutes = Math.floor((distance % (1000 * 60 * 60)) / (1000 * 60));
  var seconds = Math.floor((distance % (1000 * 60)) / 1000);

  // Display the result in the element with id="demo"
  document.getElementById("time").innerHTML = "Còn " + days + " Ngày " + hours + " Giờ "
  + minutes + " Phút " + seconds + " Giây "+" Coming";

  // If the count down is finished, write some text
  if (distance < 0) {
    clearInterval(x);
    document.getElementById("time").innerHTML = "EXPIRED";
  }
}, 1000);

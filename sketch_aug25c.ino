
#include <U8g2lib.h>
#include <WiFi.h>
#include <time.h>
const char* ssid="WWLLAANN";

const char* password="11223344";

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE, /* clock=*/ 9, /* data=*/ 8);  //屏幕标识符 屏幕的名称（一些定义）


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println();
  Serial.println("******************************************************");
  Serial.print("Connecting to ");
  Serial.println(ssid);
WiFi.begin(ssid, password);  //把wifi账号密码传给c3的wifi模块让它去和路由器交互

  while (WiFi.status() != WL_CONNECTED) {

    delay(500);

    Serial.print(".");

  }

  Serial.println("");

  Serial.println("WiFi connected");

  Serial.println("IP address: ");

  Serial.println(WiFi.localIP());

//以上是让ESP32连接到wifi的操作

  u8g2.begin(); //是初始化 OLED 屏幕，让屏幕进入可以接收显示数据的状态

  configTime(28800, 0, "pool.ntp.org");
}

void loop() {
  struct tm timeinfo;
getLocalTime(&timeinfo);

char timeStr[9];  //定义一个字符串装时间：10:11:10

strftime(timeStr, sizeof(timeStr), "%H:%M:%S", &timeinfo);

u8g2.clearBuffer();                 // 清空缓存  //把timeinfo转化为字符串结果写入timeStr

u8g2.setFont(u8g2_font_ncenB18_tf);
    
    u8g2.drawStr(5, 42, timeStr);

    u8g2.sendBuffer();


    
}

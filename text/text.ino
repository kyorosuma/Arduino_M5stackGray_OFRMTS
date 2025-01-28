#include <M5Stack.h>

void setup() {
    // M5Stackの初期化
    M5.begin();
    
    // LCDの背景色を黒に設定
    M5.Lcd.fillScreen(BLACK);
    
    // テキストの色を白に設定
    M5.Lcd.setTextColor(WHITE);
    
    // フォントサイズを設定
    M5.Lcd.setTextSize(2);
    
    // 画面の中央にテキストを表示
    M5.Lcd.setCursor(50, 100);
    M5.Lcd.print("Hello, M5Stack!");
}

void loop() {
    // ループ内では何もしない
}

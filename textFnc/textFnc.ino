#include <M5Stack.h>

// 文字列をLCDに表示する関数
void displayText(const char* text, int x, int y, uint16_t color, int size) {
    M5.Lcd.setTextColor(color);
    M5.Lcd.setTextSize(size);
    M5.Lcd.setCursor(x, y);
    M5.Lcd.print(text);
}

void setup() {
    M5.begin();
    M5.Lcd.fillScreen(BLACK);
    
    // 文字列を表示
    displayText("test", 50, 100, WHITE, 2); //日本語だと表示できないので注意
}

void loop() {
    // ループ内では何もしない
}

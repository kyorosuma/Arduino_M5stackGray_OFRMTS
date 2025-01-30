#include <M5Stack.h>

#define SENSOR_PIN 2  // GPIO2 にセンサを接続

void setup() {
    M5.begin();  
    M5.Lcd.setTextSize(2);
    M5.Lcd.setCursor(10, 20);
    M5.Lcd.print("Analog Read:");

    pinMode(SENSOR_PIN, INPUT); // GPIO2 を入力モードに設定
}

void loop() {
    int sensorValue = analogRead(SENSOR_PIN); // GPIO2 からアナログ値を取得

    // LCD に値を表示
    M5.Lcd.setCursor(10, 50);
    M5.Lcd.fillRect(10, 50, 150, 30, BLACK); // 前の値を消去
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.print(sensorValue);

    delay(500); // 500msごとに更新
}

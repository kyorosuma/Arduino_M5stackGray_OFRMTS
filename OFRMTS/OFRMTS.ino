#include <M5Stack.h>

#define SENSOR_PIN 2  // GPIO2 にセンサを接続
#define BUZZER_PIN 25  // M5Stack Gray のブザーは GPIO 25 に接続
#define BUZZER_CHANNEL 0  // ESP32 の PWM チャンネルを指定

// 文字列をLCDに表示する関数
void displayText(const char* text, int x, int y, uint16_t color, int size) {
    M5.Lcd.setTextColor(color);
    M5.Lcd.setTextSize(size);
    M5.Lcd.setCursor(x, y);
    M5.Lcd.print(text);
}

// 数値をLCDに表示する関数
void displayNumber(int number, int x, int y, uint16_t color, int size) {
    M5.Lcd.setTextColor(color);
    M5.Lcd.setTextSize(size);
    M5.Lcd.setCursor(x, y);
    M5.Lcd.fillRect(x, y, 100, 20, BLACK); // 前の数値を消去
    M5.Lcd.print(number);
}

// 周波数 Hz で音を鳴らし、指定時間 ms だけ維持する関数
void playTone(int frequency, int duration) {
    ledcSetup(BUZZER_CHANNEL, frequency, 8);   // 8-bit PWM で設定
    ledcAttachPin(BUZZER_PIN, BUZZER_CHANNEL); // GPIO 25 に PWM を割り当て
    ledcWriteTone(BUZZER_CHANNEL, frequency);  // 指定した周波数で音を鳴らす
    delay(duration);
    ledcWriteTone(BUZZER_CHANNEL, 0);          // 音を停止
}

void setup() {
    M5.begin();
    M5.Lcd.fillScreen(BLACK);
    
    // 文字列を表示
    displayText("Analog Read:", 50, 100, WHITE, 2);
}

void loop() {
    int sensorValue = analogRead(SENSOR_PIN);
    displayNumber(sensorValue, 50, 120, WHITE, 2);
    
    if (sensorValue >= 1000) {
        playTone(1000, 500); // 1000Hzの音を500ms鳴らす
        displayText("Sound ON", 50, 140, WHITE, 2);
    } else {
        displayText("Sound OFF", 50, 140, WHITE, 2);
        playTone(0, 0); // 1000Hzの音を500ms鳴らす
    }
    delay(500);
}

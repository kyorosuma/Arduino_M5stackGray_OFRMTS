#include <M5Stack.h>

#define BUZZER_PIN 25  // M5Stack Gray のブザーは GPIO 25 に接続
#define BUZZER_CHANNEL 0  // ESP32 の PWM チャンネルを指定

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
    M5.Lcd.setTextSize(2);
    M5.Lcd.setCursor(10, 50);
    M5.Lcd.print("Playing Sound...");

    // 1000Hz の音を 500ms 鳴らす
    playTone(1000, 500);
}

void loop() {
    delay(3000);          // 3秒待機
    playTone(1500, 500);  // 1500Hz の音を 500ms 鳴らす
}

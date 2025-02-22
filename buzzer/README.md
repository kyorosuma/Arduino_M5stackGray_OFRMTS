【設計書】

■ 基本設計  
概要: このプログラムは、Arduino IDEで記述されたC++コードを解析し、各関数の役割をまとめた設計書を生成するシステムです。  
入力: Arduino用C++コード（.inoまたは.cppファイル）  
出力: README.md形式の設計書  
使用技術: Arduino, C/C++  
主要ライブラリ: Arduino標準ライブラリ, M5Stackライブラリ  など

■ 詳細設計  
【関数一覧】  
- setup: Arduinoの初期設定を行う関数。M5Stackの初期化やLCDの設定を行う。
- playTone: 指定された周波数と時間で音を鳴らす関数。PWMを使用してブザーを制御する。
- loop: メインの処理ループ。一定時間待機後に指定された周波数で音を鳴らす。

【クラス一覧】  
（該当するクラスがあれば記載）

ロジックのフロー図:
```
+---------------------+
|      開始           |
+---------------------+
          |
          v
       setup()
          |
          v
   +--------------+
   |     loop()   |
   +--------------+
          |
          v
       playTone()
          |
          v
   +--------------+
   |     loop()   |
   +--------------+
          |
          v
+---------------------+
|        終了         |
+---------------------+
```
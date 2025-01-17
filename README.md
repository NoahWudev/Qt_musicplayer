# Qt Music Player

## 概述

Qt Music Player 是一個基於 Qt 6.7.1 框架開發的音樂播放器應用程序。該應用程序使用 Model-View-Controller (MVC) 架構設計，提供了簡潔的用戶界面和基本的音樂播放功能。

## 功能特點

- 音頻文件播放：支持常見的音頻格式（如 MP3、WAV）
- 基本播放控制：播放、暫停、停止
- 進度控制：可拖動進度條調整播放位置
- 實時顯示：當前播放時間和總時長
- 文件選擇：允許用戶選擇音訊檔案

## 專案結構

該專案遵照 MVC 架構，主要包含以下組件：

### Model

`AudioModel` 類 負責核心的音訊處理邏輯：

- 使用 `QMediaPlayer` 管理音訊播放
- 提供音訊加載、播放控制和狀態查詢功能
- 發送音訊狀態變化的信號（如持續時間、播放位置變化）

### View

`PlayerView` 類 處理user interface：

- 包含播放控制按鈕、進度條和時間顯示
- 提供文件選擇功能
- 負責更新 UI 以反映當前播放狀態

### Controller

`PlayerController` 類 協調 Model 和 View 之間的溝通互動：

- 處理UI的輸入動作（如按鈕點擊、進度條調整）
- 更新 Model 狀態
- 將 Model 的變化傳送到到 View 上

### MainWindow

`MainWindow` 類 作為應用程序的主視窗，整合了 MVC 的各個部位。

## 關鍵類別關係

- `MainWindow` 創建並管理 `AudioModel`、`PlayerView` 和 `PlayerController` 的實體
- `PlayerController` 包含 `AudioModel` 和 `PlayerView` 的引用，負責它們之間的通信
- `AudioModel` 和 `PlayerView` 通過 Signal & Slot 機制與 `PlayerController` 互動，保持低耦合

## 技術細節

- 開發框架：Qt 6.7.1
- 編程語言：C++
- 音訊後端：QMediaPlayer
- 版本控制：Git

## 安裝和運行

1. 確保您的系統已安裝 Qt 6.7.1 或更高版本
2. Clone 此儲存庫：
   ```
   git clone https://github.com/yourusername/qt-music-player.git
   ```
3. 使用 Qt Creator 打開專案文件 (.pro)
4. 編譯並執行專案
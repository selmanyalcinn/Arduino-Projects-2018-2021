# 🚭 Smoking Addiction Reduction & ❤️ Heart Health Monitoring with Smartwatches

## 📖 Project Summary

This project aims to combat smoking addiction and monitor heart health using smartwatches. Smartwatches are typically worn throughout the day, making them valuable tools for addiction management and health tracking. The project supports two quitting approaches:

✅ **Cold Turkey**  
✅ **Gradual Reduction**

Users can choose their quitting method via the smartwatch screen. 🚀

👨‍⚕️👩‍⚕️ Family members and doctors can also track smoking habits and offer support. Friendly competitions through the app (like “who smoked less today?”) motivate users further!

Smoke detection leverages **MQ-2 gas sensors**, while **heart rate monitoring** uses a pulse sensor. 📈 The app visualizes daily, weekly, and monthly heart rate trends and abnormal values for early detection of heart-related issues (and even other health concerns like depression).

---

## 🎯 Project Objective

🩺 Use smartwatches to fight addiction and monitor heart health!  
Previous projects had about **85% accuracy** (heart rate only). We boosted accuracy by adding smoke sensor data!  
Unlike past projects, we also **calculate heart rate averages** for long-term health monitoring.

---

## 📝 Introduction

🚀 We started by studying previous works that only used heart rate changes for smoking detection, but heart rate can change due to exercise, stress, etc.

💡 **Our improvement**:  
✔️ Integrated smoke sensor data  
✔️ Enabled long-term heart health tracking

---

## 🔧 Methodology

### 👥 Participants

- 2 middle-aged male smokers
- Additional data from the internet and various cigarette brands

### 🛠️ Experimental Setup

- **Display**: 1.7-inch TFT ST7735 screen
- **Buttons**: 3 physical buttons (with 22kΩ resistors)
- **MCU**: Arduino UNO
- **Wireless**: NodeMCU (serial pins 5 & 6) for Firebase integration
- **App**: MIT App Inventor
- **Database**: Firebase
- **Sensors**:
  - Heart Rate Sensor: Grove Pulse Sensor (Seeed Studio) 💓
  - Smoke Sensor: MQ-2 Gas Sensor 🌫️

### 🏫 Environment

Tests were conducted in a large, ventilated indoor environment (school ground floor). Each experiment lasted 6–7 minutes (a cigarette’s burn time).

### 🧮 Data Analysis

Arduino code (C++):

- Smoke sensor ≥ 150
- Heart rate ≥ 85 BPM  
  ➡️ **Smoking detected**

Graphs and figures highlight the clear changes in sensor readings during smoking vs. non-smoking. 📊

---

## 📈 Results & Discussion

✔️ Accurate smoking detection and display of data in the app  
✔️ Supports “Cold Turkey” and “Gradual Reduction” programs  
✔️ Family and doctor support integrated  
✔️ Friendly competitions with friends through the app  
✔️ Potential early detection of heart diseases

⚠️ **Limitation**: Sensors continuously running = higher power consumption 🔋  
Future: Use energy-efficient sensors & bigger smartwatch batteries!

---

## 💻 Arduino Code Overview

Main libraries used:

```cpp
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Adafruit_ST7789.h>
#include <Wire.h>
#include <SoftwareSerial.h>
```

## 🏗️ Key Functionalities

✅ Menu navigation & data input with 3 buttons
✅ Smoke & heart rate detection
✅ Heart rate averaging
✅ Daily cigarette count
✅ Data sent to NodeMCU for Firebase upload
✅ Visual data in the app

📂 Check the full Arduino code in smartWatchCode.ino.

## 🚀 Getting Started

🔌 Hardware Setup: Follow the wiring diagram.

🖥️ Upload the code to your Arduino UNO.

🌐 Connect NodeMCU to Firebase.

📲 Build the app in MIT App Inventor.

🏁 Start tracking your smoking habits and heart health!

## 💡 Future Work
Reduce sensor energy usage 🔋

Enhance app graphs and visualizations 📊

Test with a wider range of users 🌍

AI predictions for heart disease risks 🤖

## 📜 License
This project is licensed under the MIT License.

## 🤝 Contact
For questions or collaborations, feel free to open an issue or contact me directly!

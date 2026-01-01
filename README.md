# 🌱 Irrigation Controller (Single Zone & Dual Zone)

کنترلر آبیاری مبتنی بر آردوینو با پشتیبانی از **یک زون** و **دو زون**  
Arduino-based irrigation controller supporting **single-zone** and **dual-zone** operation.

---

## 📌 Supported Hardware
- Arduino UNO / Nano
- 16x2 LCD (4-bit mode)
- Soil moisture / water level sensors (e.g. YL69)
- Relay modules / solenoid valves
- Push buttons
- Buzzer

---

# 🔹 Single Zone Version – Pinout
## نسخه تک‌زون – پین‌ها

### 📥 Inputs | ورودی‌ها

| Arduino Pin | Type | Description | توضیح |
|------------|------|-------------|-------|
| A0 | Analog Input | Soil / water level sensor | سنسور رطوبت خاک / سطح آب |
| D8 | Digital Input (INPUT_PULLUP) | Increase SET level | افزایش مقدار SET |
| D9 | Digital Input (INPUT_PULLUP) | Decrease SET level | کاهش مقدار SET |

---

### 📤 Outputs | خروجی‌ها

| Arduino Pin | Type | Description | توضیح |
|------------|------|-------------|-------|
| D10 | Digital Output | Buzzer (button feedback) | بیزر هنگام فشردن دکمه |
| D11 | Digital Output | Relay / Solenoid valve (Zone 1) | رله / شیر برقی زون 1 |

---

### 🖥 LCD 16x2 (4-bit Mode)

| LCD Pin | Arduino Pin |
|-------|-------------|
| RS | D7 |
| E  | D6 |
| D4 | D5 |
| D5 | D4 |
| D6 | D3 |
| D7 | D2 |

---

# 🔹 Dual Zone Version – Pinout
## نسخه دو‌زون – پین‌ها

### 📥 Inputs | ورودی‌ها

| Arduino Pin | Type | Description | توضیح |
|------------|------|-------------|-------|
| A0 | Analog Input | Sensor – Zone 1 | سنسور زون 1 |
| A1 | Analog Input | Sensor – Zone 2 | سنسور زون 2 |
| D8 | Digital Input (INPUT_PULLUP) | Zone 1 SET + | افزایش SET زون 1 |
| D9 | Digital Input (INPUT_PULLUP) | Zone 1 SET − | کاهش SET زون 1 |
| D12 | Digital Input (INPUT_PULLUP) | Zone 2 SET + | افزایش SET زون 2 |
| D13 | Digital Input (INPUT_PULLUP) | Zone 2 SET − | کاهش SET زون 2 |

---

### 📤 Outputs | خروجی‌ها

| Arduino Pin | Type | Description | توضیح |
|------------|------|-------------|-------|
| D10 | Digital Output | Buzzer (shared) | بیزر مشترک |
| D11 | Digital Output | Relay / Solenoid valve – Zone 1 | رله / شیر برقی زون 1 |
| D0  | Digital Output | Relay / Solenoid valve – Zone 2 | رله / شیر برقی زون 2 |

---

### 🖥 LCD 16x2 (Shared)

| LCD Pin | Arduino Pin |
|-------|-------------|
| RS | D7 |
| E  | D6 |
| D4 | D5 |
| D5 | D4 |
| D6 | D3 |
| D7 | D2 |


schematic tow zone👇
![not image](https://github.com/Mohammadhosseinmoeinzadeh/intelligent-irrigation/blob/main/data%20sheet.png)

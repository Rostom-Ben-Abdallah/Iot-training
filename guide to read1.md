
### **Setting Up Your ESP32 with Arduino IDE**

Follow these quick steps to get your ESP32 ready for action:

---

### **Step 1: Add the ESP32 Board Manager URL**
1. Open the Arduino IDE.  
2. Go to **File > Preferences**.  
3. In the **Additional Board Manager URLs** field, paste this link:  
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```
4. Click **OK**.

---

### **Step 2: Install the Necessary Driver**
1. Check your ESP32 board to see if it uses the **CP2102** or **CH340** driver.  
   - Download **CP2102** driver: [Link](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers)  
   - Download **CH340** driver: [Link](https://sparks.gogo.co.nz/ch340.html)  
2. Install the driver to enable communication between your computer and the ESP32.

---

### **Step 3: Install the ESP32 Board in Arduino IDE**
1. Go to **Tools > Board > Boards Manager**.  
2. Search for "**ESP32**."  
3. Click **Install** for "**ESP32 by Espressif Systems**."

---

### **Step 4: Select Your Board**
1. Go to **Tools > Board > ESP32 Arduino**.  
2. Choose "**ESP32 Dev Module**."

---

Now your setup is ready! You can start programming your ESP32 board with Arduino IDE.

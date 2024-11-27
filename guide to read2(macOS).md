### IoT Training Session 2: Mosquitto MQTT Broker on macOS

---

# IoT Training Session 2
Welcome to the **IoT Training Session**! In this guide, you will learn how to set up and test **Mosquitto MQTT Broker** on a Mac.

---

## **1. Installing Mosquitto MQTT Broker (macOS)**  

### **Prerequisites**
Ensure you have **Homebrew** installed on your Mac. If not, install it using the following command in the terminal:
```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

### **Installation Steps**
1. Open a terminal.
2. Install Mosquitto using Homebrew:
   ```bash
   brew install mosquitto
   ```
3. Start the Mosquitto service:
   ```bash
   brew services start mosquitto
   ```
4. Verify the installation by checking the Mosquitto version:
   ```bash
   mosquitto -v
   ```
   This command should show the version of Mosquitto running on your system.

---

## **2. Configuring Mosquitto**

### **Locate the Configuration File**
The Mosquitto configuration file is located at:
```bash
/usr/local/etc/mosquitto/mosquitto.conf
```

### **Modify the Configuration**
1. Open the configuration file in a text editor:
   ```bash
   nano /usr/local/etc/mosquitto/mosquitto.conf
   ```
2. Add the following lines to allow anonymous access and listen on port 1883:
   ```plaintext
   listener 1883
   allow_anonymous true
   ```
3. Save the file (`Ctrl+O`, `Enter`) and exit (`Ctrl+X`).

### **Restart Mosquitto Service**
After modifying the configuration, restart the Mosquitto service:
```bash
brew services restart mosquitto
```

---

## **3. Running Mosquitto Broker**

### **Verify the Mosquitto Service**
1. Ensure Mosquitto is running:
   ```bash
   brew services list
   ```
   - Look for the Mosquitto service; it should show as "started."

2. Alternatively, run Mosquitto manually in verbose mode to see the logs:
   ```bash
   mosquitto -v
   ```

---

## **4. Testing the MQTT Broker**

### **Step 1: Find Your IP Address**
If you're not using `localhost`, find your broker's IP address:
1. Run the following command to get your IP address:
   ```bash
   ifconfig
   ```
2. Look for your **IPv4 address** under your network adapter (e.g., `192.168.x.x`).

---

### **Step 2: Subscribe to a Topic**
1. Open a terminal and subscribe to a topic:
   - Using `localhost`:
     ```bash
     mosquitto_sub -h localhost -t "test/topic"
     ```
   - Using your **IP address**:
     ```bash
     mosquitto_sub -h 192.168.x.x -t "test/topic"
     ```

---

### **Step 3: Publish a Message**
2. Open another terminal and publish a message to the same topic:
   - Using `localhost`:
     ```bash
     mosquitto_pub -h localhost -t "test/topic" -m "Hello, MQTT!"
     ```
   - Using your **IP address**:
     ```bash
     mosquitto_pub -h 192.168.x.x -t "test/topic" -m "Hello, MQTT!"
     ```

---

### **5. Notes and Best Practices**
- Ensure the **IP address** and **topic name** match between the publisher and subscriber.
- To retain a message, use the `-r` flag when publishing:
  ```bash
  mosquitto_pub -h localhost -t "test/topic" -m "Retained message" -r
  ```
- To verify logs, run Mosquitto in verbose mode:
  ```bash
  mosquitto -v
  ```

---

### **6. Troubleshooting**
1. If Mosquitto fails to start, check its logs by running:
   ```bash
   brew services log mosquitto
   ```
2. Ensure the configuration file (`/usr/local/etc/mosquitto/mosquitto.conf`) is correctly formatted and saved.
3. Check if port 1883 is open and accessible:
   ```bash
   sudo lsof -i -P -n | grep mosquitto
   ```
4. Restart the Mosquitto service if needed:
   ```bash
   brew services restart mosquitto
   ```

---


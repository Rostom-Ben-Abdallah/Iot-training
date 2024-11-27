### IoT Training Session 2: Mosquitto MQTT Broker on Ubuntu

---

# IoT Training Session 2
Welcome to the **IoT Training Session**! In this guide, you will learn how to set up and test **Mosquitto MQTT Broker** on an Ubuntu system.

---

## **1. Installing Mosquitto MQTT Broker (Ubuntu)**  

### **Installation Steps**
1. Open a terminal.
2. Update the package list:
   ```bash
   sudo apt update
   ```
3. Install Mosquitto and the Mosquitto clients:
   ```bash
   sudo apt install mosquitto mosquitto-clients -y
   ```
4. Enable and start the Mosquitto service:
   ```bash
   sudo systemctl enable mosquitto
   sudo systemctl start mosquitto
   ```
5. Verify installation by checking the Mosquitto version:
   ```bash
   mosquitto -v
   ```

---

## **2. Configuring Mosquitto**  

### **Locate the Configuration File**  
The configuration file is located at:  
```bash
/etc/mosquitto/mosquitto.conf
```

### **Modify the Configuration**  
1. Open the configuration file in a text editor:
   ```bash
   sudo nano /etc/mosquitto/mosquitto.conf
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
sudo systemctl restart mosquitto
```

---

## **3. Running Mosquitto Broker**  

### **Verify the Mosquitto Service**
1. Check if the Mosquitto service is running:
   ```bash
   sudo systemctl status mosquitto
   ```
   - You should see "active (running)" in the output.

---

## **4. Testing the MQTT Broker**  

### **Step 1: Find Your IP Address**
If you're not using `localhost`, find your broker's IP address:
1. Run the following command to get your IP address:
   ```bash
   ip a
   ```
2. Look for your **IPv4 address** under your network adapter (e.g., `192.168.x.x`).

---

### **Step 2: Subscribe to a Topic**  
In the first terminal window, subscribe to a topic using the following command:
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
In a second terminal window, publish a message to the same topic:
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
- Ensure the **IP address** and **topic name** are consistent across commands.
- To retain messages, use the `-r` flag when publishing:
  ```bash
  mosquitto_pub -h localhost -t "test/topic" -m "Retained message" -r
  ```
- Check the connection by ensuring the message appears in the subscribed terminal.

---

### **6. Troubleshooting**  
1. If the Mosquitto service does not start, check the logs:
   ```bash
   sudo journalctl -u mosquitto
   ```
2. Ensure the configuration file (`/etc/mosquitto/mosquitto.conf`) is saved correctly and formatted properly.
3. Verify port 1883 is open and not blocked by your firewall:
   ```bash
   sudo ufw allow 1883
   ```

---

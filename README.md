# Iot-training
**************************** To install mosquitto: windows ****************************

mosquitto-2.0.18-install-windows-x64.exe [https://mosquitto.org/files/binary/win64/mosquitto-2.0.18-install-windows-x64.exe] (64-bit build, Windows Vista and up, built with Visual Studio Community 2019)

mosquitto-2.0.18-install-windows-x32.exe [https://mosquitto.org/files/binary/win32/mosquitto-2.0.18-install-windows-x86.exe] (32-bit build, Windows Vista and up, built with Visual Studio Community 2019)

run the installer
**************************** mosquitto config example ****************************

listener 1883

allow_anonymous true

******************************************************************************
run command prompt as administrator

cd c:\program files\mosquitto

net start mosquitto

Verify the Installation: mosquitto -v

Testing the Broker:

cmd1: mosquitto_sub -h localhost -t test/topic

cmd2: mosquitto_pub -h localhost -t test/topic -m "Hello, MQTT!"

mosquitto config file:

C:\Program Files\mosquitto\mosquitto.conf


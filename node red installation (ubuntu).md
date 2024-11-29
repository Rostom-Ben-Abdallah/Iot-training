# Guide to Install Node-RED on Ubuntu

This guide provides step-by-step instructions for students to install and run Node-RED on an Ubuntu system. Follow these steps to set up Node-RED in a Linux environment.

---

## Step 1: Install Node.js
1. **Update Your System**:
   Open a terminal and update your system's package list:
   ```bash
   sudo apt update && sudo apt upgrade -y
   ```

2. **Install Node.js**:
   Use the Node.js package manager to install the LTS version of Node.js:

   - Download and install the Node.js repository setup script:
     ```bash
     curl -fsSL https://deb.nodesource.com/setup_lts.x | sudo -E bash -
     ```

   - Install Node.js:
     ```bash
     sudo apt install -y nodejs
     ```

3. **Verify Installation**:
   Check the installed versions of Node.js and npm:
   ```bash
   node --version
   npm --version
   ```
   Example output:
   ```
   v18.15.0
   9.5.0
   ```

---

## Step 2: Install Node-RED
1. **Install Node-RED Globally**:
   Run the following command to install Node-RED as a global npm module:
   ```bash
   sudo npm install -g --unsafe-perm node-red
   ```

2. **Verify Installation**:
   Ensure the Node-RED command is accessible:
   ```bash
   node-red --help
   ```

---

## Step 3: Run Node-RED
1. **Start Node-RED**:
   Launch Node-RED using the terminal:
   ```bash
   node-red
   ```

2. **Access the Editor**:
   Once Node-RED starts, it will provide a URL in the terminal (usually `http://127.0.0.1:1880`). Open this URL in your browser to access the Node-RED editor.

---

**Note**: For troubleshooting and additional help, refer to the official [Node-RED Documentation](https://nodered.org/docs/getting-started/).

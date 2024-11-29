# Guide to Install Node-RED on Windows

This guide provides direct steps to install Node-RED on a Windows system, suitable for students. Follow these instructions to set up Node-RED using PowerShell or Command Prompt.

---

## Step 1: Install Node.js
1. **Download Node.js**:
   - Visit the official Node.js website: [Node.js Downloads](https://nodejs.org/)
   - Download the **LTS version** (recommended for most users).

2. **Install Node.js**:
   - Run the downloaded `.msi` installer.
   - Follow the installation wizard, accepting the default options.
   - Administrator rights are required; you may need to provide the administrator password.

3. **Verify Installation**:
   - Close and reopen your terminal (PowerShell is recommended).
   - Run the following commands:
     - Using **PowerShell**: 
       ```bash
       node --version; npm --version
       ```
     - Using **cmd**: 
       ```bash
       node --version && npm --version
       ```
   - Example output:
     ```
     v18.15.0
     9.5.0
     ```

---

## Step 2: Install Node-RED
1. Open your terminal (PowerShell or cmd).
2. Run the following command to install Node-RED globally:
   ```bash
   npm install -g --unsafe-perm node-red
   ```

---

## Step 3: Run Node-RED
1. Start Node-RED by running:
   ```bash
   node-red
   ```
2. After starting, open your browser and navigate to:
   ```
   http://"your ip adress":1880
   ```
   This will open the Node-RED editor.

---

**Note**: If you encounter any errors or require additional help, refer to the official [Node-RED Documentation](https://nodered.org/docs/getting-started/).

# Serial Data Visualizer

Serial Data Visualizer is a Qt-based desktop application designed to read, visualize, and process serial data sent via an ESP32 device. The application supports data visualization through charts, raw data display, and features like data validation and serial connection management.

---

## Repository Structure
This repository is organized into five main folders:

### 1. `documentation`
Contains user guides and design reflections:
- **`README.md`**: Complete user guidelines for the application.
- **`design_reflection`**: A report on design decisions, challenges faced, and lessons learned.

### 2. `installer`
Includes files for creating and running application installers:
- **Windows**:
  - `serial_data_visualizer_qt.exe`: Pre-built application.
  - `SerialDataVisualizerSetup.exe`: Windows installer.
- **Ubuntu**:
  - `serial_data_ubuntu.deb`: Debian package installer.
  - `serial_data_ubuntu`: Pre-built binary for Ubuntu.

### 3. `serial_data_visualizer_qt (Windows)`
Source code for the Windows version of the application:
- **`headers`**: Class interface definitions.
- **`sources`**: Implementation files.
- **`ui`**: UI files created with Qt Designer.
- **`resources`**: Icons and other assets.
- **`serial_data_visualizer_qt.pro`**: Qt Creator project file.

### 4. `serial_data_visualizer_ubuntu (Linux)`
Source code for the Linux version of the application:
- Same structure as the Windows folder, tailored for Linux environments.

### 5. `serial_port_device`
Code for simulating serial communication and testing:
- **`esp32_serial_data_simulation`**: ESP32-based simulation code.
- **`serial_data_code_test`**: Code for testing serial communication.

---

## Implementation Workflow
Follow these steps to implement and use the application:

### Step 1: Setting Up the Desktop Application
- For **Windows**, use the `serial_data_visualizer_qt` folder.
- For **Linux**, use the `serial_data_visualizer_ubuntu` folder.
- Refer to the respective README in each folder for detailed setup instructions.

### Step 2: Setting Up the Serial Device
- Go to the `serial_port_device` folder.
- Follow the instructions in the README to configure and run the ESP32 device.

### Step 3: Using the Installer
- Navigate to the `installer` folder.
- Use the provided pre-built installers or follow the README to build one for your platform.

---

## Usage Guidelines
1. Run the application through Qt Creator or the provided installer.
2. Connect the ESP32 device to your computer via a USB cable.
3. Select the serial port and baudrate from the dropdown menu in the application.
4. Click **Connect** to establish a connection between the application and the device.
5. Click **Start** to begin receiving and visualizing data.
6. Click **View Raw Data** to display raw incoming data.
7. Click **Stop** to stop the data streaming process.
8. Use **Clear** to reset the data display.

For detailed usage instructions, refer to the `documentation` folder.

---

## Important Notes
- Ensure Qt Creator is installed and properly configured for your operating system.
- For serial data simulation, make sure the ESP32 is flashed with the code in the `esp32_serial_data_simulation` folder.
- If you prefer not to install Qt Creator, you can use the pre-built installer in the `installer` folder.

For more details, refer to the README in the respective folder.

# Serial Data Visualizer

Serial Data Visualizer is a Qt Creator-based desktop application designed to read, visualize, and process serial data sent via an ESP32 device. The application supports data visualization through charts, raw data display, and features like data validation and serial connection management.

## Repository Structure
This repository contains four main folders:

### 1. `documentation`
This folder contains filers for documentaion user guidelines the application and design reflection for the system, including:
- **`README.md`**: Complete user guidelines for feature of the application
- **`design_reflection`**: A brief report on design decisions, challenges faced, and main learnings from the project. 

### 2. `installer`
This folder contains files for creating the application installer, including:
- **`installer.nsi`**: NSIS configuration script for building the installer.
- **`SerialDataVisualizerSetup.exe`**: The generated executable installer.

### 3. `serial_data_visualizer_qt`
This folder contains all source code for the desktop application, including:
- **`headers`**: Header files defining class interfaces.
- **`sources`**: Implementations of the header files.
- **`ui`**: User interface files created using Qt Designer.
- **`resources`**: Resource files such as icons or graphics.
- **`serial_data_visualizer_qt.pro`**: Qt Creator project file for configuring the build.

### 4. `serial_port_device`
This folder contains code and simulations related to the ESP32 device, including:
- **`esp32_serial_data_simulation`**: Code for simulating serial data on the ESP32.
- **`serial_data_code_test`**: Code for testing serial communication.

## Implementation Workflow
Follow these steps to implement and run the application:

### 1. Setting Up the Desktop Application
- Navigate to the `serial_data_visualizer_qt` folder.
- Follow the instructions in the README inside this folder to build and run the application using Qt Creator.

### 2. Setting Up the Serial Device
- Navigate to the `serial_port_device` folder.
- Follow the README in this folder to configure and run serial data simulation using the ESP32.

### 3. Creating the Application Installer
- Navigate to the `installer` folder.
- Follow the README in this folder to build the installer using NSIS or run the existing installer.

## Usage Guidelines
1. Run the application through Qt Creator or the created installer.
2. Connect the ESP32 device to your computer via a USB cable.
3. Select the serial port and baudrate from the dropdown menu in the application.
4. Click **Connect** to establish a connection between the application and the device.
5. Click **Start** to begin receiving and visualizing data.
6. Click **View Raw Data** to display raw incoming data.
7. Click **Stop** to stop the data streaming process.
8. Use **Clear** to clear the data display.

For further details on each step, refer to the README in `documentation` folder.

## Important Notes
- Ensure that Qt Creator and NSIS are installed on your system.
- For serial data simulation, make sure the ESP32 is flashed with code from the `esp32_serial_data_simulation` folder.
- If you don't want to **install QT Creator** but want to try the **application directly**, please visit the installer folder to install the application directly without installing QT Creator.

For further details on each step, refer to the README in the respective folder.


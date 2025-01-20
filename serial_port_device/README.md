# Serial Port Device

This folder contains code for the ESP32 board to simulate serial data, which is essential for the Serial Data Visualizer application. Follow the instructions below to set up and use this code effectively.

---

## Prerequisites
Before proceeding, ensure that the Serial Data Visualizer application is installed or built. Follow one of these options:
- If you are building the application manually:
  - Navigate to the **`serial_data_visualizer_qt`** folder (for Windows OS) or the **`serial_data_visualizer_ubuntu`** folder (for Ubuntu/Linux OS) and follow the build instructions in the respective README.
- If you prefer to use the pre-built application:
  - Go to the **`installer`** folder and install the application directly (available for both Windows and Ubuntu/Linux).

---

## Folder Structure
This folder contains the following subfolders:
1. **`esp32_serial_data_simulation`**: Contains code for simulating serial data on the ESP32 board.
2. **`serial_data_code_test`**: Includes additional testing code for serial communication.

---

## Setting Up the ESP32 Board
To simulate serial data using the ESP32, follow these steps:

1. **Install the Arduino IDE**  
   - Download and install the Arduino IDE if it is not already installed on your system.

2. **Set Up ESP32 Board Package**  
   - Ensure that the necessary ESP32 board package is installed in the Arduino IDE. You can refer to the official ESP32 documentation for setup instructions.

3. **Open the Simulation Code**  
   - Open the code from the **`esp32_serial_data_simulation`** folder in the Arduino IDE.

4. **Connect the ESP32 Board**  
   - Use a USB cable to connect your ESP32 or Arduino board to your computer.

5. **Flash the Code**  
   - Select the correct **board** and **port** in the Arduino IDE.
   - Click the **Upload** button to flash the code onto the ESP32 board.

---

## Next Steps
Once the ESP32 board is successfully flashed:
- Connect the board to the Serial Data Visualizer application.
- Refer to the **documentation** folder in the main repository for step-by-step instructions on how to use the application effectively.

---

## Additional Notes
- Ensure your ESP32 board is properly configured and powered during the setup process.
- Use the **`serial_data_code_test`** folder for testing and debugging serial communication before running the full application.

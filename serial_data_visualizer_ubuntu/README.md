# Serial Data Visualizer Ubuntu

This folder contains all the necessary files for building, running, and using the Serial Data Visualizer desktop application on Ubuntu. Below are the instructions to set up the environment, install dependencies, and run the application.

---

## Flow Overview
To successfully run this project, follow these steps:

### 1. Install Dependencies
Ensure the following dependencies are installed on your system:
- **Qt 6.2.4 or newer**
- **GCC (g++) or Clang**
- **Required Qt Modules**:
  - **Qt Charts**
  - **Qt Serial Port**

Run the following command to install the necessary dependencies:
```bash
sudo apt update
sudo apt install libqt6core6 libqt6widgets6 libqt6charts6 libqt6serialport6 build-essential
```

### 2. Clone the Repository
Clone the repository containing this folder using the following command:
```bash
git clone git@github.com:avivsabilal29/Serial-Data-Visualizer-.git
```
Navigate to the `serial_data_visualizer_ubuntu` folder:
```bash
cd Serial-Data-Visualizer-/installer/serial_data_ubuntu
```

### 3. Run the Pre-Built Binary
To quickly use the application without building it, run the pre-built binary:
```bash
./serial_data_visualizer_ubuntu
```
Ensure that the required permissions are set for the serial port. You can add your user to the dialout group to avoid permission issues:
```bash
sudo usermod -a -G dialout $USER
```
Logout and log back in for the changes to take effect.

### 4. Building the Application (Optional)
If you prefer to build the application yourself, ensure you have the Qt development tools installed.

1. Please install qt development tools by following this link:
    ```bash
    https://wiki.qt.io/Install_Qt_5_on_Ubuntu
    ```

2. Open the project in Qt Creator:
    - Navigate to the `serial_data_visualizer_ubuntu` folder.
    - Open the file `serial_data_visualizer_ubuntu.pro`.

3. Perform a **Clean Build** by selecting **Build > Clean All**.

4. Select **Build > Build All** to build the project.

5. Once the build is complete, run the application directly from Qt Creator or using the binary in the build folder.


### 5. Using the Application
For detailed instructions on how to use the application, refer to the documentation folder in the main repository.

## Notes
- Make sure all dependencies are installed before running or building the application.
- If you encounter any issues with the serial port, ensure the appropriate permissions are set.
- For a simpler installation process, consider using the Debian package provided in the `installer` folder.




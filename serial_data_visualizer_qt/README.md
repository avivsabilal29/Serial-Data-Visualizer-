# Serial Data Visualizer Qt

This folder contains all the necessary source code for building and running the Serial Data Visualizer desktop application. Below are the instructions to set up the environment, install dependencies, and run the application.

## Flow Overview
To successfully run this project, follow these steps:

### 1. Install Dependencies
Ensure you have the following installed on your system:
- **Qt 6.2.4**
- **MinGW 6.2.4 64-bit**

Additionally, ensure the following Qt modules are installed:
- **Qt Charts**
- **Qt Serial Port**

Refer to the official Qt documentation for guidance on installing these components via the Qt Maintenance Tool.

### 2. Clone the Repository
Clone the repository containing this folder using the following command:
```bash
git clone git@github.com:avivsabilal29/Serial-Data-Visualizer-.git
```

Navigate to the `serial_data_visualizer_qt` folder:
```bash
cd serial_data_visualizer_qt
```

### 3. Open the Project
1. Open Qt Creator.
2. Click on **File > Open File or Project**.
3. Select the file `serial_data_visualizer_qt.pro` in this folder.

### 4. Build and Run the Application
1. Once the project is loaded, perform a **Clean Build** by selecting **Build > Clean All**.
2. After cleaning, select **Build > Build All** to build the project.
3. Once the build is complete, click the **Run** button to launch the application.

### 5. Using the Application
Refer to the **documentation** folder in the main repository for detailed guidance on application features and usage instructions.

---

### Notes
- Ensure all required dependencies are correctly installed before running the application.
- If you encounter any issues during the build process, refer to the Qt Creator logs for troubleshooting.


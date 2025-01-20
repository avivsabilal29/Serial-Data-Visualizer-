# Installer

This folder provides two options for installing and using the Serial Data Visualizer application. Follow the instructions below based on your preference.

## Option 1: Install on Windows
1. Navigate to the **`serial_data_visualizer_windows`** folder.
2. Download the **`SerialDataVisualizerSetup.exe`** file.
3. Run **`SerialDataVisualizerSetup.exe`** to install the Serial Data Visualizer application on your system.


## Option 2: Use Pre-Built Application (Windows)
1. Navigate to the **`serial_data_visualizer_windows`** folder.
2. Download the zip file containing the pre-built application.
3. Extract the zip file to your desired location.
4. Inside the extracted folder, locate and run the **`serial_data_visualizer_qt.exe`** file to start using the application.


## Option 3: Install on Ubuntu (Linux)
1. Install Required Dependencies
Before using the application, ensure that the required libraries and tools are installed on your Ubuntu system.
Run the following commands to install dependencies:
    ```bash
    sudo apt update
    sudo apt install libqt6core6 libqt6widgets6 libqt6charts6 libqt6serialport6
    ```

2. Download the Debian Package
Navigate to folder `serial_data_visulaizer_ubuntu` and then download `serial_data_ubuntu.deb` debian package

3. Install the Application
Use the following command to install the .deb package:
    ```bash 
    sudo dpkg -i serial-data-visualizer.deb
    ````
    If you encounter dependency issues during installation, run:
    ```bash
    sudo apt-get install -f
    ````

4. Verify the Installation
    
    Once installed, you can launch the application by running:
    ```bash
    serial_data_visualizer_ubuntu
    ```

## Option 4: Use Pre-Built Application (Linux)
1. Navigate to the **`/serial_data_visulaizer_ubuntu/serial_data_ubuntu/usr/bin/`** select `serial_data_visualizer_ubuntu`.
2. Download the `serial_data_visualizer_ubuntu` file containing the pre-built application.
3. Run the **`serial_data_visualizer_ubuntu`** file to start using the application.
## Next Steps
For detailed instructions on how to use the application, please refer to the **documentation** folder in the main repository.


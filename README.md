# Setting up Azure IoT C SDK 🚀

### Running on Ubuntu in WSL2 🐧

---

1. Ensure you have WSL2 installed and set up on your Windows machine.
2. Install Ubuntu from the Microsoft Store.
3. Open Ubuntu and follow the instructions above to set up and run the Azure IoT C SDK.
4. Update the `main.c` file with your connection string and telemetry data you want to send.
5. Enjoy your IoT application running on Ubuntu in WSL2! 🎉

### Install Required Libraries and Tools 🛠️

---

- `sudo apt-get update`
- `sudo apt-get install -y cmake curl uuid-dev libssl-dev git build-essential libcurl4-openssl-dev`

### Create Base Project and SDKs Directory 📁

---

- `mkdir <project_name> && cd <project_name>`
- `mkdir sdks && cd sdks`

### Clone Azure IoT C SDK Repository 📦

---

- `git clone https://github.com/Azure/azure-iot-sdk-c.git`
- `cd azure-iot-sdk-c`
- `git submodule update --init --recursive`

### Build the SDK 🏗️

---

- `mkdir cmake && cd cmake`
- `cmake .. -Duse_prov_client=OFF -Dskip_samples=ON`
- `cmake --build .`
- `sudo cmake --build . --target install`

### Compile and Run the Program ▶️

---

- `mkdir build && cd build`
- `cmake ..`
- `make`
- `./AzureIoTHub_Device_Simulation`

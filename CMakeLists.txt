cmake_minimum_required(VERSION 3.10)
cmake_minimum_required(VERSION 3.10)
project(AzureIoTHub_Device_Simulation)

set(CMAKE_C_STANDARD 99)
set(CMAKE_PREFIX_PATH "/usr/local")

add_executable(AzureIoTHub_Device_Simulation main.c)
target_include_directories(AzureIoTHub_Device_Simulation PRIVATE /usr/local/include/azureiot)
target_link_libraries(AzureIoTHub_Device_Simulation
    iothub_client
    iothub_client_mqtt_transport
    umqtt
    aziotsharedutil
    serializer
    curl
    uuid
    ssl
    crypto
    pthread
    m
    parson
)
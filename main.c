#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <azureiot/iothub.h>
#include <azureiot/iothub_device_client_ll.h>
#include <azureiot/iothub_message.h>
#include <azureiot/iothubtransportmqtt.h>
#include <azure_c_shared_utility/threadapi.h>
#include <azure_c_shared_utility/platform.h>
#include <azure_c_shared_utility/shared_util_options.h>

#define MSG_TEXT_BUFFER_SIZE 512

static const char* connectionString = "<Your IoT Hub Device Connection String>";

void send_telemetry(IOTHUB_DEVICE_CLIENT_LL_HANDLE device_handle)
{
    srand((unsigned int)time(NULL));
    int counter = 0;
    char msgText[MSG_TEXT_BUFFER_SIZE];
    IOTHUB_MESSAGE_HANDLE message_handle;

    while (counter < 100)
    {
        int random_value = rand() % 16 + 1;
        snprintf(msgText, sizeof(msgText), "{\"messageId\":%d,\"temperature\":%d}", counter, random_value); // Replace with your telemetry data

        message_handle = IoTHubMessage_CreateFromString(msgText);
        IoTHubMessage_SetContentTypeSystemProperty(message_handle, "application/json");
        IoTHubMessage_SetContentEncodingSystemProperty(message_handle, "utf-8");

        IOTHUB_CLIENT_RESULT result = IoTHubDeviceClient_LL_SendEventAsync(device_handle, message_handle, NULL, NULL);
        if (result != IOTHUB_CLIENT_OK)
        {
            printf("Failed to send message to IoT Hub\n");
        }
        else
        {
            printf("Message sent successfully: %s\n", msgText);
        }

        IoTHubMessage_Destroy(message_handle);
        IoTHubDeviceClient_LL_DoWork(device_handle);
        ThreadAPI_Sleep(5000);

        counter++;
    }
}

int main(void)
{
    IOTHUB_DEVICE_CLIENT_LL_HANDLE device_handle;

    IoTHub_Init();
    device_handle = IoTHubDeviceClient_LL_CreateFromConnectionString(connectionString, MQTT_Protocol);

    if (device_handle == NULL)
    {
        printf("Failed to create client handle\n");
        return 1;
    }

    send_telemetry(device_handle);

    IoTHubDeviceClient_LL_Destroy(device_handle);
    IoTHub_Deinit();

    return 0;
}

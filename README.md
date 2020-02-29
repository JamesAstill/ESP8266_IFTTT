# ESP8266_IFTTT
A script made for a ESP8266 microprocessor to read from a PIR sensor and alert via IFTTT notifications.


## To set up the IFTTT webhook
1. Create an IFTTT account and create your own applet (Desktop)
2. Set up IF webhooks THEN Notification (Rich) applet
3. Note the event_trigger name and webhook code (bit after /use/ in settings)

## To run the code on the device
1. Open file via Arduino IDE
2. Replace SSID and Password with WIFI information
3. Replace trigger with event_name set up. Enter maker key from IFTTT also.
4. Connect NodeMCU device via USB
5. Upload main code file
6. Unplug USB and power via mains or battery pack

## To receive notifications
1. Download IFTTT app from your mobile devices app store
2. Log in and allow notifications

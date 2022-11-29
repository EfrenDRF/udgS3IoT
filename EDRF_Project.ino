/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID           "TMPLbhOnvxf0"
#define BLYNK_DEVICE_NAME           "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "4jxR0yBw4MeV2yGL2qaD0rLcq_XdG9Em"

#define EDRF_DEBUG

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#include "Wifi_Cfg.h"
#include "LM35.h"

char auth[] = BLYNK_AUTH_TOKEN;

/*Local Variables -------------------------------------------------------------*/
BlynkTimer  timer;
static uint16_t    tempC;

#ifdef EDRF_DEBUG
static bool tempCSentOut = false;
#endif

#if (0)
// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();

  // Update state
  Blynk.virtualWrite(V1, value);
}
#endif

#if (0)
// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}
#endif

// This function sends Arduino's uptime every second to Virtual Pin 2.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.

# ifdef EDRF_DEBUG
  tempCSentOut = true;
# endif
  Blynk.virtualWrite( V0, tempC );
}

void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin( auth, WifiCfg_ssid , WifiCfg_pass );
  
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!

  

# ifdef EDRF_DEBUG
  if ( true == tempCSentOut )
  {
    tempCSentOut = false;
    
    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.println("°C");
  }
# endif

  tempC = LM45_GetTempC();
}

/*************************************************************
 * Author:  Efren Del Real
 * file:    edrfIoTApp.ino
 * Date:    November 29th 2022
 *************************************************************/
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#include "Wifi_Cfg.h"
#include "LM35.h"

/*Local Macros*******************************************************************/
/*
 * Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
 * See the Device Info tab, or Template settings
 */
#define BLYNK_TEMPLATE_ID           "TMPLbhOnvxf0"
#define BLYNK_DEVICE_NAME           "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "4jxR0yBw4MeV2yGL2qaD0rLcq_XdG9Em"

/*Local Variables*****************************************************************/
BlynkTimer  timer;
char auth[] = BLYNK_AUTH_TOKEN;


/*********************************************************************************
 * myTimerEvent()
 *********************************************************************************
 * 
 * brief  This function sends Arduino's uptime every second to Virtual Pin 0.
 */
void myTimerEvent()
{
  /*
   * You can send any value at any time.
   * Please don't send more that 10 values per second.
   */
  Blynk.virtualWrite( V0, Lm35_GetTempCAvg() );

#if ( DEBUG_CFG_ON == DEBUG_CFG_LM35 )
  Lm35_SetSerialPrintTempCFlag( true );
#endif

}

/*********************************************************************************
 * setup()
 *********************************************************************************
 * 
 */
void setup()
{
  /* Debug console */
  Serial.begin( 115200 );

  Blynk.begin( auth, WifiCfg_ssid , WifiCfg_pass );

  /* Setup a function to be called every three seconds */
  timer.setInterval( 3000L, myTimerEvent );
}

/*********************************************************************************
 * loop()
 *********************************************************************************
 * 
 */
void loop()
{

  /* */
  Lm35_MainFunction();

  /* */
  Blynk.run();
  timer.run();
}

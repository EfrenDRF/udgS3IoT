#include "LM35.h"

/* Global variable definition ****************************************************/
temp_t  Lm35_TemperatureCAvg      = 0x00u;

#if ( DEBUG_CFG_ON == DEBUG_CFG_LM35 )
bool    Lm35_serialPrintTempCFlag = false;
#endif

/*Local function definition ******************************************************/
static float  Lm35_ReadCurrentmVInput( void );
static temp_t Lm35_GetCurrentTempC( void );

#if ( DEBUG_CFG_ON == DEBUG_CFG_LM35 )
static void   Lm35_serialPrintTempC( void );
#endif


/*********************************************************************************
 * Lm35_ReadCurrentmVInput()
 *********************************************************************************
 * 
 */
static float Lm35_ReadCurrentmVInput( void )
{
  uint16_t  rawData;
  float     retVal;
  
  /* Reads Analog Input */
  rawData = analogRead( LM35CFG_INPUT_PIN );

  /* Translates raw data to mV */
  retVal = ( ( rawData * LM35CFG_ADC_VRE ) / LM35CFG_ADC_SCALE_FACTOR );

  return retVal;
}

# if ( DEBUG_CFG_ON == DEBUG_CFG_LM35 )
/*********************************************************************************
 * Lm35_serialPrintTempC()
 *********************************************************************************
 * 
 */
static void Lm35_serialPrintTempC( void )
{
    Serial.print("Temperature: ");
    Serial.print( Lm35_GetTempCAvg() );
    Serial.println("°C");

    Lm35_SetSerialPrintTempCFlag( false );
}
# endif

/*********************************************************************************
 * Lm35_processTempCAvg()
 *********************************************************************************
 * 
 */
static void Lm35_processTempCAvg( void )
{
  static temp_t prevTempC = LM35CFG_TEMPC_MAX;

  if ( LM35CFG_TEMPC_MAX != prevTempC )
  {
    Lm35_TemperatureCAvg = ( Lm35_GetCurrentTempC() + prevTempC ) / 2;

  }

  prevTempC = Lm35_TemperatureCAvg;
}

/*********************************************************************************
 * Lm35_GetCurrentTempC()
 *********************************************************************************
 * 
 * return:        27.59°C -> 2759 
 */
static temp_t Lm35_GetCurrentTempC( void )
{
  float   milliVolts;
  float   temp;
  temp_t  retVal;

  milliVolts  = Lm35_ReadCurrentmVInput();
  temp        = ( milliVolts / LM35CFG_SCALE_FACTOR );
  retVal      = ( temp * LM32CFG_NEW_SCALE_FACTOR );

  return retVal;
}


/*********************************************************************************
 * Lm35_MainFunction()
 *********************************************************************************
 * 
 */
void Lm35_MainFunction( void )
{


#if ( DEBUG_CFG_ON == DEBUG_CFG_LM35 )
  if ( false != Lm35_serialPrintTempCFlag )
  {
    Lm35_serialPrintTempC();
  }
#endif


Lm35_processTempCAvg();

}

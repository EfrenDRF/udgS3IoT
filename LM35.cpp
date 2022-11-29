#include "LM35.h"
#include "LM35_Cfg.h"



/*********************************************************************************
 * FunctionName: LM35_ReadmVInput()
 * 
 */
static uint32_t LM35_ReadmVInput(void)
{
  uint16_t  rawData;
  float     retVal;
  
  /* Reads Analog Input */
  rawData = analogRead( LM35CFG_INPUT_PIN );

  /* Translates raw data to mV */
  retVal = ( ( rawData * LM35CFG_ADC_VRE ) / LM35CFG_ADC_SCALE_FACTOR );

  return retVal;
}

/*********************************************************************************
 * LM45_GetTempC()
 * 
 * return:        27.59°C -> 2759 
 */
uint16_t LM45_GetTempC( void )
{
  float     milliVolts;
  float     temp;
  uint16_t  retVal;

  milliVolts  = LM35_ReadmVInput();
  temp        = ( milliVolts / LM35CFG_SCALE_FACTOR );
  retVal      = ( temp * LM32CFG_NEW_SCALE_FACTOR );

  return retVal;
}

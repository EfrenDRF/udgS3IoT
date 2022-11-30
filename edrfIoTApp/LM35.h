/*************************************************************
 * Author:  Efren Del Real
 * file:    LM35.h
 * Date:    November 29th 2022
 *************************************************************/

#ifndef LM35_H_
# define LM35_H_

# include <stdint.h>
# include "LM35_Cfg.h"
# include "Debug_Cfg.h"

/* Macros interfaces ****************************************************/
# define Lm35_GetTempCAvg()                         Lm35_TemperatureCAvg
# define Lm35_SetSerialPrintTempCFlag( value )      Lm35_serialPrintTempCFlag = ( value );

/* Global Variables *****************************************************/
extern temp_t   Lm35_TemperatureCAvg;
extern bool     Lm35_serialPrintTempCFlag;

/* Global Function *******************************************************/
extern void     Lm35_MainFunction( void );

#endif

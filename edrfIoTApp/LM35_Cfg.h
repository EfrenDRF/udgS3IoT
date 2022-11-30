/*************************************************************
 * Author:  Efren Del Real
 * file:    LM35_Cfg.h
 * Date:    November 29th 2022
 *************************************************************/
#ifndef LM35_CFG_H_
# define LM35_CFG_H_

# include <Arduino.h>

# define LM35CFG_SCALE_FACTOR           (   10u ) /* 10 mV/C */
# define LM32CFG_NEW_SCALE_FACTOR       (  100u ) /* unadimentional unit- Default value must be 1 */

# define LM35CFG_ADC_VRE                ( 3300u ) /* 3300 mV - 3.3 V */
# define LM35CFG_ADC_SCALE_FACTOR       ( 4095u ) /* 12 bits - Raw data */
# define LM35CFG_INPUT_PIN              (   36u ) /* ESP32 pin GIOP36 ( ADC0 ) */

# define LM35CFG_TEMPC_MAX              ( (temp_t) 0xFFFF)

typedef uint16_t temp_t; 

#endif


/*************************************************************
 * Author:  Efren Del Real
 * file:    Wifi_Cfg.h
 * Date:    November 29th 2022
 *************************************************************/

#ifndef WIFI_CFG_H_
# define WIFI_CFG_H_


#include <stdint.h>


# define WIFICFG_SSDI_LEN ( 16u )
# define WIFICFG_PASS_LEN ( 13u )




extern const char WifiCfg_ssid[ WIFICFG_SSDI_LEN ];

extern const char WifiCfg_pass[ WIFICFG_PASS_LEN ];

#endif

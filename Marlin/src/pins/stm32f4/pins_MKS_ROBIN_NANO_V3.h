/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

#define ALLOW_STM32DUINO
#include "env_validate.h"

#if HOTENDS > 2 || E_STEPPERS > 2
  #error "MKS Robin Nano V3 supports up to 2 hotends / E-steppers."
#elif HAS_FSMC_TFT
  #error "MKS Robin Nano V3 doesn't support FSMC-based TFT displays."
#endif

#define BOARD_INFO_NAME "MKS Robin Nano V3"

// Use soft PWM for fans - PWM is not working properly when paired with STM32 Arduino Core v1.7.0
// This can be removed when Core version is updated and PWM behaviour is fixed.
#define FAN_SOFT_PWM

// USB Flash Drive support
#define HAS_OTG_USB_HOST_SUPPORT

// Avoid conflict with TIMER_TONE
#define STEP_TIMER                            10

// Use one of these or SDCard-based Emulation will be used
//#define SRAM_EEPROM_EMULATION                   // Use BackSRAM-based EEPROM emulation
//#define FLASH_EEPROM_EMULATION                  // Use Flash-based EEPROM emulation
#define I2C_EEPROM
#define MARLIN_EEPROM_SIZE                0x1000  // 4KB

#define I2C_SCL_PIN                       PB6
#define I2C_SDA_PIN                       PB7

//
// Release PB4 (Z_DIR_PIN) from JTAG NRST role
//
//#define DISABLE_DEBUG

//
// Servos
//
#define SERVO0_PIN                          PA8   // Enable BLTOUCH -- it's not a servo, but a Hall sensor, wtf?

//
// Limit Switches
//
#define X_DIAG_PIN                          PD15 // E1_STEP     -- error?
#define Y_DIAG_PIN                          PD2  // Y- endstop
#define Z_DIAG_PIN                          PC8  // Z- endstop
#define E0_DIAG_PIN                         PC4  // Z+ endstop
#define E1_DIAG_PIN                         PE7  // E1- endstop

//
#define X_STOP_PIN                          PA15
#define Y_STOP_PIN                          PD2
#define Z_MIN_PIN                           PC8
#define Z_MAX_PIN                           PC4

//
// Steppers
//
#define X_ENABLE_PIN                        PE4
#define X_STEP_PIN                          PE3
#define X_DIR_PIN                           PE2

#ifndef X_CS_PIN
  #define X_CS_PIN                          PD5
#endif

#ifndef Y_CS_PIN
  #define Y_CS_PIN                          PD7
#endif

#ifndef Z_CS_PIN
  #define Z_CS_PIN                          PD4
#endif

#ifndef E0_CS_PIN
  #define E0_CS_PIN                         PD9
#endif

#ifndef E1_CS_PIN
  #define E1_CS_PIN                         PD8
#endif

//
// Software SPI pins for TMC2130 stepper drivers
// This board only supports SW SPI for stepper drivers
//
#if HAS_TMC_SPI
  #define TMC_USE_SW_SPI
#endif
#if ENABLED(TMC_USE_SW_SPI)
  #if !defined(TMC_SW_MOSI) || TMC_SW_MOSI == -1
    #define TMC_SW_MOSI                     PD14
  #endif
  #if !defined(TMC_SW_MISO) || TMC_SW_MISO == -1
    #define TMC_SW_MISO                     PD1
  #endif
  #if !defined(TMC_SW_SCK) || TMC_SW_SCK == -1
    #define TMC_SW_SCK                      PD0
  #endif
#endif

#include "pins_MKS_ROBIN_NANO_V3_common.h"

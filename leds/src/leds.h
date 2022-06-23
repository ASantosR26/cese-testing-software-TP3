/*
 * Copyright (c) YEAR NOMBRE <MAIL>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * @file   : leds.h
 * @date   : 10 jun. 2022
 * @author : NOMBRE <MAIL>
 * @version	v1.0.0
 */

#ifndef LEDS_H_
#define LEDS_H_

/********************** CPP guard ********************************************/
#ifdef __cplusplus
extern "C" {
#endif

/********************** inclusions *******************************************/
#include <stdint.h>
#include <stdbool.h>

/********************** macros ***********************************************/

/********************** typedef **********************************************/

/********************** external data declaration ****************************/

/********************** external functions declaration ***********************/
/**
 * @brief Configura la biblioteca y apaga todos los leds.
 *
 * @param direccion Direccion del puerto GPIO que controla los leds.
 */
void LedsInit(uint16_t *direccion);

/**
 * @brief Enciende un led en especifico.
 *
 * @param led Indica el numero del led a encender (del 1 al 16).
 */
void LedTurnOn(uint8_t led);

/**
 * @brief Apaga un led en especifico.
 *
 * @param led Indica el numero del led a apagar ( de 1 al 16).
 */
void LedTurnOff(uint8_t led);

/**
 * @brief Enciende todos los leds.
 * 
 */
void LedsAllTurnOn(void);

/**
 * @brief Apaga todos los leds.
 * 
 */
void LedsAllTurnOff(void);

/**
 * @brief Obtiene el estado del led especificado
 * 
 * @param led Indica el numero del led a encender (del 1 al 16).
 * @return uint8_t Si el led esta encendido 1, sino 0.
 */
uint8_t LedGetState(uint8_t led);

/********************** End of CPP guard *************************************/
#ifdef __cplusplus
}
#endif

#endif /* LEDS_H_ */
/********************** end of file ******************************************/
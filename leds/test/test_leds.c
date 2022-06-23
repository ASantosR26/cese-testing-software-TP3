/*
Se puede prender un LED individual.
Se puede apagar un LEd individual.
Se puede prender y apagar múltiples LED's.
Se puede prender todos los LEDs de una vez. 
Se pueden apagar todos los LEDs de una vez. 
Se puede consultar el estado de un LED apagado. 
Se puede consultar el estado de un LED encendido.
Revisar límites de los parámetros.
Revisar parámetros fuera de los límites.
*/

#include "leds.h"
#include "mock_errores.h"
#include "unity.h"

static uint16_t ledsVirtuales;

void setUp(void) { 
  LedsInit(&ledsVirtuales); 
}

// Después de la inicialización todos los LEDs deben quedar apagados.
void test_LedsOffAfterCreate(void) {
  uint16_t ledsVirtuales = 0xFFFF;
  LedsInit(&ledsVirtuales);
  TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
}

// Se puede prender un LED individual
void test_TurnOnOneLed(void) {
  LedTurnOn(5);
  TEST_ASSERT_EQUAL_HEX16(1 << 4, ledsVirtuales);
}

// Se puede apagar un LED individual
void test_TurnOffOneLed(void) {
  LedTurnOn(3);
  LedTurnOff(3);
  TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
}

// Se puede apagar y prender múltiples leds
void test_TurnOnAndOfManyLeds(void) {
  LedTurnOn(5);
  LedTurnOn(3);
  LedTurnOn(11);
  LedTurnOff(3);
  LedTurnOff(11);
  TEST_ASSERT_EQUAL_HEX16(1 << 4, ledsVirtuales);
}

// Se puede prender todos los leds de una vez
void test_TurnOnAllLeds(void) {
  LedsAllTurnOn();
  TEST_ASSERT_EQUAL_HEX16(0xFFFF, ledsVirtuales);
}

// Se puede apagar todos los leds de una vez
void test_TurnOffAllLeds(void) {
  LedsAllTurnOn();
  LedsAllTurnOff();
  TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
}

// Se puede consultar el estado de un led apagado
void test_GetStateLedOff(void) {
  LedsAllTurnOn();
  LedTurnOff(5);
  uint8_t state = LedGetState(5);
  TEST_ASSERT_TRUE(state == 0);
}

// Se puede consultar el estado de un led encendido
void test_GetStateLedOn(void) {
  LedTurnOn(3);
  uint8_t state = LedGetState(3);
  TEST_ASSERT_TRUE(state == 1);
}

void test_InavalidUpperLimitTurnOnLed(void) {
  RegistrarMensaje_Expect(ALERTA, "LedTurnOn", 0, "Numero de led invalido");
  RegistrarMensaje_IgnoreArg_linea();
  LedTurnOn(17);
}
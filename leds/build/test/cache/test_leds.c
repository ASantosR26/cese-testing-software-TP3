#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"
#include "build/test/mocks/mock_errores.h"
#include "src/leds.h"




static uint16_t ledsVirtuales;



void setUp(void) {

  LedsInit(&ledsVirtuales);

}





void test_LedsOffAfterCreate(void) {

  uint16_t ledsVirtuales = 0xFFFF;

  LedsInit(&ledsVirtuales);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

 ((void *)0)

 ), (UNITY_UINT)(27), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOnOneLed(void) {

  LedTurnOn(5);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << 4)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

 ((void *)0)

 ), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOffOneLed(void) {

  LedTurnOn(3);

  LedTurnOff(3);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

 ((void *)0)

 ), (UNITY_UINT)(40), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOnAndOfManyLeds(void) {

  LedTurnOn(5);

  LedTurnOn(3);

  LedTurnOn(11);

  LedTurnOff(3);

  LedTurnOff(11);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << 4)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

 ((void *)0)

 ), (UNITY_UINT)(50), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOnAllLeds(void) {

  LedsAllTurnOn();

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

 ((void *)0)

 ), (UNITY_UINT)(56), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOffAllLeds(void) {

  LedsAllTurnOn();

  LedsAllTurnOff();

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

 ((void *)0)

 ), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_HEX16);

}





void test_GetStateLedOff(void) {

  LedsAllTurnOn();

  LedTurnOff(5);

  uint8_t state = LedGetState(5);

  do {if ((state == 0)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(71)));}} while(0);

}





void test_GetStateLedOn(void) {

  LedTurnOn(3);

  uint8_t state = LedGetState(3);

  do {if ((state == 1)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(78)));}} while(0);

}



void test_InavalidUpperLimitTurnOnLed(void) {

  RegistrarMensaje_CMockExpect(82, ALERTA, "LedTurnOn", 0, "Numero de led invalido");

  RegistrarMensaje_CMockIgnoreArg_linea(83);

  LedTurnOn(17);

}

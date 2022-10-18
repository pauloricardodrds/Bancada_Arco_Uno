ine INCLUDE_COMMON_DEFINES_H_

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Pushbutton.h>
#include "BasicStepperDriver.h"

//*************************************************************************
// Motor
//*************************************************************************
#define MOTOR_STEPS 1600
#define MICROSTEPS 1
#define STEP 9
#define SLEEP 10
#define DIR 11
uint8_t RPM = 120;
BasicStepperDriver stepper(MOTOR_STEPS, DIR, STEP, SLEEP);
//*************************************************************************
// LCD
//*************************************************************************
LiquidCrystal_I2C lcd(0x27, 20, 4);
//*************************************************************************
// Globais
//*************************************************************************
Pushbutton button_up(5);
Pushbutton button_esc(6);
Pushbutton button_down(7);
Pushbutton button_select(8);
//*************************************************************************
// Variáveis Menu
//*************************************************************************
enum itens {Item1 = 1, Item2, Item3};
enum telas
{
  Menu,
  Tela1,
  Tela2,
  Tela3
}
Telas;
uint8_t posi_Menu = Item1, posi_anterior_Menu = Item2;

#endif /* INCLUDE_COMMON_DEFINES_H_ */
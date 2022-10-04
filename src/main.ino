/*

   Código de Menu em C
   Desenvolvido por Paulo Ricardo Dutra Ribeiro da Silva
   pauloricardo.drds@gmail.com

    V0.1 - Compilação da estrutura inicial
    V0.2 - Adicionando Telas no Menu E PushButton
    V0.3 - Adicionando nomes do Menu principal e criando função de menu secundário
    V0.4 - Implementação do menu secundário da tela 1
    V0.5 - Implementação do uso do motor
    V0.6 - Implementação da tela pré teste, Implementação da Tela Config
    V0.7 - Implementação Mov. Motor
    V0.8 - Implementação dos avisos
    V0.9 - Otimização do Código
    V1.0 - Sistema Operando e otimizado para o VSCode PlataformIO

*/

#include<Arduino.h>
#include"common_defines.h"

//*************************************************************************
// Menu de opções do programa
//*************************************************************************

void setup()
{
  Serial.begin(9600);
  stepper.begin(RPM, MICROSTEPS);
  stepper.setEnableActiveState(LOW);
  stepper.disable();
  lcd.init();                      // initialize the lcd
  // Print a message to the LCD.
  lcd.backlight();
  menu_principal();
}

void loop()
{
  if (button_select.getSingleDebouncedRelease())
  {
    if (posi_Menu == Item1)
    {
      tela_testes();
    } else if (posi_Menu == Item2)
    {
      tela_config();
    } else if (posi_Menu == Item3)
    {
      tela_autoteste();
    }
  }
  if (button_up.getSingleDebouncedRelease())
  {
    posi_anterior_Menu = posi_Menu;
    posi_Menu = (posi_Menu == Item1) ? Item3 : (posi_Menu == Item2) ? Item1 : Item2;
    menu_principal();

  }
  if (button_down.getSingleDebouncedRelease())
  {
    posi_anterior_Menu = posi_Menu;
    posi_Menu = (posi_Menu == Item1) ? Item2 : (posi_Menu == Item2) ? Item3 : Item1;
    menu_principal();
  }
}

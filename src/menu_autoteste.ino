//*************************************************************************
/*Trecho responsável pela execução da rotina do menu "Auto Teste"

* Ainda sem implementação

*/
//*************************************************************************


void tela_autoteste()
{
  uint8_t retorno = 1;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   Funcao Nao");
  lcd.setCursor(0, 1);
  lcd.print("  Implementada");
  while (retorno != 0)
  {
    if (button_esc.getSingleDebouncedRelease())
    {
      retorno = 0;
    }
  }
  menu_principal();
}
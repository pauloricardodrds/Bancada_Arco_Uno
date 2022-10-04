//*************************************************************************
/*Trecho responsável pela execução da rotina do menu "Config"

* Funções iniciadas com "menu" são usadas para criação dos nomes no display LCD
* Funções iniciadas com "tela" são usadas para criar a lógica de funcionamento, em alguns casos as duas funções são
associadas na função "tela" devido ao curto trecho necessário
* Para evitar a criação de variáveis globais, é adotada funções com argumento da posição anterior do menu, para que 
quando retorne ele consiga voltar a posição que estava no menu passado


*/
//*************************************************************************


void menu_tela_config(uint8_t menu_posi, uint8_t menu_posi_ant)
{
  switch (menu_posi) // Usado para definir qual texto será selecionado no menu
  {
    case 1:
      {
        if (menu_posi_ant == 3)
        {
          //Serial.println("Case Item 1 - If 1");
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Log de Erro");
          lcd.setCursor(0, 1);
          lcd.print("*Mov. Motor");

        } else if (menu_posi_ant == 2)
        {
          //Serial.println("Case Item 1 - If 2");
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("*Mov. Motor");
          lcd.setCursor(0, 1);
          lcd.print("Troca de Eixo");
        }
        break;
      }
    case 2:
      {
        if (menu_posi_ant == 1)
        {
          //Serial.println("Case Item 2 - If 1");
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Mov. Motor");
          lcd.setCursor(0, 1);
          lcd.print("*Troca de Eixo");
        } else if (menu_posi_ant == 3)
        {
          //Serial.println("Case Item 2 - If 2");
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("*Troca de Eixo");
          lcd.setCursor(0, 1);
          lcd.print("Log de Erro");
        }
        break;
      }
    case 3:
      {
        if (menu_posi_ant == 2)
        {
          //Serial.println("Case Item 3 - If 1");
          //escreva aqui o código que vai desenhar seu menu em C quando o primeiro item estiver selecionado.
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Troca de Eixo");
          lcd.setCursor(0, 1);
          lcd.print("*Log de Erro");

        } else if (menu_posi_ant == 1)
        {
          //Serial.println("Case Item 3 - If 2");
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("*Log de Erro");
          lcd.setCursor(0, 1);
          lcd.print("Mov. Motor");
        }
        break;
      }
    default:
      break;    // Não implementado, mas é bom criar uma rotina para caso ocorra algum erro de parametro. 
  }
}

void tela_config_Mov(uint8_t posi_tela_config, uint8_t posi_anterior_telaconfig)
{
  uint8_t retorno = 1;  // Usada para auxiliar no retorno ao menu anterior, quando fica preso em um While temporário de uma função
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Press. Select e");
  lcd.setCursor(0, 1);
  lcd.print("+/- para ir Deva");
  stepper.enable(); // Nunca esquecer de ativar e desativar o motor para conseguir rodar
  while (retorno != 0)
  {
    while (button_select.isPressed())
    {

      if (button_up.getSingleDebouncedRelease())
      {
        stepper.move(5); // Função para aplicar 5 passos 
      } else if (button_down.getSingleDebouncedRelease())
      {
        stepper.move(-5);
      }
    }
    if (button_up.isPressed())
    {
      stepper.move(1);
    }
    if (button_down.isPressed())
    {
      stepper.move(-1);
    }
    if (button_esc.getSingleDebouncedRelease())
    {
      retorno = 0;
    }
  }
  stepper.disable(); // Nunca esquecer de ativar e desativar o motor para conseguir rodar
  menu_tela_config(posi_tela_config, posi_anterior_telaconfig);
}

void tela_config_Troca(uint8_t posi_tela_config, uint8_t posi_anterior_telaconfig)
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
  menu_tela_config(posi_tela_config, posi_anterior_telaconfig);
}

void tela_config_Log(uint8_t posi_tela_config, uint8_t posi_anterior_telaconfig)
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
  menu_tela_config(posi_tela_config, posi_anterior_telaconfig);
}

void tela_config()
{
  uint8_t posi_tela_config = 1, posi_anterior_telaconfig = 2;
  uint8_t retorno = 1;
  menu_tela_config(posi_tela_config, posi_anterior_telaconfig);

  while (retorno != 0)
  {
    if (button_select.getSingleDebouncedRelease())
    {
      if (posi_tela_config == 1)
      {
        tela_config_Mov(posi_tela_config, posi_anterior_telaconfig);
      } else if (posi_tela_config == 2)
      {
        tela_config_Troca(posi_tela_config, posi_anterior_telaconfig);
      } else if (posi_tela_config == 3)
      {
        tela_config_Log(posi_tela_config, posi_anterior_telaconfig);
      }
    }
    if (button_up.getSingleDebouncedRelease())
    {
      posi_anterior_telaconfig = posi_tela_config;
      posi_tela_config = (posi_tela_config == 1) ? 3 : (posi_tela_config == 2) ? 1 : 2;
      menu_tela_config(posi_tela_config, posi_anterior_telaconfig);
    }
    if (button_down.getSingleDebouncedRelease())
    {
      posi_anterior_telaconfig = posi_tela_config;
      posi_tela_config = (posi_tela_config == 1) ? 2 : (posi_tela_config == 2) ? 3 : 1;
      menu_tela_config(posi_tela_config, posi_anterior_telaconfig);
    }
    if (button_esc.getSingleDebouncedRelease())
    {
      retorno = 0;
    }
  }
  menu_principal();
}


void menu_testes(uint8_t menu_posi, uint8_t menu_posi_ant)
{
  switch (menu_posi)
  {
    case 1:
      {
        if (menu_posi_ant == 4)
        {
          //Serial.println("Case Item 1 - If 1");
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Teste N 4");
          lcd.setCursor(0, 1);
          lcd.print("*Teste N 1");

        } else if (menu_posi_ant == 2)
        {
          //Serial.println("Case Item 1 - If 2");

          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("*Teste N 1");
          lcd.setCursor(0, 1);
          lcd.print("Teste N 2");
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
          lcd.print("Teste N 1");
          lcd.setCursor(0, 1);
          lcd.print("*Teste N 2");
        } else if (menu_posi_ant == 3)
        {
          //Serial.println("Case Item 2 - If 2");
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("*Teste N 2");
          lcd.setCursor(0, 1);
          lcd.print("Teste N 3");
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
          lcd.print("Teste N 2");
          lcd.setCursor(0, 1);
          lcd.print("*Teste N 3");

        } else if (menu_posi_ant == 4)
        {
          //Serial.println("Case Item 3 - If 2");
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("*Teste N 3");
          lcd.setCursor(0, 1);
          lcd.print("Teste N 4");
        }
        break;
      }
    case 4:
      {
        if (menu_posi_ant == 3)
        {
          //Serial.println("Case Item 3 - If 1");
          //escreva aqui o código que vai desenhar seu menu em C quando o primeiro item estiver selecionado.
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Teste N 3");
          lcd.setCursor(0, 1);
          lcd.print("*Teste N 4");

        } else if (menu_posi_ant == 1)
        {
          //Serial.println("Case Item 3 - If 2");
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("*Teste N 4");
          lcd.setCursor(0, 1);
          lcd.print("Teste N 1");
        }
        break;
      }
    default:
      break;//deu ruim!
  }
}

void tela_testes()
{
  uint8_t posi_tela_testes = 1, posi_anterior_tela_testes = 2;
  uint8_t retorno = 1;
  menu_testes(posi_tela_testes, posi_anterior_tela_testes);

  while (retorno != 0)
  {
    if (button_select.getSingleDebouncedRelease())
    {
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("*Iniciar");
      while (retorno != 0)
      {
        if (posi_tela_testes == 1)
        {
          lcd.setCursor(0, 0);
          lcd.print("N1Caracteristica");
        } else if (posi_tela_testes == 2)
        {
          lcd.setCursor(0, 0);
          lcd.print("N2Caracteristica");
        } else if (posi_tela_testes == 3)
        {
          lcd.setCursor(0, 0);
          lcd.print("N3Caracteristica");
        } else if (posi_tela_testes == 4)
        {
          lcd.setCursor(0, 0);
          lcd.print("N4Caracteristica");
        }

        if (button_select.getSingleDebouncedRelease())
        {
          exe_test(posi_tela_testes);
        }
        if (button_esc.getSingleDebouncedRelease())
        {
          retorno = 0;
        }
      }
      retorno = 1;
      menu_testes(posi_tela_testes, posi_anterior_tela_testes);

    }

    if (button_up.getSingleDebouncedRelease())
    {
      posi_anterior_tela_testes = posi_tela_testes;
      posi_tela_testes = (posi_tela_testes == 1) ? 4 : (posi_tela_testes == 2) ? 1 : (posi_tela_testes == 3) ? 2 : 3;
      menu_testes(posi_tela_testes, posi_anterior_tela_testes);
    }
    if (button_down.getSingleDebouncedRelease())
    {
      posi_anterior_tela_testes = posi_tela_testes;
      posi_tela_testes = (posi_tela_testes == 1) ? 2 : (posi_tela_testes == 2) ? 3 : (posi_tela_testes == 3) ? 4 : 1;
      menu_testes(posi_tela_testes, posi_anterior_tela_testes);
    }
    if (button_esc.getSingleDebouncedRelease())
    {
      retorno = 0;
    }
  }
  menu_principal();
}

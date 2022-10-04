void menu_principal()
{
  switch (posi_Menu)
  {
    case Item1:
      {
        if (posi_anterior_Menu == Item2)
        {
          //Serial.println("Case Item 1 - If 1");
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("*Teste Arco");
          lcd.setCursor(0, 1);
          lcd.print("Config");

        } else if (posi_anterior_Menu == Item3)
        {
          //Serial.println("Case Item 1 - If 2");

          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Auto Teste");
          lcd.setCursor(0, 1);
          lcd.print("*Teste Arco");
        }
        break;
      }
    case Item2:
      {
        if (posi_anterior_Menu == Item1)
        {
          //Serial.println("Case Item 2 - If 1");
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Teste Arco");
          lcd.setCursor(0, 1);
          lcd.print("*Config");
        } else if (posi_anterior_Menu == Item3)
        {
          //Serial.println("Case Item 2 - If 2");
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("*Config");
          lcd.setCursor(0, 1);
          lcd.print("Auto Teste");
        }
        break;
      }
    case Item3:
      {
        if (posi_anterior_Menu == Item1)
        {
          //Serial.println("Case Item 3 - If 1");
          //escreva aqui o código que vai desenhar seu menu em C quando o primeiro item estiver selecionado.
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("*Auto Teste");
          lcd.setCursor(0, 1);
          lcd.print("Teste Arco");

        } else if (posi_anterior_Menu == Item2)
        {
          //Serial.println("Case Item 3 - If 2");
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Config");
          lcd.setCursor(0, 1);
          lcd.print("*Auto Teste");
        }
        break;
      }
    default:
      break;//deu ruim!
  }

}


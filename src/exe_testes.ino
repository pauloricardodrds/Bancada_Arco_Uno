//*************************************************************************
/*Trecho responsável pela execução da rotina de testes

- Controle de velocidade e passo do motor
* Para realizar a mudança da velocidade faz se necessário o cálculo de rpm para m/s. (Atenção na hora de considerar o raio)
* Nunca esqueça de usar os comandos stepper.enable() e stepper.disable() isso evita que o motor aqueça enquanto está parado
* Os tempos de delay devem ser calculados de acordo com cada teste
* 

*/
//*************************************************************************

void exe_test(uint8_t n_test)
{
  lcd.clear(); // Comando para limpar tela, Sempre bom usar paraa não da conflito de caracter.
  lcd.setCursor(0, 0); // Usado para posicionar o curso na coluna 1, linha 1 (Os vetores em C iniciam em 0)
  lcd.print("Iniciando teste:"); 
  stepper.enable(); // Nunca esquecer de ativar e desativar o motor para conseguir rodar

  lcd.setCursor(0, 1);
  lcd.print("       3");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("       2");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("       1");
  delay(1000);
  lcd.clear();  
  lcd.setCursor(0, 0);
  lcd.print("  Em Execucao!");

  if (n_test == 1)
  {
    RPM = 10;
    stepper.begin(RPM, MICROSTEPS); // Usado para configurar a nova velocidade, a variável microspteps é usada para dividir o número de passos por revolução
    stepper.rotate(360); // Comando usado para rodar o motor, neste estilo é definido a rotação desejada de acordo com a quantidade de graus que deseja rodar
                         // Para converter em metros não esqueça de considerar o raio correto para a conversão em metros.

  } else if (n_test == 2)
  {
    RPM = 60;
    stepper.begin(RPM, MICROSTEPS);
    stepper.rotate(-360); // Usando o negativo permite rotacionar no sentido contrário

  } else if (n_test == 3)
  {
    RPM = 100;
    stepper.begin(RPM, MICROSTEPS);
    stepper.rotate(720);

  } else if (n_test == 4)
  {
    RPM = 200;
    stepper.begin(RPM, MICROSTEPS);
    stepper.rotate(-720);
  }

  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  Finalizando!");
  stepper.disable(); // Nunca esquecer de ativar e desativar o motor para conseguir rodar
  
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("*Iniciar");
}

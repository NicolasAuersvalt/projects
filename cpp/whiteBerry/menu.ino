
class Menu {
private:
  fases[5] = { 'Fase_0', 'Fase_1', 'Fase_2', 'Fase_3', 'Fase_4' };
  frase[6] = { 'L', 'e', 'v', 'e', 'l', ' ' };
  bool keypadAtivo = false;
  int fase_escolhida = 0;

public:
  void menu() {
    lcd.set(0, 0);

    if (keypadAtivo) {

      char key = keypad.getKey();

      if (key != NO_KEY) {

        if (key == "0") {
          lcd.print("> ") for (int i, i < 6, i++) {
            lcd.print(frase[i]);
            delay(tmp);
          }
          // Level Selecionado
          lcd.print(" 0");

          lcd.set(0, 1);
          for (int i, i < 6, i++) {
            lcd.print(frase[i]);
            delay(tmp);
          }
          // Level abaixo
          lcd.print(" 1");

          if (key == "1") {
            lcd.print("> ") for (int i, i < 6, i++) {
              lcd.print(frase[i]);
              delay(tmp);
            }
            lcd.print(" 1");
            int fase_escolhida = 1;
          }

          if (key == "2") {
            lcd.print("> ") for (int i, i < 6, i++) {
              lcd.print(frase[i]);
              delay(tmp);
            }
            lcd.print(" 2");
            int fase_escolhida = 2;
          }

          if (key == "3") {
            lcd.print("> ") for (int i, i < 6, i++) {
              lcd.print(frase[i]);
              delay(tmp);
            }
            lcd.print(" 3");
            int fase_escolhida = 3;
          }

          if (key == "4") {
            lcd.print("> ") for (int i, i < 6, i++) {
              lcd.print(frase[i]);
              delay(tmp);
            }
            lcd.print(" 4");
            int fase_escolhida = 4;
          }
        }

        if (nextBtn == 1) {
          if (fase_escolhida == 0) {
            enigma1.enigma_1();
          }
          if (fase_escolhida == 1) {
            enigma1.enigma_2();
          }
          if (fase_escolhida == 2) {
            enigma1.enigma_3();
          }
          if (fase_escolhida == 3) {
            enigma1.enigma_4();
          }
          if (fase_escolhida == 4) {
            enigma1.enigma_5();
          }
        }
      };

      void setup() {
        // put your setup code here, to run once:
      }

      void loop() {
        // put your main code here, to run repeatedly:
      }


#include <LiquidCrystal.h>
#include <Keypad.h>

const int prevBtn = A1;
const int nextBtn = A2;

const byte ROWS = 4;  // Quatro linhas
const byte COLS = 3;  // Três colunas

char keys[ROWS][COLS] = {
  { '1', '2', '3' },
  { '4', '5', '6' },
  { '7', '8', '9' },
  { '*', '0', '#' }
};

byte rowPins[ROWS] = { 13, 12, 11, 10 };
byte colPins[COLS] = { 9, 8, 7 };

LiquidCrystal lcd(6, 5, 4, 3, 2, A0);
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void menu() {
  const int tmp = 100;
  char fases[5][7] = {"Fase_0", "Fase_1", "Fase_2", "Fase_3", "Fase_4"};
  char frase[6] = {'L', 'e', 'v', 'e', 'l', ' '};
  bool keypadAtivo = false;
  int fase_escolhida = 0;

  lcd.setCursor(0, 0);
  lcd.print("> ");
  for (int i = 0; i < 6; i++) {
    lcd.print(frase[i]);
    delay(tmp);
  }
  // Level Selecionado
  lcd.print(" 0");

  lcd.setCursor(0, 1);
  for (int i = 0; i < 6; i++) {
    lcd.print(frase[i]);
    delay(tmp);
  }
  // Level abaixo
  lcd.print(" 1");

  char key = keypad.getKey();
  if (key == '0') {
    lcd.clear();
    lcd.print("> ");
    for (int i = 0; i < 6; i++) {
      lcd.print(frase[i]);
      delay(tmp);
    }
    lcd.print(" 0");
    fase_escolhida = 0;
  } else if (key == '1') {
    lcd.clear();
    lcd.print("> ");
    for (int i = 0; i < 6; i++) {
      lcd.print(frase[i]);
      delay(tmp);
    }
    lcd.print(" 1");
    fase_escolhida = 1;
  } else if (key == '2') {
    lcd.clear();
    lcd.print("> ");
    for (int i = 0; i < 6; i++) {
      lcd.print(frase[i]);
      delay(tmp);
    }
    lcd.print(" 2");
    fase_escolhida = 2;
  } else if (key == '3') {
    lcd.clear();
    lcd.print("> ");
    for (int i = 0; i < 6; i++) {
      lcd.print(frase[i]);
      delay(tmp);
    }
    lcd.print(" 3");
    fase_escolhida = 3;
  } else if (key == '4') {
    lcd.clear();
    lcd.print("> ");
    for (int i = 0; i < 6; i++) {
      lcd.print(frase[i]);
      delay(tmp);
    }
    lcd.print(" 4");
    fase_escolhida = 4;
  }

  if (digitalRead(nextBtn) == HIGH) {
    lcd.clear();
    lcd.print("Fase selecionada: ");
    lcd.print(fases[fase_escolhida]);
    Serial.print("Botão Apertado");
    Serial.println(fases[fase_escolhida]);
  }
  else{
    Serial.print("Botão solto ");
  }
}

void setup() {
  pinMode(prevBtn, INPUT_PULLUP);
  pinMode(nextBtn, INPUT_PULLUP); 
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  menu();
}

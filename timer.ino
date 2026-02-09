#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

// ---------- LCD I2C ----------
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ---------- TECLADO ----------
const byte FILAS = 4;
const byte COLUMNAS = 4;

char teclas[FILAS][COLUMNAS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pinesFilas[FILAS] = {9, 8, 7, 6};
byte pinesColumnas[COLUMNAS] = {5, 4, 3, 2};

Keypad teclado = Keypad(makeKeymap(teclas), pinesFilas, pinesColumnas, FILAS, COLUMNAS);

// ---------- BUZZER ----------
const int buzzer = 10;

// ---------- VARIABLES ----------
String entrada = "";            // MMSS
unsigned long tiempo = 0;       // segundos
bool contando = false;

void setup() {
  pinMode(buzzer, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Timer MM:SS");
  lcd.setCursor(0, 1);
  lcd.print("00:00");
}

void loop() {

  char tecla = teclado.getKey();

  if (tecla && !contando) {

    // ---- NUMEROS (MAX 4) ----
    if (tecla >= '0' && tecla <= '9' && entrada.length() < 4) {
      entrada += tecla;
      mostrarEntrada();
    }

    // ---- BORRAR ULTIMO DIGITO (*) ----
    if (tecla == '*' && entrada.length() > 0) {
      entrada.remove(entrada.length() - 1);
      mostrarEntrada();
    }

    // ---- INICIAR (A) ----
    if (tecla == 'A' && entrada.length() == 4) {
      convertirMMSS();
      contando = true;
      entrada = "";

      lcd.setCursor(0, 0);
      lcd.print("Corriendo...   ");
    }

    // ---- RESET (C) ----
    if (tecla == 'C') {
      entrada = "";
      tiempo = 0;
      contando = false;

      lcd.setCursor(0, 0);
      lcd.print("Timer MM:SS    ");
      lcd.setCursor(0, 1);
      lcd.print("00:00          ");
    }
  }

  // ---- CUENTA REGRESIVA ----
  if (contando && tiempo > 0) {
    mostrarTiempo(tiempo);
    delay(1000);
    tiempo--;
  }

  // ---- FIN ----
  if (contando && tiempo == 0) {
    contando = false;

    lcd.setCursor(0, 0);
    lcd.print("Tiempo terminado");
    lcd.setCursor(0, 1);
    lcd.print("00:00          ");

    for (int i = 0; i < 5; i++) {
      digitalWrite(buzzer, HIGH);
      delay(200);
      digitalWrite(buzzer, LOW);
      delay(200);
    }
  }
}

// ---------- MOSTRAR ENTRADA MM:SS ----------
void mostrarEntrada() {

  String temp = entrada;
  while (temp.length() < 4) temp = "0" + temp;

  lcd.setCursor(0, 1);
  lcd.print(temp.substring(0, 2));
  lcd.print(":");
  lcd.print(temp.substring(2, 4));
  lcd.print("        ");
}

// ---------- CONVERTIR MMSS ----------
void convertirMMSS() {

  int valor = entrada.toInt();
  int minutos = valor / 100;
  int segundos = valor % 100;

  if (segundos > 59) segundos = 59;

  tiempo = (minutos * 60) + segundos;
}

// ---------- MOSTRAR TIEMPO ----------
void mostrarTiempo(unsigned long total) {

  int minutos = total / 60;
  int segundos = total % 60;

  lcd.setCursor(0, 1);

  if (minutos < 10) lcd.print("0");
  lcd.print(minutos);
  lcd.print(":");

  if (segundos < 10) lcd.print("0");
  lcd.print(segundos);
  lcd.print("        ");
}

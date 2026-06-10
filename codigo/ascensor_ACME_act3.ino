#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

#define LDR A0

#define LED_VERDE 6
#define LED_ROJO 7

#define BUZZER 10

bool falloDHT = false;
bool falloLDR = false;
bool modoSeguro = false;

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

  Serial.begin(9600);

  dht.begin();

  lcd.init();
  lcd.backlight();

  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);

  pinMode(BUZZER, OUTPUT);

  Serial.println("Sistema iniciado");
  Serial.println("Autodiagnostico activado");

}

void loop() {

  float temperatura = dht.readTemperature();
  float humedad = dht.readHumidity();
  int luz = analogRead(LDR);

  falloDHT = false;
  falloLDR = false;
  modoSeguro = false;

  // -------------------------
  // AUTODIAGNOSTICO
  // -------------------------

  if (isnan(temperatura) || isnan(humedad)) {
    falloDHT = true;
  }

  if (temperatura < -20 || temperatura > 80) {
    falloDHT = true;
  }

  if (humedad < 0 || humedad > 100) {
    falloDHT = true;
  }

  if (luz < 0 || luz > 1023) {
    falloLDR = true;
  }

  if (falloDHT || falloLDR) {

    modoSeguro = true;

    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_ROJO, HIGH);

    tone(BUZZER, 1500);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("FALLO SENSOR");

    lcd.setCursor(0, 1);
    lcd.print("MODO SEGURO");

    Serial.println("ERROR SENSOR DETECTADO");
    Serial.println("MODO SEGURO ACTIVADO");

    delay(2000);

    return;
  }

  // -------------------------
  // CONTROL DE ILUMINACION
  // -------------------------

  if (luz < 500) {
    digitalWrite(LED_VERDE, HIGH);
  } else {
    digitalWrite(LED_VERDE, LOW);
  }

  // -------------------------
  // CONTROL DE TEMPERATURA
  // -------------------------

  if (temperatura > 28) {

    digitalWrite(LED_ROJO, HIGH);
    tone(BUZZER, 1000);

  } else {

    digitalWrite(LED_ROJO, LOW);
    noTone(BUZZER);

  }

  // -------------------------
  // MONITOR SERIE
  // -------------------------

  Serial.print("Temperatura: ");
  Serial.print(temperatura);

  Serial.print(" Humedad: ");
  Serial.print(humedad);

  Serial.print(" Luz: ");
  Serial.print(luz);

  Serial.println(" Estado: OK");

  // -------------------------
  // VISUALIZACION LCD
  // -------------------------

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperatura);

  lcd.print(" H:");
  lcd.print(humedad);

  lcd.setCursor(0, 1);
  lcd.print("L:");
  lcd.print(luz);

  delay(1000);

}

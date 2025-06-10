#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <RotaryEncoder.h>


// OLED
#define OLED_RESET     -1
#define SCREEN_ADDRESS 0x3C//78
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64


// Encoder KY-040
#define ENCODER_CLK 5
#define ENCODER_DT  6

#define LED_PIN 4

#define SDA_PIN 8
#define SCL_PIN 9

// MCP41050
#define CS_PIN 10 // Chip Select
#define SCLK_PIN 12 
#define MOSI_PIN 11
#define MISO_PIN 13

#define V_MAX 97.8
#define V_MID 37.3
#define V_MIN 23.3
 
RotaryEncoder encoder(ENCODER_CLK, ENCODER_DT, RotaryEncoder::LatchMode::FOUR0);
SPIClass SPIbus(FSPI);  // Puedes usar VSPI/HSPI/FSPI según el core

TwoWire I2CBus = TwoWire(0); // Puedes usar Wire también si solo usas uno
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &I2CBus, OLED_RESET);

float v_out = 23.3;



volatile int currentValue = 50;  // Valor de salida (0–100%)
int lastClkState;


void updateOutput(int percent);
float calcularVoltaje(int x);

void IRAM_ATTR checkEncoder() 
{
  encoder.tick();  // Debe llamarse en interrupción
}

void setup()
{
  Serial.begin(9600);
  while(!Serial);


  I2CBus.begin(SDA_PIN, SCL_PIN);
  SPIbus.begin(SCLK_PIN, MISO_PIN, MOSI_PIN, CS_PIN);
  
  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH);
  
  pinMode(LED_PIN,OUTPUT);
  digitalWrite(LED_PIN,HIGH);
  
  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH);
  
  pinMode(ENCODER_CLK, INPUT);
  pinMode(ENCODER_DT, INPUT);

   // Inicializar encoder
  attachInterrupt(digitalPinToInterrupt(ENCODER_CLK), checkEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCODER_DT),  checkEncoder, CHANGE);

  Serial.println(F("Setup listo"));

  encoder.setPosition(currentValue);
  Serial.println(F("Encendiendo pantalla"));
  // OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) 
  {
    Serial.println(F("No se encontró pantalla OLED"));
  
  }

  // OLED
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);

  updateOutput(currentValue);


}

void loop() 
{
  encoder.tick(); // También debe llamarse en loop()

  static int lastPos = -1;
  int newPos = encoder.getPosition();

  if (newPos != lastPos) 
  {
    currentValue = constrain(newPos, 0, 100);
    v_out = calcularVoltaje(currentValue);
    v_out = int(v_out*100 + 0.5)/100.0; 
    updateOutput(currentValue);
    lastPos = newPos;
  }
}


void updateOutput(int percent) 
{
  int value = map(percent, 0, 100, 255, 0);
  Serial.println(F("updating value"));

  // Enviar a MCP41050
  digitalWrite(CS_PIN, LOW);
  SPIbus.transfer(0x11); // Comando para escribir
  SPIbus.transfer(value);
  digitalWrite(CS_PIN, HIGH);

  // Mostrar en pantalla OLED
  display.clearDisplay();
  display.setCursor(10, 20);
  display.print("P: ");
  display.print(percent);
  display.print("%");
  display.setCursor(10, 40);
  display.print("V: ");
  display.print(v_out);
  
  display.display();

  // Serial debug
  Serial.print("Valor de salida: ");
  Serial.print(percent);
  Serial.print("% ; Voltaje estimado : ");
  Serial.println(v_out);
}

float calcularVoltaje(int x) {
  //return 0.000003238 * pow(x, 3) - 0.0005 * pow(x, 2) + 0.0911 * x + 23.3007;
  return 23.3 * exp(0.014617 * x);
}

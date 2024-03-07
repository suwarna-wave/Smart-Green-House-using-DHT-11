#include <dht.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2              // Digital pin connected to the DHT sensor
#define LED_PIN 13            // Digital pin connected to the LED
#define FAN_PIN 12            // Digital pin connected to the fan
#define RELAY_PIN 11          // Digital pin connected to the relay module

#define THRESHOLD_TEMP 25     // Threshold temperature in Celsius
#define THRESHOLD_HUMIDITY 60 // Threshold humidity percentage
#define LCD_UPDATE_INTERVAL 5000 // LCD update interval in milliseconds

dht DHT;  // Initialize DHT sensor

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 columns and 2 rows

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Make sure relay is initially off

  lcd.init(); // Initialize the LCD
  lcd.backlight(); // Turn on backlight
}

void loop() {
  // Read temperature and humidity values from the sensor
  int chk = DHT.read11(DHTPIN);
  float temperature = DHT.temperature;
  float humidity = DHT.humidity;

  // Display temperature and humidity on the LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print(" %");

  // Check temperature threshold
  if (temperature < THRESHOLD_TEMP) {
    // Turn on the LED (simulating heater)
    digitalWrite(LED_PIN, HIGH);
  } else {
    // Turn off the LED
    digitalWrite(LED_PIN, LOW);
  }

  // Check humidity threshold
  if (humidity < THRESHOLD_HUMIDITY) {
    // Turn on the relay to activate the humidifier
    digitalWrite(RELAY_PIN, HIGH);
    // Turn off the fan
    digitalWrite(FAN_PIN, LOW);
  } else {
    // Turn off the relay
    digitalWrite(RELAY_PIN, LOW);
    // Turn on the fan
    digitalWrite(FAN_PIN, HIGH);
  }
  
  // Check if the sensor reading is successful
  if (chk != DHTLIB_OK) {
    Serial.println("Failed to read from DHT sensor!");
  }

  // Delay for LCD update interval
  delay(LCD_UPDATE_INTERVAL);
}

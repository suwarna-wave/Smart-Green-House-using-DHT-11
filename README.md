# Smart-Green-House-using-DHT-11
Certainly! Here are the connections and steps in detail:

### Connections:

1. **DHT Sensor (DHT11)**:
   - Connect the VCC pin of the DHT sensor to the 5V pin on the Arduino.
   - Connect the GND pin of the DHT sensor to any GND pin on the Arduino.
   - Connect the signal pin (data pin) of the DHT sensor to digital pin 2 (DHTPIN) on the Arduino.

2. **LED (Simulating Heater)**:
   - Connect the anode (longer leg) of the LED to digital pin 13 (LED_PIN) on the Arduino.
   - Connect the cathode (shorter leg) of the LED to GND of Arduino. 
   - Use Register if Provided , else LED being very sensitive may get damaged. 

3. **Fan**:
   - Connect one wire of the fan to digital pin 12 (FAN_PIN) on the Arduino.
   - Connect the other wire of the fan to any GND pin on the Arduino.

4. **Relay Module**:
   - Connect the VCC pin of the relay module to the 5V pin on the Arduino.
   - Connect the GND pin of the relay module to any GND pin on the Arduino.
   - Connect the signal pin (control pin) of the relay module to digital pin 11 (RELAY_PIN) on the Arduino.

5. **Liquid Crystal Display (LCD)**:
   - Connect the SDA pin of the LCD to the SDA pin (analog pin 4) on the Arduino.
   - Connect the SCL pin of the LCD to the SCL pin (analog pin 5) on the Arduino.
   - Connect the VCC pin of the LCD to the 5V pin on the Arduino.
   - Connect the GND pin of the LCD to any GND pin on the Arduino.

### Steps to Follow:

1. **Connect the Components**:
   - Make sure your Arduino board is disconnected from any power source.
   - Connect all the components according to the connections mentioned above.
     
2. **Install Libraries:**   
   **DHT Sensor Library**:
    
    - This library enables communication with the DHT11 sensor and allows you to read temperature and humidity values. You can install it from the Arduino Library Manager.
    - To install, open the Arduino IDE, go to Sketch > Include Library > Manage Libraries, then search for "DHT sensor library" and install the one provided by Adafruit.
	**LiquidCrystal_I2C Library**:
    
    - This library facilitates communication with I2C LCD displays and allows you to control them easily. It is necessary for your LCD display to function.
    - You can also install this library from the Arduino Library Manager.
    - Search for "LiquidCrystal I2C" and install the library by Frank de Brabander.

2. **Upload the Code**:
   - Open the Arduino IDE on your computer.
   - Copy the provided code into the Arduino IDE.
   - Connect your Arduino board to your computer using a USB cable.
   - Select the correct board and port from the Tools menu in the Arduino IDE.
   - Click the Upload button to upload the code to your Arduino board.

3. **Check Serial Monitor**:
   - Once the code is uploaded, open the Serial Monitor in the Arduino IDE.
   - Check if the temperature and humidity readings are displayed correctly.
   - Verify that there are no error messages in the Serial Monitor.

4. **Test the LCD Display**:
   - Ensure that your LCD display is connected properly.
   - After uploading the code, the LCD should display the temperature and humidity readings.

5. **Test the Functionality**:
   - Test the functionality of the system by varying the temperature and humidity around the DHT sensor.
   - Observe how the LED, fan, and relay module respond to changes in temperature and humidity.
   - Make sure the LED turns on when the temperature is below the threshold, the fan turns on when the humidity is above the threshold, and the relay module controls the humidifier accordingly.

By following these steps, you should be able to set up and test your Arduino-based smart greenhouse system effectively.

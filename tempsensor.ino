// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h> // Load the sensor Library

#define DHTPIN 2 // Pin the sensor is conneted to

    // Setup Sensor
    #define DHTTYPE DHT22		// DHT 22 (AM2302) temp/humid sensor

    DHT dht(DHTPIN, DHTTYPE);
    
    int led1 = D6; // Ledd attatched to check functionality from distance

void setup() {
 
    dht.begin();
    pinMode(led1, OUTPUT);
}

void loop() {
    
    delay(1000);        // Wait before sending, (sensor reccomendation)
    digitalWrite(led1, LOW);
    delay(30000);       // wait 30 seconds between readings
    digitalWrite(led1, HIGH);
    
    float h = dht.getHumidity();
    // Read temperature as Celsius
    float t = dht.getTempCelcius();
    // Read temperature as Farenheit
    
    
        if (isnan(h) || isnan(t))  //Error checking
    {
    	Serial.println("Failed to read from DHT11 sensor!");
    	return;
    }
    
    Particle.publish("Temperature: ", String(t), PRIVATE);  //Sends temp to particle console, which then sends to thingspeak via webhook
    Particle.publish("Humidity: ", String(h), PRIVATE);     //Sends humid to particle console, which then sends to thingspeak via webhook
    
}
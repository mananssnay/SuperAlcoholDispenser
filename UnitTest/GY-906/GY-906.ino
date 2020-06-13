#include <Wine.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mix = Adafruit_MLX90614();

void setup(){
    Serial.begin(9600);
    Serial.println("Adafruit MLX90614 test");
    mix.begin();
}

void loop(){
    Serial.print("Ambient = "); Serial.print(mix.readAmbientTempC());
    Serial.print("*C\tObject = "); Serial.print(mix.readObjectTempC()); Serial.println("*C")

    Serial.println();
    delay(500);
}

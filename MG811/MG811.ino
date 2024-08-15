/*
  Analog Input

  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED) connected to digital pin 13.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead().

  The circuit:
  - potentiometer
    center pin of the potentiometer to the analog input 0
    one side pin (either one) to ground
    the other side pin to +5V
  - LED
    anode (long leg) attached to digital output 13 through 220 ohm resistor
    cathode (short leg) attached to ground

  - Note: because most Arduinos have a built-in LED attached to pin 13 on the
    board, the LED is optional.

  created by David Cuartielles
  modified 30 Aug 2011
  By Tom Igoe
23
  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogInput
*/

int sensorPin = A1;    // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
float voltage=0;
float v400 = 0.12;
float v40000 = 0.09;
float A = 0;
float B = 0;
float C = 0;
float deltaV = 0;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
  Serial.println("MG811 CO2 Sensor");
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin)*6;
  //voltage=map(sensorValue, 0, 1023, 0, 6);
  //voltage=(sensorValue)/1.023;
  voltage=(sensorValue)/1.023;
  // turn the ledPin on
  Serial.print("Raw voltage: ");
  //Serial.print(voltage/1000);
  Serial.print("ppm CO2:");
  //Serial.println(voltage/1023);

  //buffer = (v400 - v40000)/(log10(400) - log10(40000)); // Delta V
  //buffer = (voltage - v400)/buffer;
  //Serial.println(buffer);
  //buffer = buffer+log10(400);
  //Serial.println(buffer);
  //Serial.println(pow(10, buffer));

  deltaV = (v400 - v40000);
  A = deltaV/(log(400) - log(40000));
  Serial.print(A);
  Serial.print(" valor medido: ");
  B = ((voltage) - v400)/(A);
  C = B+log(400);
  Serial.println(pow(10, C));
  
}

/*
 * Code by: Sergio Carrilho
 * Date modified: 10/19/2018
 * https://github.com/scarrilho/ArduinoProjects
 * Tutorial page: https://sergiocarrilho.com/2018/09/22/automatic-plant-watering-system-with-arduino/
 *
 * The Arduino drives one mini-pump to automatically water one vase, based on a timer.
 */

/* Constants */
const unsigned long SECOND = 1000; //1sec is 1000ms
const unsigned long MINUTE = 60*SECOND;
const unsigned long HOUR = 60*MINUTE;
const unsigned long DAY = 24*HOUR;

/* Drive mini pump for plant water feeding */
int motorPin = A0;    // Pump pin
int ledPin = 13;      // LED pin
int waterTime = 1*SECOND;    // Watering duration
int waittime = 3*DAY;  // Waiting time between watering intervals

int timesRan = 0;     // For logging purposes

void setup() {

  pinMode(motorPin, OUTPUT); // A0 will switch the transistor
  pinMode(ledPin, OUTPUT);   // set pin 13 to an output so we can use it to turn on the LED
  Serial.begin(9600);        // start serial 
  
  Serial.println("- Start Serial Monitor -"); // For logging purposes
}

void loop() {

  /* First time only */ 
  if(timesRan == 0) 
  {
    delay(5000); // delay 5s first time it starts
    Serial.println("First run!");
  }

  /* Usual operation */
  digitalWrite(motorPin, HIGH); // Turn pump on
  digitalWrite(ledPin, HIGH); // turn on the built-in LED
  delay(waterTime);        // Pump active time

  digitalWrite(ledPin, LOW); // turn off the built-in LED
  digitalWrite(motorPin, LOW);  // Turn pump off

  /* Track number of times it ran */
  timesRan++;
  logEvents(timesRan);

  /* Wait until next watering */
  delay(waittime);        // Delay between watering period

}

void logEvents(int numbTimes)
{
  Serial.println("Times ran: ");
  Serial.print(timesRan);
  Serial.println(); //End the line
}

/** ORG
 * A simple PWM/signal generator that permits setting of the frequency
 * in Herz and the pulse width (duty cycle). It uses a bit banging method
 * to generate the signal. This sketch can also be used to generate a PWM 
 * signal on any digital pin.
 * 
 * Author: Mario Gianota July 2020 
 * 
 * Edit for Ben Eater worst video card project 
 * VGA test 
 * Ford 11/2022
 * On reset it will pause, then send the 
 * Pulse count set in pCount
 * You can also hook up a button to
 * 52 and 50. 
 * The buttonPin does one clock pulse
 * without bounce
 * If held down it will do a slow pulse
 * The clock pin will output a clock signal while held down.
 * There is a dedicated LED pin to show when it is outputting
 * allows output pin to be used alone for clean clock 
 */
 
#define OUTPUT_PIN 2  // PWM/Signal output pin
#define OUTPUT_LED 3  // PWM/Signal output pin
float frequency;        // Frequency in Herz
float dutyCycle;      // Duty cycle (pulse width) percentage
float pCount;
float lCount;
double period;
double offFor;
double onFor; 
const int buttonPin = 52;  // the number of the pushbutton pin
const int clockPin = 50;
const int ledPin = 6;    // the number of the LED pin

// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status
int clockState = 0;
void setup() {

// This is the total number of pulses to send
// After a pause the reset/power up will send this many pulses:

// Ben Eater VGA counts:
//H sync
// 200, 210, 242, 264
//V sync
// 600, 601, 605, 625
  //pCount = 20;
  //pCount = 200;
  pCount = 199;
  //pCount = 210;
  //pCount = 209;
  //pCount = 242;
  //pCount = 241;
  //pCount = 264;
  //pCount = 263;
  //pCount = 590;

  
  // Set the frequency and the duty cycle. For most
  // purposes you will want to leave the duty cycle set
  // to 50%.
  //frequency = 9000;//100;
  frequency = 200;
  dutyCycle = 50;
  lCount = 0;

  pinMode(OUTPUT_PIN, OUTPUT);
   // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  pinMode(clockPin, INPUT);

  // Calculate the period and the amount of time the output is on for (HIGH) and 
  // off for (LOW).
  period = 1000000 / frequency;
  offFor = period - (period * (dutyCycle/100));
  onFor = period - offFor;
  delay(300);

    while (lCount < pCount)
    {
      lCount++;
        if( period > 16383 ) {
          // If the period is greater than 16383 then use the millisecond timer delay,
          // otherwise use the microsecond timer delay. Currently, the largest value that
          // will produce an accurate delay for the microsecond timer is 16383.
      
          digitalWrite(OUTPUT_PIN, HIGH);
          digitalWrite(OUTPUT_LED, HIGH);
          delay((long)onFor/1000);
          
          digitalWrite(OUTPUT_PIN, LOW);
          digitalWrite(OUTPUT_LED, LOW);
          delay((long)offFor/1000);
        } else {
          digitalWrite(OUTPUT_PIN, HIGH);
          digitalWrite(OUTPUT_LED, HIGH);
          delayMicroseconds((long)onFor);
          
          digitalWrite(OUTPUT_PIN, LOW);
          digitalWrite(OUTPUT_LED, LOW);
          delayMicroseconds((long)offFor);
        }
    }


}
    


void loop() {

 frequency = 20;
 period = 1000000 / frequency;
 offFor = period - (period * (dutyCycle/100));
 onFor = period - offFor;

  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    if( period > 16383 ) {
          // If the period is greater than 16383 then use the millisecond timer delay,
          // otherwise use the microsecond timer delay. Currently, the largest value that
          // will produce an accurate delay for the microsecond timer is 16383.
      
          digitalWrite(OUTPUT_PIN, HIGH);
          digitalWrite(OUTPUT_LED, HIGH);
          delay((long)onFor/1000);
          
          digitalWrite(OUTPUT_PIN, LOW);
          digitalWrite(OUTPUT_LED, LOW);
          delay((long)offFor/1000);
        } else {
          digitalWrite(OUTPUT_PIN, HIGH);
          digitalWrite(OUTPUT_LED, HIGH);
          delayMicroseconds((long)onFor);
          
          digitalWrite(OUTPUT_PIN, LOW);
          digitalWrite(OUTPUT_LED, LOW);
          delayMicroseconds((long)offFor);
        }
        delay(150);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }



 frequency = 99000;
 period = 1000000 / frequency;
 offFor = period - (period * (dutyCycle/100));
 onFor = period - offFor;

  clockState = digitalRead(clockPin);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (clockState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    if( period > 16383 ) {
          // If the period is greater than 16383 then use the millisecond timer delay,
          // otherwise use the microsecond timer delay. Currently, the largest value that
          // will produce an accurate delay for the microsecond timer is 16383.
      
          digitalWrite(OUTPUT_PIN, HIGH);
          digitalWrite(OUTPUT_LED, HIGH);
          delay((long)onFor/1000);
          
          digitalWrite(OUTPUT_PIN, LOW);
          digitalWrite(OUTPUT_LED, LOW);
          delay((long)offFor/1000);
        } else {
          digitalWrite(OUTPUT_PIN, HIGH);
          digitalWrite(OUTPUT_LED, HIGH);
          delayMicroseconds((long)onFor);
          
          digitalWrite(OUTPUT_PIN, LOW);
          digitalWrite(OUTPUT_LED, LOW);
          delayMicroseconds((long)offFor);
        }
       // delay(100);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
  

  
  
}

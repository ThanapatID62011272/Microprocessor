int counter = 0;



int buttonPin = 3;

int LED1 = 8;



int delayTime;



void setup()

{

pinMode(buttonPin, INPUT);

pinMode(LED1, OUTPUT);

}



void loop()

{

 //Handle input

 digitalRead(buttonPin);

 if(buttonPin = HIGH)

 {

   counter + 1;

   //Reset count if over max mode number

   if(counter == 3)

   {

     counter = 0;

   }

 }

 

 //Change mode

 if(counter == 0)

 {

   delayTime = 1000; // delay 1 second

 }

 else if(counter == 1)

 {

   delayTime = 2000; // delay 2 seconds 

 }

 else if(counter == 2)

 {

   delayTime = 3000; // delay 3 seconds 

 }

 

 //Light show!

 digitalWrite(LED1, HIGH);

 delay(delayTime); // get variables 

 digitalWrite(LED1, LOW);

 delay(delayTime); 
}

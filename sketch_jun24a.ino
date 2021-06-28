#include <Stepper.h>

#define STEPS 200

#define motorInterfaceType 1
#define motiondetect 3

Stepper stepper(STEPS, 2, 4);

int relay=7;
int pump=5;
int step_num =700;
void setup() {

  Serial.begin(9600); //activare seria monitor cu frevcenta de 9600

  pinMode(relay,OUTPUT);//setare pin valva cu functia de iesire

  pinMode(pump, OUTPUT);//setare pin pompa cu functia de iesire

  stepper.setSpeed(300);

  pinMode(4,OUTPUT);//setare pini de iesire motor directie

  pinMode(2,OUTPUT);//setare pin activare motorului prin pasi
  pinMode(motiondetect, INPUT);//setare pin senzor IR cu functia de intrare
}
  void loop() {

Serial.print(digitalRead(motiondetect)); //printare motiondetect 1010 seznorul functioneaza
while (digitalRead(motiondetect) == HIGH) { //bucla verificare a detectare si rulare a sistemului
Serial.print(digitalRead(motiondetect));

  
    digitalWrite(relay,LOW);    // releul este oprit condiție(motorul pornit)
    digitalWrite(pump,LOW);
  delay(3000);
      break;
    }


    while (digitalRead(motiondetect) == LOW) { //bucla verificare a detectiei paharului cand nu este pahar
   
 
    digitalWrite(relay,HIGH);    // releul este oprit condiție(motorul pornit)
digitalWrite(pump,HIGH);
     stepper.step(0); //oprire motor pas cu pas
     
  
break;
    }
stepper.step(step_num);
Serial.print("Electrovalva");
Serial.println(digitalRead(relay));
Serial.println("pompa");
Serial.print(digitalRead(pump));

  }
  

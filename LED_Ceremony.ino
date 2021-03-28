#define delay50 100

int MyLED[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
int num_of_led;

void setup(){
  num_of_led = sizeof(MyLED) / sizeof(int);
  for(int i = 0; i < num_of_led; i++){
  pinMode(MyLED[i], OUTPUT);
} 
}

void loop(){
  
  delay(1000);
  LEDON();
  delay(1000);
  LEDOFF();
  for (int i = 0; i < 6; i++) {pattern1();}
  for (int i = 0; i < 6; i++) {pattern2();}
  for (int i = 0; i < 6; i++) {pattern3();}
  for (int i = 0; i < 6; i++) {pattern4();}
  for (int i = 0; i < 35; i++){pattern5();}
  for (int i = 0; i < 6; i++) {pattern6();}
  for (int i = 0; i < 20; i++){pattern7();}
  for (int i = 0; i < 20; i++){pattern8();}
  for (int i = 0; i < 6; i++) {pattern9();}
// for (int i = 0; i < 6; i++) {pattern10();}
//  for (int i = 0; i < 50; i++){pattern11();}
//  for (int i = 0; i < 50; i++){pattern12();}
  LEDOFF();
  delay(5000);

}

//Turn ON all LED
void LEDON(){
  for(int i = 0; i < num_of_led; i++){
    digitalWrite(MyLED[i], HIGH);
  }
}

//Turn OFF all LED
void LEDOFF(){
  for(int i = 0; i < num_of_led; i++){
    digitalWrite(MyLED[i], HIGH);
  }
}

//Left to right
void pattern1(){
  for(int i = 0; i < num_of_led; i++){
    digitalWrite(MyLED[i], HIGH);
    delay(100);
    digitalWrite(MyLED[i], LOW);
  }
}

//Right to left
void pattern2(){
  for(int i = num_of_led; i > 0; i--){
    digitalWrite(MyLED[i - 1], HIGH);
    delay(100);
    digitalWrite(MyLED[i - 1], LOW);
  }
}

//Left to right fill
void pattern3(){
  for(int i = 0; i < num_of_led; i++){
    digitalWrite(MyLED[i], HIGH);
    delay(100);
  }

  for(int i = num_of_led; i > 0; i--){
    digitalWrite(MyLED[i - 1], LOW);
    delay(100);
  }
}

//Right to left fill
void pattern4(){
  LEDON();
  
  for(int i = 0; i < num_of_led; i++){
    digitalWrite(MyLED[i], LOW);
    delay(100);
  }
  
  for(int i = num_of_led; i > 0; i--){
    digitalWrite(MyLED[i - 1], HIGH);
    delay(100);
  }
  
  LEDOFF();
  
}

// Alternate lEDs
void pattern5(){
  for(int i = 0; i < num_of_led; i = i + 2){
    digitalWrite(MyLED[i], HIGH);
    digitalWrite(MyLED[i + 1], LOW);
  }
  delay(100);
  for(int i = 0; i < num_of_led; i = i + 2){
    digitalWrite(MyLED[i], LOW);
    digitalWrite(MyLED[i + 1], HIGH);
  }
  delay(100);
}

// Oscillating LEDs
void pattern6(){
  for(int i = 0; i < num_of_led; i++){
    digitalWrite(MyLED[i], HIGH);
    delay(100);
    digitalWrite(MyLED[i], LOW);
  }

  for(int i = num_of_led; i > 0; i--){
    digitalWrite(MyLED[i - 1], LOW);
    delay(100);
    digitalWrite(MyLED[i], LOW);
  }
}

// Outside to Inside
void pattern7(){
  for(int i = 0; i < num_of_led / 2; i++){
    digitalWrite(MyLED[i], HIGH);
    digitalWrite(MyLED[num_of_led - 1 - i], HIGH);
    delay(100);
    digitalWrite(MyLED[i], LOW);
    digitalWrite(MyLED[num_of_led - 1 - i], LOW);
  }
}

// Inside to Outside
void pattern8(){
  for(int i = (num_of_led / 2) - 1; i >= 0; i--){
    digitalWrite(MyLED[i], HIGH);
    digitalWrite(MyLED[num_of_led - 1 - i], HIGH);
    delay(100);
    digitalWrite(MyLED[i], LOW);
    digitalWrite(MyLED[num_of_led - 1 - i], LOW);
  }
}

// Left to right 3 LEDs
void pattern9(){
  for(int i = 0; i < num_of_led + 3; i++){
    if(i <= num_of_led){
    digitalWrite(MyLED[i], HIGH);
  }
  if(i > 2){
    digitalWrite(MyLED[i - 3], LOW);
  }
  delay(100);
  }
}

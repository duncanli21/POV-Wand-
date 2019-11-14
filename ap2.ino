//include libraries
//#include <stdlib.h>
//#include <string.h>

//Define all of LEDs
#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5
#define LED5 6
#define LED6 7
#define LED7 8
#define ain a0

//Message to be displayed
String s = "HIGH";
int l = s.length();

//Letter matrix
int letter[26][5] = {
    
    {31, 36, 68, 68, 127}, //A - 0
    {127, 73, 73, 73, 54}, //B - 1
    {62, 65, 65, 65, 34}, //C - 2
    {127, 65, 65, 65, 62}, //D - 3
    {127, 73, 73, 73, 65}, //E - 4
    {127, 72, 72, 72, 64}, //F - 5 
    {62, 65, 65, 69, 38}, //G - 6
    {127, 8, 8, 8, 127}, //H - 7
    {0, 65, 127, 65, 0}, //I - 8
    {0, 2, 65, 65, 126}, //J - 9
    {127, 8, 20, 34, 65}, //K - 10 
    {127, 1, 1, 1, 1}, //L - 11 
    {127, 32, 24, 32, 127}, //M - 12
    {127, 16, 8, 4, 127}, //N - 13
    {62, 65, 65, 65, 62}, //O - 14
    {127, 72, 72, 72, 48}, //P - 15
    {60, 66, 66, 66, 61}, //Q - 16
    {127, 72, 76, 74, 49}, //R - 17
    {50, 73, 73, 73, 50}, //S - 18
    {64, 64, 127, 64, 64}, //T - 19
    {126, 1, 1, 1, 126}, //U - 20
    {124, 2, 1, 2, 124}, //V - 21
    {126, 1, 6, 1, 126}, //W - 22
    {99, 20, 8, 20, 99}, //X - 23
    {112, 8, 15, 8, 112}, //Y - 24 
    {67, 69, 73, 81, 67} //Z - 25
    
  };

void setup() {
  // set all pins to be output pins
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
}

void loop() {
  
     Serial.print("foreward loop");

  //forward loop
   for(int i = 0; i < l; i++){
    char c = s[i];
    Serial.print("foreward loop");
    getChar(c, 0);  
   }
   
  //backward loop
  for(int i = l; i >= 0; i--){
    char c = s[i];
    getChar(c, 1); 
  }
}

void getChar(char c, int flag){
  int current[5];
  Serial.print("Get Char");
  //make smaller array that is just the current letter
  for(int i = 0; i < 5; i++){
    current[i] = letter[c-65][i];
  }
  
  ledSet(current, flag);
}

void ledSet(int array[5], int flag){
  if(flag == 0){
    for(int i = 0; i < 5; i++){
      char BinArr[7];
      itoa(array[i], BinArr, 2); 
       
      ledon(BinArr);
      
      delay(100);
        }

  }else{
    for(int i = 4; i >= 0; i--){
      char BinArr[7];
      itoa(array[i], BinArr, 2);
      
      ledon(BinArr);
      
      //add delay
    }
  }
}

void ledon(char BinArr[7]){

      if(BinArr[0] == 1){
        digitalWrite(LED1, HIGH);
      }
      else
      {
        digitalWrite(LED1, LOW);
      }

      
      if(BinArr[1] == 1){
        digitalWrite(LED2, HIGH);
      }
       else
      {
        digitalWrite(LED2, LOW);
      }

      
      if(BinArr[2] == 1){
        digitalWrite(LED3, HIGH);
      }
       else
      {
        digitalWrite(LED3, LOW);
      }

      
      if(BinArr[3] == 1){
        digitalWrite(LED4, HIGH);
      }
       else
      {
        digitalWrite(LED4, LOW);
      }

      
      if(BinArr[4] == 1){
        digitalWrite(LED5, HIGH);
      }
       else
      {
        digitalWrite(LED5, LOW);
      }

      
      if(BinArr[5] == 1){
        digitalWrite(LED6, HIGH);
      }
       else
      {
        digitalWrite(LED6, LOW);
      }

      
      if(BinArr[6] == 1){
        digitalWrite(LED7, HIGH);
      }
       else
      {
        digitalWrite(LED7, LOW);
      }
}

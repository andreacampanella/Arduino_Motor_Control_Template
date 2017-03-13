/*************************************************************
 Motor Control Template 
 By Andrea "emuboy" Campanella
 emuboy85@gmail.com
*************************************************************/

#define M1A_PWM 12
#define M1A_Init 3
#define M1A_Break 9

#define M1B_PWM 13
#define M1B_Init 11
#define M1B_Break 8


/*
  M_Init  : enable line of the motor
  M_Break : hold line of the motor 
  M_PWM   : PWM output pin
  M_SPEED : Speed (0-255) 
  M_DIR   : Direction (1: Forward 2: Backward)
*/
void Move(int M_Init , int M_Break , int M_PWM, int M_SPEED, int M_DIR){    
  digitalWrite(M_Init, M_DIR); //Establishes forward direction of Channel A
  digitalWrite(M_Break, LOW);   //Disengage the Brake for Channel A
  analogWrite (M_PWM, M_SPEED);   //Spins the motor on Channel A at full speed
}
void Break(int M_Break){    
  digitalWrite(M_Break, HIGH);  //Engage the Brake
}


void setup() {
  Serial.begin(9600);
  Serial.print("Start");
  //Setup Channel A
  pinMode(M1A_Init , OUTPUT); //Initiates Motor Channel A pin
  pinMode(M1A_Break, OUTPUT);  //Initiates Brake Channel A pin

  //Setup Channel B
  pinMode(M1B_Init , OUTPUT); //Initiates Motor Channel B pin
  pinMode(M1B_Break, OUTPUT);  //Initiates Brake Channel B pin
  
}

void loop(){
  Serial.print("loop");
  //Test Motors
  Move(M1A_Init,M1A_Break,M1A_PWM,255 , 1);
  Move(M1B_Init,M1B_Break,M1B_PWM,255 , 1);

  delay(3000);

 Break(M1A_Break);
 Break(M1B_Break);

 delay(3000);
   
}


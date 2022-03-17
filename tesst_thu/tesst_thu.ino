#Hoai ham hap ahihi
#abc
int ENA = 9;  //10
int IN1 = 4; //5
int IN2 = 2;//6
int IN3 = 5;//9
int IN4 = 8;//8
int ENB = 3;//3
int POT = 0;
void setup() {
  pinMode(IN1, OUTPUT);     //phai
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);     //trai
  pinMode(IN4, OUTPUT);
  pinMode(POT, INPUT);
  Serial.begin(9600);
}

void TienLui(){
  digitalWrite(IN1, HIGH);   //tien
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);    //tien
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 115);    //12
  analogWrite(ENB, 120);    //34
  delay(3000);
  digitalWrite(IN1, LOW);   //tien
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);    //tien
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 115);
  analogWrite(ENB, 120);
  delay(3000); 
}

void Tien(int a){
  digitalWrite(IN1, LOW);   //tien
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);    //tien
  digitalWrite(IN4, LOW);
  analogWrite(ENA, a);
  analogWrite(ENB, a + 5);
}

void Lui(int a){
  digitalWrite(IN1, HIGH);     //lui
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);     //lui
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, a);
  analogWrite(ENB, a + 5);
}


  int target = 460;
void dk(){
  int value = analogRead(POT);

  if(value > target - 50 && value < target + 50){
    Tien (100); 
  }
  else if(value < target - 50){
    Lui((value - target)/30);
  }
  else if(value > target + 50){
    Tien((target - value)/30);
  }
}

void loop() {
  /*digitalWrite(IN1, HIGH);   //tien
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);    //tien
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);*/
  //TienLui();
  int value = analogRead(POT);
  //int doc = analogRead(POT);
  //Serial.print(doc);
  
  Serial.print(value);
  Serial.print("\n");
  delay(100);
  dk();
  //Tien(200);
}

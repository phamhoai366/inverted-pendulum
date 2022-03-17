#define IN1A 9
#define IN1B 4
#define PWM1 2
#define IN2A 5
#define IN2B 8
#define PWM2 3
#define POT 0

int errorcw = 0;
int errorccw = 0;
int correction = 0;
double kp = 20;
double ki = 1.5;
double kd = 0.5
            ;
int PID = 0;
int error = 0;
int last_error = 0;
int angle = 0;
int sp = 460;

void setup()
{
  Serial.begin(9600);
  pinMode(IN1A, OUTPUT);
  pinMode(IN1B, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(IN2A, OUTPUT);
  pinMode(IN2B, OUTPUT);
  pinMode(PWM2, OUTPUT);
  pinMode(POT, INPUT);

}

int calcPid(int error)
{
  PID = (kp * (error)) + (ki * (error + last_error)) + (kd * (error - last_error));
  last_error = error;
  PID = constrain(PID, 0, 255);
  //return (60 + ((PID*195)/255));
  //constrain() rang buoc, PID = PID neu PID thuoc [0,255], PID < 0 thi PID = 0, PID > 255 thi PID = 255
  return PID;
}

void loop()
{
  char buffer[5];
  angle = analogRead(POT);
  Serial.print(itoa((angle), buffer, 10));
  Serial.print("       ");
//  Serial.println(calcPid(sp - angle));
  if (angle >= 800 || angle <= 20 || (angle >= sp - 2 && angle <= sp + 2)) {
    Serial.println("111111111");
    digitalWrite(IN2A, LOW);
    digitalWrite(IN2B, LOW);
    digitalWrite(IN1A, LOW);
    digitalWrite(IN1B, LOW);
  }
  else {
    if (angle < sp - 2)
    {
      errorcw = (sp - angle);
      correction = calcPid(errorcw);
      analogWrite(PWM1, correction);
      Serial.println(correction);
      digitalWrite(IN2A, LOW);
      digitalWrite(IN2B, HIGH);
      analogWrite(PWM2, correction);
      digitalWrite(IN1A, HIGH);
      digitalWrite(IN1B, LOW);
    }
    if (angle > sp + 2)
    {
      errorccw = (angle - sp);
      correction = calcPid(errorccw);

      analogWrite(PWM1, correction);
      Serial.println(correction);
      digitalWrite(IN2A, HIGH);
      digitalWrite(IN2B, LOW);
      analogWrite(PWM2, correction);
      digitalWrite(IN1A, LOW);
      digitalWrite(IN1B, HIGH);
    }
  }
  //  delay(50);
  return;
}

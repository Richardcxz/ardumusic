 const int pinoled = 7;
const int pinoLDR = A5;
int valorLdr;

void setup()
{
  Serial.begin(9600);
  pinMode(pinoled, OUTPUT);
  pinMode(pinoLDR, INPUT);
}

void loop()
{
  valorLdr = analogRead(pinoLDR);
  if(valorLdr > 700){
     Serial.print("\n ligado");
    digitalWrite(pinoled, LOW);
  } else {
    Serial.print("\n desligado");
    digitalWrite(pinoled, HIGH);
  }
  delay(1000);
}

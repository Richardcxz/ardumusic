void setup() {
  Serial.begin(9600);
  pinMode(10,OUTPUT);
}

void loop() {
String ml;
int melo[7];
ml = Serial.readString();


melo[1]=ml.substring(0,3).toInt();melo[2]=ml.substring(3,6).toInt();
melo[3]=ml.substring(6,9).toInt();melo[4]=ml.substring(9,12).toInt();melo[5]=ml.substring(12,15).toInt();
melo[6]=ml.substring(15,18).toInt();melo[7]=ml.substring(18,21).toInt();

int melody[] = { 
melo[1],melo[2],melo[3],melo[4],melo[5],melo[6],melo[7]
};
int noteDurations[] = { 
555,555,555,555,555,555,555
};

  for (int thisNote = 0; thisNote < sizeof(melody) / sizeof(int); thisNote++)
  {    
    tone(11, melody[thisNote], noteDurations[thisNote] * .7);    
    delay(noteDurations[thisNote]);    
    noTone(11);
  }
}
float vpp = 0.0048828125;
float sensitivity = 0.6;
float wattSecond;
float wattSecondu;
float voltsu = 5;
bool balance = true;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(balance == true)
    digitalWrite(7, HIGH);
  else
    digitalWrite(7, LOW);
  
  float watts = 0;
  float wattsu = 0;
  for(int i = 1; i<=10; i++){
    float amperage= .1; //(vt/sensitivity) + .1;
    float volts = (analogRead(A1) * 5)/1023;
    watts = watts + (amperage*volts);

    int currentu = analogRead(A2) + 1;
    float vtu = currentu * vpp;
    vtu -= 2.5;
    float amperageu= (vtu/sensitivity) + .1;
    wattsu = wattsu + (amperageu*voltsu);
    
    delay(100);
  }
  watts = watts/10;
  wattSecond = watts;
  Serial.println("Watt Seconds Produced: " + String(wattSecond));
  wattsu = wattsu/10;
  wattSecondu = wattsu;
  Serial.println("Watt Seconds Used: " + String(wattSecondu));
  
}

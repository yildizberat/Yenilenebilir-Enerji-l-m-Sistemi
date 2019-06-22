int buton_1_SENSOR = 9;     // buton 1in bağlandığı pin
int buton_2_SENSOR =7;    // buton 2nin bağlandığı pin
int buton_3_SENSOR = 11; // buton 3ün bağlandığı pin
const int analogIn1 = 0; //Connect current sensor with A0 of Arduino
const int analogIn2 = 0;
const int analogIn3 = 0;
int mVperAmp = 185; // use 100 for 20A Module and 66 for 30A Module
int RawValue1= 0;
int RawValue2= 0;

int  butonDurumu_1_SENSOR =0;
int  butonDurumu_2_SENSOR =0;
int  butonDurumu_3_SENSOR =0;
int mvperAmp = 185;
int ACSoffset = 2500; 
double Voltage = 0; //voltage measuring
double Amps = 0;// Current measuring
double Powers = 0;
int counter = 0;
int voltage1=0;
int voltage2=0;
int voltage3=0;
int amps1=0;
int amps2=0;
int amps3=0;
int power1=0;
int power2=0;
int power3=0;





void setup() {
  pinMode(buton_1_SENSOR, INPUT);
  pinMode(buton_2_SENSOR, INPUT);
  pinMode(buton_3_SENSOR, INPUT);
  Serial.begin(9600);//baud rate at which arduino communicates with Laptop/PC
  
}
 
double VoltageFonk(double value){ 
  double Voltage = (value / 1024.0) * 5000; // Gets you mV
  return Voltage;
  }


double AmpsFonk(int rawValue , double volt )
{ 
  double Amps = ((volt - ACSoffset) / mVperAmp);; 
  return Amps;
  }  

double PowerFonk(int Voltage , double Amps ){ // toplama adında fonksiyon tanımladık
  double PowerVal = Voltage * Amps;
  return PowerVal;
  }  
void loop() //method to run the source code repeatedly
{
 butonDurumu_1_SENSOR = digitalRead(buton_1_SENSOR);
 RawValue1 = analogRead(analogIn1);
 RawValue2 = analogRead(analogIn2);

 
 
 if (butonDurumu_1_SENSOR  == HIGH) {

  counter = 1;

  while ( counter != 0){
    
  Voltage = VoltageFonk(RawValue1);
  Amps = AmpsFonk(RawValue1 , Voltage);
  Powers = PowerFonk(Voltage , Amps);
  voltage1 = Voltage;
  amps1 = Amps;
  power1 = Powers;
 Serial.print("Raw Value 1. Sensor =  " );
 Serial.print(RawValue1);
 Serial.print("\n");
 Serial.print("mV 1. Sensor = "); 
 Serial.print(Voltage,3); 
 Serial.print("\n");
 Serial.print("Amps 1.Sensor ="); 
 Serial.println(Amps,3);
 Serial.print("\n");
  Serial.print("Power 1. Sensor = "); 
 Serial.println(Powers,3);
  Serial.print("\n");
  Serial.print("******************************************************************************************************\n");
  counter = 0;
  }
Voltage = 0; //voltage measuring
Amps = 0;// Current measuring
Powers = 0;
  } 
 butonDurumu_2_SENSOR = digitalRead(buton_2_SENSOR); 
  if (butonDurumu_2_SENSOR  == HIGH) {

  counter = 1;

  while ( counter != 0){
    
  Voltage = VoltageFonk(RawValue1);
  Amps = AmpsFonk(RawValue1 , Voltage);
  Powers = PowerFonk(Voltage , Amps);
  voltage2 = Voltage;
  amps2 = Amps;
  power2 = Powers;
 Serial.print("Raw Value 2. Sensor =" ); // prints on the serial monitor
 Serial.print(RawValue1, "\n"); //prints the results on the serial monitor
 
 Serial.print("mV 2. Sensor = "); // shows the voltage measured 
 Serial.print(Voltage,3); // the '3' after voltage allows you to display 3 digits after decimal point
 Serial.print("\n");
 Serial.print("Amps 2.Sensor ="); // shows the voltage measured 
 Serial.println(Amps,3);// the '3' after voltage allows you to display 3 digits after decimal point
 Serial.print("\n");
  Serial.print("Power 2. Sensor ="); // shows the voltage measured 
 Serial.println(Powers,3);// the '3' after voltage allows you to display 3 digits after decimal point
  Serial.print("\n");
 Serial.print("******************************************************************************************************\n");
  counter = 0;
  }
Voltage = 0; //voltage measuring
Amps = 0;// Current measuring
Powers = 0;
  } 
  
  butonDurumu_3_SENSOR = digitalRead(buton_3_SENSOR); 

if (butonDurumu_3_SENSOR  == HIGH) {

 counter = 1;
  while ( counter != 0){

  
  Voltage = VoltageFonk(RawValue1);
  Amps = AmpsFonk(RawValue1 , Voltage);
  Powers = PowerFonk(Voltage , Amps);
   
voltage3 = Voltage;
  amps3 = Amps;
  power3 = Powers;

  
 Serial.print("Raw Value 3. Sensor = \n" ); 
 Serial.print(RawValue1); 
 
 Serial.print("mV 3. Sensor = \n"); 
 Serial.print(Voltage,3); 

 Serial.print("Amps 3.Sensor = \n"); 
 Serial.println(Amps,3);

  Serial.print("Power 3. Sensor = \n"); 
 Serial.println(Powers,3);
 Serial.print("******************************************************************************************************\n");
counter = 0;
  }
  
Voltage = 0; 
Amps = 0;
Powers = 0;  
 }

  

}

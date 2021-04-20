int pinSerial = 2;
int pSclk = 3;
int prclk = 4;
int valor[]={0,1,0,0,0,0,1,1};


void setup()
{
  pinMode(pinSerial, OUTPUT);
  pinMode(pSclk, OUTPUT);
  pinMode(prclk, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  Serial.println("");
 
    
  PruebaLeds();
  
}
//ingrearia así: binraio [LSB,...,MSB]
void SerialC(int *ptr){
  for(int i=0;i<8;i++){
    if(i<8){
    digitalWrite(pinSerial,*(ptr+i));
    digitalWrite(prclk,LOW);
    digitalWrite(prclk,HIGH);
   
    }
    else break;}
    
     
    digitalWrite(pSclk,LOW);
    digitalWrite(pSclk,HIGH);   
     
  
}
void PruebaLeds(){
        //LSB...........MSB	
  int v[]={1,1,1,1,1,1,1,1};
  int *ptr=&v[0];
  SerialC(ptr);
}




int pinSerial = 2;
int prclk = 3;
int pSclk= 4;
int state=0;

int ver[]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int A[]={1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,0,1,1,1,1,1,1,0};
int B[]={0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0};
int C[]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int D[]={0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0};
int E[]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int F[]={0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int G[]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0};
int H[]={1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1};

int cinco[]={0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};



void setup()
{  
  pinMode(pinSerial, OUTPUT);
  pinMode(pSclk, OUTPUT);
  pinMode(prclk, OUTPUT);
  Serial.begin(9600);
  
}


//-------------------------------------------
void loop()
{
 
  
  while(state==0)
  {
    state=1;
    Serial.print("Que desea realizar :\n");
    Serial.print("1) verificar funioncionamiento de los leds \n2) Ingresar patron por serial \n 3) Mostrar Secuencia de patrones a cierto tiempo\n");
    
    while(state==1)
    {
      if(Serial.available()>0)
      {
        char opc;
        
        while(Serial.available()>0)
        {
          opc= Serial.read();
         
        }
        if(opc=='1')
        {
          
          state=2;
         
        }
       else if(opc=='2')
        {
         	state=3;
         	
        }
       else if(opc=='3')
        {
          state=4;
          
        }
       else {state=0;}
       }
     }
     while(state==2)
     {
       Serial.print("\nVerificacion de los leds\n");
       verificacion(ver);
       state=0;
     }
    while(state==3)
     {
        Serial.print("\nIngrese el patron a observar segun el manual: \n");
        state=5;
        String bits;
        while(state==5)
        {

          if(Serial.available()>0)
          {
            while(Serial.available()>0)
            {
              bits+=(char)Serial.read();
            }
          }

          if(bits.length()>=64)
          {
            state=3;
          }  
        }

       str2car2(bits);

       state=0;
     }
    while(state==4)
     {
        Serial.print("\nIngrese los caracteres que desea observar\n");
        state=6;
        bool datafull=false;
        String cantidad="";
        String secuencia="";
        String tiempoD="";
                     
         while(state==6)
        {
          
          if(Serial.available()>0)
          {
            while(Serial.available()>0)
            {
              secuencia+= (char) Serial.read();
           
            }
           
           datafull=true;
          
           }
           if(datafull==true)
           {
             state=4;
           }
           delay(1000);
        }
        Serial.println("\nIngrese el tiempo (milesegundos) entre cada patron\n");
        state=7;
        datafull=false;
         while(state==7)
        {
          if(Serial.available()>0)
          {
            while(Serial.available()>0)
            {
              tiempoD+=(char)Serial.read();
            }
           datafull=true;
           
         }
            if(datafull==true)
           {
             state=4;
           }
           delay(1000);
        }
           
	   publik(secuencia,tiempoD);
       state=0;
		}
	}
 }
                     
//-------------------------------------------
void str2car2(String vector)
{
  int vecInt[64];
  for(int i=0;i<64;i++)
  {
    vecInt[i]=(vector[i]-48);
  }
  caracter2(vecInt);
}
//-------------------------------------------
void publik(String secuencia,String tiempo)
{
  int t=tiempo.toInt();
  char nombre;
  for(int i=0;i<secuencia.length();i++)
  {
    
    Serial.println(secuencia[i]);
    nombre=secuencia[i];
    findVector(nombre);
    delay(t);
  }
  
}
//------------------------------------------- 
void caracter2(int car1[])
{
  Serial.print("Funcion caracter2\n");
  int j=0;
  for(int i=0;i<64;i++)
  { 
    digitalWrite(pinSerial,*(car1+i));
    SCLK();j++;    
    if(j==8){j=0;RCLK();}
  }
}

//-------------------------------------------
void verificacion(int ver[]){
 caracter2(ver);
}
void findVector(char nombre)
{
  
  int *ptr;
  
  if(nombre=='a'|| nombre=='A')
  {
    ptr=&A[0];
    
  }
  else if(nombre=='b' || nombre=='B')
  {
   ptr=&B[0];
  }
   else if(nombre=='c' || nombre=='C')
  {
   ptr=&C[0];
  }
   else if(nombre=='d' || nombre=='D')
  {
   ptr=&D[0];
  }
   else if(nombre=='e' || nombre=='E')
  {
   ptr=&D[0];
  }
  else if(nombre=='f' || nombre=='F')
  {
   ptr=&D[0];
  }
  else if(nombre=='g' || nombre=='G')
  {
   ptr=&D[0];
  }
  else if(nombre=='h' || nombre=='H')
  {
   ptr=&D[0];
  }
 caracter2(ptr);
}
//-------------------------------------------------
//FUNCION PARA ENVIAR DATOS A SCLK
void SCLK(){
  
  delay(20);
  digitalWrite(pSclk, LOW);
  delay(20);
  digitalWrite(pSclk, HIGH);
}
//FUNCION PARA ENVIAR DATOS A RCLK
void RCLK(){
  
  digitalWrite(prclk,LOW);
  delay(10);
  digitalWrite(prclk,HIGH);
  delay(10);
  digitalWrite(prclk,LOW);
}

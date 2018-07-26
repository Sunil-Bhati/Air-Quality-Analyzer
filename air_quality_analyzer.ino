unsigned int gas,smoke,cnt1=0,cnt2=0,cnt3=0;
unsigned char temp;

// this runs once
void setup() {                
  // enable debug serial
  Serial.begin(9600); 
Serial.print("gas,smoke,temp\n");  
}

void loop() {
  
temp=analogRead(A0);
temp=(temp/2)-1;
delay(50);

smoke=analogRead(A1);
delay(50);

gas=analogRead(A2);
delay(50);

if(temp>20)     // 40
{
  if(cnt2==0)
  {
  sms_send1();
  cnt3=1;
  }
}

if(temp<20)     //40
{
  cnt3=0;
}

if(gas>50)    //300
{
  if(cnt1==0)
  {
  sms_send1();
  cnt1=1;
  }
}

if(smoke>50)   //300
{
  if(cnt2==0)
  {
  sms_send1();
  cnt2=1;
  }
}

if(gas<50)  //300
{
  cnt1=0;
}

if(smoke<50) //300
{
  cnt2=0;
}

}  //loop end

void sms_send1(){

  Serial.print(gas);     
  delay(500);
  Serial.print(",");
   delay(500);
  Serial.print(smoke);          
  delay(500);
  Serial.print(",");
   delay(500);
  Serial.print(temp);        
  delay(500);
  Serial.print("\n");
  delay(500);
}

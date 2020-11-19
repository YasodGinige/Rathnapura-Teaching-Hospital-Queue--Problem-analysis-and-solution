#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define S4 6
#define S5 7
#define S6 8

#define P0 9
#define P1 10
#define P2 11
#define P3 12

#define SVALUE 800
#define PVALUE 800

int display_num;
int digits[4]={0,0,0,0}
              
             //0 1 2 3 4 5 6
int SSMatrix={{1,1,1,0,1,1,1}, //0
              {0,0,1,0,0,1,0}, //1
              {1,0,1,1,1,0,1}, //2
              {1,0,1,1,0,1,1}, //3
              {0,1,1,1,0,1,0}, //4
              {1,1,0,1,0,1,1}, //5
              {1,1,0,1,1,1,1}, //6
              {1,0,1,0,0,1,0}, //7
              {1,1,1,1,1,1,1}, //8
              {1,1,1,1,0,1,0}} //9

void setup() {
  pinMode(S0,OUTPUT);
  pinMode(S1,OUTPUT);
  pinMode(S2,OUTPUT);
  pinMode(S3,OUTPUT);
  pinMode(S4,OUTPUT);
  pinMode(S5,OUTPUT);
  pinMode(S6,OUTPUT);

  pinMode(P0,OUTPUT);
  pinMode(P1,OUTPUT);
  pinMode(P2,OUTPUT);
  pinMode(S3,OUTPUT);
}

void setNewDigits(){
  digits[0] =number%10;
  number/=10;
  digits[1] =number%10;
  number/=10;
  digits[2] =number%10;
  number/=10;
  digits[3] =number%10;
  number/=10; 
}
void setSevenSegment(int d){
  for(int s=0;s<7;s++){
    String curPin = "S"+String(s);
    digitalWrite(curPin,SSMatrix[d][s]);
  }
}
void displayDigits(){
  
  for(int d=0;d<4;d++){
    String digitPin ="P"+String(d);
    setSevenSegment(digits[d]);
    digitalWrite(digitPin,HIGH);
    delay(10);
    digitalWrite(digitPin,LOW); 
  }
}
void displayNumber(int number) {
  
  setNewDigits();
  displayDigits();
  display_number=number;  

}

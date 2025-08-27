//////////////////////*****************D.C Motor Control********************///////////////////////////////
//////////////////////***************Author: Siddhanta Borah***************///////////////////////////////

#include <reg51.h>

//////////////////////////////// Defines Pins	for Motor1	
 
sbit IN1 =P2^1;             
sbit IN2 =P2^2; 
//////////////////////////////// Defines Pins	for Motor2	
sbit IN3 =P2^4;             
sbit IN4 =P2^5;  

unsigned char cmd;

/////////////////////////////////////function for giving a delay of  millisecond

void delay(int a)
{
 unsigned int i,j; 
 for(i=0;i<a;i++)
 for(j=0;j<1275;j++);
}
////////////////////////////////////// Function to initialize serial communication
void initialize_serial()	
	{ 
	TMOD=0x20;  //use Timer 1, 8 bit ,auto reload
	TH1=0xFD;   //9600 baudrate
	SCON=0x50;
	TR1=1;     //start timer
  //RI=0;
	}
////////////////////////////////////// Function to Receive data serially
void receive()
	{
	 while(RI==0);
	 cmd=SBUF;
	 RI=0;
	}
///////////////////////////////////////Function to move Left
void move_left()
   { 	
	  IN1=0; IN2=1;
	  IN3=1; IN4=0;
   }
///////////////////////////////////////Function to move Right

void move_right()
   { 	
	  IN1=1; IN2=0;
	  IN3=0; IN4=1;
   }
///////////////////////////////////////Function to move forward

void move_forward()
   { 
	  IN1=1; IN2=0;
	  IN3=1; IN4=0; 
   }

///////////////////////////////////////Function to move backward

void move_backward()
   { 
		IN1=0; IN2=1;
	  IN3=0; IN4=1; 	 
   }
///////////////////////////////////////Function to stop

void stop()
   { 	
		IN1=0; IN2=0;
	  IN3=0; IN4=0; 	
	 }     
 
////////////////////////////////********** Main program**************************//////////////////////////
void main()
{   
  IN1=0; IN2=0;  
	IN3=0; IN4=0; 
  initialize_serial(); 
	while(1)
	{  
	 receive();
	 if(cmd=='F')
	 {
		 move_forward();
		 delay(10);
		 //stop();
	 }
	 else if(cmd=='B')
	 {
		 move_backward();
		 delay(10);
		 //stop();
	 }
	 else if(cmd=='L')
	 {
		 move_left();
		 delay(10);
		 //stop();
	 }
	 else if(cmd=='R')
	 {
		 move_right();
		 delay(10);
		 //stop();
	 }
	 else if(cmd=='S')
	 {
		 stop();
		 delay(10);
	 }	
  }
}

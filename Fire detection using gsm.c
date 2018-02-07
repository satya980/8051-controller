#include<reg51.h>
sbit rs=P1^0;
sbit rw=P1^1;
sbit en=P1^2;
sbit sensor=P1^5;
unsigned int cmd[]={0x38,0x0e,0x01,0x06,0x80};
unsigned char at1[]="AT/r";
unsigned char at2[]="AT+CMGF=1/r";
unsigned char at3[]={'A','T','+','C','M','G','S','=',0x22,'+','9','1','9','6','5','8','4','0','4','3','4','0',0x22,0x0d};
unsigned char at4[]="Fire DETECTED";
unsigned char lcdmsg[]="MESSAGE SEND";
unsigned int a,a1,b,c,d,e,f;
	
	
void delay()
{

for(a1=0;a1<32000;a1++);
	}	

	 void cmmd()
{
rs=0;
rw=0;
en=1;
delay();
en=0;
}
void dat()
{
rs=1;
rw=0;
en=1;
delay();
delay();

en=0;
}

void nexline()
{
	SBUF=0x0d;
	while(TI==0);
	TI=0;
	}

	
	void main()
	{
			while(1)
		{
		TMOD=0x20;
		SCON=0x50;
		TR1=1;
		TH1=0xfd;
		
			
	for(a=0;a<6;a++)
{
P2=cmd[a];
cmmd();
}
delay();	




for(c=0;c<2;c++)
{
SBUF=at1[c];
while(TI==0);
TI=0;
}
nexline();
delay();


	

for(c=0;c<9;c++)
{
	SBUF=at2[c];
while(TI==0);
TI=0;
}
nexline();
delay();


l:while (sensor==1);

for(c=0;c<24;c++)
{
SBUF=at3[c];
while(TI==0);
TI=0; 
}
delay();



for(c=0;c<13;c++)
{
SBUF=at4[c];
while(TI==0);
TI=0;
}


SBUF=0x1a;
while(TI==0);
TI=0;
delay();

for(a=0;a<6;a++)
{
P2=cmd[a];
cmmd();
}


for(c=0;c<12;c++)
{
P2=lcdmsg[c];
dat();
	}
}
//delay();
goto l;
}

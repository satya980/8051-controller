#include<reg51.h>
sbit rs=P2^1;
sbit rw=P2^2;
sbit en=P2^3;
unsigned int i,i1,j;
unsigned int cmmd[]={0x38,0x0E,0x01,0x06,0x80};
unsigned int cmm[1]={0xC0};
unsigned char dat[]="enter password";
unsigned char wr[]="Incorrect";
unsigned char ri[]="Matched";
unsigned char after[]="enter after 30 seconds";


//delay function
void delay()
{
	for(i1=0;i1<10000;i1++);
}


//delay for 1 second
void delay1()
{
int i2;
for(i2=0;i2<14;i2++)
{
TH1=0;
TL1=0;
TR1=1;
while(TF1==0);
TR1=0;
TF1=0;
}
}

//motor function
void motor()
{	

	P0=0x06;
	delay1();
		
	P0=0x03;
	delay1();
	
	P0=0x09;
	delay1();
	
	P0=0x0C;
	delay1();

}

//delay for 30 seconds
void delay30()
{
TL1=0;
	TH1=0;
	for(i=0;i<420;i++)
	{
		TR1=1;
		while(TF1==0);
		TF1=0;
		TR1=0;
	}
}

//command function
void command()
{
rs=0;
rw=0;
en=1;
delay();
en=0;
}

//data function
void data1()
{
rs=1;
rw=0;
en=1;
delay();
en=0;
}

//display "enter password"
void enter()
{
for(i=0;i<5;i++)
{
P1=cmmd[i];
command();
}
for(j=0;j<14;j++)
{
P1=dat[j];
data1();
}
}

//display "incorrect password";
void wrong()
{
for(i=0;i<5;i++)
{
P1=cmmd[i];
command();
}
for(j=0;j<9;j++)
{
P1=wr[j];
data1();
}
}

//display "password match"
void right()
{
for(i=0;i<5;i++)
{
P1=cmmd[i];
command();
}
for(j=0;j<5;j++)
{
P1=ri[j];
data1();
}
}

//display "enter after 30 seconds"
void seconds()
{
for(i=0;i<5;i++)
{
P1=cmmd[i];
command();
}
for(j=0;j<11;j++)
{
P1=after[j];
data1();	
}
P1=cmm[0];
command();
for(j=11;j<23;j++)
{
P1=after[j];
data1();	
}
}

//display asterisk
void next()
{
P1=0xc0;
command();
}
void star()
{
P1='*';
data1();
}


//main program
void main()
{
	unsigned int k,x,wrcount=0,count=0;
	unsigned int a,b,c;
	unsigned int row[]={0xFE,0xFD,0xFB,0xF7};
  unsigned int col[]={0xEF,0xDF,0xBF,0x7F};
  unsigned char key[]={'0','1','2','3','4','5','6','7','8','9'};
	unsigned char pass[]={'1','2','3','7'};
	TMOD=0x10;

	enter();
	delay();
	next();
	while(1)
	{
		for(k=0;k<4;k++)
			{
					P3=0xF0;
					while(P3==0xF0);
					star();
					//P3=0xF0;
					a=0;
					for(b=0;b<4;b++)
					{
					P3=row[b];
					for(c=0;c<4;c++)
						{
						if((P3|0x0F)==col[c])
							{
								x=key[a];delay();delay();delay();delay();
								goto l;
							}
							else
							a=a+1;
							}
							}
							l:if(x==pass[k])
					count=count+1;
					}
			if(count==4)
			{
				count=0;
			right();
				motor();
				wrcount=0;
			}
			else
			{
				count=0;
			wrong();
			wrcount=wrcount+1;
			if(wrcount==4)
			{
				seconds();
				delay30();
				wrcount=0;
			}
			}	
			P1=0x01;
			enter();	next();
	}
}
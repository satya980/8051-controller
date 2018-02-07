#include<reg51.h>
void delay()
{
int i=0;
while(i<14)
{
TH0=0;
TL0=0;
TR0=1;
while(TF0==0);
TR0=0;
TF0=0;
i++;
}
}
void main()
{
while(1)
{
P3=6;
while(i>0)
{
i--;
	P3=P3-1;
  delay();
}
}
}
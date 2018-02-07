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
P2=P0=P3=0;
while(1)
{
if(P1==24) /Updating hour/
{
P1=0;
}
else
{
if(P2==60)  /Updating minute/
{
P2=0;
P0=P0+1;
}
else
{
if(P3==60) /Updating seconds/
{
P3=0;
P2=P2+1;
delay();
}
else
{
delay();
P3=P3+1;
}
}
}
}
}
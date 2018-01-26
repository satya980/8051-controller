#include<reg51.h>
void delay()
{
	int i=0;
for(i=0;i<30000;i++);

}
void main()
{
	int i=0;
char a[]="satyakam" ;
for(i=0;i<8;i++)
{
P2=a[i];
	
delay();
}

}
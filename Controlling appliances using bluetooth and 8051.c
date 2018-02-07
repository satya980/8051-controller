#include<reg51.h>

sbit a =P1^1;
sbit b = P1^2;
sbit  c  =P1^3;
sbit d =P1^4;
int x,x1,x2,x3;
void main()
{

	P1=0;
	x=x1=x2=x3=0;



       SCON=0X50;
       TMOD=0X20;
       TH1=0XFD;
       TR1=1;


		while(1)
	{
while(RI==0);


	
	if(SBUF=='1')         /Controlling first appliance /
	{
				if(x==0)
				{
		    a=1;
					x=1;
				}
				else if(x==1)
				{
					a=0;
					x=0;
				}
			}                                         
	
	
		
	

		if(SBUF=='2')                       /Controlling second appliance /
	{
	
				if(x1==0)
				{
		    b=1;
					x1=1;
				}
				else if(x1==1)
				{
					b=0;
					x1=0;
				}
			}   
	



		if(SBUF=='3')                        /Controlling third appliance /
	{
			
				if(x2==0)
				{
		    c=1;
					x2=1;
				}
				else if(x2==1)
				{
					c=0;
					x2=0;
				}
			}   
	
	
	if(SBUF=='8')                          /Controlling fourth appliance /
	{
	
				if(x3==0)
				{
		    d=1;
					x3=1;
				}
				else if(x3==1)
				{
					d=0;
					x3=0;
				}
			} 
RI=0;  
	
		

	}}

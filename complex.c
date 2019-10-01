#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14159265

struct Complex
{
	float real;
	float imag;
	
	float amp;
	float angg;
};

float abss(struct Complex x)
{
	return sqrt(pow(x.real,2)+pow(x.imag,2));
}

float ang(struct Complex x)
{
	return atan2(x.imag,x.real)*180/pi;
}

struct Complex addd(struct Complex x,struct Complex y)
{
	struct Complex z;
	
	z.real=x.real+y.real;
	z.imag=x.imag+y.imag;
	
	return z;
}

struct Complex subb(struct Complex x,struct Complex y)
{
	struct Complex z;
	
	z.real=x.real-y.real;
	z.imag=x.imag-y.imag;
	
	return z;
}

struct Complex multp(struct Complex x,struct Complex y)
{
	struct Complex z;
	
	z.real=x.real*y.real-x.imag*y.imag;
	z.imag=x.real*y.imag+y.real*x.imag;
	
	return z;
}

struct Complex conju(struct Complex x)
{
	x.real=x.real;
	x.imag=(-1)*x.imag;
	
	return x;
}

struct Complex divv(struct Complex x,struct Complex y)
{
	struct Complex a,b,c;
	
	b=multp(y,conju(y));
	a=multp(x,conju(y));
	
	c.real=a.real/b.real;
	c.imag=a.imag/b.real;
	
	return c;
}

struct Complex polar(struct Complex x)
{
	struct Complex z;
	
	z.real=x.amp*cos((x.angg*pi)/180);
	z.imag=x.amp*sin((x.angg*pi)/180);
	
	return z;
}

struct Complex expp(float aci)
{
	struct Complex z;
	
	z.real=cos((aci*pi)/180);
	z.imag=sin((aci*pi)/180);
	
	return z;
}

struct Complex poww(struct Complex x,int us)
{
	int i=0;
	struct Complex z;
	z.real=1;
	z.imag=0;
	
	for(i=0;i<us;i++)
	{
		z=multp(z,x);
	}
	
	return z;
}

void main(int argc, char *argv[]) 
{
	struct Complex a,b,c;
	
	a.real=3;
	a.imag=4;
	
	b.real=4;
	b.imag=3;
	
	c=addd(a,b);
	printf("Toplam:%.2f %.2fi\r\n",c.real,c.imag);
	printf("----------------\r\n");
	c=subb(a,b);
	printf("Cikarma:%.2f %.2fi\r\n",c.real,c.imag);
	printf("----------------\r\n");
	c=multp(a,b);
	printf("Carpim:%.2f %.2fi\r\n",c.real,c.imag);
	printf("----------------\r\n");
	c=divv(a,b);
	printf("Bolme:%.2f %.2fi\r\n",c.real,c.imag);
	printf("----------------\r\n");
	c=conju(a);
	printf("Eslenik:%.2f %.2fi\r\n",c.real,c.imag);
	printf("----------------\r\n");
	printf("Genlik:%.2f\r\n",abss(a));
	printf("----------------\r\n");
	printf("Aci:%f\r\n",ang(a));
	printf("----------------\r\n");
	a.amp=abss(a);
	a.angg=ang(a);
	
	c=polar(a);
	printf("Polar:%.2f %.2fi\r\n",c.real,c.imag);
	printf("----------------\r\n");
	
	a.real=0;
	a.imag=1;
	c=poww(a,2);
	printf("Us:%f %fi\r\n",c.real,c.imag);
	printf("----------------\r\n");
	
	c=expp(53.130104);
	printf("Exp:%.2f %.2fi\r\n",5*c.real,5*c.imag);
}

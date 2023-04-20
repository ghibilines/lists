#include <stdio.h>
#include <malloc.h>

double *list(int a);
void fill(double * ptr);
void print(double * ptr);
void sqn(double * ptr, int a,int b);
double first(double*ptr);
double last(double *ptr);
double*flip(double*ptr);

#define lfor(x)	( for(int i=*(x+1);i<=*(x);i++) )
#define f(y) (first((double *) y))
#define l(y) (last((double *) y))

double *list(int a)	{
	double *ptr;
	ptr = malloc(sizeof(double)*(a+1));
	*(ptr) = a;
	return ptr;
}

void fill(double * ptr)	{
	int i;
	for(i=1;i<=*(ptr);i++)	{
		*(ptr + i) = 0;
	}
}

void print(double * ptr)	{
	for(int i=0;i<=*(ptr);i++)	{
		if (i==0) printf("size%d\t%f\n",i,*(ptr+i));
		else printf("cell%d\t%f\n",i,*(ptr+i) );	
	}
}

void sqn(double * ptr, int a,int b)
{
	for(int i=1;i<=*(ptr);i++)	{
		*(ptr+i) = a + (i-1)*b;
	}
}

double first(double*ptr)
{
	return *(ptr+1);
}

double last(double*ptr)
{
	return *(ptr + (int) *(ptr) );
}

double*flip(double*ptr)
{
	double * temp;
	temp = malloc(sizeof(double)*(1+(int)*(ptr)) );
	*(temp) = *(ptr);
	for(int i=1;i<=*(ptr);i++)	{
		if (i==*(ptr)-i) *(temp+i)=*(ptr+i);
		else *(temp+i) = *(ptr + (int)*(ptr) - i +1);
	}
	free(ptr);
	return temp;
}

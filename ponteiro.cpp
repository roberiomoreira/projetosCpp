#include<stdio.h>
#include<stdlib.h>
int main(){
	int b, a;
	int *c;
	
	b=10;
	printf("\n%d",b);
	printf("\n%d",&b);
	c=&a;
	printf("\n%d",c);
	*c=11;
	printf("\n%d",*c);
	printf("\n%d",a);
	printf("\n%d",&c);
	printf("\n%d",c);
	a=b*(*c);
	
	printf("\n%d\n",a);
	printf("\n%d",&a);
	return 1;
}

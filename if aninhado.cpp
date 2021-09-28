#include <stdio.h>
#include <stdlib.h>

int main(){
	int a;
	
	printf("Digite o consumo:");
	scanf("%d",&a);
	
	if(a>=0 && a<=10){
		printf("seu consumo foi de 6,25 por mes");
	}
	else{
		if(a>10 && a<=20){
			printf("seu consumo foi de 0,71 m3");
		}else{
			if(a>20 && a<=30){
				printf("seu consumo foi de 2,36 m3");
			}else{
				if(a>30 && a<=50){
					printf("seu consumo foi de 7,14 m3");
				}else{
					if(a>50){
						printf("seu consumo foi de 7,89 m3");
					}
				}
			}
		}
	}
	return 0;
}

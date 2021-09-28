#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Ponto.h"//inclui os protótipos

Ponto* pto_cria(float x, float y);

struct ponto{
		float x;
		float y;
};
	
int main(){	 
	 float d;
	 Ponto *p, *q;
	 
	 p = pto_cria(10,21);
	 q = pto_cria(7,25);
	 
	 d = pto_distancia(p,q);
	 
	 printf("Distancia entre pontos: %3.3f ", d);
	 printf("\n");
	 
	 pto_libera(p);
	 pto_libera(q);
	 
	 system("pause");
	return 0;
}

Ponto* pto_cria(float x, float y){
	 	Ponto* p = (Ponto*)malloc(sizeof(Ponto));
	 	if(p!=NULL){
	 		p->x = x;
	 		p->y = y;
		 }
		 return p;
}

void pto_atribui(Ponto* p, float x, float y){
	p->x = x;
	p->y = y;	
}

float pto_distancia(Ponto* p1, Ponto* p2){
	float dx = p1->x - p2->x;	
	float dy = p1->y - p2->y;
	return sqrt(dx * dx + dy *dy);
}

void pto_libera(Ponto *p){
	free(p);
}

void pto_acessa(Ponto* p, float* x, float* y){
	*x = p->x;
	*y = p->y;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct _RegPilha{
 char* dado;
 struct _RegPilha *prox;
}RegPilha;

typedef RegPilha* Pilha;
typedef enum boolean{true,false} bool;

RegPilha *AlocaRegPilha(){
 RegPilha* q;
 q = (RegPilha*)calloc(1, sizeof(RegPilha));
 if(q==NULL) exit(-1);
 return q;
}

Pilha CriaPilha(){
 Pilha p;
 p = AlocaRegPilha();
 p->prox = NULL;
 return p;
}

void LiberaPilha(Pilha p){
 RegPilha *q,*t;
 q = p;
 while(q!=NULL){
 	t = q;
 	q = q->prox;
 	free(t);
 }
}

void Empilha(Pilha p, TipoDado x){
 RegPilha *q;
 q = AlocaRegPilha();
 q->dado = x;
 q->prox = p->prox;
 p->prox = q;
}

TipoDado Desempilha(Pilha p){
 RegPilha *q;
 TipoDado x;
 q = p->prox;
 if(q==NULL) exit(-1);
 x = q->dado;
 p->prox = q->prox;
 free(q);
 return x;
}
void In2Pos(char expr[]){
	Pilha p;
	int i = 0;
	char c, t;
	
	p = CriaPilha();
	Empilha(p, '(');
	
	do{
		c = expr[i];
    i++;
    if(c >= 'a' && c <= 'z'){
      printf("%c", c);
    }
    else if(c == '('){
      Empilha(p, '(');
    }
    else if(c == ')' || c == '\0'){
      do{
        t = Desempilha(p);
        if(t != '(')
          printf("%c", t);
      }while(t != '(');
    }
    else if(c == '+' || c == '-' || 
            c == '*' || c == '/' ||
            c == '^' ){
      while(1){
        t = Desempilha(p);
        if(Prioridade(c,t)){
          Empilha(p, t);
          Empilha(p, c);
          break;
        }
        else{
          printf("%c", t);
        }
      }
    }
  }while(c != '\0');
  printf("\n");
  LiberaPilha(p);
}

int Prioridade(char c, char t){
  int pc,pt;
 
  if(c == '^')
    pc = 4;
  else if(c == '*' || c == '/')
    pc = 2;
  else if(c == '+' || c == '-')
    pc = 1;
  else if(c == '(')
    pc = 4;
 
  if(t == '^')
    pt = 3;
  else if(t == '*' || t == '/')
    pt = 2;
  else if(t == '+' || t == '-')
    pt = 1;
  else if(t == '(')
    pt = 0;
 
  return (pc > pt);
}

int main(){
  char expr[] = "a*b+c*d^e/f-g*h";
  
  In2Pos(expr);
  return 0;
}

#include <stdio.h>
#include <conjunto_char.h>
#define true 1;
#define false 0;


Conjunto nuevoconjunto(Conjunto S){
	S.tam = 0;
  return S;	
}

int esVacio(Conjunto S){
	if (S.tam == 0)
    return true;
  return false;	    
}

int cardinalidad(Conjunto S){
   return S.tam;   
     
}

int pertenece(Conjunto *S, char c){
	int i;
  for (i = 0; i < S->tam; i++)
    if (S->elementos[i] == c)  return true;
  return false;
}

Conjunto agregarElemento(Conjunto *S, char c)
{
  if (!pertenece(S, c))
    S->elementos[S->tam++] = c;
  return S;
}

Conjunto removerElemento(Conjunto *S, char c)
{
  int i;
  for (i = 0; i < S->tam; i++)
    if (S->elementos[i] == c) {
      S->elementos[i] = S->elementos[S->tam-1];
      S->tam--; 
      
    }
   return S; 
}

Conjunto Union(Conjunto *A, Conjunto *B){ //la variable R del ultimo 
										//	parametro es para almacenar el resultado 
	int i;
  Conjunto R;
  R = *A;
  for (i = 0; i < B->tam; i++)			// esto sería R = AUB
    if (!pertenece(A, B->elementos[i]))
      agregarElemento(R, B->elementos[i]);
  return R;
}
Conjunto interseccion(Conjunto *A, Conjunto *B){
 	int i;
  Conjunto R;
  R.tam = 0;
  for (i = 0; i < A->tam; i++)			// R = AinterseccionB
    if (pertenece(B, A->elementos[i]))
      agregarElemento(R, A->elementos[i]);
  return R;
}
Conjunto resta(Conjunto *A, Conjunto *B){
	int i;
  Conjunto R;
  R.tam = 0;
  for (i = 0; i < A->tam; i++)
    if (!pertenece(B, A->elementos[i]))
      agregarElemento(R, A->elementos[i]);
  return R;
}
Conjunto complemento(Conjunto *A, Conjunto *S){   //S es el conjunto universo
	int i;
  Conjunto R;
  R.tam = 0;							// R = S-A = A^c donde S es el conjunto universo
  for (i = 0; i < A->tam; i++)
    if (!pertenece(A, S.elementos[i]))
      agregarElemento(R, S.elementos[i]);
  return R;
}

void imprime(Conjunto S){
  for (int i = 0; i < S.tam; ++i)
  {
    printf("%s\n",S.elementos[i] );
  }
}

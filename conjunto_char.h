typedef struct 
  {
  	char elementos[26];
  	int tam;	
  }Conjunto;  
  
Conjunto nuevoconjunto(Conjunto S);
int esVacio(Conjunto S);
int cardinalidad(Conjunto S);
int pertenece(Conjunto S, char c);
Conjunto agregarElemento(Conjunto S, char c);
Conjunto removerElemento(Conjunto S, char c);
Conjunto Union(Conjunto A, Conjunto B);
Conjunto interseccion(Conjunto A, Conjunto B);
Conjunto resta(Conjunto A, Conjunto B);
Conjunto complemento(Conjunto A);
void imprime(Conjunto S);

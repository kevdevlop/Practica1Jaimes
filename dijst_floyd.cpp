#include <stdio.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#define INFINITO 10000

using namespace std;
using namespace std::chrono;



int min(int a, int b){
	if (a<b)
		return a;
	else 
		return b;		
}

int dismin(vector<int> &D, vector<int> &R){
	
	int menor = INFINITO;
	for(int i=0; R.size(); i++){
		if(D[R[i]] < menor){
			menor = D[R[i]];
		}
	}
	return menor;	
		
}

void Matriz(vector<vector<int> > &m){
	srand(time(NULL));

	for(int i = 0 ; i < m.size(); i++){
		for(int j= 0; j< m.size(); j++){
			if(j == i)
				m[i][j] = 0;

			else if(rand()%10 < 2){
					m[i][j] = INFINITO;
					
				}else
					m[i][j] = 1+rand()%30;
			
		}
	}
	
}

void dijkstra(vector< vector<int> > &M, vector<int> &D){
	for (int i = 0; i < D.size(); ++i)
	{
		D[i] = M[1][i];
	}

	vector<int> S;
	S.push_back(0);

	vector<int> R(D.size());

	for (int i = 0; i < R.size(); ++i)
	{
		R[i] = i+1;
	}

	for (int i = 1; i < D.size(); ++i)
	{
		int k = 0;
		int w = dismin(D,R);
		S.push_back(w);
		while( k < R.size()) {
			if(D[k] != w)
				k++;
			else 
				R[k] = R[R.size()];
		}
		
		R.resize(R.size()-1);	

		for (int j = 0; j < R.size(); ++j)
		{
			if(M[w][R[j]] != INFINITO) 
				D[R[j]] = min(D[R[j]], D[w] + M[w][R[j]]);
		}
	}

}
void floyd(vector< vector <int> > &m){
	auto a=m;
	for(int k=1;k<m.size();k++){
		for(int i=1;i<m.size();i++){
			for(int j=1;j<m.size();j++){
				if(a[i][k]+a[k][j]<a[i][j])
					a[i][j]=a[i][k]+a[k][j];
			}
		}
	}
}

int main(){

	vector<vector <int> > m;
	vector<vector <int> > c;
	vector<int> D;
	
	for(int n = 400; n<=40000; n+=200){
		m.resize(n);
		D.resize(n);
		Matriz(m);
		auto t1 = high_resolution_clock::now();
		dijkstra(m, D);
		auto t2 = high_resolution_clock::now();
		auto tiempoDijkstra = duration_cast < microseconds >( t2 - t1 ). count();
		cout << tiempoDijkstra/1e6  << endl ;

		c.resize(n);
		auto t3=high_resolution_clock::now();
		floyd(m);
		auto t4=high_resolution_clock::now();
		auto tiempoFloyd = duration_cast < microseconds >( t4 - t2 ). count();
		cout << tiempoFloyd/1e6 << endl ;

		cout << n << " \t" << tiempoDijkstra << " \t " << tiempoFloyd << endl ;
	}
	
	




	return 0;	
}

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <chrono>
#include <vector>
#define INF 1000

using namespace std;
//using namespace std::vector;
using namespace std::chrono;


void matriz(vector< vector <int> > &m){
	srand(time(NULL));
	for(int i=0;i<m.size();i++){
		for(int j=0;j<m.size();j++){
			if(j==i)
				m[i][j]=0;
			else{
				if(rand()%10<2)
					m[i][j]=INF;
				else
					m[i][j]=1+rand()%30;
			}
			
		}	
	}
}

void floyd(vector< vector <int> > &m){
	auto a=m;
	for(int k=1;k<m.size();k++)
		for(int i=1;i<m.size();i++)
			for(int j=1;j<m.size();j++)
				if(a[i][k]+a[k][j]<a[i][j])
					a[i][j]=a[i][k]+a[k][j];
}

int main(){

	vector< vector <int> > m;
	for(int i=400;i<4000;i+=200	){
		
		m.resize(i);
		cout << m.size() << endl;
		matriz(m);
		
		auto t1=high_resolution_clock::now();
		floyd(m);
		auto t2=high_resolution_clock::now();
		auto tiempoFloyd=duration_cast < microseconds >( t2 - t1 ). count ();
		cout << tiempoFloyd/1e6 << endl ;

		cout << i << " \t " << tiempoFloyd << endl ;
	}
	
/*	for(int i=400;i<400;i+=400){
		matriz m(i,vector<int>(i));
		auto ti=high_resolution_clock::now();
		floyd(m);
		auto t2=high_resolution_clock::now();
		auto tiempo=duration_cast < microseconds >( t2 - t1 ). count ();
		cout << tiempo /1 e6 << endl ;
	}
	cout << n << " \ t " << tiempoDijkstra << " \ t " << tiempoFloyd << endl ;
*/
}

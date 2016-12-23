#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1000+10;
int N;
double A,B,H[maxn];

bool C(double mid){
	H[1] = mid;
	for(int i=2; i<N; i++){
		H[i] = 2*H[i-1]+2-H[i-2];
		if(H[i]<0) return false;
	}

	B = H[N-1];
	return true;
}

int main(){
	scanf("%d%lf",&N,&A);
	H[0] = A;
	double lb=-1,ub=maxn;
	for(int i=0; i<100; i++){
		double mid = (ub+lb)/2;
		if(C(mid)) ub=mid;
		else lb=mid;
	}

	printf("%.2lf\n",B);

}
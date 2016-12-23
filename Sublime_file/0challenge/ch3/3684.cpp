#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 100+5;
const double g = 10.0;

int N,H,R,T;
double y[maxn];

double calc(int T){
	if(T<0) return H;
	double t = sqrt(2*H/g);

	int k = (int)(T/t);
	if(k%2==0){
		double d = T-k*t;
		return H - g*d*d/2;
	}else{
		double d = k*t+t-T;
		return H - g*d*d/2;
	}
}

void solve(){
	for(int i=0; i<N; i++){
		y[i] = calc(T-i);
	}
	sort(y,y+N);
	for(int i=0; i<N; i++){
		printf("%.2lf%c",y[i]+2*R*i/100.0,i+1==N?'\n':' ');
	}
}

int main(){
	scanf("%d%d%d%d",&N,&H,&R,&T);
	solve();
}
#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
using namespace std;

const int maxn = 1e6+10;
typedef unsigned long long ull;

ull X[maxn],Y[maxn],Z[maxn];
ull C[maxn];
int N;

ull count_sum(ull limit){
	ull sum = 0;
	for(int i=0; i<N; i++){
		if(limit >= Y[i])
			sum += C[i];
		else if(limit >= X[i])
			sum += (limit-X[i])/Z[i]+1;
	}

	return sum;
}

char buf[1024];

bool input(){
	int f = 0;
	N = 0;
	while((f=(gets(buf)!=NULL)) && strlen(buf)>2){
		sscanf(buf,"%I64d %I64d %I64d",&X[N],&Y[N],&Z[N]);
		N++;
	}

	return f||N;
}

int main(){
	while(input()){
		if(!N) continue;

		ull last_bit = 0;
		for(int i=0; i<N; i++){
			C[i] = (Y[i]-X[i])/Z[i] + 1;
			last_bit ^= C[i];
		}

		if(!(last_bit&1)){
			cout << "no corruption" << endl;
		}else{
			ull lb=0,ub=0xffffffff;
			
			while(ub-lb>0){
				ull mid = (ub+lb)/2;
				if(count_sum(mid)&1){
					ub = mid;
				}else{
					lb = mid+1;
				}
			}

			cout << ub << " " << count_sum(ub)-count_sum(ub-1) << endl;
		}


	}
}

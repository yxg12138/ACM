#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1e5+10;

int size;
int primes[maxn];
bool is_primes[maxn];

void init(){
	fill(is_primes,is_primes+maxn,1);
	is_primes[0] = is_primes[1] = false;

	for(int i=2; i<maxn; i++){
		if(is_primes[i]){
			primes[size++] = i;
			for(int j=i*2; j<maxn; j+=i)
				is_primes[j] = false;
		}
	}
}

int main(){
	init();

	int n;
	while(cin>>n && n){
		int le=0,ri=0,sum=0,res=0;
		for(;;){
			while(sum<n && ri<size){
				sum += primes[ri++];
			}

			if(sum < n)
				break;

			if(sum == n){
				++res;
			}

			sum -= primes[le++];
		}

		printf("%d\n", res);
	}

}
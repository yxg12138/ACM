#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

const int maxh = 1e6+10;

bool is_H_prime[maxh],is_H_semiprime[maxh];
int H_prime[maxh];
int accumulate[maxh];

int main(){
	int p = 0;
	for(int i=5; i<maxh; i+=4){
		if(is_H_prime[i]) continue;
		H_prime[p++] = i;
		for(int j=i*5; j<maxh; j+=i*4){
			is_H_prime[j] = true;
		}
	}

	for(int i=0; i<p; i++){
		for(int j=0; j<i+1; j++){
			unsigned long long composite = H_prime[i]*H_prime[j];
			if(composite > maxh) break;
			is_H_semiprime[composite] = true;
		}
	}

	for(int i=1; i<maxh; i++){
		accumulate[i] = accumulate[i-1] + is_H_semiprime[i];
	}

	int h;
	while(cin >> h && h){
		cout << h << " " << accumulate[h] << endl;
	}

}
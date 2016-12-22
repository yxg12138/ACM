#include <bits/stdc++.h>
using namespace std;

long long f[105];

void init(){
	f[0] = 1,f[1] = 1;
	for(int i=2; i<=100; i++)
		f[i] = f[i-1] + f[i-2];
}

int main(){
	init();

	long long n;
	cin >> n;
	n--;
	long long sum = 0;

	int i = 1;
	while(sum < n){
		sum += f[i++];
	}


	cout << i-1 << endl;

}

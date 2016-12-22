#include <bits/stdc++.h>
using namespace std;

bool prime(long long x){
	if(x == 2) return true;

	for(int i=2; i<=floor(sqrt(x+0.5)); i++){
		if(x%i == 0)
			return false;  
	}

	return true;
}


int main(){
	long long N;
	cin >> N;

	if(N == 2){
		cout << 1 << endl;
		return 0;
	}

	if(N%2 == 0){
		cout << 2 << endl;
		return 0;
	}

	if(N%2){
		if(prime(N)){
			cout << 1 << endl;
			return 0;
		}
		if(prime(N-2)){
			cout << 2 << endl;
			return 0;
		}
	}

	cout << 3 << endl;
}
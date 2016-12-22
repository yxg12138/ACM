#include <iostream>
using namespace std;

long long M,N,ans;

int main(){
	int T;
	cin >> T;
	while(T--){
		ans = 0;
		cin >> M >> N;
		for(int i=0; i<N; i++){
			M = M*2+1;
		}

		cout << M << endl;
	}
}
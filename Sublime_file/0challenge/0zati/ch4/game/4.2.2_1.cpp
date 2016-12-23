//Nim
#include <iostream>
using namespace std;

const int maxn = 1e6;
int n,a[maxn];

int main(){
	while(cin >> n){
		for(int i=0; i<n; i++)
			cin >> a[i];
		int tmp = 0;
		for(int i=0; i<n; i++)
			tmp ^= a[i];

		if(tmp != 0) cout << "Alice" << endl;
		else cout << "Bob" << endl;
	}
}
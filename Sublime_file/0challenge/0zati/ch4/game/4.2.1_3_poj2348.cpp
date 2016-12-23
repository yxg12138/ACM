#include <iostream>
#include <algorithm>
using namespace std;

int a,b;

void solve(){
	bool f = true;

	for(;;){
		if(a > b) swap(a,b);
		if(b%a==0) break;

		if(b-a>a) break;

		b -= a;
		f = !f;
	}
	if(f) cout << "Stan wins" << endl;
	else cout << "Olice wins" << endl;
}

int main(){
	cin >> a >> b;
	solv1e();
}
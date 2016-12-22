#include <bits/stdc++.h>
using namespace std;

int n;
int a[3],x;

int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> x;
		a[i%3] += x;
	}

	int mx = max(a[0],max(a[1],a[2]));
	if(a[0] == mx)
		cout << "back" << endl;
	else if(a[1] == mx)
		cout << "chest" << endl;
	else
		cout << "biceps" << endl;

}
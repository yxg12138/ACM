#include <bits/stdc++.h>
using namespace std;


int main(){
	long long x,y,z,n;
	cin >> n;
	x = n, y = n+1, z = x*y;
	if(x==y || x==z || y==z)
		cout << -1 << endl;
	else
		cout << x << " " << y << " " << z << endl;
}
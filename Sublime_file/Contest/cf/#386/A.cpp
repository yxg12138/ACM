#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+10;

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	int k = 7;
	int ans = min(min(a,b/2),c/4);
	cout << ans*7 << endl;
	
}
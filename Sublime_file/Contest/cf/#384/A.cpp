#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;
char s[maxn];

int main(){
	int n,a,b;
	cin >> n >> a >> b;
	if(a > b) swap(a,b);
	cin >> s;
	if(s[a-1] != s[b-1]) cout << "1" << endl;
	else cout << "0" << endl;

}
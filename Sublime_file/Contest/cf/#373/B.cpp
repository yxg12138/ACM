#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;

char s[maxn],p[maxn];

int main(){
	int n;
	cin >> n >> s;
	int w1=0,w2=0;
	for(int i=0; i<n; i++){
		if(i%2) { if(s[i]!='b') w1++;}
		else { if(s[i]!='r') w2++;}
	}
	int ans = abs(w1-w2)+min(w1,w2);
	w1=w2=0;
	for(int i=0; i<n; i++){
		if(i%2) { if(s[i]!='r') w1++;}
		else { if(s[i]!='b') w2++;}
	}
	ans = min(ans,abs(w1-w2)+min(w1,w2));

	cout << ans << endl;
}
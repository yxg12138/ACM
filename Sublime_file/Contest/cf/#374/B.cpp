#include <bits/stdc++.h>
using namespace std;

char s[105][105];

int main(){
	int n,k;
	cin >> n >> k;
	for(int i=0; i<=n; i++)
		cin >> s[i];

	int tmp = strlen(s[n]);
	int mi=0,mx=0;

	for(int i=0; i<n; i++){
		if(tmp > strlen(s[i]))
			mi++;
		else if(tmp==strlen(s[i]) && strcmp(s[i],s[n])!=0)
			mx++;
	}

	int ans = mi / k;
	cout << 5*ans+mi+1 << " " << mi+1+(mi+mx)/k*5+mx << endl;

}
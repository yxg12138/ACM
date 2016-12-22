#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5+10;
int n,m,_next[maxn],a[maxn],b[maxn],c[maxn],d[maxn];
int ans;

void get_next(int str[]){
	int k = 0;
	_next[1] = 0;
	for(int i=2; i<=m; i++){
		while(k>0 && str[k+1]!=str[i])
			k = _next[k];
		if(str[k+1] == str[i])
			k++;
		_next[i] = k;
	}
}

void kmp(int P[],int T[]){
	get_next(P);
	int k = 0;
	for(int i=1; i<=n; i++){
		while(k>0 && P[k+1]!=T[i])
			k = _next[k];
		if(P[k+1] == T[i])
			k++;
		if(k == m){
			ans++;
			k = _next[k];
		}
	}
}

int main(){
	cin >> n >> m;
	ans = 0;
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<m; i++) cin >> b[i];

		if(m == 1)
			cout << n << endl;
		else{
			for(int i=1; i<n; i++)
				c[i] = a[i]-a[i-1];
			for(int i=1; i<m; i++)
				d[i] = b[i]-b[i-1];

			n--,m--;
			kmp(d,c);
			cout << ans << endl;
		}

}
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;
int a[maxn],b[maxn],n,m;

int main(){
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> a[i];

	int t=0;
	for(int i=1; i<=n; i++){
		if(a[i] > m) t++;
		else b[a[i]]++;
	}

	int ans = n/m,cnt=0;
	for(int i=1; i<=m; i++){
		if(b[i] < ans){
			if(t){
				for(int j=1; j<=n; j++){
					if(a[j] > m) a[j]=i,t--,b[i]++,cnt++;
					if(b[i] == ans) break;
				}
				if(b[i] == ans) continue;
			}
			for(int j=1; j<=n; j++){
				if(b[a[j]] > ans) { b[a[j]]--; a[j]=i; b[i]++; cnt++;}
				if(b[i] == ans) break;
			}
		}
	}

	cout << ans << " " << cnt << endl;
	for(int i=1; i<=n; i++) cout << a[i] << " ";
	cout << endl;
}
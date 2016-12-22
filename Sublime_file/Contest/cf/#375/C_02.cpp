#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;
int a[maxn],f[maxn],ans,n,m;

int main(){
	cin >> n >> m;
	int x = n/m;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		if(a[i] <= m)
			f[a[i]]++;
	}

	for(int i=1; i<=n; i++)
		if(a[i] > m)
			for(int j=1; j<=m; j++)
				if(f[j] < x){
					a[i] = j; f[j]++; ans++; break;
				}

	for(int i=1; i<=m; i++)
		if(f[i] < x)
			for(int j=1; j<=n; j++){
				if(f[i] == x) break;
				if(f[a[j]] > x){
					f[a[j]]--; a[j]=i; ans++; f[i]++;
				}
			}

	cout << x << " " << ans << endl;
	for(int i=1; i<=n; i++) cout << a[i] << " ";
	cout << endl;

}
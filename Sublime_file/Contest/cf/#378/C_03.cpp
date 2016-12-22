#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;
int a[maxn],b[maxn];
vector<int> seg[maxn];

int main(){
	int n,k;
	cin >> n;
	for(int i=1; i<=n; i++)
		cin >> a[i];
	cin >> k;
	for(int i=1; i<=k; i++)
		cin >> b[i];

	for(int i=1,j=1; i<=k; i++){
		while(j<=n && b[i]>0){
			seg[i].push_back(j);
			b[i] -= a[j++];
		}
		if((i==k && j<=n) || b[i] != 0) { cout << "NO\n"; return 0;} 
	}

	for(int i=1; i<=k; i++){
		if(seg[i].size() == 1) continue;
		int mi=a[seg[i][0]],mx=a[seg[i][0]];
		for(int j=0; j<seg[i].size(); j++)
			mi=min(mi,a[seg[i][j]]),mx=max(mx,a[seg[i][j]]);
		if(mi == mx) { cout << "NO\n"; return 0;}	
	}

	cout << "YES\n";
	for(int i=1; i<=k; i++){
		int mx = a[seg[i][0]];
		for(int j=0; j<seg[i].size(); j++)
			mx = max(mx,a[seg[i][j]]);
		bool isok = 0;
		for(int j=0; j+1<seg[i].size() && !isok; j++){
			if(a[seg[i][j]]==mx && a[seg[i][j+1]]<mx){
				for(int k=j; k+1<seg[i].size(); k++)
					cout << i+j << " R\n";
				for(int k=j; k>0; k--)
					cout << i+k << " L\n";
				isok = 1;
			}
		}

		for(int j=1; j<seg[i].size() && !isok; j++){
			if(a[seg[i][j]]==mx && a[seg[i][j-1]]<mx){
				for(int k=j; k>0; k--)
					cout << i+k << " L\n";
				for(int k=j; k+1<seg[i].size(); k++)
					cout << i << " R\n";
			}
		}
	}
}
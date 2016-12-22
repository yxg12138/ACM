#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3+10;

int n,m;
int a[maxn][maxn];
int ifl[maxn][maxn];
int ifr[maxn][maxn];
int ifu[maxn][maxn];
int ifd[maxn][maxn];

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> a[i][j];

	for(int i=0; i<n; i++){
		int flag = 0;
		for(int j=0; j<m; j++){
			if(a[i][j]) flag=1;
			ifl[i][j] = flag;
		}
	}

	for(int i=0; i<n; i++){
		int flag = 0;
		for(int j=m-1; j>=0; j--){
			if(a[i][j]) flag=1;
			ifr[i][j] = flag;
		}
	}

	for(int j=0; j<m; j++){
		int flag = 0;
		for(int i=0; i<n; i++){
			if(a[i][j]) flag=1;
			ifu[i][j] = flag;
		}
	}
	for(int j=0; j<m; j++){
		int flag = 0;
		for(int i=n-1; i>=0; i--){
			if(a[i][j]) flag=1;
			ifd[i][j] = flag;
		}
	}

	int ans = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(a[i][j]) continue;
			ans += ifl[i][j];
			ans += ifr[i][j];
			ans += ifu[i][j];
			ans += ifd[i][j];	
		}
	}

	cout << ans << endl;
}

// 5 7
// 0 0 0 0 0 0 1
// 0 0 0 0 0 0 1
// 0 0 0 1 0 0 0
// 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+10;

struct node{
	int x,y;
}A[maxn];

int n,m;
int Time[maxn];

int main(){
	int T;
	cin >> T;
	while(T--){
		memset(Time,0,sizeof(Time));
		memset(A,0,sizeof(A));
		cin >> n >> m;
		for(int i=1; i<=n; i++)
			cin >> A[i].x >> A[i].y;
		for(int i=1; i<=m; i++){
			int x; cin >> x;
			Time[x]++;
		}
		int Max[3];
		Max[0]=Max[1] = 0;
		int ans = 0, tot = 0;
		for(int i=n; i>=1; i--){
			tot += Time[i];
			A[i].y += tot;
			if(Max[A[i].x^1] > A[i].y)
				ans++;
			Max[A[i].x] = max(Max[A[i].x],A[i].y);
		}
		cout << n-ans << endl;
	}
}
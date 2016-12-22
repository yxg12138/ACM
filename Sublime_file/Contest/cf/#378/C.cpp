#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4+5;
int a[maxn],need[maxn],pos[maxn],vis[maxn];
int all;

bool solve(int x,int op){
	memset(vis,0,sizeof(vis));
	int mx = 0,cnt = 0;
	for(int i=pos[x-1]+1; i<=pos[x]; i++){
		if(a[i] > mx){
			cnt = 0;
			vis[++cnt] = i;
			mx = a[i];
		}else if(a[i] == mx){
			vis[++cnt] = i;
		}
	}

	int t = 0;
	for(int i=pos[x-1]+1; i<=pos[x]; i++){
		if(a[i] == mx) t++;
	}

	if(t!=1 && t==pos[x]-pos[x-1])
		return 0;

	if(op == 1){
		int bt,le,ri;

		for(int i=1; i<=cnt; i++){
			le=1,ri=1;
			if(vis[i]==pos[x-1]+1 || (vis[i]!=pos[x-1]+1&&vis[i]==vis[i-1]+1))
				le = 0;
			if(vis[i]==pos[x] || vis[i]==vis[i+1]-1)
				ri = 0;

			if(le==1 || ri==1){
				bt = vis[i];
				break;
			}
		}

		if(le == 1){
			for(int i=bt; i>pos[x-1]+1; i--){
				cout << i-all << " L\n";
			}
			for(int i=bt; i<pos[x]; i++){
				cout << pos[x-1]+1-all << " R\n";
			}
		}else if(ri == 1){
			for(int i=bt; i<pos[x]; i++){
				cout << bt-all << " R\n";
			}
			for(int i=bt; i>pos[x-1]+1; i--){
				cout << i-all << " L\n";
			}
		}
	}


	return 1;
}

int main(){
	int n,k;
	cin >> n;
	for(int i=1; i<=n; i++)
		cin >> a[i];
	cin >> k;
	for(int i=1; i<=k; i++)
		cin >> need[i];

	int sum=0,cnt=1,over=0;
	int i;

	for(i=1; i<=n; i++){
		sum += a[i];
		if(sum == need[cnt]){
			pos[cnt++] = i;
			sum = 0;
		}else if(sum > need[cnt]){
			over = 1;
			break;
		}
	}
	pos[0] = 0;
	if(i!=n+1 || cnt!=k+1) over = 1;
	if(over) cout << "NO\n";

	if(over == 0){
		for(int i=1; i<=k; i++){
			if(solve(i,0) == 0){
				over = 1;
				break;
			}
		}
		if(over)
			cout << "NO\n";
		else{
			cout << "YES\n";
			all = 0;
			for(int i=1; i<=k; i++){
				solve(i,1);
				all += pos[i]-pos[i-1]-1;
			}
		}
	}
}
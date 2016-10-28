//2.1.4 部分和问题
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000;
int a[maxn];
int n,k;

bool dfs(int i,int sum){
	if(i == n) return sum==k;

	if(dfs(i+1,sum)) return true;
	if(dfs(i+1,sum+a[i])) return true;

	return false;
}

void solve(){
	if(dfs(0,0)) puts("Yes");
	else puts("No");
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	solve();
}

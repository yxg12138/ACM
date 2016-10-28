//2.2.1
#include <bits/stdc++.h>
using namespace std;

const int V[6] = {1,5,10,50,100,500};

int C[6];
int A;

void solve(){
	int ans = 0;
	for(int i=5; i>=0; i--){
		int t = min(A/V[i],C[i]);
		ans += t;
		A -= t*V[i];
	}
	printf("%d\n",ans);
}

int main(){
	for(int i=0; i<6; i++) scanf("%d",&C[i]);
	scanf("%d",&A);
	solve();
	return 0;
}
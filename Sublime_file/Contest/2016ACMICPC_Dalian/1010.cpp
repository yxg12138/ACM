#include <bits/stdc++.h>
using namespace std;

int a[35],N,x;

int main(){
	scanf("%d",&N);
	int ans = 0;
	for(int i=0; i<N; i++){
		memset(a,0,sizeof(a));
		int cnt=0;
		scanf("%d",&x);
		while(x!=0){
			if((x&1)==1) a[cnt] = 1;
			x>>=1;
			cnt++;
		}
		for(int i=0; i<32; i+=8){
			if(a[i]==1 && a[i+1]==0 && a[i+2]==0 && a[i+3]==0 &&
				a[i+4]==0 && a[i+5]==1 && a[i+6]==1 && a[i+7]==0)
				ans++;
		}
	}
	cout << ans << endl;
}
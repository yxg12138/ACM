#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3+10;

char g[maxn][maxn];
int n,m,q;
int f[maxn];

void init(){
	for(int i=0; i<n; i++){
		f[i] = n-i-1;
		for(int j=0; j<m; j++)
			g[i][j] = '.';
	}

}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		
		scanf("%d%d%d", &n,&m,&q);
		init();
		for(int i=0; i<q; i++){
			int k;
			scanf("%d",&k);
			if(k==1){
				int x,y;
				scanf("%d%d%d",&k,&x,&y);
				if(k==1)
					g[f[n-x]][y-1] = 'w';
				else
					g[f[n-x]][y-1] = 'b';
			}else{
				int r1,r2;
				scanf("%d%d",&r1,&r2);
				swap(f[n-r1],f[n-r2]);
			}
		}
		for(int i=n-1; i>=0; i--){		
				printf("%s\n",g[f[i]]);
		}
	}
}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// .......TLE
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 1000+10;
int d[maxn][maxn];

int V,M,X;

void warshall_floyd(){
	for(int k=0; k<V; k++)
		for(int i=0; i<V; i++)
			for(int j=0; j<V; j++)
				d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
}


int main(){
	scanf("%d%d%d",&V,&M,&X);
	--X;

	memset(d,0x3f,sizeof(d));
	
	for(int i=0; i<V; i++) d[i][i] = 0;
	while(M--){
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		--u,--v;
		d[u][v] = c;
	}

	warshall_floyd();

	int ans = 0;
	for(int i=0; i<V; i++){
		ans = max(ans,d[i][X]+d[X][i]);
	}

	printf("%d\n",ans);
}
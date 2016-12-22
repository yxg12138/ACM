#include <bits/stdc++.h>
using namespace std;

const int maxn = 505;
int d[maxn],res[maxn];
bool G[maxn][maxn];
int n,m;

void Topo(){
	int p;
	for(int i=1; i<=n; i++){
		p = -1;
		for(int j=1; j<=n; j++){
			if(d[j] == 0){
				d[j]--;
				res[i] = p = j;
				break;
			}
		}

		for(int j=1; j<=n; j++){
			if(G[p][j]){
				G[p][j] = 0;
				d[j]--;
			}
		}
	}
}


int main(){
	int i,x,y;
	while(scanf("%d%d",&n,&m) == 2){
		memset(G,0,sizeof(G));
		memset(d,0,sizeof(d));
		memset(res,0,sizeof(res));

		for(i=1; i<=m; i++){
			scanf("%d%d",&x,&y);
			if(G[x][y] == 0){
				G[x][y] = 1;
				d[y]++;
			}
		}

		Topo();
		for(int i=1; i<=n; i++)
			cout << res[i] << " ";
		cout << endl;
	}

}
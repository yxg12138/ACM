//2.1.5 迷宫的最短路径
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
const int INF = 1e9;
const int maxn = 100+5;

int N,M;
int sx,sy,gx,gy;
int d[maxn][maxn];
char mp[maxn][maxn];

int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};

bool judge(int x,int y){
	return x>=0 && x<N && y>=0 && y<M && d[x][y]==INF && mp[x][y] != '#';
}

int bfs(){
	queue<P> que;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			d[i][j] = INF;
	que.push(P(sx,sy));
	d[sx][sy] = 0;

	while(!que.empty()){
		P p = que.front(); que.pop();
		if(p.first == gx && p.second == gy) break;

		for(int i=0; i<4; i++){
			int nx = p.first + dx[i],ny = p.second + dy[i];
			if(judge(nx,ny)){
				que.push(P(nx,ny));
				d[nx][ny] = d[p.first][p.second]+1;
			}
		}
	}

	return d[gx][gy];
}


void solve(){
	int res = bfs();
	printf("%d\n",res);
}

int main(){
	while(scanf("%d%d",&N,&M)==2){
		for(int i=0; i<N; i++) scanf("%s",mp[i]);
		for(int i=0; i<N; i++)
			for(int j=0; j<M; j++)
			{
				if(mp[i][j] == 'S')
					sx=i,sy=j;
				if(mp[i][j] == 'G')
					gx=i,gy=j;
			}

		solve();
	}

}
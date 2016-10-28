#include <cstdio>
using namespace std;

int N,M;
char field[105][105];

bool judge(int x,int y){
	return x>=0 && y>=0 && x<N && y<M && field[x][y]=='W';
}

void dfs(int x,int y){
	field[x][y] = '.';

	for(int dx=-1; dx<=1; dx++)
		for(int dy=-1; dy<=1; dy++){
			int nx = x + dx, ny = y + dy;
			if(judge(nx,ny))
				dfs(nx,ny);
		}

}

void solve(){
	int res = 0;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			if(field[i][j] == 'W')
			{
				dfs(i,j);
				res++;
			}

	printf("%d\n",res);
}

int main(){
	while(scanf("%d%d",&N,&M)==2){
		for(int i=0; i<N; i++)
			scanf("%s",field[i]);
		solve();
	}

}


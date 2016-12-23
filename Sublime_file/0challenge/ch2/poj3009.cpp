#include <cstdio>

const int INF = 1e9;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1}};
int mp[25][25];
int w,h,steps,minn,ex,ey;

void dfs(int x,int y){
	int pi,pj;
	if(steps>=10) return;

	for(int i=0; i<4; i++){
		pi=x,pj=y;
		while(1){
			pi += dir[i][0];
			pj += dir[i][1];
			if(pi<=0 || pi>h || pj<=0 || pj>w) break;
			if(pi==ex && pj==ey){
				steps++;
				if(minn>steps) minn = steps;
				steps--;
				return;
			}else if(mp[pi][pj]==1){
				if(pi-dir[i][0]!=x || pj-dir[i][1]!=y){
					mp[pi][pj] = 0;
					steps++;
					dfs(pi-dir[i][0],pj-dir[i][1]);
					mp[pi][pj] = 1;
					steps--;
				}
				break;
			}
		}
	}
}
int main(){
	int sx,sy;
	while(scanf("%d%d",&w,&h)==2 && (w||h)){
		for(int i=1; i<=h; i++)
			for(int j=1; j<=w; j++){
				scanf("%d",&mp[i][j]);
				if(mp[i][j]==2)
					sx = i, sy = j;
				else if(mp[i][j]==3)
					ex=i,ey=j;
			}

		minn = INF;
		steps = 0;
		dfs(sx,sy);
		if(minn == INF) printf("-1\n");
		else printf("%d\n",minn);
	}
}
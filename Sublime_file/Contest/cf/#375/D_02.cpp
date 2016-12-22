#include <bits/stdc++.h>
using namespace std;

const int maxn = 55;

char s[maxn][maxn];
int vis[maxn][maxn];
int dir[4][2] = {1,0,-1,0,0,1,0,-1};
int n,m,k;
priority_queue<int,vector<int>,greater<int> > q;
int flag = 0;

void dfs(int x,int y,int &cnt){
	if(x<0 || x>=n || y<0 || y>=m){
		flag=1;
		return;
	}
	if(vis[x][y]!=0 || s[x][y]=='*') return;
	vis[x][y] = -1;
	cnt++;
	for(int i=0; i<4; i++){
		int tx = x+dir[i][0], ty = y+dir[i][1];
		dfs(tx,ty,cnt);
	}
}

void dfs1(int x,int y,int cnt){
	if(x<0 || x>=n || y<0 || y>=m) return;
	if(vis[x][y]>0 || s[x][y]=='*') return;
	vis[x][y] = cnt;
	for(int i=0; i<4; i++){
		int tx = x+dir[i][0], ty = y+dir[i][1];
		dfs1(tx,ty,cnt);
	}
}

void dfs2(int x,int y){
	if(x<0 || x>=n || y<0 || y>=m) return;
	if(s[x][y]=='*') return;
	s[x][y] = '*';
	for(int i=0; i<4; i++){
		int tx = x+dir[i][0], ty = y+dir[i][1];
		dfs2(tx,ty);
	}
}

int main(){
	cin >> n >> m >> k;
	for(int i=0; i<n; i++) cin >> s[i];

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(!vis[i][j] && s[i][j]=='.'){
				flag = 0;
				int cnt = 0;
				dfs(i,j,cnt);
				if(cnt>0 && !flag){
					q.push(cnt);
					dfs1(i,j,cnt);
				}
			}
		}
	}

	int ans = 0;
	while(q.size() > k){
		int cur = q.top(); q.pop();
		flag = 0;
		ans += cur;
		for(int i=0; i<n&&!flag; i++)
			for(int j=0; j<m&&!flag; j++)
				if(s[i][j]=='.' && vis[i][j]==cur){
					dfs2(i,j);
					flag = 1;
				}
	}

	cout << ans << endl;
	for(int i=0; i<n; i++) cout << s[i] << endl;
}
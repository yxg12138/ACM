#include <bits/stdc++.h>
using namespace std;

const int maxn = 55;

bool f[maxn][maxn],vis[maxn][maxn];
int dx[4] = {0,0,-1,1},dy[4]={-1,1,0,0};

struct node{ int x, y;};
struct nn{
	int s;
	vector<node> a;
	bool operator<(const nn &rhs) const{
		return s < rhs.s;
	}
}p[maxn*maxn];

queue<node> q;
int n,m,k;

void work(int i,int j){
	q.push((node){i,j});
	vis[i][j] = 1;
	while(!q.empty()){
		int x=q.front().x, y=q.front().y; q.pop();
		for(int i=0; i<4; i++){
			int a=x+dx[i],b=y+dy[i];
			if(!f[a][b] && !vis[a][b] && a>=1 && a<=n && b>=1 && b<=m)
				vis[a][b]=1,q.push((node){a,b});
		}
	}
}

int main(){
	cin >> n >> m >> k;
	int tot = 0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			char ch = getchar();
			while(ch!='.' && ch!='*') ch=getchar();
			f[i][j] = bool(ch=='*');
		}
	}

	for(int i=1; i<=m; i++){
		if(!f[1][i] && !vis[1][i]) work(1,i);
		if(!f[n][i] && !vis[n][i]) work(n,i);
	}
	for(int i=1; i<=n; i++){
		if(!f[i][1] && !vis[i][1]) work(i,1);
		if(!f[i][m] && !vis[i][m]) work(i,m);
	}
	// cout << f[1][1] << endl;

	// for(int i=1; i<=n; i++){
	// 	for(int j=1; j<=m; j++) putchar(vis[i][j]?'*':'.');
	// 	cout << endl;
	// }

	// cout << "===================\n";

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(!f[i][j] && !vis[i][j]){
				q.push((node){i,j});
				p[++tot].s = 1;
				vis[i][j] = 1;
				while(!q.empty()){
					int x=q.front().x, y=q.front().y; q.pop();
					p[tot].a.push_back((node){x,y});
					for(int i=0; i<4; i++){
						int a=x+dx[i], b=y+dy[i];
						if(!f[a][b] && !vis[a][b] && a>=1 && a<=n && b>=1 && b<=m){
							vis[a][b]=1; q.push((node){a,b}); p[tot].s++;
						}
					}
				}
			}
		}
	}

	sort(p+1,p+1+tot);
	int ans = 0;
	k = tot-k;
	// cout << tot << "  "<< k << endl;
	for(int i=1; i<=k; i++){
		int sum = p[i].a.size();
		for(int j=0; j<sum; j++){
			int x = p[i].a[j].x, y = p[i].a[j].y;
			f[x][y] = 1;
		}
		ans += p[i].s;
	}

	cout << ans << endl;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++) putchar(f[i][j]?'*':'.');
		cout << endl;
	}
}
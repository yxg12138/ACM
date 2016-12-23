#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxm = 2e5+10;
const int maxn = 10005;

struct node{
	int to,d,w,next;
};

node edges[maxn*maxn];

int n,m;
int head[maxn],edge;
bool vis[maxn];
long long dis[maxn],cost[maxn];

void add(int u,int v,int d,int c){
	edges[edge].w = c;
	edges[edge].d = d;
	edges[edge].to = v;
	edges[edge].next = head[u];
	head[u] = edge++;
}

void init(){
	memset(head,-1,sizeof(head));
	edge = 0;
}

int spfa(int n){
	int u,sum2 = 0;
	dis[0] = 0;
	cost[0] = 0;
	for(int i=1; i<=n; i++){
		dis[i] = INF;
		cost[i] = INF;
	}

	memset(vis,0,sizeof(vis));
	queue<int> Q;
	Q.push(1);
	vis[1] = 1;
	dis[1] = 0;
	cost[1] = 0;
	while(!Q.empty()){
		u = Q.front(); Q.pop();
		vis[u] = false;

		for(int i=head[u]; i!=-1; i=edges[i].next){
			int v = edges[i].to;
			int w = edges[i].w;
			int d = edges[i].d;
			if(dis[v] > dis[u]+d){
				dis[v] = dis[u] + d;
				cost[v] = w;
				if(!vis[v]){
					vis[v] = true;
					Q.push(v);
				}
			}else if(dis[v] == dis[u]+d){
				if(cost[v] > w) cost[v] = w;
			}
		}
	}

	for(int i=1; i<=n; i++){
		cost[0] += cost[i];
	}
	return cost[0];
}


int main(){
	int u,v,d,c;
	while(scanf("%d%d",&n,&m) && n){
		init();
		int sum = 0;
		for(int i=1; i<=m; i++){
			scanf("%d%d%d%d",&u,&v,&d,&c);
			add(u,v,d,c);
			add(v,u,d,c);
		}

		sum = spfa(n);
		printf("%d\n",sum);
	}
}
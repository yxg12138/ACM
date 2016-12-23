#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

typedef pair<int,int> P;
struct edge{
	int to,cost;
	edge(int to=0,int cost=0) : cost(cost),to(to){}
};

const int maxn = 1000+10;

int mincost[maxn];
bool used[maxn];
int V;

vector<edge> G[maxn];

int prim(){
	int res = 0;
	memset(mincost,0x3f,sizeof(mincost));
	memset(used,0,sizeof(used));
	mincost[0] = 0;
	priority_queue<P> Q;
	Q.push(P(0,0));

	while(!Q.empty()){
		P p = Q.top(); Q.pop();
		int v = p.second;
		if(used[v] || mincost[v]<-p.first) continue;
		used[v] = true;
		res += mincost[v];
		for(int i=0; i<G[v].size(); i++){
			edge e = G[v][i];
			if(mincost[e.to] > e.cost){
				mincost[e.to] = e.cost;
				Q.push(P(-mincost[e.to],e.to));
			}
		}		
	}

	return res;
}


int main(){
	while(scanf("%d",&V)==1 && V){
		for(int i=0; i<V; i++){
			G[i].clear();
			for(int j=0; j<V; j++){
				int c;
				scanf("%d",&c);
				G[i].push_back(edge(j,c));
			}
		}

		printf("%d\n",prim());
	}
}
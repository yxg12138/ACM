#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxe = 2e5+10;

const int maxn = 1000+10;
int pa[maxn],rank[maxn];

void init(const int& n){
	for(int i=0; i<n; i++){
		pa[i] = i;
		rank[i] = 0;
	}
}

int find(const int& x){
	if(pa[x]==x) return x;
	else return pa[x] = find(pa[x]);
}

void unite(int x,int y){
	x = find(x); y = find(y);
	if(x==y) return;
	if(rank[x]<rank[y]) pa[x] = y;
	else{
		pa[y] = x;
		if(rank[x]==rank[y])
			++rank[x];
	}
}

bool same(int x,int y){
	return find(x) == find(y);
}

struct edge{
	int u,v,cost;
	edge(int u=0,int v=0,int cost=0) : u(u),v(v),cost(cost) {}
	bool operator<(const edge& rhs) const{
		return cost > rhs.cost;
	}	
};

edge es[maxe];
int V,E;
int in_tree;

int kruskal(){
	sort(es,es+E);
	init(V);
	int res = 0;
	in_tree = 1;
	for(int i=0; i<E && in_tree<=V; i++){
		edge e = es[i];
		if(!same(e.u,e.v)){
			unite(e.u,e.v);
			res += e.cost;
			++in_tree;
		}

	}
	return res;
}

int main(){
	scanf("%d%d",&V,&E);
	for(int i=0; i<E; i++){
		scanf("%d%d%d",&es[i].u,&es[i].v,&es[i].cost);
		--es[i].u,--es[i].v;		
	}

	int ans = kruskal();
	if(in_tree < V) ans = -1;

	printf("%d\n",ans);
}

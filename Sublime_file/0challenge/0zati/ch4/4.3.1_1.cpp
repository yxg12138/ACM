#include <bits/stdc++.h>
using namespace std;

const int maxv = 1e7;

int V,M; // 顶点数,边数
vector<int> G[maxv]; //图的邻接表表示
vector<int> rG[maxv]; //把边反向后的图
vector<int> vs; //后序遍历顺序的顶点列表
bool used[maxv]; //访问标记
int cmp[maxv]; //所属强连通分量的拓扑序

void add_edge(int from,int to){
	G[from].push_back(to);
	rG[to].push_back(from);
}

void dfs(int v){
	used[v] = true;
	for(int i=0; i<G[v].size(); i++)
		if(!used[G[v][i]]) dfs(G[v][i]);

	vs.push_back(v);
}


void rdfs(int v,int k){
	used[v] = true;
	cmp[v] = k;
	for(int i=0; i<rG[v].size(); i++){
		if(!used[rG[v][i]]) rdfs(G[v][i],k);
	}
}

int scc(){
	memset(used,0,sizeof(used));
	vs.clear();
	for(int v=0; v<V; v++){
		if(!used[v]) dfs(v);
	}

	memset(used,0,sizeof(used));
	int k = 0;
	for(int i=vs.size()-1; i>=0; i--){
		if(!used[vs[i]]) rdfs(vs[i],k++);
	}

	return k;
}


int main(){
	cin>>V>>M;
	int x,y;
	for(int i=0; i<M; i++){
		cin >> x >> y;
		add_edge(x,y);
	}

	cout << scc() << endl;
}
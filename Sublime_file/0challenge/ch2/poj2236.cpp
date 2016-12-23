#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 1000+10;
int pa[maxn],rank[maxn];
bool status[maxn];
bool able[maxn][maxn];

void init(const int& n){
	for(int i=0; i<n; i++){
		pa[i] = i;
		rank[i] = 0;
	}
}

int find(const int& x){
	if(pa[x] == x) return x;
	else return pa[x]=find(pa[x]);
}

void unite(int x,int y){
	x = find(x); y = find(y);
	if(x==y) return;

	if(rank[x]<rank[y])
		pa[x] = y;
	else{
		pa[y] = x;
		if(rank[x] == rank[y])
			++rank[x];
	}
}

bool same(const int& x,const int& y){
	return find(x)==find(y);
}

int square(const int& x){
	return x*x;
}

pair<int,int> comp[maxn];

int main(){
	int N,d;
	cin >> N >> d;
	for(int i=0; i<N; i++)
		cin >> comp[i].first >> comp[i].second;

	init(N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(square(comp[i].first-comp[j].first)+square(comp[i].second-comp[j].second) <= square(d)){
				able[i][j] = true;
				able[j][i] = true;
			}
		}
	}

	char op;
	int x,y;
	while(cin >> op){
		if(op == 'O'){
			cin >> x;
			--x;
			status[x] = true;
			for(int i=0; i<N; i++){
				if(i==x) continue;
				if(status[i] && able[x][i]){
					unite(i,x);
				}
			}
		}else{
			cin >> x >> y;
			--x,--y;
			if(same(x,y)) cout << "SUCCESS" << endl;
			else cout << "FAIL" << endl;
		}


	}
}
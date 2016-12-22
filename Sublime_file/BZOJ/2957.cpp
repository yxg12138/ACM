#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 1e5+10;

int block,belong[maxn],num,l[500],r[500],n,m,x,h;
double Max[maxn],k[maxn];
vector<double> see[500];


void build(){
	memset(Max,0,sizeof(Max));
	block = sqrt((double)n*1.05);
	num = n/block; if(n%block) num++;
	for(int i=1; i<=num; i++)
		l[i] = (i-1)*block+1, r[i] = i*block;
	r[num] = n;
	for(int i=1; i<=n; i++)
		belong[i] = (i-1)/block+1;
}

void update(int x,int y){
	double a = x,b = y;
	k[x] = b/a;
	Max[belong[x]] = 0;
	see[belong[x]].clear();
	for(int i=l[belong[x]]; i<=r[belong[x]]; i++){
		if(k[i] > Max[belong[x]]){
			Max[belong[x]] = k[i];
			see[belong[x]].push_back(k[i]);
		}
	}
}

int query(){
	int ans = 0;
	double tmp = 0;
	for(int i=1; i<=num; i++){
		if(!see[i].empty()){
			ans += see[i].end() - upper_bound(see[i].begin(),see[i].end(), tmp);
			tmp = max(tmp,Max[i]);
		}
	}
	return ans;
}

int main(){
	scanf("%d%d",&n,&m);
	build();
	while(m--){
		scanf("%d%d",&x,&h);
		update(x,h);
		printf("%d\n",query());

	}
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 1<<30;
const int maxn = 1e5+10;

int n,q;
pair<int,int> p[maxn];

void find(int t){
	int i=0,j=1,ans=INF,le,ri,va,tmp,k;
	while(i<=n && j<=n && ans){
		tmp = p[j].first - p[i].first;
		if(abs(tmp-t)<ans){
			ans = abs(tmp-t);
			va = tmp;
			le = p[i].second;
			ri = p[j].second;
		}
		if(tmp < t) j++;
		if(tmp > t) i++;
		if(i==j) j++;
	}

	if(le > ri) swap(le,ri);
	printf("%d %d %d\n",va,le+1,ri);
}

int main(){
	while(~scanf("%d%d",&n,&q) && (n||q)){
		int sum=0,num;
		p[0] = make_pair(0,0);
		for(int i=1; i<=n; i++){
			scanf("%d",&num);
			sum += num;	
			p[i] = make_pair(sum,i);
		}

		sort(p,p+n+1);
		while(q--){
			scanf("%d",&num);
			find(num);
		}
	}
	

}

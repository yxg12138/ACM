#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+7;

int block,belong[maxn],num,l[maxn],r[maxn],n,q;
long long a[maxn],Max[maxn];

void build(){
	block = sqrt(n);
	num = n/block; if(n%block) num++;
	for(int i=1; i<=num; i++)
		l[i] = (i-1)*block+1, r[i] = i*block;
	r[num] = n;
	for(int i=1; i<=n; i++)
		belong[i] = (i-1)/block+1;

	for(int i=1; i<=num; i++)
		for(int j=l[i]; j<=r[i]; j++)
			Max[i] = max(Max[i],a[j]);
}

void update(int x,int y){
	a[x] += y;
	Max[belong[x]] = max(Max[belong[x]],a[x]);
}

long long ask(int x,int y){
	long long ans = 0;
	if(belong[x]==belong[y]){
		for(int i=x; i<=y; i++)
			ans = max(a[i],ans);
		return ans;
	}
	for(int i=x; i<=r[belong[x]]; i++)
			ans = max(ans,a[i]);
	for(int i=belong[x]+1; i<belong[y]; i++)
		ans = max(ans,Max[i]);
	for(int i=l[belong[y]]; i<=y; i++)
		ans = max(ans,a[i]);
	return ans;
}

int main(){
	scanf("%d%d",&n,&q);
	build();
	for(int i=1; i<=q; i++){
		int op,l,r;
		scanf("%d%d%d",&op,&l,&r);
		if(op == 1) update(l,r);
		else printf("%lld\n",ask(l,r));
	}
}
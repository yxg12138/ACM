#include <cstdio>

const int maxn = 1e5+10;

int bits[maxn],n;
int a[maxn];

int sum(int i){
	int s = 0;
	while(i>0){
		s += bits[i];
		i -= i&-i;
	}

	return s;
}

void add(int i,int x){
	while(i <= n){
		bits[i] += x;
		i += i&-i;
	}
}


void solve(){
	long long ans = 0;
	for(int j=0; j<n; j++){
		ans += j-sum(a[j]);
		add(a[j],1);
	}

	printf("%lld\n",ans);
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	solve();

}
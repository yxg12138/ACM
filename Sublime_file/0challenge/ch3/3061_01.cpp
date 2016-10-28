#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1e5+10;
int n,s;
int a[maxn];
int sum[maxn];

void solve(){
	for(int i=0; i<n; i++)
		sum[i+1] = sum[i] + a[i];
}

int main(){
	scanf("%d%d",&n,&s);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	solve();
}
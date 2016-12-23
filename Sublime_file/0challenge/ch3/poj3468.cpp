#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int maxn = 1e5+10;
const int DAT_SIZE = (1<<18)-1;
int N,Q,a[maxn],q[maxn],L[maxn],R[maxn],X[maxn];
char T[maxn];

ll data[DAT_SIZE],datb[DAT_SIZE];

void add(int a,int b,int x, int k,int le,int ri){
	if(a<=le && b>=ri){
		// cout << "data " << data[k] << " x " << x<<endl;
		data[k] += x;
	}else if(a<ri && b>le){
		datb[k] += (min(b,ri) - max(a,le))*x;
		add(a,b,x,k*2+1,le,(le+ri)/2);
		add(a,b,x,k*2+2,(le+ri)/2,ri);
	}
}


ll sum(int a,int b,int k, int le,int ri){
	if(b<=le || a>=ri) return 0;
	else if(a<=le && b>=ri){
		return data[k] * (ri-le) + datb[k];
	}else{
		ll res = (min(b,ri)-max(a,le))*data[k];
		//cout << " aaaa" << data[k] << endl;
		res += sum(a,b,k*2+1,le,(le+ri)/2);
		res += sum(a,b,k*2+2,(le+ri)/2,ri);
		//cout << "--------" << res << endl;
		return res;
	}
}

void solve(){
	for(int i=0; i<N; i++){
		add(i,i+1,a[i],0,0,N);
	}

	for(int i=0; i<Q; i++){
		if(T[i] == 'C'){
			add(L[i],R[i]+1,X[i],0,0,N);
		}else{
			printf("%lld\n",sum(L[i],R[i]+1,0,0,N));
		}
	}
}

int main(){
	scanf("%d%d",&N,&Q);
	for(int i=0; i<N; i++){
		scanf("%d",&a[i]);
	}
	for(int i=0; i<Q; i++){
		cin >> T[i];
		if(T[i] == 'Q'){
			scanf("%d%d",&L[i],&R[i]);
			L[i]--,R[i]--;
		}else{
			scanf("%d%d%d",&L[i],&R[i],&X[i]);
			L[i]--,R[i]--;
		}
	}

	solve();


}
// lower_bound
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+10;
int n,k;
int a[maxn];

void solve(){
	int lb = -1,ub = n;

	while(ub - lb >= 1){
		int mid = lb + (ub-lb)/2;
		if(a[mid] >= k) ub = mid;
		else lb = mid+1;
	}

	printf("%d\n",ub);

}


int main(){
	cin >> n >> k;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	solve();

}
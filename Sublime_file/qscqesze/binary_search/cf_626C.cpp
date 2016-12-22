#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+10;
int n,m;

bool check(int x){
	int num1 = x/2;
	int num2 = x/3;
	int num3 = x/6;
	if(num1 < n) return false;
	if(num2 < m) return false;
	if(min(num3,num1-n) < m-(num2-num3)) return false;
	return true;
}

int main(){
	cin >> n >> m;
	int l = 0,r = 3*maxn,ans;
	while(l <= r){
		int mid = (l+r) / 2;
		if(check(mid)) ans=mid,r=mid-1;
		else l = mid+1;
	}

	cout << ans << endl;
}
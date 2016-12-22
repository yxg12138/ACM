#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
int n,a[maxn],vis[maxn];

int gcd(int a,int b){
	return b==0 ? a : gcd(b, a%b);
}

int main(){
	cin >> n;
	for(int i=1; i<=n; i++)
		cin >> a[i];

	vector<int> ans;
	for(int i=1; i<=n; i++){
		if(vis[i]) continue;
		int now = i;
		int cnt = 0;
		while(!vis[now]){
			vis[now] = 1;
			now = a[now];
			cnt++;
		}
		if(now != i)
			return puts("-1"),0;
		if(cnt % 2 == 0) cnt /= 2;
		ans.push_back(cnt);
	}

	long long Ans = ans[0];
	for(int i=1; i<ans.size(); i++)
		Ans = Ans*ans[i] / gcd(Ans,ans[i]);

	cout << Ans << endl;
}
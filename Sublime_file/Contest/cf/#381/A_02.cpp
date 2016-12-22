#include <bits/stdc++.h>
using namespace std;

const int INF = 1<<30;

long long ans,n,a,b,c;;

void dfs(long long num, long long res){
	if(num%4 == 0) ans = min(ans,res);
	if(num > 3*n) return ;

	dfs(num+1,res+a);
	dfs(num+2,res+b);
	dfs(num+3,res+c);
}

int main(){

	cin >> n >> a >> b >> c;
	ans = INF;

	n %= 4;
	dfs(n,0);

	cout << ans << endl;

}
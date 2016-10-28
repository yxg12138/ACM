#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

const int maxn = 10000 + 5;
int e[maxn];
vector<int> prime;
bool vis[maxn];

void init(){
	int m = sqrt(maxn + 0.5);
	prime.clear();
	memset(vis, 0, sizeof(vis));
	for (int i = 2; i <= m; i++) if (!vis[i]){
		for (int j = i * i; j <= maxn; j += i) 
			vis[j] = 1;
	}
	for (int i = 2; i < maxn; i++)
		if (!vis[i]) prime.push_back(i);
}

// 乘以或除以n. d=1表示乘，d=-1表示除
void add_integer(int n, int d){
	for (int i = 0; i < prime.size(); i++){
		while (n%prime[i] == 0){
			n /= prime[i];
			e[i] += d;
		}
		if (n == 1) break;  // 提前终止循环，节约时间
	}
}

void add_factorial(int n, int d){
	for (int i = 1; i <= n; i++)
		add_integer(i, d);
}


int main()
{
// 	freopen("in.txt", "r", stdin);
	init();
	int p, q, r, s;
	while (~scanf("%d%d%d%d", &p, &q, &r, &s))
	{
		memset(e, 0, sizeof(e));
		add_factorial(p, 1);
		add_factorial(q, -1);
		add_factorial(p - q, -1);
		add_factorial(r, -1);
		add_factorial(s, 1);
		add_factorial(r - s, 1);
		double ans = 1;
		for (int i = 0; i < prime.size(); i++){
			ans *= pow(prime[i], e[i]);
		}
		printf("%.5lf\n", ans);
	}


}

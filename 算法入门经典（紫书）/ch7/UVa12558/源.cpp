#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
ll maxd, ans[10240], v[10240];
set<ll> ban;

ll gcd(ll a, ll b)
{
	return b ? gcd(b, a%b) : a;
}

ll get_first(ll a, ll b)
{
	return b / a + 1;
}

bool better(int d)
{
	for (int i = d; i >= 0; i--)
	{
		if (v[i] != ans[i])
			return ans[i] == -1 || v[i] < ans[i];
	}
	return false;
}


bool dfs(int d, ll from, ll aa, ll bb)
{
	if (d == maxd)
	{
		if (bb%aa || ban.count(bb / aa)) return false;
		v[d] = bb / aa;
		if (better(d))
			memcpy(ans, v, sizeof(ll)*(d + 1));
		return true;
	}

	bool ok = false;
	from = max(from, get_first(aa, bb));
	for (ll i = from;; ++i)
	{
		if (ban.count(i)) continue;
		if (bb*(maxd + 1 - d) <= i*aa) break;
		v[d] = i;
		ll b2 = bb*i, a2 = aa*i - bb;
		ll g = gcd(a2, b2);
		if (dfs(d + 1, i + 1, a2 / g, b2 / g)) ok = true;
	}
	return ok;
}

int main()
{
// 	freopen("in.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		int a, b, n;
		scanf("%d%d%d", &a, &b, &n);
		ban.clear();
		while (n--)
		{
			int x;
			scanf("%d", &x);
			ban.insert(x);
		}
		for (maxd = 1;; ++maxd)
		{
			memset(ans, -1, sizeof(ans));
			if (dfs(0, get_first(a, b), a, b))
				break;
		}
		printf("Case %d: %d/%d=1/%lld", t, a, b, ans[0]);
		for (int i = 1; i <= maxd; i++)
			printf("+1/%lld", ans[i]);
		printf("\n");
		
	}


}
#include <cstdio>
#include <cstring>


const int maxn = 505;

int m, k;
long long arr[maxn],sum,minn,ans;
bool vis[maxn];

int divide(long long M)
{
	memset(vis, 0, sizeof(vis));
	int cnt = 0;
	int pos = m - 1;
	while (pos >= 0)
	{
		long long sum = 0;
		bool ok = true;
		while (pos >= 0 && sum + arr[pos] <= M)
		{
			ok = false;
			sum += arr[pos];
			pos--;
		}
		if (ok) return k + 1;
		++cnt;
		if (pos >= 0) vis[pos] = true;
	}
	return cnt;
}


long long binary()
{
	long long le = minn, ri = sum;
	while (le < ri)
	{
		int mid = (le + ri) / 2;
		if (divide(mid) <= k) ri = mid;
		else le = mid + 1;
	}

	return ri;
}

void output()
{
	int cnt = divide(ans);
	for (int i = 0; i < m-1 &&cnt < k; i++)
	{
		if (!vis[i]){
			vis[i] = true;
			cnt++;
		}
	}

	for (int i = 0; i < m; i++)
	{
		if (!i) printf("%lld", arr[i]);
		else printf(" %lld", arr[i]);
		if (vis[i]) printf(" /");
	}
	printf("\n");
}

int main()
{
// 	freopen("in.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &m,&k);
		sum = 0, minn = 0;
		for (int i = 0; i < m; i++)
		{
			scanf("%lld", &arr[i]);
			sum += arr[i];
			if (arr[i] > minn) minn = arr[i];

		}

		ans = binary();
		output();
	}
}


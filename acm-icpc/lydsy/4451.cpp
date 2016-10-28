#include <cmath>
#include <stdio.h>
#include <algorithm>
typedef long long LL;
const int maxn = 200001, maxm = 1 << 19, mod = 1000003;
const long double pi = acos(-1.0);
struct complex
{
	long double r, i;
	complex() {}
	complex(long double x, long double y) : r(x), i(y) {}
	friend complex operator + (const complex &a, const complex &b) { return complex(a.r + b.r, a.i + b.i); }
	friend complex operator - (const complex &a, const complex &b) { return complex(a.r - b.r, a.i - b.i); }
	friend complex operator * (const complex &a, const complex &b) { return complex(a.r * b.r - a.i * b.i, a.r * b.i + a.i * b.r); }
	complex conj() { return complex(r, -i); }
} X[maxm], Y[maxm];
void FFT(complex a[], int n, int flag)
{
	for(int i = 1, j = n >> 1, k; i < n - 1; ++i)
	{
		if(i < j)
			std::swap(a[i], a[j]);
		for(k = n >> 1; j >= k; k >>= 1)
			j -= k;
		if(j < k)
			j += k;
	}
	for(int i = 1; i < n; i <<= 1)
	{
		complex wn(cos(pi / i), flag * sin(pi / i));
		for(int j = 0; j < n; j += i << 1)
		{
			complex w(1, 0);
			for(int k = 0; k < i; ++k, w = w * wn)
			{
				complex t = w * a[j + k + i];
				a[j + k + i] = a[j + k] - t;
				a[j + k] = a[j + k] + t;
			}
		}
	}
	if(flag == -1)
		for(int i = 0; i < n; ++i)
			a[i].r /= n;
}
int n, len, a[maxn], b[maxn], c, fact[maxn << 1], iact[maxn];
int f[maxn << 1], ans;
int main()
{
	scanf("%d%d%d%d", &n, a + 1, b + 1, &c);
	a[0] = b[0] = iact[1] = 1;
	for(int i = 2; i <= n; ++i)
	{
		a[i] = (LL)a[i - 1] * a[1] % mod;
		b[i] = (LL)b[i - 1] * b[1] % mod;
		iact[i] = mod - mod / i * (LL)iact[mod % i] % mod;
	}
	fact[0] = iact[0] = 1;
	for(int i = 2; i <= n; ++i)
		iact[i] = (LL)iact[i - 1] * iact[i] % mod;
	for(int i = 1; i <= n << 1; ++i)
		fact[i] = (LL)fact[i - 1] * i % mod;
	scanf("%*d");
	for(int i = 2, x; i <= n; ++i)
	{
		scanf("%d", &x);
		ans = (ans + (LL)fact[(n - 1 << 1) - i] * iact[n - i] * iact[n - 2] % mod * a[n - 1] * b[n - i] % mod * x) % mod;
	}
	scanf("%*d");
	for(int i = 2, x; i <= n; ++i)
	{
		scanf("%d", &x);
		ans = (ans + (LL)fact[(n - 1 << 1) - i] * iact[n - i] * iact[n - 2] % mod * a[n - i] * b[n - 1] % mod * x) % mod;
	}
	for(len = 1; len < (n << 1 | 1); len <<= 1);
	for(int i = 1; i <= n; ++i)
		a[i] = (LL)a[i] * iact[i] % mod;
	std::reverse(a, a + n + 1);
	for(int i = 1; i <= n; ++i)
		b[i] = (LL)b[i] * iact[i] % mod;
	std::reverse(b, b + n + 1);
	for(len = 1; len < (n << 1 | 1); len <<= 1);
	X[0] = X[1] = complex(0, 0);
	for(int i = 2; i < len; ++i)
		X[i] = i <= n ? complex(a[i] >> 10, b[i] >> 10) : complex(0, 0);
	FFT(X, len, 1);
	for(int i = 0; i < len; ++i)
	{
		int j = (len - i) & (len - 1);
		Y[i] = (X[i] * X[i] - (X[j] * X[j]).conj()) * complex(0, -0.25);
	}
	FFT(Y, len, -1);
	for(int i = 4; i <= n << 1; ++i)
		f[i] = (LL)(Y[i].r + 0.5) % mod * ((1 << 20) - mod) % mod;
	X[0] = X[1] = complex(0, 0);
	for(int i = 2; i < len; ++i)
		X[i] = i <= n ? complex(a[i] & ((1 << 10) - 1), b[i] & ((1 << 10) - 1)) : complex(0, 0);
	FFT(X, len, 1);
	for(int i = 0; i < len; ++i)
	{
		int j = (len - i) & (len - 1);
		Y[i] = (X[i] * X[i] - (X[j] * X[j]).conj()) * complex(0, -0.25);
	}
	FFT(Y, len, -1);
	for(int i = 4, x; i <= n << 1; ++i)
		f[i] = (f[i] + (LL)(Y[i].r + 0.5)) % mod;
	X[0] = X[1] = complex(0, 0);
	for(int i = 2; i < len; ++i)
		X[i] = i <= n ? complex(a[i] >> 10, b[i] & ((1 << 10) - 1)) : complex(0, 0);
	FFT(X, len, 1);
	for(int i = 0; i < len; ++i)
	{
		int j = (len - i) & (len - 1);
		Y[i] = (X[i] * X[i] - (X[j] * X[j]).conj()) * complex(0, -0.25);
	}
	FFT(Y, len, -1);
	for(int i = 4; i <= n << 1; ++i)
		f[i] = (f[i] + ((LL)(Y[i].r + 0.5) << 10)) % mod;
	X[0] = X[1] = complex(0, 0);
	for(int i = 2; i < len; ++i)
		X[i] = i <= n ? complex(a[i] & ((1 << 10) - 1), b[i] >> 10) : complex(0, 0);
	FFT(X, len, 1);
	for(int i = 0; i < len; ++i)
	{
		int j = (len - i) & (len - 1);
		Y[i] = (X[i] * X[i] - (X[j] * X[j]).conj()) * complex(0, -0.25);
	}
	FFT(Y, len, -1);
	for(int i = 4; i <= n << 1; ++i)
	{
		f[i] = (f[i] + ((LL)(Y[i].r + 0.5) << 10)) % mod;
		ans = (ans + (LL)f[i] * fact[(n << 1) - i] * c) % mod;
	}
	printf("%d\n", ans);
	return 0;
}

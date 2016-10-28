/*
 * gcd(fib_i, fib_{i + 1}) = gcd(fib_{i - 1}, fib_i) = ... = gcd(fib_1, fib_2) = 1
 * fib_{n + m} = fib_{n - 1} * fib_m + fib_n * fib_{m + 1}
 * ���� gcd(fib_{n + m}, fib_n) = gcd(fib_{n - 1} * fib_m, fib_n) = gcd(fib_{n - 1}, fib_n) * gcd(fib_m, fib_n) = gcd(fib_m, fib_n)
 * ���� gcd(fib_i, fib_j) = fib_{gcd(i, j)}
 * ���� fib_j | fib_i �ȼ��� j | i
 * ��e[i]Ϊi����С������������d[i]Ϊi��ȥ��С������������g[i]Ϊi������������f[i]Ϊi������ƽ���� 
 * ����ŷʽɸ��i mod prime[j]Ϊ0�����:
 * ��С������+1����������������С�������������㣬d[]���䣬f[]Ϊf[i] * prime[j] ^ 2 + f[d[]]
 * ����i mod prime[j]��0�����:
 * ����������С����������������������f[]Ϊf[i] * prime[j] ^ 2 + f[i]
 * ע��fib_1 = fib_2 = 1 
 */
#include <cstdio>
typedef long long LL;
const int maxc = 664580, maxv = 10000001, mod = 1000000007;
int cnt, prime[maxc], e[maxv], d[maxv], g[maxv], f[maxv], sumg, sumf;
bool vis[maxv];
int main()
{
	int Q, q, A, B, C;
	scanf("%d%d%d%d%d", &Q, &q, &A, &B, &C);
	A %= C, B %= C;
	g[1] = f[1] = 1;
	for(int i = 2; i <= C; ++i)
	{
		if(!vis[i])
		{
			prime[cnt++] = i;
			e[i] = d[i] = 1;
			g[i] = 2;
			f[i] = ((LL)i * i + 1) % mod;
		}
		for(int j = 0, k; j < cnt && (k = i * prime[j]) <= C; ++j)
		{
			vis[k] = 1;
			if(i % prime[j] == 0)
			{
				e[k] = e[i] + 1;
				g[k] = (g[i] / (e[i] + 1)) * (e[k] + 1);
				d[k] = d[i];
				f[k] = (f[i] * ((LL)prime[j] * prime[j] % mod) + f[d[i]]) % mod;
				break;
			}
			else
			{
				e[k] = 1;
				d[k] = i;
				g[k] = g[i] << 1;
				f[k] = f[i] * (((LL)prime[j] * prime[j] + 1) % mod) % mod;
			}
		}
	}
	while(Q--)
	{
		sumg += g[q] + (q & 1);
		sumf += f[q] + 4 * (q & 1);
		if(sumg >= mod) sumg -= mod;
		if(sumf >= mod) sumf -= mod;
		q = (q * (LL)A + B) % C + 1;
	}
	printf("%d\n%d\n", sumg, sumf);
	return 0;
}

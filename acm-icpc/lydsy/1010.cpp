/*
 * ��f[i]��ʾ��i����Ʒ�����i+1����Ʒ����һ�𣬵�1��i����Ʒװ�����С���á�
 * f[i]=min(f[k]+((i-k-1)+(s[i]-s[k])-L)^2)=min(f[k]+((s[i]+i)-(s[k]+k+1+L))^2)
 * �����㷨O(n^2)������֤��TLE�������Ӷ�ת��ΪO(n).
 * ��f[i]Ӧ��f[k]ת�ƣ�jΪ[0,i)������һ��������k��������
 * ��Ϊf[i]��f[k]ת�ƣ������У�f[k]+((s[i]+i)-(s[k]+k+1+L))^2 <= f[j]+((s[i]+i)-(s[j]+j+1+L))^2
 * ��A[i]=s[i]+i��B[i]=s[i]+i+1+L
 * ����ʽ����Ϊ f[k]+(A[i]-B[k])^2 <= f[j]+(A[i]-B[j])^2
 * ����ã�(f[k]+B[k]^2) - (f[j]+B[j]^2) <= 2*A[i]* (B[k]-B[j])
 * �򣬵�B[k]>B[j]����k>jʱ��( (f[k]+B[k]^2) - (f[j]+B[j]^2) ) / (B[k]-B[j]) <=2*A[i]
 * ������B[k]<B[j]����k<jʱ��( (f[k]+B[k]^2) - (f[j]+B[j]^2) ) / (B[k]-B[j]) >=2*A[i]
 * ������(B[i],f[i]+B[i]^2)����i������ϵ�ж�Ӧ��P(i)������ʽ˵����k��Ҫ���㣺
 * ��������0<=j<k��P(j)-P(k)��б�ʲ�����2*A[i]
 * ��������k<j<i��P(k)-P(j)��б�ʲ�С��2*A[i]
 * �õ�������ά�������͹�ԣ��Ҹ㼴�ɡ�
 */
#include <cstdio>
int n, l, q[50001] = {};
long long sum[50001] = {}, f[50001] = {};
inline long long sqr(const long long x) { return x * x; }
bool check(const int i, const int j, const int k) { return ((f[i] + sqr(sum[i])) - (f[k] + sqr(sum[k]))) * (sum[i] - sum[j]) < ((f[i] + sqr(sum[i])) - (f[j] + sqr(sum[j]))) * (sum[i] - sum[k]); }
long long calc(const int i, const int j) { return f[j] + sqr(sum[i] - sum[j] - l); }
int main()
{
	int i, tmp, head = 1, tail = 1;
	scanf("%d%d", &n, &l); ++l;
	for(i = 1; i <= n; ++i)
	{
		scanf("%d", &tmp);
		sum[i] = sum[i - 1] + tmp + 1;
	}
	for(i = 1; i <= n; ++i)
	{
		while(head < tail && calc(i, q[head]) > calc(i, q[head + 1])) ++head;
		f[i] = calc(i, q[head]);
		while(head < tail && check(i, q[tail - 1], q[tail])) --tail;
		q[++tail] = i;
	}
	printf("%lld\n", f[n]);
	return 0;
}

/*
 * ����n * n�ľ�����г˷���O(n ^ 3)�� 
 * ����һ��1 * n�ľ����һ��n * n�ľ�����O(n ^ 2)�� 
 * ���ǽ���Ŀʽ�Ӹ�Ϊ T * A * B = T * C
 * ������켸��1 * n�ľ���T���жϴ��Ƿ���ȣ�����һ������� 
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
const int maxn = 1000;
struct Matrix
{
	int r, c, data[maxn][maxn];
	bool cmp(const Matrix &x) const
	{
		for(int i = 0; i < r; ++i)
			for(int j = 0; j < c; ++j)
				if(data[i][j] != x.data[i][j]) return 0;
		return 1;
	}
	void Multiply(const Matrix &x, const Matrix &y)
	{
		memset(data, 0, sizeof data);
		r = x.r, c = y.c;
		for(int i = 0; i < r; ++i)
			for(int j = 0; j < x.c; ++j)
				for(int k = 0; k < c; ++k)
					data[i][k] += x.data[i][j] * y.data[j][k];
	}
} T, A, B, C, T1, T2;
int n;
bool flag;
int main()
{
	srand(2333);
	while(scanf("%d", &n) != EOF)
	{
		T.r = 1, T.c = A.r = A.c = B.r = B.c = C.r = C.c = n;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				scanf("%d", &A.data[i][j]);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				scanf("%d", &B.data[i][j]);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				scanf("%d", &C.data[i][j]);
		flag = 1;
		for(int i = 0; i < 10; ++i)
		{
			for(int j = 0; j < n; ++j)
				T.data[0][j] = rand() % 2333;
			T1.Multiply(T, A);
			T2.Multiply(T, C);
			T.Multiply(T1, B);
			if(!T.cmp(T2))
			{
				flag = 0;
				break;
			}
		}
		puts(flag ? "Yes" : "No");
	}
	return 0;
}

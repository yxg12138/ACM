#include <cstdio>
#include <cstring>

const int maxn = 31;
int arr[maxn], n;

void rev(int k)
{
	printf("%d ", n - k);
	for (int i = 0; i <= k / 2; i++)
	{
		int tmp = arr[i];
		arr[i] = arr[k - i];
		arr[k - i] = tmp;
	}
}

int main()
{
// 	freopen("in.txt", "r", stdin);
	while (scanf("%d",&arr[0])!=EOF)
	{
		n = 1;
		if (getchar() != '\n')
		{
			while (scanf("%d", &arr[n++]))
			if (getchar() == '\n') break;
		}
		printf("%d", arr[0]);
		for (int i = 1; i < n; i++)
		{
			printf(" %d", arr[i]);
		}
		printf("\n");
		
		int cnt = n;
		while (cnt)
		{
			int maxx = 0, rec;
			for (int i = 0; i < cnt; i++)
			{
				if (arr[i] > maxx)
				{
					maxx = arr[i];
					rec = i;
				}
			}

			if (rec != cnt - 1)
			{
				if (rec != 0)
					rev(rec);
				rev(cnt - 1);
			}
			cnt--;
		}
		printf("0\n");
	}
}
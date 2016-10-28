#include<cstdio>
#include<stack>
using namespace std;
const int MAXN = 1000 + 10;

int n, target[MAXN];

int main() {
	while (scanf("%d", &n) == 1) {
		if (n == 0)
		{
				break;
		}
		while (1)
		{
			stack<int> s;
			int A = 1, B = 1,flag = 0;
			for (int i = 1; i <= n; i++)
			{
				scanf("%d", &target[i]);
				if (target[1] == 0)
				{
					flag = 1;
					printf("\n");
					break;
				}
			}
			if (flag) break;
			int ok = 1;
			while (B <= n) {
				if (A == target[B]){ A++; B++; }
				else if (!s.empty() && s.top() == target[B]){ s.pop(); B++; }
				else if (A <= n) s.push(A++);
				else { ok = 0; break; }
			}
			printf("%s\n", ok ? "Yes" : "No");
		}
	}
	return 0;
}

/*
 * ������ ע���ڴ�
 * ����2^3 ~ 2^64֮�� 
 * �������unsigned long long��2^64����������� 
 */
#include <stdio.h>
#include <string.h>
int t, x;
unsigned long long i, ans;
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        ans = 0;
        scanf("%d", &x); ans += 1ll << x;
        scanf("%d", &x); ans += 1ll << x;
        scanf("%d", &x); ans += 1ll << x;
        scanf("%d", &x); ans += 1ll << x;
        scanf("%d", &x); ans += 1ll << x;
        scanf("%d", &x); ans += 1ll << x;
        scanf("%d", &x); ans += 1ll << x;
        scanf("%d", &x); ans += 1ll << x;
        scanf("%Lu", &i); ans += i;
        if(!ans) printf("18446744073709551616\n");
        else printf("%llu\n", ans);
    }
    return 0;
}

/*
 * ��ǰn���������������������ΪAn,�� An+1 = (m - 1) * An , A1 = m
 * ans = m ^ n - m * (m - 1) ^ (n - 1),ȡģ������ 
 */
#include <iostream>
using namespace std;
const int mod = 100003;
long long m, n;
int quick_pow(long long num, long long n)
{
    long long ans = 1;
    while(n)
    {
        if(n & 1) ans = ans * num % mod;
        n >>= 1;
        num = num * num % mod;
    }
    return ans;
}
int main()
{
    long long ans;
    ios::sync_with_stdio(false);
    cin >> m >> n;
    ans = quick_pow(m, n) - (m * quick_pow(m - 1, n - 1) % mod);
    while(ans < 0) ans += mod;
    cout << ans << endl;
    return 0;
}

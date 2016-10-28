/*
 * ���� THU ������ ��֤���� 
 * ����ȡ��һ����ʹ������ߵķ���������Ca�㣬���д�������ÿһ�����Ŀ���ΪAi
 * ��ȡһ����ʹ�ױ���̵ķ���������Cb�㣬���д�������ÿһ�����Ŀ���ΪBi
 * ��ȻA1>=B1,ACb<=BCb����˵�����ٴ���һ��k����(1,CB)������Ak-1>=Bk-1��Ak<=Bk
 * Ҳ����˵������A��k����ȫ������B��k�����
 * ����һ���·�������k�����ϰ�����A�����°�����B�����߶���Ҫ�Ŀ���м䵱��k�� 
 * �·����Ĳ�����A��ͬ�����ױ߳�����B��ͬ 
 * 
 * ����sum��¼ǰ׺�ͷ������ 
 * f[i]��ʾi~n���²���С��� g[i]��ʾi�Ĳ���  
 * f[i] = min{sum[j - 1] �C sum[i - 1]} (sum[j - 1] �C sum[i - 1] >= f[j])
 * �õ�������ά��j :
 * ��sum[q[head + 1] �C 1] �C sum[i - 1] >= f[q[head + 1]] ɾȥ���� 
 * ��sum[j' - 1] �C f[j'] >= sum[j - 1] �C f[j]����j > j' ɾȥ��β 
 */
#include <iostream>
using namespace std;
int n, sum[100001] = {}, f[100001] = {}, g[100001] = {};
int q[100001] = {}, head = 0, tail = 0;
int main()
{
    int i;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; ++i)
    {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }
    q[head] = n + 1;
    for(i = n; i >= 1; --i)
    {
        while(head < tail && sum[q[head + 1] - 1] - f[q[head + 1]] >= sum[i - 1]) ++head;
        f[i] = sum[q[head] - 1] - sum[i - 1];
        g[i] = g[q[head]] + 1;
        while(head <= tail && sum[i - 1] - f[i] >= sum[q[tail] - 1] - f[q[tail]]) --tail;
        q[++tail] = i;
    }
    cout << g[1] << endl;
    return 0;
}

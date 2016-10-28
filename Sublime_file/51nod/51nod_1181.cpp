#include <cstdio> 
#include <iostream> 
#include <cstring>
using namespace std; 

const int Maxn=1e6+10;
int pri[Maxn]= {0};
int main()
{
    int n;
    scanf("%d",&n);
    long long cnt = 0,i,j;
    pri[1] = 1;
    pri[2] = 0;
    for(i=2; i <= Maxn;i++)
    {
        if(!pri[i])
        {
            cnt++;
            if(!pri[cnt]&&i>=n)
            {
                printf("%d\n",i);
                break;
            }
            for(j = i*i;j <= Maxn;j+=i)
                pri[j] = 1;
        }
    }

    return 0;
}
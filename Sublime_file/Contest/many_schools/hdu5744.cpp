#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
    int n,t,k,sum=0,tmp=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        sum = 0,tmp = 0;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&k);
            sum += k;
            if(k%2)
            {
                sum--;
                tmp++;
            }
        }
        if(tmp==0)
            printf("%d\n",sum);
        else printf("%d\n",sum/2/tmp*2+1);
    }

    return 0;
}
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

char s[100010];  
char p[10010];  
  
int main()  
{  
    int t,n,m;  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%d %d",&n,&m);  
        scanf("%s %s",s,p);  
        for(int i = 0 ; i < n ; i++)  
        {  
            if(i > n - m)  
            {  
                putchar('0');  
                continue;  
            }  
            bool f = true;  
            for(int j = 0 ; j < m ; j++)  
            {  
                if(j < m - 1 && p[j] == s[i + j + 1] && p[j + 1] == s[i + j])  
                    j++;  
                else if(p[j] != s[i + j])  
                {  
                    f = false;  
                    break;  
                }  
            }  
            putchar(f ? '1' : '0');  
        }  
        puts("");  
    }  
  
    return 0;  
}  

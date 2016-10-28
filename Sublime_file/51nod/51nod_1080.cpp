#include <cstdio> 
#include <iostream> 
#include <cstring>
using namespace std;  

int CountOne(int n) {  
    int current=0,after=0,before=0;
    int i = 1,cnt = 0;
    while(n/i)
    {
        current = (n/i)%10;
        before = n / (i*10);
        after = n - (n/i)*i;
        if (current > 1)
        {
            cnt += (before + 1)*i;
        }
        else if(current == 1)
        {
            cnt += before*i + after + 1;
        }
        else if(current == 0)
            cnt += before*i;
        i *= 10;
    }
    return cnt;
}
int main()  
{  
    int n;  
    while(cin>>n){  
        int res=CountOne(n);  
        cout<<res<<endl;
    }  
    return 0;  
}  
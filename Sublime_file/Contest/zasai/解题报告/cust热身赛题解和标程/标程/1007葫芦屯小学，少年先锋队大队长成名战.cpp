#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[105];
    while(cin>>s)
    {
        int l=strlen(s);
        if(s[l-1]=='0'||s[l-1]=='2'||s[l-1]=='4'||s[l-1]=='6'||s[l-1]=='8'||s[l-1]=='5')
            {
                cout<<"headmaster"<<endl;
                continue;
            }
        int sum=0;
        for(int i=0;i<l;i++)
            sum+=s[i]-'0';
        if(sum%3==0)
            cout<<"headmaster"<<endl;
        else
            cout<<"love_me_again"<<endl;
    }
    return 0;
}

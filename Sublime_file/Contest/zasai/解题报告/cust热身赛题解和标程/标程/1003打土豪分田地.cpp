#include <iostream>
#include <cstdio>
using namespace std;
int n;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(cin>>n)
    {
	n=2*n+1;
        for(int i=1;i<=n;i++)
        {
            if(i==1||i==n||i==(n/2)+1)
                for(int j=1;j<=n;j++)
                    cout<<'*';
            else
			{
                for(int j=1;j<=n;j++)
                {
                    if(j==1||j==n||j==(n/2)+1)
                        cout<<'*';
                    else cout<<' ';
                }
            }
            cout<<endl;
        }
    }

    return 0;
}

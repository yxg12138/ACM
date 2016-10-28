#include <bits/stdc++.h>
using namespace std;
vector<int> ans;

void TAT()
{

    for(int i=2; i<=50; i++)
    {
        int flag=0;
        for(int j=2; j<i; j++)
            if(i%j==0) flag=1;
        if(!flag) ans.push_back(i);
    }
    ans.push_back(4);
    ans.push_back(9);
    ans.push_back(25);
    ans.push_back(49);
    int tmp=0;
    for(int i=0; i<ans.size(); i++)
    {
        cout << ans[i] << endl;
        string s;
        cin >> s;
        if(s=="yes") tmp++;
    }
    if(tmp<2) cout << "prime" << endl;
    else cout << "composite" << endl;
}
int main()
{
    TAT();

    return 0;
}
//题解：只需要判断字符串中是否有连续的7个0或7个1即可
//以下给出的一种比较暴力的解法，直接遍历字符串中每一个字符，
//用cnt记录连续出现的字符的个数，如果出现不同的字符，cnt置为1
//最后如果cnt>=7则跳出遍历，输出NO。
//如果全部遍历完成后没出现cnt>=7情况，输出YES
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    string str;
    while(cin >> str)
    {
        int cnt = 1,ans=0;
        char f;
        int l = str.length();
        f=str[0];//记录第一个字符
        for(int i = 1 ;i<l;i++)//从第二个字符开始
        {
            if(str[i]==f)//判断当前字符是否与上一个相同
            {
                cnt++;
                if(cnt>=7)
                {
                    ans=1;//有7个连续相同的字符出现，跳出
                    break;
                }
            }
            else
            {
                cnt = 1;//cnt重置
                f=str[i];
            }
        }
        if(ans==1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

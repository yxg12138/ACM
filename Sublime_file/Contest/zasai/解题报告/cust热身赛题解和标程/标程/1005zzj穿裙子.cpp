//��⣺ֻ��Ҫ�ж��ַ������Ƿ���������7��0��7��1����
//���¸�����һ�ֱȽϱ����Ľⷨ��ֱ�ӱ����ַ�����ÿһ���ַ���
//��cnt��¼�������ֵ��ַ��ĸ�����������ֲ�ͬ���ַ���cnt��Ϊ1
//������cnt>=7���������������NO��
//���ȫ��������ɺ�û����cnt>=7��������YES
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
        f=str[0];//��¼��һ���ַ�
        for(int i = 1 ;i<l;i++)//�ӵڶ����ַ���ʼ
        {
            if(str[i]==f)//�жϵ�ǰ�ַ��Ƿ�����һ����ͬ
            {
                cnt++;
                if(cnt>=7)
                {
                    ans=1;//��7��������ͬ���ַ����֣�����
                    break;
                }
            }
            else
            {
                cnt = 1;//cnt����
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

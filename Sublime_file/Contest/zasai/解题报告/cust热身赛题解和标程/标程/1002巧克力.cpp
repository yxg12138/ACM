/*
��⣺���������Ҫ���ɿ�����������s=(y/100*n)-x,
��Ҫע�⣬�����������s������������Ҫ����ȡ��
�������ԭ�����ɿ�����Ŀx�Ѿ����˵Ļ�����Ϊ0��Ϊ����
��󣬸��������Ƽ��þ��ȸߵ�double����
*/
#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
	double n,x,y;
	while(cin >> n >> x >> y)
    {
        double s=y/100.0*n;
        s=s-x;
        int c=s;//ȡ����������
        if (s>c)
            c++;
        if (c<=0)
            cout << 0 << endl;
        else
            cout << c << endl;
    }
    return 0;
}

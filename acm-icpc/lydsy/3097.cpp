/*
 * ��u64�൱�ڶ�2^64ȡģ��
 * ���base��ż���Ļ��ͺܺÿ��ˣ�aaa......a��baaa......a��a�кö�ö�����������ַ�����hashֵ����ͬ�ġ�
 * ���base�������Ļ�������ֻ����a��b������ĸ��
 * a \ b��ʾa������b����orz ������ѧ��
 * ����ѧ�ϵĺ���not(S)��ʾ���ַ���S��ÿ��λ�õ�'a'���'b'����'b'���'a'���γɵ��ַ���������not("ababaa") = "bababb"
 * strA . strB�����ַ�����������"��" . "����" = "�޹���"
 * |str|��ʾ�ַ���str�ĳ��ȡ�
 * ���ַ�������{orzstr[i]}��orzstr[1] = "a", orzstr[i] = orzstr[i - 1] . not(orzstr[i - 1])
 * ��ô|orzstr[i]| = |orzstr[i - 1]| * 2����Ȼ���ǵȱ����У��õ���|orzstr[i]| = |orzstr[1]| . 2 ^ (i - 1) = 2 ^ (i - 1)
 * ��hash(str)Ϊstr�Ĺ�ϣֵ��
 * ��hash(orzstr[i]) = hash(orzstr[i - 1]) * base ^ |not(orzstr[i - 1])| + hash(not(orzstr[i - 1]))
                       = hash(orzstr[i - 1]) * base ^ (2 ^ (i - 2)) + hash(not(orzstr[i - 1]))
 * hash(not(orzstr[i])) = hash(not(orzstr[i - 1])) * base ^ (2 ^ (i - 2)) + hash(orzstr[i - 1])
 * ��ʽ�����hash(orzstr[i]) - hash(not(orzstr[i])) = (hash(orzstr[i - 1]) * base ^ (2 ^ (i - 2)) + hash(not(orzstr[i - 1]))) - (hash(not(orzstr[i - 1])) * base ^ (2 ^ (i - 2)) + hash(orzstr[i - 1]))
 *                                                  = (hash(orzstr[i - 1]) - hash(not(orzstr[i - 1]))) * (base ^ (2 ^ (i - 2)) - 1)
 * �������Ƿ��֣�hash(orzstr[i]) - hash(not(orzstr[i]))�ƺ��Ǹ�����Ķ����������ǵ�Ŀ��ʵ������Ҫ�������ַ���strA, strBʹ��
 * hash(strA) % 2^64 = hash(strB) % 2^64
 * �൱�� 2^64 \ hash(strA) - hash(strB)
 * ������{f[i]}��f[i] = hash(orzstr[i]) - hash(not(orzstr[i]))
 * �������У�f[i] = f[i - 1] * (base ^ (2 ^ (i - 2)) - 1)
 * �����е㲻ˬ������������������{g[i]}��g[i] = base ^ (2 ^ (i - 1)) - 1
 * ������д�ɣ�f[i] = f[i - 1] * g[i - 1]
 * ��f[i] = f[1] * g[1] * g[2] * ... * g[i - 1]
 * Ȼ����һ����������飿
 * base����������base�������������η�Ҳһ�������������Զ��������i����g[i]Ϊż��������2 ^ (i - 1) \ f[i]
 * �����ǲ��ǽ������ء�������û�С��������Ļ�����Ҫʹ2 ^ 64 \ f[i]�����ٵ���i = 65����Ȼ����|orzstr[65]|�Ǹ��������֡�
 * �������Ǹղ���������̫�ӵ��ˡ���
 * i > 1ʱ�У�g[i] = base ^ (2 ^ (i - 1)) - 1 = (base ^ (2 ^ (i - 2)) - 1) * (base ^ (2 ^ (i - 2)) + 1) = g[i - 1] * һ��ż��
 * ��g[1]��Ȼ��ż���ɡ���
 * ��ô4 \ g[2]��8 \ g[3]...
 * Ҳ����˵2 ^ i \ g[i]
 * ����f[i] ʵ�����У�
 * (2 ^ 1) * (2 ^ 2) * (2 ^ 3) * ... * (2 ^ (i - 1)) \ f[i]
 * 2 ^ (i * (i - 1) / 2) \ f[i]
 * ��iȡ12ʱ������66��2��Ӵ��
 * ����ǿ�baseΪ����ʱ�ķ�����orzstr[12]��not(orzstr[12])��Ϊ����
 * ����spj���ѡ��������ѡ��ż������
 * ��Ȼ���Ǻܺð�ɡ���
 */
#include <cstdio>
int n, l;
char s[100001];
int main()
{
	n = 1;
	s[0] = 'a';
	for(int i = 0; i < 12; ++i)
	{
		for(int j = 0; j < n; ++j) s[j + n] = s[j] == 'a' ? 'b' : 'a';
		n <<= 1;
	}
	l = n >> 1;
	s[n++] = 'a';
	for(int i = 1; i < l; i++) s[n++] = 'a';
	s[n++] = 'b';
	for(int i = 1; i < l; i++) s[n++] = 'a';
	s[n] = '\0';
	printf("%d %d\n%s\n", n, l, s);
	return 0;
}

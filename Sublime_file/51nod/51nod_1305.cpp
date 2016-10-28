// 1305 Pairwise Sum and Divide
// 有这样一段程序，fun会对整数数组A进行求值，其中Floor表示向下取整：

// fun(A)
//     sum = 0
//     for i = 1 to A.length
//         for j = i+1 to A.length
//             sum = sum + Floor((A[i]+A[j])/(A[i]*A[j])) 
//     return sum

// 给出数组A，由你来计算fun(A)的结果。例如：A = {1, 4, 1}，fun(A) = [5/4] + [2/1] + [5/4] = 1 + 2 + 1 = 4。

#include <iostream>
using namespace std;

int main()
{
	int n,x,c1=0,c2=0,c_other = 0;
	cin >> n;
	while(n--)
	{
		cin >> x;
		if(x==1) c1++;
		else if(x==2) c2++;
		else c_other++;
	}
	long long ans = c1*(c1+c2+c_other-1) + c2*(c2-1) / 2;
	cout << ans << endl;


	return 0;
}
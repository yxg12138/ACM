#include <bits/stdc++.h>
using namespace std;

int a1[105],a2[105],a3[105],a4[105],c1,c2,c3,c4;
int w,h,q;
int x,y,a;

int main(){
	cin >> w >> h >> q;
	for(int i=0; i<q; i++){
		cin >> x >> y >> a;
		if(a==1)
			a1[c1++] = x;
		if(a==2)
			a2[c2++] = x;
		if(a==3)
			a3[c3++] = y;
		if(a==4)
			a4[c4++] = y;
	}
	sort(a1,a1+c1),sort(a2,a2+c2),sort(a3,a3+c3),sort(a4,a4+c4);
	int x1,x2,y1,y2;
	x1 = a1[c1-1],x2 = a2[0];
	y1 = a3[c3-1],y2 = a4[0];
	// cout << x1 << " " << x2 << " " << y1 << " " << y2 << endl;
	if(c2 == 0) x2 = w;
	if(c4 == 0) y2 = h;
	if(x2-x1<=0 || y2-y1<=0)
		cout << "0" << endl;
	else
		cout << (x2-x1)*(y2-y1) << endl;

}
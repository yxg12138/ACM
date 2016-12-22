#include <bits/stdc++.h>
using namespace std;

const int maxn = 1006;
const double pi = acos(-1.0);

struct node{
	double x,y;
}p[maxn],P[maxn];

int n,tot;
double l,ans;

double X(node A,node B,node C){
	return (B.x-A.x)*(C.y-A.y) - (C.x-A.x)*(B.y-A.y);
}

double len(node A,node B){
	return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));
}

bool cmp(node A,node B){
	double pp = X(p[0],A,B);
	if(pp > 0) return true;
	if(pp < 0) return false;
	return len(p[0],A) < len(p[0],B);
}

int main(){
	int T;
	scanf("%d",&T);
	for(int cas=1; cas<=T; cas++){
		if(cas!=1) printf("\n");
		scanf("%d%lf",&n,&l);
		ans = 2 * pi * l;
		for(int i=0; i<n; i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		
		if(n == 1) printf("%.0f\n",ans);
		else if(n == 2) printf("%.0f\n",ans+len(p[0],p[1]));
		else{
			for(int i=0; i<n; i++){
				if(p[i].y < p[0].y)
					swap(p[i],p[0]);
				else if(p[i].y==p[0].y && p[i].x<p[0].x)
					swap(p[i],p[0]);
			}
			sort(p+1,p+n,cmp);
			P[0] = p[0];
			P[1] = p[1];
			// cout << "=====" << P[0].x << " " << P[0].y << "======" << P[1].x << " " << P[1].y << endl;
			tot = 1;
			for(int i=2; i<n; i++){
				while(tot>0 && X(P[tot-1],P[tot],p[i])<=0) tot--;
				tot++;
				P[tot] = p[i];
			}

			for(int i=0; i<tot; i++)
				ans += len(P[i],P[i+1]);
			ans += len(P[0],P[tot]);

			printf("%.0f\n",ans);
		}

	}
}
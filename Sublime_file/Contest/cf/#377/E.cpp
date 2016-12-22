#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5+10;

struct node{
	int pow,id;
};

map<int,int> fre;
vector<int> v[maxn];
int n,m,ans1[maxn],ans2[maxn],cnt;
node a[maxn];

bool cmp(node a,node b){
	return a.pow < b.pow;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++){
		int x;
		cin >> x;
		int tmp = fre[x];
		if(tmp == 0){
			fre[x] = ++cnt;
			v[cnt].push_back(i);
		}else{
			v[tmp].push_back(i);
		}
	}
	for(int i=1; i<=m; i++)
		scanf("%d",&a[i].pow),a[i].id = i;

	sort(a+1,a+1+m,cmp);

	int tot = 0, num = 0;
	for(int i=1; i<=m; i++){
		int sub = 0;
		int x = a[i].pow;
		while(x){
			int id = fre[x];
			if(id){
				int len = v[id].size();
				if(len){
					int it = v[id][len-1];
					ans2[it] = a[i].id;
					ans1[a[i].id] = sub;
					v[id].pop_back();
					tot += sub;
					num++;
					break;
				}else
					fre.erase(x);
			}
			if(x == 1) break;
			x = (x+1) / 2;
			sub ++;
		}
	}

	printf("%d %d\n",num,tot);
	for(int i=1; i<=m; i++)
		printf("%d%c",ans1[i],(i==m ? '\n' : ' '));
	for(int i=1; i<=n; i++)
		printf("%d%c",ans2[i],(i==n ? '\n' : ' '));

}
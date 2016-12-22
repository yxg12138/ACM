#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e3+10;

int b[maxn],cur,n,k;

struct node{
	int index,cmd;
	node(){}
	node(int in,int cm) : index(in),cmd(cm) {}
}ans[maxn];

int solve(int *a,int len,int pre){
	if(len == 1) return 1;
	int flag=0,mx = -1;
	for(int i=1; i<len; i++){
		if(a[i]!=a[i-1]){
			flag = 1;
			break;
		}
	}
	if(!flag) return 0;

	for(int i=0; i<len; i++){
		mx = max(mx,a[i]);
	}
	int s = -1;

	for(int i=0; i<len; i++){
		if(a[i] == mx){
			if(i==0 && a[i+1]!=mx) { s=i; break;}
			if(i==len-1 && a[i-1]!=mx) { s=i; break;}
			if(i && a[i-1]!=a[i] || a[i+1]!=a[i]) { s=i; break;}
		}
	}

	if(s>0 && a[s-1]==a[s]){
		for(int i=s+1; i<len; i++)
			ans[cur++] = node(pre+s+1,1);
		for(int i=0; i<s; i++)
			ans[cur++] = node(pre+s+1-i,0);
	}else{
		for(int i=0; i<s; i++)
			ans[cur++] = node(pre+s+1-i,0);
		for(int i=s+1; i<len; i++)
			ans[cur++] = node(pre+1,1);
	}
	return 1;
}


int main(){
	int a[maxn];
	while(scanf("%d",&n) == 1){
		for(int i=0; i<n; i++)
			cin >> a[i];
		cin >> k;
		for(int i=0; i<k; i++)
			cin >> b[i];

		int num=0,cnt=0,cur1=0,i;
		for(i=0; i<n; i++){
			if(num+a[i] == b[cur1]){
				num = 0;
				cur1++;
			}else if(num+a[i] < b[cur1])
				num += a[i];
			else
				break;

			if(cur1 == k) break;
		}

		if(i<n-1 || cur1<k){
			cout << "NO\n";
			continue;
		}

		cur1=0,num=0,cnt=0,cur=0;
		int flag = 0;
		for(int i=0; i<n; i++){
			num += a[i];
			cnt++;
			if(num == b[cur1]){
				if(!solve(a+i-cnt+1,cnt,cur1)){
					flag = 1;
					break;
				}
				num = 0;
				cnt = 0;
				cur1++;
			}
		}

		if(flag) cout << "NO\n";
		else{
			cout << "YES\n";
			for(int i=0; i<cur; i++)
				cout << ans[i].index << " " << (ans[i].cmd ? 'R' : 'L') << endl;
		}
	}
}
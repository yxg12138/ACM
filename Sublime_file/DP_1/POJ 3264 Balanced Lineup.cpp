#include <iostream>
#include <cstdio>
using namespace std;

const int INF = 0x7ffffff;
int minV = INF;
int maxV = -INF;

struct node
{
	int L,R;
	int minV,maxV;
	int mid()
	{return (L+R)/2;}

}tree[1600010];

void build(int root,int L,int R)
{
	tree[root].L = L;
	tree[root].R = R;
	tree[root].minV = INF;
	tree[root].maxV = -INF;
	if(L!=R)
	{
		build(2*root,L,(L+R)/2);
		build(2*root+1,(L+R)/2+1,R);
	}
}

void insert(int root,int i,int v)
{
	if(tree[root].L==tree[root].R)
	{
		tree[root].minV = v;
		tree[root].maxV = v;
		return ;
	}
	tree[root].minV = min(tree[root].minV,v);
	tree[root].maxV = max(tree[root].maxV,v);
	if(i<=tree[root].mid())
		insert(root*2,i,v);
	else
		insert(root*2+1,i,v);
}

void query(int root,int s,int e)
{
	if(tree[root].minV >= minV && tree[root].maxV<=maxV)
		return ;
	if(tree[root].L==s && tree[root].R==e)
	{
		maxV = max(tree[root].maxV,maxV);
		minV = min(tree[root].minV,minV);
		return ;
	}
	if(e <= tree[root].mid())
		query(root*2+1,s,e);
	else
	{
		query(root*2,s,tree[root].mid());
		query(root*2+1,tree[root].mid()+1,e);
	}
}

int main()
{
	int N,T,h;
	cin >> N >> T;
	build(1,1,N);
	for(int i=1; i<=T; i++)
	{
		int s,e;
		cin>>s>>e;
		minV = INF;
		maxV = -INF;
		query(1,s,e);
		cout << maxV-minV<<endl;
	}


}
#include <iostream>
#include <cstdio>-
#include <algorithm>
using namespace std;

const int maxn = 5e4+10;
const int maxt = maxn*4;
int a[maxn];
int N,Q,L,R;

struct node{
    int le,ri,Tmax,Tmin;
}tree[maxt];


void build(int rt,int le,int ri){
    tree[rt].le = le;
    tree[rt].ri = ri;

    if(le == ri){
        tree[rt].Tmax = a[le];
        tree[rt].Tmin = a[le];
        return;
    }

    int mid = (le+ri) / 2;
    build(rt<<1,le,mid);
    build(rt<<1|1,mid+1,ri);

    tree[rt].Tmax = max(tree[rt<<1].Tmax,tree[rt<<1|1].Tmax);
    tree[rt].Tmin = min(tree[rt<<1].Tmin,tree[rt<<1|1].Tmin);
}

int query(int rt,int le,int ri,int flag){
    if(tree[rt].le==le && tree[rt].ri==ri){
        return (flag ? tree[rt].Tmin : tree[rt].Tmax);
    }

    int mid = (tree[rt].le+tree[rt].ri) / 2;
    if(R<=mid)
        return query(rt<<1,le,ri,flag);
    else if(L>mid)
        return query(rt<<1|1,le,ri,flag);
    else{
        if(flag) return min(query(rt<<1,le,mid,flag),query(rt<<1|1,mid+1,ri,flag));
        else return max(query(rt<<1,le,mid,flag), query(rt<<1|1,mid+1,ri,flag));
    }

}

int main()
{
    while(scanf("%d%d",&N,&Q) == 2){
        for(int i=1; i<=N; i++)
            scanf("%d",&a[i]);

        build(1,1,N);

        while(Q--){
            scanf("%d%d",&L,&R);
            printf("%d\n",query(1,L,R,0) - query(1,L,R,1));
        }
    }

    return 0;
}

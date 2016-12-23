#include <cstdio>

const int N = 1e5+10;

int n,p;
int pa[N+1];

// int find(int x){
//     while(x != pa[x])
//         x = pa[x];
//     return x;
// }
int find(int x){
    if(x==pa[x]) return x;
    return find(pa[x]);
}


int main(){
    while(scanf("%d%d",&n,&p) == 2){
        if(!n && !p) break;
        pa[1] = 1;
        for(int i=2; i<=n; i++)
            scanf("%d",&pa[i]);

        long long sum = 0;
        for(int i=1; i<=p; i++){
            char s[2];
            int x;
            scanf("%s%d",s,&x);
            if(s[0] == 'M')
                pa[x] = x;
            else
                sum += find(x);
        }
        printf("%lld\n",sum);
    }
}
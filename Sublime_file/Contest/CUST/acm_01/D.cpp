#include <bits/stdc++.h>

using namespace std;

inline int get_int()
{
    int r=0;
    char c;
    while((c=getchar())!=' '&&c!='\n')
        r=r*10+c-'0';
    return r;
}
inline void out(int x)
{
    if(x>10)
    {
        out(x/10);
    }
    putchar(x % 10 + '0');
    putchar('\n');
}
/****************************************/

char a[500],b[500],c[500],d[500];
int xiao(int xx,int yy){return xx<yy?xx:yy;}
int main()
{
    int aa,dd,bb,l,n,i,j,xx;
    cin>>c;
    n=strlen(c);
    aa=c[0]-'0';
    for(j=0,i=2;i<n;i++,j++){
        if(c[i]=='e')
            break;
        d[j]=c[i];
    }
    bb=0;
    for(j=0,i++;i<n;i++,j++)
        bb=bb*10+c[i]-'0';
    //aa=strlen(a);
    //bb=strlen(b);
    dd=strlen(d);
    l=0;
    if(aa)
        printf("%d",aa);
    l=aa;
    xx=xiao(bb,dd);
    for(i=0;i<xx;i++){
        if(l==0&&d[i]=='0')
            continue;
        printf("%c",d[i]);
        l=1;
    }
    if(xx==dd){
        for(i=dd;i<bb;i++)
            printf("0");
    }
    else{
        if(l==0)
          printf("0");
        l=0;
        for(int i=xx;i<dd;i++){
            if(d[i]>'0'){
                l=1;
                break;
            }
        }
        if(l){
            printf(".");
        for(i=xx;i<dd;i++)
            printf("%c",d[i]);
        }

    }
    printf("\n");
}
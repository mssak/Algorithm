#import<cstdio>
int a[42],n,s;
main(){while(scanf("%d",&n)>0)a[n%42]=1;for(int n:a)s+=n;printf("%d",s);}
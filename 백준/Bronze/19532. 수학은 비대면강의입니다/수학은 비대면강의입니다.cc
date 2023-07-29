#include<bits/stdc++.h>
#define MAX 
using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,b,c,d,e,f,x,y;
    cin>>a>>b>>c>>d>>e>>f;


    if(a==0){
        y=c/b;
        x=(f-e*y)/d;
        printf("%d %d",x,y);
        return 0;
    }

    if(b==0){
        x=c/a;
        y=(f-d*x)/e;
        printf("%d %d",x,y);
        return 0;
    }

    if(d==0){
        y=f/e;
        x=(c-b*y)/a;
        printf("%d %d",x,y);
        return 0;
    }

    if(e==0){
        x=f/d;
        y=(c-a*x)/b;
        printf("%d %d",x,y);
        return 0;
    }

    for(x=-999;;x++){
        y=(c-a*x)/b;
        if(y*b!=c-a*x){
            continue;
        }

        if(d*x+e*y==f){
            printf("%d %d",x,y);
            return 0;
        }
    }
}
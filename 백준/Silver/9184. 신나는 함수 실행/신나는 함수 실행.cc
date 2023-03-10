#include<bits/stdc++.h>
#define MAX 21
using namespace std;

int arr[MAX][MAX][MAX]={};

int w(int a,int b,int c)
{
    if(a<=0 or b<=0 or c<=0){
        return 1;
    }

    if(a>20 or b>20 or c>20){
        return w(20,20,20);
    }

    if(arr[a][b][c]!=-1){
        return arr[a][b][c];
    }

    if(a<b and b<c){
        int res = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
        arr[a][b][c]=res;
        return res;
    }

    int res = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    arr[a][b][c]=res;
    return res;
}

int main()
{
    int a,b,c;
    for(int i=0;i<MAX;i++){
            for(int j=0;j<MAX;j++){
                for(int k=0;k<MAX;k++){
                    arr[i][j][k]=-1;
                }
            }
        }


    while(1){
        scanf("%d%d%d",&a,&b,&c);
        if(a==-1 and b==-1 and c==-1){
            break;
        }
        printf("w(%d, %d, %d) = %d\n",a,b,c,w(a,b,c));
    }
}
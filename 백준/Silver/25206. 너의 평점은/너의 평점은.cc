#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    double sum1=0;
    double sum2=0;

    for(int i=0;i<20;i++){
        string s;
        float f;
        cin>>s>>f>>s;

        if(s=="P"){
            continue;
        }
        sum1+=f;
        if(s=="A+"){
            sum2+=f*4.5;
        }
        else if(s=="A0"){
            sum2+=f*4;
        }
        else if(s=="B+"){
            sum2+=f*3.5;
        }
        else if(s=="B0"){
            sum2+=f*3;
        }
        else if(s=="C+"){
            sum2+=f*2.5;
        }
        else if(s=="C0"){
            sum2+=f*2;
        }
        else if(s=="D+"){
            sum2+=f*1.5;
        }
        else if(s=="D0"){
            sum2+=f;
        }
    }

    printf("%.6f",sum2/sum1);
}
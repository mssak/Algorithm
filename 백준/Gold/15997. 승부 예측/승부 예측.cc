#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    unordered_map<string,int> team;
    double rate[4][4][3];
    for(int i=0;i<4;i++){
        string s;
        cin>>s;
        team[s]=i;
    }
    for(int i=0;i<6;i++){
        string a,b;
        double w,d,l;
        cin>>a>>b>>w>>d>>l;
        rate[team[a]][team[b]][0]=w;
        rate[team[b]][team[a]][2]=w;
        rate[team[a]][team[b]][1]=d;
        rate[team[b]][team[a]][1]=d;
        rate[team[a]][team[b]][2]=l;
        rate[team[b]][team[a]][0]=l;
    }

    double ans[4]={0};
    int ws[3]={3,1,0};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                for(int l=0;l<3;l++){
                    for(int m=0;m<3;m++){
                        for(int n=0;n<3;n++){
                            double r=1;
                            int score[4]={0};
                            
                            r*=rate[0][1][i];
                            score[0]+=ws[i];
                            score[1]+=ws[2-i];

                            r*=rate[0][2][j];
                            score[0]+=ws[j];
                            score[2]+=ws[2-j];

                            r*=rate[0][3][k];
                            score[0]+=ws[k];
                            score[3]+=ws[2-k];

                            r*=rate[1][2][l];
                            score[1]+=ws[l];
                            score[2]+=ws[2-l];

                            r*=rate[1][3][m];
                            score[1]+=ws[m];
                            score[3]+=ws[2-m];

                            r*=rate[2][3][n];
                            score[2]+=ws[n];
                            score[3]+=ws[2-n];

                            if(r==0){
                                continue;
                            }

                            pair<int,int> order[5];
                            for(int i=0;i<4;i++){
                                order[i]={score[i],i};
                            }
                            sort(order,order+4,greater<>());
                            order[4]={-1,-1};
                            for(int i=0,c=1,e=2;i<4;i++){
                                if(order[i].first==order[i+1].first){
                                    c++;
                                }
                                else{
                                    int up=min(c,e);
                                    for(int j=0;j<c;j++){
                                        ans[order[i-j].second]+=r/(double)c*(double)up;
                                    }
                                    e-=up;
                                    c=1;
                                    if(e<=0){
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    double s=0;
    for(int i=0;i<4;i++){
        s+=ans[i];
    }

    for(int i=0;i<4;i++){
        printf("%f\n",ans[i]);
    }
}

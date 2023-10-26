#include<bits/stdc++.h>
#define MAX 102
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int mp[MAX][MAX][2];
    int shark[MAX*MAX][5];
    unordered_set<int> si;
    int R,C,M;
    cin>>R>>C>>M;

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            mp[i][j][0]=-1;
            mp[i][j][1]=-1;
        }
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<5;j++){   //0 1 2 3 4
            cin>>shark[i][j];   //r c s d z
        }
        if(shark[i][3]==1 || shark[i][3]==2){
            shark[i][2]%=2*(R-1);
        }
        else{
            shark[i][2]%=2*(C-1);
        }
        shark[i][0]--;
        shark[i][1]--;
        mp[shark[i][0]][shark[i][1]][0]=i;
        si.insert(i);
    }

    int ans=0;
    for(int pos=0,flag=0;pos<C;pos++,flag^=1){
        for(int i=0;i<R;i++){
            if(mp[i][pos][flag]!=-1){
                ans+=shark[mp[i][pos][flag]][4];
                si.erase(mp[i][pos][flag]);
                mp[i][pos][flag]=-1;
                break;
            }
        }

        set<int> rm;
        for (int idx:si) {
            int &r=shark[idx][0];
            int &c=shark[idx][1];
            int &s=shark[idx][2];
            int &d=shark[idx][3];
            int &z=shark[idx][4];

            mp[r][c][flag]=-1;
            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, 1, -1};
            for (int j=0;j<s;j++) {
                r += dr[d-1];
                c += dc[d-1];
                
                if (r<0){r=1;d=2;}
                else if(r>=R){r=R-2;d=1;}
                else if(c<0){c=1;d=3;}
                else if(c>=C){c=C-2;d=4;}
            }

            if(mp[r][c][flag^1]!=-1){
                if(shark[mp[r][c][flag^1]][4]<z){
                    rm.insert(mp[r][c][flag^1]);
                    mp[r][c][flag^1]=idx;
                }
                else{
                    rm.insert(idx);
                }
            }   
            else{
                mp[r][c][flag^1]=idx;
            }
        }
        for(int i:rm){
            si.erase(i);
        }
    }
    cout<<ans<<"\n";
}

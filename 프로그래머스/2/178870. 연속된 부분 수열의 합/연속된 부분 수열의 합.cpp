#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> seq, int k) {
    vector<int> answer(2);
    int n=seq.size();
    vector<int> sum(n+1);

    for(int i=1;i<n;i++){
        sum[i]=sum[i-1]+seq[i-1];
    }

    int mn=1e9;

    for(int i=0;i<n;i++){
        int s=0;
        int e=n-1;
        while(s<=e){
            int m=(s+e)/2;
            int sm=sum[m]-sum[i]+seq[m];
            if(sm==k){
                if(mn>m-i){
                    answer[0]=i;
                    answer[1]=m;
                    mn=m-i;
                }
                break;
            }else if(sm<k){
                s=m+1;
            }else{
                e=m-1;
            }
        }
    }

    return answer;
}
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4);
    int top;
    unordered_set<int> nodes;
    unordered_map<int,int> out;
    unordered_map<int,int> in;
    
    
    for(auto i:edges){
        nodes.insert(i[0]);
        nodes.insert(i[1]);
        out[i[0]]++;
        in[i[1]]++;
    }
    
    int mx=-1;
    for(int i:nodes){
        if(in[i]==0&&out[i]>mx){
            top=i;
            mx=out[i];
            answer[0]=i;
        }
    }

    
    for(int i:nodes){
        if(i==top){
            continue;
        }
        
        if(out[i]==0){
            answer[2]++;
        }else if(out[i]==2){
            answer[3]++;
        }
    }
    
    answer[1]=out[top]-answer[2]-answer[3];
    
    return answer;
}
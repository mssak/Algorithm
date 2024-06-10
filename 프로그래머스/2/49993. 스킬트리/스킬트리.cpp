#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int arr[26]{0};
    for(int i=0;i<skill.size();i++){
        arr[skill[i]-'A']=i+1;
    }
    
    for(string i:skill_trees){
        int pos=1;
        bool can=true;
        for(char c:i){
            if(arr[c-'A']!=0){
                if(pos==arr[c-'A']){
                    pos++;
                }
                else{
                    can=false;
                    break;
                }
            }
        }
        if(can){
            answer++;
        }
    }
    return answer;
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <memory.h>
using namespace std;
int n; // 주유소 개수
int l,p; // 마을까지 남은 거리 , 트럭에 남아있는 연료양
pair<int,int> stations[10000];
int counter;
// 가까운 거리 기준으로 정렬한 벡터
// 연료 기준으로 정렬한 벡터
// 멈추더라도 최대한 기름이 많은 주유소에서 멈추고 싶다
// 정렬이 되있으면...

void Solve(){
    sort(stations,stations+n);
    priority_queue<int> pq; // 내림차순
    int idx = 0;
    while(l>p){
       // 현재 위치에서 도달할 수 있는 모든 주유소를 우선순위 큐에 넣기
        while(stations[idx].first<=p && idx<n){
            pq.push(stations[idx].second);
            idx++;
        }
       // 제일 우선순위의 pos를 빼와서 해당 기름 채워주기
        if(!pq.empty()){ // 주유소 정지
            p += pq.top();
            pq.pop();
            counter++;
        }
        else if(idx==n || stations[idx].first>p){ // 마지막까지 검사했는데 업거나 혹은 다음 주유소까지 도달할수 없거나
            cout<<-1;
            return;
        }
    }
    cout<<counter;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>stations[i].first>>stations[i].second;
    }
    cin>>l>>p;
    Solve();
}
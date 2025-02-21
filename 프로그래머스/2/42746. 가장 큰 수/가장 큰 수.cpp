#include <bits/stdc++.h>
using namespace std;

bool comp(int a, int b) {
    string sa = to_string(a);
    string sb = to_string(b);
    return (sa + sb) > (sb + sa);
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), comp);
    
    // 모든 숫자가 0일 경우 "0"을 리턴
    if(numbers[0] == 0) return "0";
    
    for (int i : numbers) {
        answer += to_string(i);
    }
    return answer;
}

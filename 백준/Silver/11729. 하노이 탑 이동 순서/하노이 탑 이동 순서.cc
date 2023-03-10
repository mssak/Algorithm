#include<bits/stdc++.h>

using namespace std;

string answer="";
int cnt=0;

void move(int n, char src, char tmp, char dest)
{
    if (n > 0)
    {
        move(n - 1, src, dest, tmp);
        answer+=src;
        answer+=" ";
        answer+=dest;
        answer+="\n";
        cnt++;
        move(n - 1, tmp, src, dest);
    }
}
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a;
    cin>>a;

    move(a,'1','2','3');
    cout<<cnt<<"\n"<<answer;
}
#include<bits/stdc++.h>

using namespace std;

int f[41];
int b=0,c=0;

int fib(int n) {
    if (n == 1 or n == 2){
        b++;
        return 1;
    } 
    else return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n) {
    f[1] =1;
    f[2] =1;
    for (int i=3;i<=n;i++){
        c++;
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a;
    cin>>a;
    fib(a);
    fibonacci(a);
    cout<<b<<" "<<c;
}
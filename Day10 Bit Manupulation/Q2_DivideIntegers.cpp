#include<bits/stdc++.h>
using namespace std;
int divide(int A, int B) {
    if(B==0) return INT_MAX;
    int sign = 1;
    if(A<0) sign *= -1;
    if(B<0) sign *= -1;
    if(abs(A)<0) return INT_MAX;
    A = abs(A);
    B = abs(B);
    while(B!=1){
        A>>=1;
        B>>=1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cout<<divide(-2147483648,-1);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int solve(const vector<int> &A){
    int t=0;
    int mask;
    int sb;
    for(int i=0;i<32;++i){
        mask = 1<<i;
        sb = 0;
        for(auto x:A){
            if(mask&x) sb++;
        }
        t += pow(2,i)*(sb%3);
    }
    return t;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int x;
    vector<int> A;
    while(cin>>x) A.emplace_back(x);
    cout<<solve(A);
    return 0;
}

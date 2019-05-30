#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &A) {
    int n = A.size();
    int c=0;
    int mx = A[0];
    for(int i=0;i<n;++i){
        if(A[i]>mx) mx = A[i];
        if(mx==i) c++;
    }
    return c;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<int> A;
    int x;
    while(cin>>x) A.emplace_back(x);
    cout<<solve(A);
    return 0;
}

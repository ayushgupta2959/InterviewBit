#include<bits/stdc++.h>
using namespace std;
int firstMissingPositive(vector<int> &A) {
    int n = A.size();
    for(int i=0;i<n;++i) if(A[i]<1 || A[i]>(n)) A[i] = 0;
    for(int i=0;i<n;++i) {
        if(A[i]){
            int t = abs(A[i]);
            if(A[t-1]<0) continue; //repeated number
            else if(A[t-1]==0) A[t-1] = -(t);
            else A[t-1] = -A[t-1];
        }
    }
    int i=0;
    for(;i<n;++i) if(A[i]>=0) break;
    return (i+1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int x;
    vector<int> A;
    while(cin>>x) A.emplace_back(x);
    cout<<firstMissingPositive(A);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int firstMissingPositive(vector<int> &A) {
    int n = A.size();
    cout<<n<<"\n";
    for(int i=0;i<n;++i) if(A[i]<1 || A[i]>(n+1)) A[i] = 0;
    for(int i=0;i<n;++i) {
        if(A[i]){
            int t = abs(A[i]);
            if(A[t-1]<0) continue; //repeated number
            else if(A[t-1]==0) A[t-1] = -(t);
            else A[t-1] = -A[t-1];
        }
    }
    for(int i=0;i<n;++i) cout<<A[i]<<" ";
    cout<<"\n";
    for(int i=0;i<n;++i) if(A[i]>=0) return (i+1);
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

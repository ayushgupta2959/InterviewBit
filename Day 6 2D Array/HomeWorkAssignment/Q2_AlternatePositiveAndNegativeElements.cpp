#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> &A) {
    int n = A.size();
    //even index = -ve element
    //odd index = +ve element
    int j;
    for(int i=0;i<n;++i){
        if(i&1){
            j=i;
            while(j<n && A[j]<0) j++;
            if(j==n) continue;
            while(j!=i){
                swap(A[j-1],A[j]);
                j--;
            }
        }
        else{
            j=i;
            while(j<n && A[j]>=0) j++;
            if(j==n) continue;
            while(j!=i){
                swap(A[j-1],A[j]);
                j--;
            }
        }
    }
    return A;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<int> A;
    int x;
    while(cin>>x) A.emplace_back(x);
    A = solve(A);
    for(auto x:A) cout<<x<<" ";
    return 0;
}

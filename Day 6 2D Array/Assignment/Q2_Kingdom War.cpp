#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    for(int i=m-1;i>=0;--i){
        for(int j=n-1;j>=0;--j){
            if((i+1)<m) A[i][j] += A[i+1][j];
            if((j+1)<n) A[i][j] += A[i][j+1];
            if((i+1)<m && (j+1)<n) A[i][j] -= A[i+1][j+1];
        }
    }
    int mx = A[0][0];
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(A[i][j]>mx){
                mx=A[i][j];
            }
        }
    }
    return mx;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int m,n;
    cin>>m>>n;
    vector<vector<int>> A(m,vector<int>(n));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>A[i][j];
        }
    }
    cout<<solve(A);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

/*top down
int solve(int i,int A,vector<vector<int>> &memo){
    while(i*i>A) i--;
    if(i*i==A) return 1;
    if(i==1) return A;
    if(memo[i][A]!=-1) return memo[i][A];
    int q1 = 1 + solve(i,A-i*i,memo);
    int q2 = solve(i-1,A,memo);
    memo[i][A] = min(q1,q2);
    return memo[i][A];
}
int countMinSquares(int A) {
    vector<vector<int>> memo(sqrt(A)+1,vector<int>(A+1,-1));
    return solve(sqrt(A),A,memo);
}
*/
//bottom up
/*
int countMinSquares(int A) {
    int srt = sqrt(A);
    vector<vector<int>> dp(srt+1,vector<int>(A+1));
    for(int i=1;i<=A;++i) dp[1][i] = i;
    for(int j=1;j<=srt;++j) dp[j][1] = 1;
    for(int i=2;i<=srt;++i){
        for(int j=2;j<=A;++j){
            if(i*i>j) dp[i][j] =  dp[i-1][j];
            else if(i*i==j) dp[i][j] = 1;
            else{
                dp[i][j] = min(1 + dp[i][j-i*i],dp[i-1][j]);
            }
        }
    }
    return dp[srt][A];
}
*/
//bottom up optimized space
int countMinSquares(int A) {
    int srt = sqrt(A);
    //vector<vector<int>> dp(srt+1,vector<int>(A+1));
    vector<int> a(A+1),b(A+1);
    for(int i=1;i<=A;++i) a[i] = i;
    for(int i=2;i<=srt;++i){
        b[1] = 1;
        for(int j=2;j<=A;++j){
            if(i*i>j) b[j] =  a[j];
            else if(i*i==j) b[j] = 1;
            else{
                b[j] = min(1 + b[j-i*i],a[j]);
            }
        }
        a = b;
    }
    return a[A];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int A;
    //cin>>A;
    cout<<countMinSquares(97280)<<"\n";
    return 0;
}

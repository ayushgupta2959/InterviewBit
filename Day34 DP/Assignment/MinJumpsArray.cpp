//O(n^2)
int Solution::jump(vector<int> &A) {
    int n = A.size();
    vector<int> dp(n,INT_MAX);
    dp[0] = 0;
    int j;
    for(int i=0;i<n;++i){
        if(dp[i]==INT_MAX) return -1;
        j = min(n-1,i+A[i]);
        for(;j>i;j--){
            dp[j] = min(dp[j],dp[i]+1);
        }
    }
    return dp[n-1];
}

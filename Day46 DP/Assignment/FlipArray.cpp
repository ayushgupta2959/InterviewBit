/*accepted 
#define pi pair<int,int>
int Solution::solve(const vector<int> &A) {
    int n = A.size();
    int sum = accumulate(A.begin(),A.end(),0);
    int m = sum/2;
    vector<vector<pi>> dp(n+1,vector<pi>(m+1,{0,0}));
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(j<A[i-1]) dp[i][j] = dp[i-1][j];
            else{
                int x = A[i-1] + dp[i-1][j-A[i-1]].first - dp[i-1][j].first;
                if(x<0) dp[i][j] = dp[i-1][j];
                else if(x==0){
                    dp[i][j].first = dp[i-1][j].first;
                    dp[i][j].second = min(dp[i-1][j].second,1+dp[i-1][j-A[i-1]].second);
                }
                else{
                    dp[i][j].first = A[i-1] + dp[i-1][j-A[i-1]].first;
                    dp[i][j].second = 1+dp[i-1][j-A[i-1]].second;
                }
            }
        }
    }
    return dp[n][m].second;
}
*/
//space optimized
int Solution::solve(const vector<int> &A)
{
    int sum=0;
    for(int i=0;i<A.size();i++)
    sum+=A[i];
    int temp=sum/2;
    vector<int>dp(temp+1,INT_MAX);
    dp[0]=0;
    for(int i=0;i<A.size();i++)
    {
        for(int j=temp;j>=A[i];j--)
        {
            if(dp[j-A[i]]!=INT_MAX)
            {
                dp[j]=min(dp[j],dp[j-A[i]]+1);
            }
        }
    }
    for(int j=temp;j>=0;j++)
    {
        if(dp[j]!=INT_MAX)
        return dp[j];
    }
}

int Solution::minDistance(string A, string B) {
    int la = A.length();
    int lb = B.length();
    vector<vector<int>> dp(la+1,vector<int>(lb+1));
    for(int i=0;i<=la;++i){
        dp[i][0]=i;
    }
    for(int j=0;j<=lb;++j){
        dp[0][j] = j;
    }
    for(int i=1;i<=la;++i){
        for(int j=1;j<=lb;++j){
            if(A[i-1]==B[j-1]) dp[i][j]=dp[i-1][j-1];
            else{
                dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
            }
        }
    }
    return dp[la][lb];
}

//space_optimized
/*
int Solution::minDistance(string A, string B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int lengthA = A.length();
    int lengthB = B.length();
    
    if (lengthA == 0 || lengthB == 0)
    {
        return max(lengthA, lengthB);
    }
    
    vector<int> cache(lengthB + 1);
    for (int i = 0; i <= lengthB; i++)
    {
        cache[i] = i;
    }
    
    int lastImpNo;
    for (int i = 1; i <= lengthA; i++)
    {
        lastImpNo = cache[0];
        cache[0] = i;
        for (int j = 1; j <= lengthB; j++)
        {
            int oldVal = cache[j];
            
            if (A[i - 1] == B[j - 1])
            {
                cache[j] = lastImpNo;
            }
            else
            {
                cache[j] = min(min(lastImpNo, cache[j - 1]), cache[j]) + 1;
            }
            
            lastImpNo = oldVal;
        }
    }
    
    return cache[lengthB];
}
*/

int Solution::titleToNumber(string A) {
    int ans = 0;
    for(auto x:A){
        ans = ans*26 + (x-'A'+1);
    }
    return ans;
}

int Solution::maxSubArray(const vector<int> &A) {
    int n = A.size();
    /*vector<int> p(n,0);
    p[0] = A[0];
    //finding prefix sum
    for(int i=1;i<n;++i) p[i] = p[i-1] + A[i];
    int mx = *(max_element(p.begin(),p.end()));
    int sum;
    //finding max element
    for(int i=1;i<n;++i){
        for(int j=i;j<n;++j){
            if(mx<(p[j]-p[i-1])) mx = p[j]-p[i-1];
        }
    }
    return mx;*/
    //Kadane's Algorithm
    int mx = A[0];
    int t = A[0];
    for(int i=1;i<n;++i){
        t = max(A[i],t+A[i]);
        mx = max(mx,t);
    }
    return mx;
}

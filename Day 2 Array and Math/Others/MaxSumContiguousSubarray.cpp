/*
int Solution::maxSubArray(const vector<int> &A) {
    int max_sum = 0;
    int sum = 0;
    int n = A.size();
    int j=0;
    while(j<n){
        sum += A[j];
        if(sum<=0){
            sum=0;
        }
        else{
            if(sum>max_sum){
                max_sum = sum;
            }
        }
        j++;
    }
    if(max_sum==0){
        return *max_element(A.begin(),A.end());
    }
    else return max_sum;
}
*/
//optimized
int Solution::maxSubArray(const vector<int> &A) {
    int max_sum = INT_MIN;
    int sum = 0;
    int n = A.size();
    int j=0;
    while(j<n){
        sum += A[j];
        max_sum = max(max_sum,sum);
        if(sum<=0){
            sum=0;
        }
        j++;
    }
    return max_sum;
}

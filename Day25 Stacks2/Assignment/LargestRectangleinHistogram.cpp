int Solution::largestRectangleArea(vector<int> &A) {
    int n = A.size();
    vector<int> la(n); // to store the index of element less then A[i]
    vector<int> ra(n); // to store the index of element greater then A[i]
    stack<int> s;
    stack<int> s1;
    for(int i=0;i<n;++i){
        if(s.empty()){
            la[i]=-1;
            s.push(i);
        }
        else{
            while(!s.empty() && A[s.top()]>=A[i]){
                s.pop();
            }
            if(s.empty()){
                s.push(i);
                la[i]=-1;
            }
            else{
                la[i] = s.top();
                s.push(i);
            }
        }
    }
    //for(auto x:la)cout<<x<<" ";
    //cout<<"\n";
    for(int i=n-1;i>=0;--i){
        if(s1.empty()){
            ra[i]=n;
            s1.push(i);
        }
        else{
            while(!s1.empty() && A[s1.top()]>=A[i]){
                s1.pop();
            }
            if(s1.empty()){
                s1.push(i);
                ra[i]=n;
            }
            else{
                ra[i] = s1.top();
                s1.push(i);
            }
        }
    }
    //for(auto x:ra) cout<<x<<" ";
    //cout<<"\n";

    int maxArea = -1;
    for(int i=0;i<n;++i){
        maxArea = max(maxArea,A[i]*(ra[i]-la[i]-1));
    }
    return maxArea;
}

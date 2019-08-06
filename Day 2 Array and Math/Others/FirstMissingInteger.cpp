int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();
    int i=0;
    while(i<n){
        if(A[i]>=(n+1)||A[i]<=0){
            A[i]=0;
            i++;
    
        }
        else{
            if(A[i]==i+1) i++; // already at right place
            else{
                if(A[i]==A[A[i]-1]) A[i]=0; //duplicate
                else swap(A[i],A[A[i]-1]); // put A[i] at right place
            }
        }
    }
    for(i=0;i<n;++i){
        if(A[i]!=i+1) return i+1;
    }
    return n+1;
}

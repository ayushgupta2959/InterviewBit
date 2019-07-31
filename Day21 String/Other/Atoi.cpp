int Solution::atoi(const string A) {
    long long ans = 0;
    long long ten = 10;
    long long int_max = INT_MAX;
    int l = A.length();
    long long sign = 1;
    int i=0;
    if(l>0){
        while(A[i]==' ') i++;
        if(A[i]=='-'){
            sign=-1;
            i++;
        }
        else if(A[i]=='+') i++;
    }
    //
    for(;i<l;++i){
        if(A[i]<='9' && A[i]>='0'){
            ans = ans*ten + (long long)(A[i]-'0');
            //cout<<ans<<"\n";
            if(ans>=int_max && sign==1) return INT_MAX;
            if(ans>=int_max+1 && sign==-1){
                //cout<<ans<<"\n";
                return INT_MIN;
            }
                
            }
        else break;
    }
    //cout<<sign<<"\n";
    ans = sign*ans;
    return ans;
}

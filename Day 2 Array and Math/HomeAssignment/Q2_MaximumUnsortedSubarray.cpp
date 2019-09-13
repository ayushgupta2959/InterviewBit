vector<int> Solution::subUnsort(vector<int> &A) {
    /*
    int n = A.size();
    int max_so_far = A[0];
    int e;
    int s = 0;
    int i=1;
    int t;
    while(i<n){
        if(A[i]>=max_so_far) max_so_far = A[i++];
        else{
            int min_so_far = A[i];
            t = i+1;
            while(t<n){
                if(A[t]<min_so_far){
                  i = t; min_so_far = A[t];
                }
                t++;
            }
            while(s<i && A[s]<=A[i]){
                s++;
            }
            break;
        }
    }
    if(i == n) return {-1};
    e = i++;
    while(i<n){
        if(A[i]>=max_so_far) max_so_far = A[i];
        else{
            e = i;
        }
        i++;
    }
    return {s,e};
    */
    int s,e,n,i;
    n = A.size();
    i=0;
    s=-1;
    e=-1;
    while(i<(n-1) && A[i]<=A[i+1]) i++;
    if(i==n-1) return {-1};
    s = i;
    i = n-1;
    while(i>s+1 && A[i]>=A[i-1]) i--;
    e = i;
    int mx,mn;
    mx = INT_MIN;
    mn = INT_MAX;
    for(i=s;i<=e;++i){
        mx = max(mx,A[i]);
        mn = min(mn,A[i]);
    }
    //cout<<s<<" "<<e<<" "<<mx<<" "<<mn<<"\n";
    i = s-1;
    while(i>=0 && A[i]>mn) i--;
    s = i+1;
    i = e+1;
    while(i<n && A[i]<mx) i++;
    e = i-1;
    return {s,e};
}

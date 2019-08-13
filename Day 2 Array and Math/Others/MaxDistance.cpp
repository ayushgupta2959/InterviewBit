/*O(nlgn)
#define f first
#define s second
#define pi pair<int,int>
bool comparator(pi a,pi b){
    if(a.f<b.f) return true;
    else if(a.f>b.f) return false;
    else{
        if(a.s<b.s) return true;
        else return false;
    }
}
int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    vector<pi> v;
    for(int i=0;i<n;++i){
        v.emplace_back(make_pair(A[i],i));
    }
    sort(v.begin(),v.end(),comparator);
    
    vector<bool> visited(n,false);
    int res = 0;
    int cmax = n-1;
    for(int i=0;i<n;++i){
        if(v[i].s<cmax){
            visited[v[i].s]=true;
            res = max(res,cmax-v[i].s);
        }
        else{
            // no index can be greater cmax
            // so else part is executed when cmax == A[i].s
            visited[cmax]=true;
            cmax--;
            while(cmax>=0 && visited[cmax]){
                cmax--;
            }
        }
    }
    
    return res;
}
*/
//optimized
//O(n)
int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    if(n==0) return -1;
    vector<int> left_min(n);
    vector<int> right_max(n);
    left_min[0] = A[0];
    for(int i=1;i<n;++i){
        left_min[i] = min(left_min[i-1],A[i]);
    }
    right_max[n-1] = A[n-1];
    for(int i=n-2;i>=0;i--){
        right_max[i] = max(right_max[i+1],A[i]);
    }
    int res=0;
    int i=0,j=0;
    while(i<n && j<n){
        if(left_min[i]<=right_max[j]){
            res = max(res,j-i);
            j++;
        }
        else{
            i++;
        }
    }
    return res;
}


typedef long long ll;
vector<int> Solution::maxset(vector<int> &A) {
    int n = A.size();
    int s=0,e=0;
    ll sum = -1,msum = -1;
    int l=0,ml=-1;
    int i=0,j=0;
    while(i<n){
        if(A[i]<0) i++;
        else{
            j=i+1;
            sum = (ll)A[i];
            l = 1;
            while(j<n && A[j]>=0){  
                sum += (ll)A[j];
                l++;
                j++;
            }
            if((sum>msum)||(sum==msum&&l>ml)||(sum==msum&&l==ml&&A[i]<A[s])){
                msum = sum;
                ml = l;
                s = i;
                e = j;
            }
            i = j;
        }
    }
    return {A.begin()+s,A.begin()+e};
    /*
    ll ci,cl,cs,mi,ml,ms,i,n;
    n = A.size();
    i=0;
    cl = 0;
    ml=0;
    ms=-1;
    while(i<n){
        if(A[i]<0){
            if((cl)&&(cs>ms)||((cs==ms)&&(cl>ml))){
                ms = cs;
                mi = ci;
                ml = cl;
            }
            cl=0;
        }
        else{
            if(cl==0){
                ci = i;
                cs = A[i];
                cl = 1;
            }
            else{
                cs+=A[i];
                cl++;
            }
        }
        i++;
    }
    if((cs>ms)||((cs==ms)&&(cl>ml))){
        ms = cs;
        mi = ci;
        ml = cl;
        cl=0;
    }
    return {A.begin()+mi,A.begin()+mi+ml};
    */
}

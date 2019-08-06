int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    //method 1
    int n = A.size();
    int srt = sqrt(n);
    int t;
    vector<int> count((n/srt)+1,0);
    for(auto x:A){
        t = x/srt;
        if(x%srt==0) t--;
        count[t]++;
    }
    int i;
    //for(i=0;i<count.size();i++) cout<<i<<" "<<count[i]<<"\n";
    for(i=0;i<count.size();++i){
        if(count[i]>srt) break;
    }
    unordered_map<int,int> m;
    for(auto x:A){
        t = x/srt;
        if(x%srt==0) t--;
        if(t==i){
            if(m.count(x)!=0) return x;
            else m[x] = 1;
        }
    }
    m.clear();
    i = count.size()-1;
    for(auto x:A){
        t = x/srt;
        if(x%srt==0) t--;
        if(t==i){
            if(m.count(x)!=0) return x;
            else m[x] = 1;
        }
    }
    return -1;
    //Method 2
    /*
    int slow = A[0];
    int fast = A[A[0]];
    while (slow != fast){
        slow = A[slow];
        fast = A[A[fast]];
    }

    fast = 0;
    while (slow != fast){
        slow = A[slow];
        fast = A[fast];
    }
    if(slow==0) return -1;
    return slow;
    */
}

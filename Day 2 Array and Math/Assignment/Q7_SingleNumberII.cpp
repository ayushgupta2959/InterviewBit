int Solution::singleNumber(const vector<int> &A) {
    /*
    int t=0;
    int mask;
    int sb;
    for(int i=0;i<32;++i){
        mask = 1<<i;
        sb = 0;
        for(auto x:A){
            if(mask&x) sb++;
        }
        t += pow(2,i)*(sb%3);
    }
    return t;
    */
    int result=0;
    int mask;
    int sb;
    for(int i=31;i>=0;i--){
        mask = 1<<i;
        sb=0;
        for(auto&x:A) if(mask&x) sb++;
        result = (result<<1) + (sb%3);
    }
    return result;
}

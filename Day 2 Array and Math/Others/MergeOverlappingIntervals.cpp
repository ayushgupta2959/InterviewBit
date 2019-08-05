/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool comparator(Interval a,Interval b){
    if(a.start <= b.start) return true;
    else return false;
}
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(A.begin(),A.end(),comparator);
    
    vector<Interval> result;
    int start = A[0].start;
    int end = A[0].end;
    int n = A.size();
    for(int i=1;i<n;++i){
        if(A[i].start<=end) end=max(end,A[i].end);
        else{
            result.emplace_back(Interval(start,end));
            start = A[i].start;
            end = A[i].end;
        }
    }
    result.emplace_back(Interval(start,end));
    return result;
}

typedef pair<int,long long> pi;
class custom_comparator{
    public:
    int operator()(const pi& a,const pi& b){
        if(a.second<b.second) return false;
        else return true;
    }
};
vector<vector<int> > Solution::solve(vector<vector<int> > &A, int B) {
    priority_queue<pi,vector<pi>,custom_comparator> pq;
    int n = A.size();
    long long x,y;
    for(int i=0;i<n;++i){
        x = A[i][0];
        y = A[i][1];
        pq.push({i,(x*x + y*y)});
    }
    vector<vector<int>> result;
    while(B--){
        pi x = pq.top();
        result.emplace_back(A[x.first]);
        pq.pop();
    }
    return result;
}

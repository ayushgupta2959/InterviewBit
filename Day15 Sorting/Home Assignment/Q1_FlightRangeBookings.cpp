vector<int> Solution::solve(int A, vector<vector<int> > &B) {
    // Difference Array range updates
    vector<int> seats(A+1,0);
    for(auto booking:B){
        seats[booking[0]] += booking[2];
        if(booking[1]<A) seats[booking[1]+1] -= booking[2];
    }
    for(int i=1;i<=A;++i) seats[i] += seats[i-1];
    return {seats.begin()+1,seats.end()};
}


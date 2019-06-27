vector<int> Solution::solve(int A) {
    if(A==1) return {1};
    else if(A==2) return {1,2};
    else if(A==3) return {1,2,3};
    //else
    int n=3;
    vector<int> result;
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    int x;
    while(n<A){
        x = q.front();
        result.emplace_back(x);
        q.pop();
        q.push(x*10+1);
        n++;
        if(n<A){
            q.push(x*10+2);
            n++;
        }
        if(n<A){
            q.push(x*10+3);
            n++;
        }
    }
    while(!q.empty()){
        result.emplace_back(q.front());
        q.pop();
    }
    return result;
}


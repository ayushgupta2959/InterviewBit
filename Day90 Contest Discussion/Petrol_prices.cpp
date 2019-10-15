/*
//Problem Statement
Petrol prices
Rishik go to IB office on N days on his bike which consume exactly 1 litre petrol every day but his bike can only store at max B Litre of petrol. You are given petrol prices for all N days as integer array A. Find Minimum cost that could occur to rishik if he chooses optimal quantity to refuel everyday. Note:
Refueling station is very very close to rishik home. So, he can reach there from home at 0 petrol. but, he cannot go to office with 0 fuel.
Initially bike has 0 fuel.
Input Format:
    First argument contains an integer array A denoting petrol prices for N days.
    Second argument contains an integer B denoting Bike capacity.
Output Format:
    Return a single integer denoting minimum cost
Constraints:
1 <= B <= N <= 100000
1 <= A[i] <=20000
For Example:
Input 1:
    A = [5, 6, 3, 4, 2, 1] , B = 2
Output 1:
    19
Explanation:
    Quantity of petrol filled each day = [2, 0, 2, 0, 1, 1]. This gives minimum cost.
*/
void update_queue(deque<int> &q, int i, vector<int> &A){
    
    while(!q.empty() && A[q.back()] >= A[i]) q.pop_back();
    
    q.push_back(i);
}
int Solution::solve(vector<int> &A, int B) {
    deque<int> q;
    int cost = 0;
    
    int i = 0;
    int n = A.size();
    
    for( ; i < B; ++i){
        update_queue(q, i, A);
        cost += A[q.front()];
    }
    
    for( ; i < n; ++i){
        if(q.front() == i-B) q.pop_front();
        update_queue(q, i, A);
        cost += A[q.front()];
    }
    
    return cost;
}



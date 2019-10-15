/*
Problem Statement
Rishik in a race
Rishik is participating in a 100 people race. He is currently at Ath place. You are given N events in form of integer array B. B[i] denotes that B[i] + 1 th ranked participant overtakes B[i]th ranked participant in chronological order. Find final rank of Rishik. 
Input Format:
    First argument contains a single integer A denoting intial rishik rank.
    Second argument contains an integer array B denoting events.
Output Format:
    return a single integer denoting final rank of rishik.
Constraints:
    1 <= A <= 100
    1 <= B[i] <= 99
    1 <= N <= 1000
For Example:
Input 1:
    A = 5 , B = [3, 4, 3, 1, 3]
Output 1:
    4
Explanation:
    Initialy Rishik is at fifth rank
    first, fourth participant overtakes third participant
    then, rishik overtakes fourth ranked and is now ranked 4
    then, again rishik overtakes and is now ranked 3
    then, second participant overtakes first participant
    then, fouth participant overtakes rishik and rishik now is ranked 4.
Input 2:
    A = 1 , B = [1, 2, 50]
Output:
    3
*/
int Solution::solve(int A, vector<int> &B) {
    for(auto&x:B){
        if(x+1==A) A-=1;
        else if(x==A) A++;
    }
    return A;
}

/*
Given two Integer A and B. Find a number X such that A xor X is minimum possible and number of set bits in X equals to B. Input Format:
    First argument contains a single integer A.
    Second argument contains a single integer B.
Ouput Format:
    return integer X
Constraints:
    0 <= A <= 10^9
    0 <= B <= 30
For Example:
Input 1:
    A = 3 , B = 3
Output 1:
    7
Explanation 1:
    3 xor 7 = 4 which is minimum
Input 2:
    A = 15 , B = 2
Output 2:
    12
*/
int Solution::solve(int A, int B) {
    int x = 0;
    for(int i=30;i>=0 && B>0;i--){
        if((1<<i)&A){
            B--;
            x |= (1<<i);
        }
    }
    if(B>0){
        for(int i=0;(i<=30 && B>0);++i){
            if(!((1<<i)&A)){
                x|=(1<<i);
                B--;
            }
        }
    }
    return x;
}

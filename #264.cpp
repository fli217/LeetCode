/*============================================================
Problem: Ugly Number II
==============================================================
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only 
include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 
is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.
Hint:
The naive approach is to call isUgly for every number until 
you reach the nth one. Most numbers are not ugly. Try to focus 
your effort on generating only the ugly ones.
An ugly number must be multiplied by either 2, 3, or 5 from a 
smaller ugly number.
The key is how to maintain the order of the ugly numbers. Try 
a similar approach of merging from three sorted lists: L1, L2, 
and L3.
Assume you have Uk, the kth ugly number. Then Uk+1 must be 
Min(L1 * 2, L2 * 3, L3 * 5).
============================================================*/
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 0) return false; // get rid of corner cases 
        int t2 = 0, t3 = 0, t5 = 0; //pointers for 2, 3, 5
        vector<int> k(n);
        k[0] = 1;
        for (int i=1; i<n; i++) {
            k[i] = min(k[t2]*2, min(k[t3]*3, k[t5]*5));
            if (k[i] == k[t2]*2) t2++; 
            if (k[i] == k[t3]*3) t3++;
            if (k[i] == k[t5]*5) t5++;
        }
        return k[n-1];
    }
};
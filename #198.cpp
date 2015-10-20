/*============================================================
Problem: House Robber
==============================================================
You are a professional robber planning to rob houses along a 
street. Each house has a certain amount of money stashed, the 
only constraint stopping you from robbing each of them is that 
adjacent houses have security system connected and it will 
automatically contact the police if two adjacent houses were 
broken into on the same night.

Given a list of non-negative integers representing the amount 
of money of each house, determine the maximum amount of money 
you can rob tonight without alerting the police.
============================================================*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        
        vector<int> dpRobAtI(n);
        vector<int> dpNotAtI(n);
        dpRobAtI[0] = nums[0];
        dpNotAtI[0] = 0;
        for (int i=1; i<n; i++) {
            dpRobAtI[i] = dpNotAtI[i-1]+nums[i];
            dpNotAtI[i] = max(dpRobAtI[i-1], dpNotAtI[i-1]);
        }
        
        return max(dpRobAtI[n-1], dpNotAtI[n-1]);
    }
};
 
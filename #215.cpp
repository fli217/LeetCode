/*============================================================
Problem: Kth Largest Element in an Array
==============================================================
Find the kth largest element in an unsorted array. Note that 
it is the kth largest element in the sorted order, not the kth 
distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.
Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
============================================================*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end(), less<int>());
        while(--k){
            pop_heap(nums.begin(),nums.end());
            nums.pop_back();
        }
        return nums[0];
    }
};

/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.
*/



class Solution {
public:
    bool canJump(vector<int>& nums) {
    int current =0;
        for(int i=0;i<nums.size();i++){
            if(current < i) return false;
            current = max(current , i+ nums[i]);
        }
        return true;
    }
};

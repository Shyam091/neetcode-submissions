class Solution {
public:
    vector<vector<int>>ans; // this is our answer 2D Vector.

    void backtrack(vector<int>&nums, int ind, int n, vector<int>v)
    {
        if(ind >= n)
        {
            ans.push_back(v);
            return;
        }
        v.push_back(nums[ind]); // pick
        backtrack(nums, ind+1, n, v);
        v.pop_back(); // not pick
        backtrack(nums, ind+1, n, v);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // we need to find all the subsets of the given data.
        // we will be using backtracking for this.
        // 1,2,3 - [1,2,3] , [1,2] ,[1,3] , [2,3], [3], [1], [2], []
        // we will be using pick and non pick approach.
        int n = nums.size(); 
        //  {nums, index, size of given vector, currentSubset-null}
         backtrack(nums, 0,  n, {}); //function for backtracking/exploring all the subsets.

         // once the backtrack function returns, we will be having all the subsets

         return ans; // returning the answer 2DVector.

    }
};

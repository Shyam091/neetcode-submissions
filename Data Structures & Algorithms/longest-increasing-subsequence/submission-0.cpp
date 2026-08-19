class Solution {
public:
        // //  we could apply backtracking here, as the constrains are too expensice we could't
         
        //  // 9,1,4,2,3,3,7
        //  bt -  if(prev < num)
        //  {
        //     pick
        //  }

        //  else{
        //     pick nhi krner 
        //  }


        //  // 2 option hain
        //  // ya to lun, ya to na lun.
        //  // pick ---- ind+1, count+1. --- count - 0 init.
        //  //non - pick ---- ind+1, count.

        //brute force to kr lia ......
        // ab krna hai isko optimize.... 
        // 1D array ka lg rha hai, kyonki sirf index pr check krna hai.

    // int ans = INT_MIN;
    
    // void backtrack(vector<int>& nums, int n , int ind, int count, int prev)
    // {
    //     if(ind >= n)
    //     {
    //         ans = max(ans , count);
    //         return ;
    //     }

    //     if(prev < nums[ind])
    //     {
    //     backtrack(nums, n , ind+1, count+1, nums[ind]); // hmne pick kr lia,
    //     }
    //     backtrack(nums, n, ind+1, count, prev); // pick nhi kia
    // }

    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     // {nums, n , ind, count, first value}
    //     backtrack(nums, n , 0, 0, INT_MIN ); 

    //     return ans;

    // }

     int lengthOfLIS(vector<int>& nums) {
            // changing value kya hai....
            // index, count, prev - 3
            // prev matter krta hai count ke sath sath
            
            int n = nums.size();
            vector<int> dp(n+1, 1); // 2d vector ---- index 
            // single element ke liye 1 count hoga
            int ans = 1;

            if(n ==1 )
            {
                return 1;
            }
            
            for(int i = 0 ; i <n ;i++)
            {
                for (int j = 0 ; j < i ; j ++)
                {
                    if(nums[j] < nums[i])
                    {
                        dp[i]=max(dp[j]+1, dp[i]);
                        ans = max(ans, dp[i]);
                    }

                } 
            }

            
            


        return ans;

    }
};

class Solution {
public:
    int maxArea(vector<int>& heights) {
        // so we have to find the container which is containing the most amount of
        // water, is it a maths based question, as we have to just find the rectangle
        // with the maximum area.
        // we will use simple area formula to solve this question.

        int n = heights.size();
        int left = 0;
        int right = n-1;
        int ans = INT_MIN;
         while(left < right)
         {
            int length = min(heights[left] , heights[right]);
            int width =  right - left;
            ans = max(ans, length * width);

            if(heights[left] >= heights[right])
            {
                right--;
            }
            else{
                left++;;
            }

         }
         return ans;
    }
};

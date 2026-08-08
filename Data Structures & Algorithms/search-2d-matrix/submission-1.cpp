class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
   
        for (int i = 0; i < n; i++) {
            int left = 0;
            int right = matrix[i].size()-1;
            if (matrix[i][0] <= target &&  target <= matrix[i][right]) {
                
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (matrix[i][mid] == target) {
                        return true;
                    }

                    else if (matrix[i][mid] > target) {
                        right = mid - 1;
                    }

                    else if (matrix[i][mid] < target) {
                        left = mid + 1 ;
                    }
                }


                {
                    return false;
                }
            }
        }
        return false;
    }
};





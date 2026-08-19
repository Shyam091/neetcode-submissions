class Solution {
   public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (isalnum(s[left]) && isalnum(s[right])) {
                if (tolower(s[left]) == tolower(s[right])) {
                    left++;
                    right--;
                } else {
                    return false;
                }
            }

            else {
                while (!isalnum(s[left])) {
                    left++;
                }
                while (!isalnum(s[right])) {
                    right--;
                }
            }
        }
        return true;
    }
};

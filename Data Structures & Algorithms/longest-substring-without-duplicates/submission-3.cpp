class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int Max = 0;
        int lastCheck=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i-1;j>=lastCheck;j--)
            {
                if(s[j] == s[i])
                {
                    Max = max(Max , i-j);
                    lastCheck=j+1;
                    break;
                }
                if(j==0 || j== lastCheck)
                {

                    Max = max(Max, i-j+1);
                    
                }
            }
        }
        if(n == 0)
        {
            return 0;
        }
        if(n==1)
        {
            return 1;
        }
        return Max;
    }
};

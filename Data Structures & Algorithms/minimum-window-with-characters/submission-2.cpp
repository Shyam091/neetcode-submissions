class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> need(256, 0);
        vector<int> window(256, 0);

        // Required frequencies
        for(char c : t)
            need[c]++;

        int left = 0;
        int matched = 0;

        int start = 0;
        int minLen = INT_MAX;

        for(int right = 0; right < s.size(); right++)
        {
            char ch = s[right];

            // Add current character to window
            window[ch]++;

            // Count it only if it is still needed
            if(window[ch] <= need[ch])
                matched++;

            // Window is valid
            while(matched == t.size())
            {
                // Update answer
                if(right - left + 1 < minLen)
                {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove left character
                window[s[left]]--;

                // If we removed a required character,
                // window becomes invalid
                if(window[s[left]] < need[s[left]])
                    matched--;

                left++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};
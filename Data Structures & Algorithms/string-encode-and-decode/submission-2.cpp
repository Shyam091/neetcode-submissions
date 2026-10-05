class Solution {
   public:
    string encode(vector<string>& strs) {
        string str = "";
        for (string s : strs) {
            int n = s.size();
            string ss = to_string(n);
            str += ss;
            str += "#";
            str += s;  //"1##"
        }

        return str;
    }

    vector<string> decode(string s) {
        vector<string> ans;
         int i = 0;

while (i < s.size()) {

    int j = i;

    // Find #
    while (s[j] != '#') {
        j++;
    }

    // Get length
    int n = stoi(s.substr(i, j - i));

    // Get string
    ans.push_back(s.substr(j + 1, n));

    // Jump to next encoded string
    i = j + 1 + n;
}


        return ans;
    }
    }
;

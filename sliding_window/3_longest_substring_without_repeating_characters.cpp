class Solution {
public:
    /* build a frequency table out of the substring we explored 
     * so far. We need to find the longest susbstring without any 
     * repetitions. So we slide end and keep building the table and as soon as 
     * we hit a repetition, meaning the end char is already in table, 
     * we start sliding begin. Finally, we record res before sliding begin */
    int lengthOfLongestSubstring(string s) {
        int res = 0;

        if (s.size() == 0)
            return res;

        unordered_map<char,int> seen;

        int begin = 0;
        int end = 0;

        while (end < s.size()) {
            char curr = s[end];

            if (seen.count(curr) == 1 && seen[curr] >= begin) {
                begin = seen[curr] + 1;
            } else {
                seen[curr] = end;
                end++;
            }

            if (end - begin > res) {
                res = end - begin;
            }
        }

        return res;
    }
};

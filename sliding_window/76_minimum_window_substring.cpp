class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> table;
        string res;
        
        for (char c : t) {
            table[c]++;
        }
        
        int begin = 0;
        int end = 0;
        int counter = table.size();
        int len = INT_MAX;

        // start sliding window
        while (end < s.size()) {
            char endchar = s[end];
            
            // if current char found in table, decrement count
            if (table.find(endchar) != table.end()) {
                table[endchar]--;
                if (table[endchar] == 0)
                    counter--;
            }
            
            end++;
            
            // if counter == 0, means we found an answer, 
            // now try to trim that window by sliding begin to right.
            while (counter == 0) {
                // store new res if smaller than previously best
                if (end - begin < len) {
                    len = end - begin;
                    res = s.substr(begin, end - begin);
                }
                
                // if found in table increment count in table, as we are 
                // leaving it out of window and moving ahead, so it would no 
                // longer be a part of the substring marked by begin-end window
                // if the count goes above zero means that the current window 
                // is missing one char to be an answer candidate 
                if (table.count(s[begin]) == 1) {
                    table[s[begin]]++;
                    if(table[s[begin]] > 0)
                    counter++;
                }
                begin++;
            }
            
        }
        
        return res;
    }
};

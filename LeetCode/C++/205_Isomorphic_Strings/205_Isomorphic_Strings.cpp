#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <sstream>
#include <memory>
#include <algorithm>
#include <map>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
    /*
     * 思路：记录一对一映射关系，既要排除一对多、也要排除多对一。
     */
    bool isIsomorphic(string s, string t) {
        map<char, char> match;
        set<char> used;
        for(int i = 0; i < s.size(); i++) {
            if(match.find(s[i]) != match.end() && match[s[i]] != t[i] 
            || match.find(s[i]) == match.end() && used.find(t[i]) != used.end()) {
                return false;
            } else {
                match[s[i]] = t[i];
                used.insert(t[i]);
            }
        }
        return true;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        string s = line;
        getline(cin, line);
        string t = line;
        
        bool isIsomorphic = Solution().isIsomorphic(s, t);

        cout << isIsomorphic << endl;
    }
    return 0;
}
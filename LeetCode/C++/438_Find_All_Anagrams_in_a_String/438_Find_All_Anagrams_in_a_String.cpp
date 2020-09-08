#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int lenP = p.size();
        map<char, int> countP;
        for(const char& ch : p) {
            countP[ch]++;
        }
        vector<int> idxs;
        int i = 0;
        while(i < s.size()) {
            map<char, int> countS = countP;
            int count = lenP, more = 0;
            while(i < s.size()) {
                if(countS.find(s[i]) == countS.end()) {
                    i++;
                    break;
                }
                if(count == more) {
                    if(countS[s[i - lenP]] < 0) {
                        more--;
                    } else {
                        count++;
                    }
                    countS[s[i - lenP]]++;
                }
                if(countS[s[i]] > 0) {
                    count--;
                } else {
                    more++;
                }
                countS[s[i]]--;
                i++;

                if(count == 0 && more == 0) {
                    idxs.push_back(i - lenP);
                }
            }
        } 
        return idxs;
    }
};
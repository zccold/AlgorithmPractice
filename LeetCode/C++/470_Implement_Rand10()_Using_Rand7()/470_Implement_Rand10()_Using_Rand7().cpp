#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int res;
        do{
            int row = rand7();
            int col = rand7();
            res = (row - 1) * 7 + col;
        } while(res > 40);
        return 1 + (res - 1) % 10;
    }
};
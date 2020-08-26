#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

class Solution {
public:
    /*
     * 思路：直观上，遍历ratings数组，若当前rating大于左右邻居且蛋糕数不大于左右邻居，
     *      则增加当前蛋糕数，循环直到收敛。这样会超时，肯定有重复操作。
     *      将ratings数组用折线图表示出来，可直观发现，当前rating大于左右邻居可转化为
     *      正序遍历与反序遍历中所有的上升折线。只需要遍历两次。
     */
    int candy(vector<int>& ratings) {
        if(ratings.empty())
            return 0;
        if(ratings.size() == 1)
            return 1;
        vector<int> candys(ratings.size(), 1);
        
        for(int i = 1; i < ratings.size(); i++) {
            if(ratings[i] > ratings[i-1] && candys[i] <= candys[i-1]) {
                candys[i] = candys[i-1] + 1;
            }
        }
        for(int i = ratings.size()-2; i >= 0; i--) {
            if(ratings[i] > ratings[i+1] && candys[i] <= candys[i+1]) {
                candys[i] = candys[i+1] + 1;
            }
        }
        int sum = 0;
        for(auto c : candys) {
            sum += c;
        }
        return sum;
    }
};

vector<int> stringToVectorInt(string input) {
    vector<int> res;
    stringstream ss(input.substr(1, input.size() - 2));
    string item;
    char delim(',');
    while(getline(ss, item, delim)) {
        res.push_back(stoi(item));
    }
    return res;
}

int main() {
    string line;
    while (true) {
        getline(cin, line);
        
        vector<int> ratings = stringToVectorInt(line);
        int count = Solution().candy(ratings);
        cout << count << endl;
    }
    return 0;
}
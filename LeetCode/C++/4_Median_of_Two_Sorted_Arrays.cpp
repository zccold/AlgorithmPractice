class Solution {
public:
    bool findMedianOneSortedArrays(int& idx, vector<int>& nums1, vector<int>& nums2){
        int l1, r1, idx1, l2, r2;
        l1 = 0, r1 = nums1.size() - 1;
        while(l1 <= r1){
            idx1 = (l1 + r1)/2;

            // 寻找第二个数组中小于nums1[idx1]的最大的数的下标
            int tmpL2, tmpR2;
            l2 = 0, r2 = nums2.size() - 1;
            while(r2 - l2 > 1){
                tmpL2 = (l2 + r2)/2;
                if(nums2[tmpL2] >= nums1[idx1])
                    r2 = tmpL2 - 1;
                else
                    l2 = tmpL2;
            }
            tmpL2 = nums2[r2] < nums1[idx1] ? r2 : (nums2[l2] < nums1[idx1] ? l2 : -1);
            // 寻找第二个数组中小于等于nums1[idx1]的最大的数的下标
            l2 = 0, r2 = nums2.size() - 1;
            while(r2 - l2 > 1){
                tmpR2 = (l2 + r2)/2;
                if(nums2[tmpR2] > nums1[idx1])
                    r2 = tmpR2 - 1;
                else
                    l2 = tmpR2;
            }
            tmpR2 = nums2[r2] <= nums1[idx1] ? r2 : (nums2[l2] <= nums1[idx1] ? l2 : -1);

            // 若tmpL2 == -1 且 tmpR2 != -1
            bool flag = true;
            if(tmpL2 == -1){
                if(idx1 == idx){
                    idx = nums1[idx1];
                    return true;
                }else if(idx1 < idx){
                    l1 = idx1 + 1;
                }else{
                    r1 = idx1 - 1;
                }
                tmpL2 = 0, flag = false;
            }
            // 二分由tmpL2与tmpR2组成的第二个数组
            int idx2;
            while(tmpL2 <= tmpR2){
                idx2 = (tmpL2 + tmpR2)/2;
                if(idx1 + idx2 + 1 == idx){
                    idx = nums1[idx1];
                    return true;
                }else if(idx1 + idx2 + 1 > idx){
                    tmpR2 = idx2 - 1;
                }else{
                    tmpL2 = idx2 + 1;
                }
            }
            // 二分第一个数组
            if(flag){
                if(idx1 + idx2 + 1 > idx){
                    r1 = idx1 - 1;
                }else{
                    l1 = idx1 + 1;
                }
            }
        }
        return false;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(!nums1.size() || !nums2.size()){
            vector<int>& nums12 = nums1.size() ? nums1 : nums2;
            if(nums12.size()%2 == 0){
                return static_cast<double>(nums12[nums12.size()/2 - 1] + nums12[nums12.size()/2])/2;
            }else{
                return nums12[nums12.size()/2];
            }
        }

        int len = nums1.size() + nums2.size();
        vector<int> res;
        if(len%2 == 0)
            res = {len/2 - 1, len/2};
        else
            res = {len/2};
        for(int& t : res){
            if(findMedianOneSortedArrays(t, nums1, nums2)
               || findMedianOneSortedArrays(t, nums2, nums1))
               continue;
            else
                return -1.0;
        }
        return accumulate(res.begin(), res.end(), 0.0)/res.size();
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);
        
        double ret = Solution().findMedianSortedArrays(nums1, nums2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
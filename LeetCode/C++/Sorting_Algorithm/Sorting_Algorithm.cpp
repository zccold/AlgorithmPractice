#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

class SortingAlgorithm {
public:
    /*
     * 冒泡排序：双层循环，第i轮外循环将全局第i小的元素冒泡到下标i。
     */
    void bubbleSort(vector<int>& nums) {
        if(nums.empty()) {
            return;
        }

        for(int i = 0; i < nums.size() - 1; i++) {
            for(int j = nums.size() - 1; j > i; j--) {
                if(nums[j] < nums[j - 1]) {
                    swap(nums[j], nums[j - 1]);
                }
            }
        }
    }

    /*
     * 插入排序：双层循环，维持一个有序局部，每轮外循环将一个无序元素加入有序局部。
     */
    void insertSort(vector<int>& nums) {
        if(nums.empty()) {
            return;
        }

        for(int i = 0; i < nums.size() - 1; i++) {
            int j = i + 1;
            while(j > 0 && nums[j] < nums[j - 1]) {
                swap(nums[j], nums[j - 1]);
                j--;
            }
        }
    }

    /*
     * 选择排序：双层循环，第i轮外循环选择全局第i小的元素与下标i的元素交换。
     */
    void selectSort(vector<int>& nums) {
        if(nums.empty()) {
            return;
        }

        for(int i = 0; i < nums.size() - 1; i++) {
            int minIdx = i;
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[j] < nums[minIdx]) {
                    minIdx = j;
                }
            }
            swap(nums[i], nums[minIdx]);
        }
    }

    /*
     * 快排
     */
    void quickSort(vector<int>& nums) {
        if(nums.empty()) {
            return;
        }
        quickSort(nums, 0, nums.size() - 1);
    }

    /*
     * 基数排序：从低位开始排编程实现较为简单。
     */
    void radixSort(vector<int>& nums) {
        if(nums.empty()) {
            return;
        }

        int len = to_string(nums[0]).size();
        vector<queue<int>> buckets(10, queue<int>());
        for(int i = 1; i <= len; i++) {
            for(const auto& num : nums) {
                int tmp = num % static_cast<int>(pow(10, i)) / static_cast<int>(pow(10, i - 1));
                buckets[tmp].push(num);
            }
            
            int idx = 0;
            for(int j = 0; j < 10; j++) {
                while(!buckets[j].empty()) {
                    nums[idx++] = buckets[j].front();
                    buckets[j].pop();
                }
            }
        }
    }

    /*
     * 堆排序：关键函数为pushDown()
     */
    void heapSort(vector<int>& nums) {
        if(nums.empty()) {
            return;
        }
        // 建堆，时间复杂度为O(nlogn)
        for(int i = (nums.size() / 2) - 1; i >= 0; i--) {
            pushDown(nums, i, nums.size());
        }
        // 整理堆，时间复杂度为O(nlogn)
        for(int i = nums.size() - 1; i > 0; i--) {
            swap(nums[0], nums[i]);
            pushDown(nums, 0, i);
        }
    }

    /*
     * 归并排序：
     */
    void mergeSort(vector<int>& nums) {
        if(nums.empty()) {
            return;
        }

        vector<vector<int>> sortTuple(2, nums);
        int flip = 0;
        for(int i = 1; i < sortTuple[flip].size(); i++) {
            for(int j = 0; j < sortTuple[flip].size(); j += 2*i) {
                if(j + i < sortTuple[flip].size()) {
                    int end = min(j + 2*i, static_cast<int>(sortTuple[flip].size()));
                    merge(sortTuple, flip, j, j+i, end);
                }
            }
            flip = 1 - flip;
        }
        for(int i = 0; i < sortTuple[flip].size(); i++) {
            nums[i] = sortTuple[flip][i];
        }
    }
private:
    // 若存在两个元素不同，返回较大者的下标，否则返回-1.
    int findPivot(const vector<int>& nums, int l, int r) {
        for(int i = l; i < r; i++) {
            if(nums[i] != nums[i+1]) {
                return (nums[i] > nums[i+1]) ? i : i+1;
            }
        }
        return -1;
    }

    int partition(vector<int>& nums, int l, int r, int pivot) {
        int val = nums[pivot];
        while(l < r) {
            // 这里只能为nums[l] < val而不能为nums[l] <= val，
            // 原因考虑case: [1,2,3,1], val = 3，正常结束时l应该位于第一个不小于val的元素下标。
            while(l < r && nums[l] < val) {
                l++;
            }
            while(l < r && nums[r] >= val) {
                r--;
            }
            if(l < r) {
                swap(nums[l], nums[r]);
            }
        }
        return l;
    }

    void quickSort(vector<int>& nums, int l, int r) {
        if(l >= r) {
            return;
        }
        int pivot = findPivot(nums, l, r);
        if(pivot == -1) {
            return;
        }
        int idx = partition(nums, l, r, pivot);
        quickSort(nums, l, idx - 1);
        quickSort(nums, idx + 1, r);
    }

    void pushDown(vector<int>& nums, int i, int len) {
        while(2*i + 1 < len) {
            int minIdx = 2*i + 1;
            if(2*i + 2 < len && nums[2*i + 2] < nums[minIdx]) {
                minIdx++;
            }
            if(nums[minIdx] < nums[i]) {
                swap(nums[minIdx], nums[i]);
                i = minIdx;
            } else {
                return;
            }
        }
    }

    void merge(vector<vector<int>>& sortTuple, int flip, int left, int right, int end) {
        int idx = left;
        while(left < right && right < end) {
            if(sortTuple[flip][left] < sortTuple[flip][right]) {
                sortTuple[1-flip][idx++] = sortTuple[flip][left];
                left++;
            } else {
                sortTuple[1-flip][idx++] = sortTuple[flip][right];
                right++;
            }
        }
        while(left < right) {
            sortTuple[1-flip][idx++] = sortTuple[flip][left];
            left++;
        }
    }
};

string vectorIntToString(const vector<int>& nums) {
    if(nums.empty()) {
        return string();
    }
    string res("[");
    for(const auto& num : nums) {
        res += to_string(num);
        res += ", ";
    }
    res.erase(res.end() - 2);
    res += "]";
    return res;
}

int main() {
    vector<vector<int>> testCaseList{
        vector<int>(),
        vector<int>{1, 1, 1, 1},
        vector<int>{1, 5, 3, 3, 4, 7}
    };
    SortingAlgorithm sa;

    cout << "###### Test bubbleSort()" << endl;
    for(auto testCase : testCaseList) {
        string before = vectorIntToString(testCase);
        cout << before << endl;

        sa.bubbleSort(testCase);

        string after = vectorIntToString(testCase);
        cout << after << endl;
    }
    cout << "###### Test bubbleSort()" << endl;

    cout << "###### Test insertSort()" << endl;
    for(auto testCase : testCaseList) {
        string before = vectorIntToString(testCase);
        cout << before << endl;

        sa.insertSort(testCase);

        string after = vectorIntToString(testCase);
        cout << after << endl;
    }
    cout << "###### Test insertSort()" << endl;

    cout << "###### Test selectSort()" << endl;
    for(auto testCase : testCaseList) {
        string before = vectorIntToString(testCase);
        cout << before << endl;

        sa.selectSort(testCase);

        string after = vectorIntToString(testCase);
        cout << after << endl;
    }
    cout << "###### Test selectSort()" << endl;

    cout << "###### Test quickSort()" << endl;
    for(auto testCase : testCaseList) {
        string before = vectorIntToString(testCase);
        cout << before << endl;

        sa.quickSort(testCase);

        string after = vectorIntToString(testCase);
        cout << after << endl;
    }
    cout << "###### Test quickSort()" << endl;

    cout << "###### Test radixSort()" << endl;
    for(auto testCase : testCaseList) {
        string before = vectorIntToString(testCase);
        cout << before << endl;

        sa.radixSort(testCase);

        string after = vectorIntToString(testCase);
        cout << after << endl;
    }
    cout << "###### Test radixSort()" << endl;

    cout << "###### Test heapSort()" << endl;
    for(auto testCase : testCaseList) {
        string before = vectorIntToString(testCase);
        cout << before << endl;

        sa.heapSort(testCase);

        string after = vectorIntToString(testCase);
        cout << after << endl;
    }
    cout << "###### Test heapSort()" << endl;

    cout << "###### Test mergeSort()" << endl;
    for(auto testCase : testCaseList) {
        string before = vectorIntToString(testCase);
        cout << before << endl;

        sa.mergeSort(testCase);

        string after = vectorIntToString(testCase);
        cout << after << endl;
    }
    cout << "###### Test mergeSort()" << endl;
}
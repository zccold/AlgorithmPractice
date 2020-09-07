#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

/*
 * 解题思路：数组+第k大的数、数组+插入排序、二叉搜索树、大顶堆+小顶堆
 */
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(_bigHeap.empty() || _bigHeap.top() >= num) {
            _bigHeap.push(num);
        } else {
            _smallHeap.push(num);
        }
        if(static_cast<int>(_bigHeap.size() - _smallHeap.size()) > 1) {
            int tmp = _bigHeap.top();
            _smallHeap.push(tmp);
            _bigHeap.pop();
        }
        if(static_cast<int>(_smallHeap.size() - _bigHeap.size()) > 1) {
            int tmp = _smallHeap.top();
            _bigHeap.push(tmp);
            _smallHeap.pop();
        }
    }
    
    double findMedian() {
        if(_bigHeap.empty() && _smallHeap.empty()) {
            return 0;
        }
        int bigSize = _bigHeap.size();
        int smallSize = _smallHeap.size();
        if(((bigSize + smallSize)) % 2 == 0) {
            return static_cast<double>(_bigHeap.top() + _smallHeap.top()) / 2;
        } else {
            return (bigSize > smallSize) ? _bigHeap.top() : _smallHeap.top();
        }
    }
private:
    priority_queue<int, vector<int>, less<int>> _bigHeap;
    priority_queue<int, vector<int>, greater<int>> _smallHeap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    obj->addNum(3);
    cout << obj->findMedian() << endl;
}
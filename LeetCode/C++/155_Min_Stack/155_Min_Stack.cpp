#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <functional>

using namespace std;

/// 
/// Solution1: my stupid solution, use one stack, one heap, and one map.
/// stack as stack, heap implement getMin(), and map record the relationship between stack and heap.
/// How stupid!!!
/// 
// class PairHash{
// public:
//     size_t operator()(const pair<int, int>& p) const{
//         size_t h1 = hash<int>{}(p.first);
//         size_t h2 = hash<int>{}(p.second);
//         return h1^h2;
//     }
// };

// class MinStack {
// public:
//     /** initialize your data structure here. */
//     MinStack() {
//     }
    
//     void push(int x) {
//         stack.push_back(x);
//         pushHeapAndMap(x, stack.size());
//     }
    
//     void pop() {
//         int val = stack.back();
//         stack.pop_back();
//         popHeapAndMap(val, stack.size()+1);
//     }
    
//     int top() {
//         return stack.back();
//     }
    
//     int getMin() {
//         return heap[0].first;
//     }
// private:
//     void pushHeapAndMap(int val, int len){
//         pair<int, int> tmp(val, len);
//         heap.push_back(tmp);
//         int i = heap.size()-1;
//         while(i > 0 && heap[i] < heap[(i-1)/2]){
//             swap(heap[i], heap[(i-1)/2]);
//             map[heap[i]] = i;
//             i = (i-1)/2;
//         }
//         map[tmp] = i;
//     }

//     void popHeapAndMap(int val, int len){
//         pair<int, int> tmp(val, len);
//         int idx = map[tmp];
//         // check idx == heap.size()-1
//         if(idx == heap.size()-1){
//             heap.pop_back();
//             map.erase(tmp);
//             return;
//         }
//         swap(heap[idx], heap.back());
//         heap.pop_back();
//         map.erase(tmp);

//         int heapLen = heap.size();
//         while(idx < heapLen){
//             int l = idx*2+1;
//             int r = l+1;
//             if(r < heapLen){
//                 if(heap[l] < heap[r] && heap[l] < heap[idx]){
//                     swap(heap[l], heap[idx]);
//                     map[heap[idx]] = idx;
//                     idx = l;
//                 }else if(heap[r] < heap[l] && heap[r] < heap[idx]){
//                     swap(heap[r], heap[idx]);
//                     map[heap[idx]] = idx;
//                     idx = r;
//                 }else{
//                     break;
//                 }
//             }else if(l <heapLen){
//                 if(heap[l] < heap[idx]){
//                     swap(heap[l], heap[idx]);
//                     map[heap[idx]] = idx;
//                     idx = l;
//                 }else{
//                     break;
//                 }
//             }else{
//                 break;
//             }
//         }
//         map[heap[idx]] = idx;
//     }
//     // int -> value
//     vector<int> stack;  
//     // pair<int, int> -> (value, stack.size() when value push)
//     vector<pair<int, int>> heap;
//     // int -> pair's idx in heap
//     unordered_map<pair<int, int>, int, PairHash> map;
// };

class MinStack{
public:
    MinStack(){ }
    
    void push(int val){
        s1.push_back(val);
        // the "==" is for equal elements
        if(s2.empty() || val <= s2.back())
            s2.push_back(val);
    }

    void pop(){
        if(s1.back() == s2.back())
            s2.pop_back();
        s1.pop_back();
    }

    int getMin(){
        return s2.back();
    }

    int top(){
        return s1.back();
    }
private:
    vector<int> s1;
    vector<int> s2;
};

void trimLeft(string& str){
    str.erase(str.begin(), find_if(str.begin(), str.end(), [](int ch){
        return !isspace(ch);
    }));
}

void trimRight(string& str){
    str.erase(find_if(str.rbegin(), str.rend(), [](int ch){
        return !isspace(ch);
    }).base(), str.end());
}

vector<string> stringToOperates(string line){
    trimLeft(line);
    trimRight(line);
    vector<string> ops;
    stringstream ss(line.substr(2, line.size()-4));
    string item;
    char delim = '"';
    while(getline(ss, item, delim)){
        ops.push_back(item);
        getline(ss, item, delim);
    }
    return ops;
}

vector<int> stringToOperands(string line){
    trimLeft(line);
    trimRight(line);
    vector<int> operands;
    stringstream ss(line.substr(2, line.size()-4));
    string item;
    char delim = ']';
    while(getline(ss, item, delim)){
        if(item.empty())
            operands.push_back(INT_MAX);
        else
            operands.push_back(stoi(item));
        getline(ss, item, '[');
    }
    return operands;
}

string vectorIntToString(vector<int>& nums){
    string str("[");
    for(auto num : nums){
        if(num == INT_MAX){
            str += "null,";
        }else{
            str += to_string(num);
            str += ",";
        }
    }
    str.erase(str.size()-1);
    str += "]";
    return str;
}

int main(){
    while(true){
        string line;
        getline(cin, line);
        vector<string> operates = stringToOperates(line);
        getline(cin, line);
        vector<int> operands = stringToOperands(line);
        MinStack* minStack(nullptr);
        vector<int> res;
        for(int i = 0; i < operates.size(); i++){
            string op = operates[i];
            // int num = operands[i];
            if(op == "MinStack"){
                minStack = new MinStack;
                res.push_back(INT_MAX);
            }else if(op == "push"){
                minStack->push(operands[i]);
                res.push_back(INT_MAX);
            }else if(op == "pop"){
                minStack->pop();
                res.push_back(INT_MAX);
            }else if(op == "getMin"){
                int val = minStack->getMin();
                res.push_back(val);
            }else{
                int val = minStack->top();
                res.push_back(val);
            }
        }
        string s = vectorIntToString(res);
        cout<<s<<endl;
    }
}
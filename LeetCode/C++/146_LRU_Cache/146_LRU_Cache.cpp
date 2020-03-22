//本地运行正确，leetcode提交产生运行时错误
/*
 * testcase
 * ["LRUCache","put","get","put","get","get"]
 * [[1],[2,1],[2],[3,2],[2],[3]]
 */
#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <sstream>
#include <memory>

using namespace std;

class LRUCache {
private:
    list<int> lru;
    map<int, list<int>::iterator> _htable;
    int _cap;
public:
    LRUCache(int capacity):_cap(capacity){}

    int get(int key) {
        if(_htable.find(key) == _htable.end())
            return -1;
        int val = *_htable[key];
        lru.erase(_htable[key]);
        lru.push_front(val);
        _htable[key] = lru.begin();
        return val;
    }
    
    void put(int key, int value) {
        if(_htable.find(key) != _htable.end()){
            *_htable[key] = value;
            lru.erase(_htable[key]);
        }else if(_cap == 0){
            _htable.erase(lru.back());
            lru.pop_back();
        }else{
            _cap--;
        }
        lru.push_front(value);
        _htable[key] = lru.begin();
    }
};

vector<vector<int>> stringToVectorVectorInt(string input){
    vector<vector<int>> ops;
    stringstream ssAllOp(input.substr(2, input.size()-4));
    string item;
    char delim1(']');
    while(getline(ssAllOp, item, delim1)){
        stringstream ssOneOp(item);
        char delim2(',');
        vector<int> oneOp;
        while(getline(ssOneOp, item, delim2))
            oneOp.push_back(stoi(item));
        ops.push_back(oneOp);
        getline(ssAllOp, item, '[');
    }
    return ops;
}

int main(void){
    LRUCache* lru = new LRUCache(2);
    while(true){
        string input;
        getline(cin, input);
        getline(cin, input);
        vector<vector<int>> ops = stringToVectorVectorInt(input);
        for(auto oneOp : ops){
            if(oneOp.size() == 1){
                cout<<"get("<<oneOp[0]<<")\t"<<lru->get(oneOp[0])<<endl;
            }else{
                lru->put(oneOp[0], oneOp[1]);
                cout<<"put("<<oneOp[0]<<", "<<oneOp[1]<<")\n";
            }
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
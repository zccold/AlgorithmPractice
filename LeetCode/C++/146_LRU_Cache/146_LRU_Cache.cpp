#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <sstream>
#include <memory>

using namespace std;

class LRUCache {
private:
    /*
     * 使用list（底层为双向链表）既能O(1)的删除节点（容量不够时），也能O(1)的将节点挪到链表首或尾。
     */
    list<pair<int, int>> _tbl;
    map<int, list<pair<int, int>>::iterator> _map;
    int _cap;
public:
    LRUCache(int capacity) : _cap(capacity){}

    int get(int key) {
        if(_map.find(key) == _map.end())
            return -1;
        int val = _map[key]->second;
        _tbl.erase(_map[key]);
        _tbl.push_front(make_pair(key, val));
        _map[key] = _tbl.begin();
        return val;
    }
    
    void put(int key, int value) {
        if(_map.find(key) != _map.end()){
            _tbl.erase(_map[key]);
        }else if(_cap == 0){
            _map.erase(_tbl.back().first);
            _tbl.pop_back();
        }else{
            _cap--;
        }
        _tbl.push_front(make_pair(key, value));
        _map[key] = _tbl.begin();
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
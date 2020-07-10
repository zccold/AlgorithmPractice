#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class LFUCache {
public:
    LFUCache(int capacity) : _cap(capacity){
        
    }
    
    // 修改_map[key]到_tbl的下标的映射，
    // 将node从当前访问频次的槽位链表移除，并插入访问频次加1的槽位的链表头。
    int get(int key) {
        if(_map.find(key) == _map.end())
            return -1;
        int idx = _map[key].first;
        ListNode* node = _map[key].second;
        removeNode(idx, node);
        _map[key] = make_pair(idx+1, node);
        addNode(idx+1, node);
        return node->val;
    }
    
    // 若node已存在，用value修改node->val，并实现get(key)的逻辑；
    // 否则创建新节点，插入访问频次为0的槽位链表头，并添加_map记录，
    //     若容量已满，则删除访问频次最低槽位的链表尾结点，并删除_map记录，最后delete节点。
    void put(int key, int value) {
        int idx;
        ListNode* node;
        if(_map.find(key) != _map.end()){
            idx = _map[key].first;
            node = _map[key].second;
            node->val = value;
            removeNode(idx, node);
            idx++;
        }else{
            idx = 0;
            node = new ListNode(key, value);
            if(_cap == _map.size()){
                for(int i = 0; i < _tbl.size(); i++)
                    if(_tbl[i]){
                        ListNode* tmp = _tbl[i]->tail;
                        removeNode(i, tmp);
                        _map.erase(tmp->key);
                        delete tmp;
                    }  
            }
        } 
        _map[key] = make_pair(idx, node);
        addNode(idx, node);
    }
private:
    class ListNode{
    public:
        ListNode(int key, int value) 
            : key(key), val(value), prev(nullptr), next(nullptr), tail(nullptr)
        {
            tail = this;
        }
        int key;
        int val;
        ListNode* prev;
        ListNode* next;
        ListNode* tail;
    };

    // 向链表头插入最新节点
    void addNode(int idx, ListNode* node){
        // 若idx代表的槽位存在，插入链表头
        if(idx < _tbl.size()){
            if(_tbl[idx]){
                node->tail = _tbl[idx]->tail;
                node->next = _tbl[idx];
                _tbl[idx]->prev = node;
                _tbl[idx] = node;
            }else{
                _tbl[idx] = node;
            }
        // 否则，创建新槽位。
        }else{
            _tbl.push_back(node);
        }
    }

    // 从链表尾删除最老节点
    void removeNode(int idx, ListNode* node){
        if(node->prev)
            node->prev->next = node->next;
        if(node->next)
            node->next->prev = node->prev;
        // 若待删除节点为槽位首节点，置槽位为nullptr。
        if(_tbl[idx] == node)
            _tbl[idx] = nullptr;
        // 若待删除节点为槽位尾结点，修改首节点缓存的尾结点。
        if(_tbl[idx] && _tbl[idx]->tail == node)
            _tbl[idx]->tail = node->prev;
    }

    int _cap;
    vector<ListNode*> _tbl;
    // _map保存key分别到_tbl的下标与到ListNode地址的映射。
    unordered_map<int, pair<int, ListNode*> > _map;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main(){
    LFUCache* obj = new LFUCache(2);
    obj->put(1, 1);
    obj->put(2, 2);
    cout<<obj->get(1)<<' ';
    obj->put(3, 3);
    cout<<obj->get(2)<<' ';
    cout<<obj->get(3)<<' ';
    obj->put(4, 4);
    cout<<obj->get(1)<<' ';
    cout<<obj->get(3)<<' ';
    cout<<obj->get(4)<<' ';
}
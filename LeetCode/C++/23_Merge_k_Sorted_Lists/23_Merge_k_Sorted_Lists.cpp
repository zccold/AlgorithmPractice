#include <iostream>
#include <string>
#include <assert.h>
#include <vector>
#include <map>
#include <sstream>
#include <queue>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
///////////////////////////////////////////////////////////
// 二路归并，假设链表长度都为n，链表数为k，所有数均匀分布。
// 时间复杂度记比较次数，为：2n+3n+kn = (k+2)kn/2
    ListNode* mergeTwoLists(ListNode* ln1, ListNode* ln2){
        ListNode head(0), *ptr;
        ptr = &head;
        while(ln1 && ln2){
            if(ln1->val < ln2->val){
                ptr->next = ln1, ln1 = ln1->next;
            }else{
                ptr->next = ln2, ln2 = ln2->next;
            }
            ptr = ptr->next;
        }
        if(ln1)
            ptr->next = ln1;
        if(ln2)
            ptr->next = ln2;
        return head.next;
    }

    ListNode *mergeKLists1(vector<ListNode *> &lists)
    {
        while(lists.size() > 1){
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
///////////////////////////////////////////////////////////
// k路归并+最小堆：时间复杂度为：klogk + k(n-1)logk = knlogk
    struct compare{
        bool operator()(const ListNode* l, const ListNode* r){
            return l->val > r->val;
        }
    };

    ListNode *mergeKLists2(vector<ListNode*> &lists){
        priority_queue<ListNode*, vector<ListNode*>, compare> q;
        for(auto t : lists){
            // exclude lists have NULL element:[NULL]
            if(t) q.push(t);
        }
        // exclude lists no elements:[]
        if(q.empty()) return NULL;

        ListNode head(0), *ptr = &head;
        while(!q.empty()){
            ptr->next = q.top();
            q.pop();
            ptr = ptr->next;
            if(ptr->next) q.push(ptr->next);
        }
        return head.next;
    }
///////////////////////////////////////////////////////////
// 堆排序，时间复杂度为：nklog(nk)
    static bool heapComp(ListNode* l, ListNode* r){
        return l->val > r->val;
    }

    ListNode *mergeKLists(vector<ListNode*> &lists){
        vector<ListNode*> heap;
        for(auto t : lists){
            while(t){
                heap.push_back(t);
                t = t->next;
            } 
        }
        make_heap(heap.begin(), heap.end(), heapComp);
        
        ListNode head(0), *ptr = &head;
        while(heap.size()){
            ptr->next = heap.front(), ptr = ptr->next;
            pop_heap(heap.begin(), heap.end(), heapComp);
            heap.pop_back();
        }
        ptr->next = NULL;
        return head.next;
    }
};

vector<ListNode*> stringToListNode(string line){
    vector<ListNode*> lists;
    stringstream ss(line.substr(3, line.size()-6));
    string item;
    char delim = ']';
    while(getline(ss, item, delim)){
        if(item.size() == 0) continue;
        ListNode head(0), *ptr = &head;
        stringstream ssi(item);
        string itemi;
        char delimi = ',';
        while(getline(ssi, itemi, delimi)){
            ptr->next = new ListNode(stoi(itemi));
            ptr = ptr->next;
        }
        lists.push_back(head.next);
        getline(ss, item, '[');
    }
    return lists;
}

string ListNodeToString(ListNode* ret){
    string str;
    while(ret){
        str += to_string(ret->val);
        ListNode *ptr = ret;
        ret = ret->next;
        delete ptr;
    }
    return str;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        vector<ListNode*> lists = stringToListNode(line);

        ListNode* ret = Solution().mergeKLists(lists);
        string out = ListNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
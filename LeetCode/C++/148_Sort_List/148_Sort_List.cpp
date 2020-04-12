#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <sstream>
#include <memory>
#include <algorithm>

using namespace std;

/*
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /*
     * 快排很难处理划分排序后子链表的头尾续接问题，归并才是正道。
     * 自底向上的链表归并的确是O(nlogn)，外循环logn，内循环merge()最多n次比较，至于divide()则是固定的n。
     * 技巧：对链表的处理，加一个preHead指针往往能减少很多边界检查。
     */
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        int len(0);
        ListNode* cur(head);
        while(cur){
            len++;
            cur = cur->next;
        }
        ListNode preHead(0);
        preHead.next = head;
        ListNode *left, *right, *sorted;
        for(int i = 1; i < len; i <<= 1){
            cur = preHead.next;
            sorted = &preHead;
            while(cur){
                left = cur;
                right = divide(left, i);
                cur = divide(right, i);
                sorted = merge(left, right, sorted);
            }
        }
        return preHead.next;
    }
private:
    ListNode* divide(ListNode* head, int len){
        while(--len && head)
            head = head->next;
        if(!head)
            return nullptr;
        ListNode* nextTail(head->next);
        head->next = nullptr;
        return nextTail;
    }

    ListNode* merge(ListNode* left, ListNode* right, ListNode* head){
        while(left && right){
            if(left->val <= right->val){
                head->next = left;
                left = left->next;
            }else{
                head->next = right;
                right = right->next;
            }
            head = head->next;
        }
        if(left)
            head->next = left;
        if(right)
            head->next = right;
        while(head->next)
            head = head->next;
        return head;
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

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        
        ListNode* ret = Solution().sortList(head);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
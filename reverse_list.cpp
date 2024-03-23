#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int data) : data(data), next(nullptr) {}
};

ListNode* addNode(ListNode* tail, int val) {
    ListNode* temp = new ListNode(val);
    tail->next = temp;
    return temp;
}

ListNode* enterListNode() {
    string input;
    getline(cin, input);
    istringstream iss(input);
    ListNode* head = new ListNode(-1);
    ListNode* tail = head;
    bool isHead = true;
    int val;

    while (iss >> val) {
        if (isHead) {
            head->data = val;
            tail = head;
            isHead = false;
        }
        else tail = addNode(tail, val);
    }

    return head;
}

void reverseListNode(ListNode* &head, int left, int right) {
    if (right - left == 0) return;

    right -= left, left--;

    ListNode* leftNode = head;
    ListNode* preLeftNode = leftNode;

    //check left =? 0
    bool isLeftIsHead = (left == 0);

    //dua preLeftNode va leftNode den dung vi tri
    while (left--) {
        preLeftNode = leftNode;
        leftNode = leftNode->next;
    }

    ListNode* rightNode = leftNode;

    //Let rightNode to right spot
    while (right--) rightNode = rightNode->next;

    //Create two node in next point
    ListNode* cur = leftNode->next;
    ListNode* prev = leftNode;


    leftNode->next = rightNode->next;
    if (isLeftIsHead) head = rightNode;
    else preLeftNode->next = rightNode;

    ListNode* condition = rightNode->next;
    while (cur != condition) {
        ListNode* nextNode = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nextNode;
    }
}

void exportListNode(ListNode* head) {
    while (head->next != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << head->data;
}

int main() {
    ListNode* head = enterListNode();

    //input left, right
    int left, right;
    cin >> left >> right;
    reverseListNode(head, left, right);

    exportListNode(head);

    return 0;
}

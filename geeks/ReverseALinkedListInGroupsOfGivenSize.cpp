#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Node {
    Node *next;
    int data;
};
Node *insert(Node *head, int val) {
    Node *node = new Node;
    node->data = val;
    node->next = NULL;
    if (head) {
        Node *p = head;
        while (p->next) {
            p = p->next;
        }
        p->next = node;
        return head;
    }
    return node;
}
Node *insert(Node *head, int index, int val) {
    Node *node = new Node;
    node->data = val;
    node->next = NULL;
    if (index < 1) {
        node->next = head;
    } else if (head) {
        Node *p = head;
        int i = 1;
        while (i < index && p->next) {
            p = p->next;
        }
        Node *q = p->next;
        p->next = node;
        node->next = q;
        return head;
    }
    return node;
}
void update(Node *head, int index, int val) {
    if (head) {
        Node *p = head;
        int i = 0;
        while (p->next && i < index) {
            p = p->next;
        }
        p->data = val;
    }
}
void print(Node *head) {
    Node *p = head;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}
class Solution {
    public:
    Node *reverse(Node *head, int k) {
        if (!head || !head->next || k <= 1) {
            return head;
        }
        Node *start = NULL;
        Node *tail = NULL;
        while (head && head->next) {
            Node *p = head;
            Node *q = head->next;
            Node *r = head->next->next;
            int i = 2;
            while (p && q) {
                q->next = p;
                p = q;
                q = r;
                if (i < k && r) {
                    r = r->next;
                } else {
                    break;
                }
                i++;
            }
            if (!start) {
                start = p;
            }
            if (tail) {
                tail->next = p;
            }
            tail = head;
            head->next = q;
            head = q;
        }
        return start;
    }
};

int main(int argc, char const *argv[]) {
    // cin.tie(0);
    // cout.tie(0);
    // ios_base::sync_with_stdio(false);
    int t;
    cout << "Enter test cases : ";
    cin >> t;
    while (t--) {
        ll n, k;
        cout << "Enter n & K: ";
        cin >> n >> k;
        Node *head = NULL;
        while (n--) {
            int x;
            cin >> x;
            head = insert(head, x);
        }
        Solution sol;
        head = sol.reverse(head, k);
        print(head);
    }
    return 0;
}

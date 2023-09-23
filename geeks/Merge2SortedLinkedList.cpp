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
    Node *sortedMerge(Node *head1, Node *head2) {
        if (!head1) {
            return head2;
        }
        if (!head2) {
            return head1;
        }
        Node *start = NULL;
        if (head1->data < head2->data) {
            start = head1;
            head1 = head1->next;
        } else {
            start = head2;
            head2 = head2->next;
        }
        Node *ptr = start;
        while (head1 || head2) {
            Node *node = NULL;
            if (!head1) {
                node = head2;
                head2 = head2->next;
            } else if (!head2) {
                node = head1;
                head1 = head1->next;
            } else if (head1->data < head2->data) {
                node = head1;
                head1 = head1->next;
            } else {
                node = head2;
                head2 = head2->next;
            }
            ptr->next = node;
            ptr = ptr->next;
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
        cout << "Enter n1 & n2: ";
        cin >> n >> k;
        Node *head1 = NULL;
        while (n--) {
            int x;
            cin >> x;
            head1 = insert(head1, x);
        }
        Node *head2 = NULL;
        while (k--) {
            int x;
            cin >> x;
            head2 = insert(head2, x);
        }
        Solution sol;
        print(sol.sortedMerge(head1, head2));
    }
    return 0;
}

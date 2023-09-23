#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Node {
    Node* left;
    Node* right;
    int data;
};
Node* create(int val) {
    Node* tmp = new Node;
    tmp->data = val;
    tmp->left = tmp->right = NULL;
    return tmp;
}
Node* insert(Node* root, int val) {
    if (root) {
        if (root->data > val) {
            root->left = insert(root->left, val);
        } else if (root->data < val) {
            root->right = insert(root->right, val);
        }
        return root;
    }
    return create(val);
}
Node* remove(Node* root, int val) {
    // Base case
    if (root == NULL) {
        return root;
    }

    // Recursive calls for deletion of child node
    if (root->data > val) {
        root->left = remove(root->left, val);
        return root;
    } else if (root->data < val) {
        root->right = remove(root->right, val);
        return root;
    }

    // Reaching here means root itself is to be deleted.

    // If one of the child is NULL
    if (root->left == NULL) {
        Node* temp = root->right;
        delete root;
        return temp;
    } else if (root->right == NULL) {
        Node* temp = root->left;
        delete root;
        return temp;
    }

    // If both children exist
    else {
        Node* parent = root;

        // Find node just greater than parent
        Node* node = root->right;
        while (node->left) {
            parent = node;
            node = node->left;
        }

        // if node has no left child then connect root->right to node->right, copy node->data to root->data and delete node
        // else if node has left children goto last left node and its parent then connect parent->left to node->right, copy node->data to root->data and delete node
        if (parent != root) {
            parent->left = node->right;
        } else {
            parent->right = node->right;
        }
        root->data = node->data;
        delete node;
        return root;
    }
}
class Solution {
    public:
    Node* ans = NULL;
    bool flag = false;
    void inOrder(Node* root, int x) {
        if (root) {
            inOrder(root->left, x);
            if (!ans && flag) {
                ans = root;
                return;
            }
            if (root->data == x) {
                flag = true;
            }
            inOrder(root->right, x);
        }
    }
    Node* inOrderSuccessor(Node* root, int x) {
        ans = NULL;
        inOrder(root, x);
        return ans;
    }
};

int main(int argc, char const* argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        ll k, n;
        cin >> n;
        cin >> k;
        Node* root = NULL;
        while (n--) {
            int x;
            cin >> x;
            root = insert(root, x);
        }
        Solution sol;
        // cout << sol.findKthNode(root, k) << "\n";
        cout << sol.inOrderSuccessor(root, k)->data << "\n";
    }
    return 0;
}

/*
13 10 18 3 11 15 20 1 6 12
*/
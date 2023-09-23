#include <bits/stdc++.h>
using namespace std;
#define ll long long
class TrieNode {
   public:
    bool isWord = false;
    vector<TrieNode*> children;
    TrieNode() { children = vector<TrieNode*>(26, NULL); }
    static void remove(TrieNode* root, string& word, int i = 0) {
        if(root){
            for (int i = 0; i < word.size(); i++) {
                if (root->children[word[i] - 'a']) {
                    root = root->children[word[i] - 'a'];
                }
            }
            if(root){
                root->isWord = false;
            }
        }
    }
    static void getAll(TrieNode* root, string word = "") {
        if (root) {
            if(root->isWord){
                cout << word << "\n";
            }
            for (int i = 0; i < root->children.size(); i++)
            {
                getAll(root->children[i], word + (char('a' + i)));
            }
        }
    }
    static void insert(TrieNode* root, string& word, int i = 0) {
        if (root) {
            if (root->children[word[i] - 'a'] == NULL) {
                root->children[word[i] - 'a'] = new TrieNode();
            }
            if (i >= word.size() - 1) {
                root->children[word[i] - 'a']->isWord = true;
            } else {
                insert(root->children[word[i] - 'a'], word, i + 1);
            }
        }
    }
    static bool contains(TrieNode* root, string& word) {
        if (root) {
            for (int i = 0; i < word.size(); i++) {
                if (root->children[word[i] - 'a'] == NULL) {
                    return false;
                }
                root = root->children[word[i] - 'a'];
            }
            return root->isWord;
        }
        return false;
    }
    static bool searchSentence(TrieNode* root, TrieNode* head, string&sentence, int i = 0) {
        if (root) {
            if(i >= sentence.size() - 1){
                return root->children[sentence[i] - 'a'] && root->children[sentence[i] - 'a']->isWord;
            }
            bool flag = false;
            if (root->children[sentence[i] - 'a'] && root->children[sentence[i] - 'a']->isWord) {
                flag = flag | searchSentence(head, head, sentence, i + 1);
            }
            flag = flag | searchSentence(root->children[sentence[i] - 'a'], head, sentence, i + 1);
            return flag;
        }
        return false;
    }
};
class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        TrieNode* root = new TrieNode();
        for (int i = 0; i < wordDict.size(); i++) {
            TrieNode::insert(root, wordDict[i]);
        }
        return TrieNode::searchSentence(root, root, s);
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int r;
    cin >> r;
    Solution solution;
    vector<string> words(r);
    for (int i = 0; i < r; i++) {
        cin >> words[i];
    }
    cout << "\nEnter test cases : \n";
    bool doMore = true;
    while(doMore) {
        string test;
        cin >> test;
        doMore = test.size() > 0;
        cout << solution.wordBreak(test, words) << "\n";
    }
    return 0;
}
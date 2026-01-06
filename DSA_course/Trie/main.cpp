#include <iostream>
#include <string>
using namespace std;

class TrieNode
{
public:
    TrieNode *child[26];
    bool isWord;
    TrieNode()
    {
        isWord = false;
        for (auto &a : child)
            a = nullptr;
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string s)
    {
        TrieNode *p = root;
        for (auto &a : s)
        {
            int i = a - 'a';
            if (!p->child[i])
                p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }

    bool search(string key, bool prefix = false)
    {
        TrieNode *p = root;
        for (auto &a : key)
        {
            int i = a - 'a';
            if (!p->child[i])
                return false;
            p = p->child[i];
        }
        if (prefix == false)
            return p->isWord;
        return true;
    }

    bool startsWith(string prefix)
    {
        return search(prefix, true);
    }

    void destroy(TrieNode *node)
    {
        if (!node)
            return;
        for (int i = 0; i < 26; i++)
        {
            if (node->child[i])
                destroy(node->child[i]);
        }
        delete node;
    }

    ~Trie() { destroy(root); }
};

int main()
{
    Trie *trie = new Trie();

    trie->insert("apple");
    trie->insert("app");

    cout << boolalpha;

    cout << "search(\"apple\"): " << trie->search("apple") << endl; // true
    cout << "search(\"app\"): " << trie->search("app") << endl;     // true
    cout << "search(\"appl\"): " << trie->search("appl") << endl;   // false

    cout << "startsWith(\"app\"): " << trie->startsWith("app") << endl; // true
    cout << "startsWith(\"bat\"): " << trie->startsWith("bat") << endl; // false

    delete (trie);
    return 0;
}
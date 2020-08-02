#include <iostream>

using namespace std;

class TrieNode
{
public:
    bool isTerminating;
    TrieNode *children[26];
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
        for (int i = 0; i < 26; i++)
        {
            root->children[i] = nullptr;
        }
    }

    void addWord(string word)
    {
        TrieNode *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (temp->children[word[i] - 'a'] == nullptr)
            {
                temp->children[word[i] - 'a'] = new TrieNode();
            }
            temp = temp->children[word[i] - 'a'];
        }
        temp->isTerminating = true;
    }

    void searchWord(string word)
    {
        TrieNode *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (temp->children[word[i] - 'a'] == nullptr)
            {
                cout << "Word not found\n";
                return;
            }
            temp = temp->children[word[i] - 'a'];
        }
        if (temp->isTerminating)
        {
            cout << "Word found!\n";
        }
        else
            cout << "Word not found\n";
    }
};

int main()
{
    Trie t;
    t.addWord("hello");
    t.addWord("search");
    t.searchWord("hel");
    t.searchWord("search");
}
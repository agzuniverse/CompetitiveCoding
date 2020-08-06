#include <iostream>

using namespace std;

class TrieNode
{
public:
    bool isTerminating;
    int noOfChildren;
    TrieNode *children[26];
};

class Trie
{
    TrieNode *root;

    bool deleteWordRecursive(TrieNode *t, string s, int i)
    {
        if (i == s.length())
            return true;
        bool hasChildBeenDeleted = deleteWordRecursive(t->children[s[i] - 'a'], s, i + 1);
        if (hasChildBeenDeleted)
        {
            t->children[s[i] - 'a'] = nullptr;
            t->noOfChildren--;
        }
        if (i == s.length() - 1)
            t->isTerminating = false;
        if (t->noOfChildren == 0 && t->isTerminating == false)
        {
            delete t;
            return true;
        }
        return false;
    }

public:
    Trie()
    {
        root = new TrieNode();
        root->noOfChildren = 0;
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
                temp->noOfChildren++;
            }
            temp = temp->children[word[i] - 'a'];
        }
        temp->isTerminating = true;
    }

    bool searchWord(string word)
    {
        TrieNode *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (temp->children[word[i] - 'a'] == nullptr)
            {
                cout << "Word not found\n";
                return false;
            }
            temp = temp->children[word[i] - 'a'];
        }
        if (temp->isTerminating)
        {
            cout << "Word found!\n";
            return true;
        }
        else
            cout << "Word not found\n";
        return false;
    }

    void deleteWord(string word)
    {
        if (searchWord(word))
        {
            deleteWordRecursive(root, word, 0);
            cout << "Word deleted\n";
            return;
        }
    }
};

int main()
{
    Trie t;
    t.addWord("hello");
    t.addWord("search");

    t.searchWord("hel"); // word does not exist
    t.searchWord("search");

    t.deleteWord("search");
    t.searchWord("search"); // word does not exist

    t.deleteWord("hel"); // word does not exist, delete should not do anything

    t.addWord("hel");
    t.deleteWord("hello");

    t.searchWord("hel"); // Should exist despite hello being deleted.
}
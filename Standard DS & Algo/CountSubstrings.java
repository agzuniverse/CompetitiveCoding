/* Given a string, print the number of unique substrings that can be made from the string */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

class TrieNode {
    HashMap<Character, TrieNode> children;
    char data;

    TrieNode(char data) {
        this.children = new HashMap<>();
        this.data = data;
    }

    void add(String s) {
        if (s.isEmpty())
            return;
        TrieNode child = this.children.get(s.charAt(0));
        if (child == null) {
            child = new TrieNode(s.charAt(0));
            this.children.put(s.charAt(0), child);
        }
        child.add(s.substring(1));
    }
}

public class CountSubstrings {

    static int countNodesInTrie(TrieNode root) {
        if (root == null)
            return 0;
        int count = 0;
        for (Character c : root.children.keySet()) {
            count += countNodesInTrie(root.children.get(c));
        }
        return count + 1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter string to count all unique substrings");
        String s = br.readLine();
        TrieNode root = new TrieNode('0');
        // Generate all suffixes of string s and add them to trie to form a suffix trie
        // This runs in O(dn) time where n is length of string and d is the alphabet
        // size
        for (int i = 0; i < s.length() - 1; i++)
            root.add(s.substring(i));
        System.out.println(countNodesInTrie(root));
    }
}

/*
 * Explanation: There are O(n^2) substrings possible, which can be put into a
 * hashmap to check for uniqueness. But to merely count the number of
 * substrings, a suffix trie can be used, which gives the solution in O(dn) time
 * where d is the alphabet size. First all the possible suffix (including empty
 * string and the full input string itself) are generated and inserted into the
 * trie, which makes it a suffix trie.
 * 
 * Now we have to count the number of nodes in the trie and this will be the
 * answer. This is because for each node of the suffix trie, the string made by
 * combining the characters from root till that node represents a valid unique
 * substring.
 */
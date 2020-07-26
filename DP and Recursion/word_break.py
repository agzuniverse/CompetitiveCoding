"""
Word Break problem

Given a string and a list of words, find the minimum number of spaces that should be inserted into
the string such that each space separated word can be found in the list of words.

This is a solution using dynamic programming and runs in O(n^2) time where n is the length of the string.
"""
import sys


def wordBreak(inp, words):
    if dp.get(inp) is not None:
        return dp.get(inp)

    minSpaces = sys.maxsize

    # If the whole inp is an allowed word
    if inp in words:
        minSpaces = 0
        dp[inp] = minSpaces
        return minSpaces

    for i in range(1, len(inp)):
        if inp[:i] in words:
            minSpaces = min(minSpaces, 1+wordBreak(inp[i:], words))
    dp[inp] = minSpaces
    return minSpaces


inp = "ilikeicecreamandmango"
list_of_words = ["mobile", "samsung", "sam",
                 "sung", "man", "mango",
                 "icecream", "and", "go",
                 "i", "like", "ice", "cream"]

# Allows O(1) checking to see if a word is in allowed list of words
words = set(list_of_words)

dp = {}  # A hashmap with string as key and the min number of spaces for that string as value
print(wordBreak(inp, words))

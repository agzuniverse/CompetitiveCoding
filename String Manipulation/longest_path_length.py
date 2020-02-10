'''
Suppose we abstract our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
    subdir1
    subdir2
        file.ext

The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext

The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).

Given a string representing the file system in the above format, return the length of the longest absolute path to file in the abstracted file system. If there is no file in the system, return 0.
'''


def lengthLongestPath(inp):
    maxlen = 0
    stack = []
    parts = inp.split("\n")
    for part in parts:
        subparts = part.split("\t")
        while(len(stack) >= len(subparts)):
            stack.pop()
        if("." in subparts[-1]):
            if(len(stack) > 0):
                maxlen = stack[-1] + len(subparts[-1]) + \
                    len(subparts)-1 if stack[-1]+len(subparts[-1]
                                                     )+len(subparts)-1 > maxlen else maxlen
            else:
                maxlen = len(subparts[-1])
        else:
            stack.append(stack[-1] + len(subparts[-1])
                         if len(stack) > 0 else len(subparts[-1]))
    return maxlen


a = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
print(lengthLongestPath(a))

# This solution runs in O(n) time.


/*
Find the next lexicographically greater permutation of characters from the input string.

This solution runs in O(n) time.
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BiggerIsGreater {
    static String nextPermutation(char word[]) {
        // Identify the smallest increasing sequence from right to left
        int suffixHeadIndex = word.length - 1;
        while (suffixHeadIndex > 0 && word[suffixHeadIndex - 1] >= word[suffixHeadIndex])
            suffixHeadIndex--;
        if (suffixHeadIndex == 0)
            return "no answer"; // The string is already at the maximum permutation
        int smaller = suffixHeadIndex - 1; // The first element that is smaller than some element in the suffix
        int leastLarger = word.length - 1;
        while (word[leastLarger] <= word[smaller])
            leastLarger--;
        // leastLarger is at the least element in the suffix larger than smaller
        char temp = word[leastLarger];
        word[leastLarger] = word[smaller];
        word[smaller] = temp;
        // Now sort all elements to the right of smaller
        // Alternatively, just reverse elements from smaller+1 to end of the word, since
        // it is already
        // guaranteed to be in decreasing order. This reduces the runtime.
        for (int i = smaller + 1, j = word.length - 1; i < (word.length - smaller) / 2 + smaller + 1; i++, j--) {
            char t = word[i];
            word[i] = word[j];
            word[j] = t;
        }
        return new String(word);
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter string to generate next lexicographically greater permutation");
        String inp = br.readLine();
        char word[] = inp.toCharArray();
        System.out.println(nextPermutation(word));
    }
}
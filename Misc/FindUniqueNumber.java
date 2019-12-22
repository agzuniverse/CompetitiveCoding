/*
Given a list of integers where every element occurs thrice except one element, which occurs once,
find that unique element in O(n) time and O(1) space.
*/

public class FindUniqueNumber {
    public static void main(String[] args) {
        int a[] = { 1, 1, 2, 4, 2, 6, 4, 2, 1, 4 }; // 6 is the unique element
        int ones = 0, twos = 0, mask = 0;
        for (int i = 0; i < a.length; i++) {
            twos |= ones & a[i]; // Find the bits that will be removed if ones ^ a[i] was done, and add them to
                                 // twos
                                 // Since these bits are occuring for the second time. (Or even number of times)
            ones ^= a[i]; // Remove bits occuring for the second time from ones
            mask = ~(ones & twos); // Bits that are common to ones and twos are bits that have occured a third time
                                   // (Or a multiple of 3 number of times)
            ones &= mask;
            twos &= mask; // Remove the bits that have occured a third time from both ones and twos
        }
        System.out.println(ones); // Ones will have the bits of the number that occurs only once.
    }
}
/*
Given 2 starting nodes of intersecting linked lists, find the node at which they intersect.
O(M+N) time and constant space are the constraints.
M and N are lengths of the two linked lists.
*/

class Node {
    public Node next;
    public int data;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class IntersectingLinkedLists {
    public static void main(String[] args) {
        //
        // 3--7--8--10--11
        // *****/
        // ****1
        // Here 8 is the intersecting element.

        Node list1 = new Node(3);
        list1.next = new Node(7);
        list1.next.next = new Node(8);
        list1.next.next.next = new Node(10);
        list1.next.next.next.next = new Node(11);

        Node list2 = new Node(1);
        list2.next = list1.next.next;
        System.out.println(findIntersectingPoint(list1, list2));
    }

    public static int findIntersectingPoint(Node a, Node b) {
        // Traverse the first linked list and find it's length, and connect the last
        // element to first element to form a loop
        int length = 0;
        Node temp = a;
        while (temp.next != null) {
            length++;
            temp = temp.next;
        }
        length++;
        temp.next = a;
        // Now the problems reduces to finding the looping point of the 2nd linked list
        // Start a pointer at node b, advance it the number of nodes equal to no. of
        // elements in loop
        // Then start another pointer at b, and advance this and the previous pointer
        // one by one until they reach the same node
        temp = b;
        for (int i = 0; i < length; i++) {
            temp = temp.next;
        }
        while (temp != b) {
            temp = temp.next;
            b = b.next;
        }
        return b.data;
    }
}
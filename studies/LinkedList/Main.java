public class Main {
    public static void main(String[] args) {
        LinkedList ll = new LinkedList();
        ll.push_back(1);
        ll.push_back(2);
        ll.push_front(0);
        ll.push_back(3);
        ll.reverse();

        for (int i = 0; i < ll.getSize(); i++) 
            System.out.print(ll.value_at(i) + " ");
        System.out.println();
    }
}

class LinkedList {
    Node head;

    class Node {
        int val;
        Node next;
        
        Node(int v) {
            val = v;
            next = null;
        }
    }

    public int getSize() {
        Node temp = head;
        int size = 0;

        while (temp != null) {
            size++;
            temp = temp.next;
        }
        return size;
    }

    public boolean isEmpty() {
        return head == null;
    }

    public int value_at(int index) {
        Node temp = head;
        int i = 0;
        while (temp != null && i != index) {
            temp = temp.next;
            i++;
        }

        return temp.val;
    }

    public void push_front(int v) {
        if (isEmpty()) {
            head = new Node(v);
        } else {
            Node newNode = new Node(v);
            newNode.next = head;
            head = newNode;
        }
    }

    public int pop_front() {
        int res = head.val;
        head = head.next;
        return res;
    }

    public void push_back(int v) {
        Node temp = head;
        Node prev = temp;
        Node newNode = new Node(v);

        if (isEmpty()) {
            head = newNode;
        } else {
            while (temp.next != null)
                temp = temp.next;

            temp.next = newNode;
        }
    }

    public int pop_back() {
        Node temp = head;

        while (temp.next.next != null) {
            temp = temp.next;
        }

        int res = temp.next.val;
        temp.next = null;
        return res;
    }

    public void reverse() {
        Node prev = null;
        Node curr = head;
        Node next = head.next;

        while (next != null) {
            curr.next = prev;
            prev = curr;
            curr = next;
            next = next.next;
        }
        curr.next = prev;
        head = curr;
    }
}


public class Main {
    public static void main(String[] args) {
        Queue queue = new Queue();
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);

        while (!queue.isEmpty()) {
            System.out.println(queue.dequeue());
        }
    }
}

class LinkedList {
    Node head;
    Node tail;

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
            tail = head;
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
        Node newNode = new Node(v);

        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            tail.next = newNode;
            tail = newNode;
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
}


class Queue {
    private LinkedList ll;

    Queue() {
        ll = new LinkedList();
    }

    public boolean isEmpty() {
        return ll.isEmpty();
    }

    public void enqueue(int v) {
        ll.push_back(v);
    }

    public int dequeue() {
        return ll.pop_front();
    }
}


public class Main {
    public static void main(String[] args) {
        Array arr = new Array();
        arr.push(1);
        arr.push(2);
        arr.push(3);
        arr.push(4);
        arr.push(5);

        int size = arr.getSize();
        for (int i = 0; i < size; i++)
            arr.delete(0);

        for (int i = 0; i < arr.getSize(); i++)
            System.out.print(arr.at(i) + " ");
        System.out.println();
    }
}

class Array {
    private int capacity;
    private int size;
    private int[] arr = new int[1];

    Array() {
        capacity = 0;
        size = 0;
    }

    public boolean is_empty() {
        return size == 0;
    }

    public int at(int i) {
        return arr[i];
    }

    public int getSize() {
        return size;
    }

    public void push(int item) {
        if (capacity <= size) {
            int[] new_arr = new int[arr.length*2];
            capacity = arr.length * 2;
            System.arraycopy(arr, 0, new_arr, 0, arr.length);
            arr = new_arr;
        }
        arr[size] = item;
        size++;
    }

    public void insert(int index, int item) {
        if (capacity <= size) {
            int[] new_arr = new int[arr.length*2];
            capacity = arr.length * 2;
            System.arraycopy(arr, 0, new_arr, 0, arr.length);
            arr = new_arr;
        }

        for (int i = size; i > index; i--)
            arr[i] = arr[i - 1];
        arr[index] = item;

        size++;
    }

    public void prepend(int item) {
        insert(0,item);
    }

    public int pop() {
        return arr[--size];
    }

    public void delete(int index) {
        for (int i = index; i < size; i++)
            arr[i] = arr[i + 1];
        size--;
    }
}


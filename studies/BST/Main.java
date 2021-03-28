public class Main {
    public static void main(String[] args) {
        BST bst = new BST();
        Node root = null;

        root = bst.insert(root, 50);
        root = bst.insert(root, 30);
        root = bst.insert(root, 20);
        root = bst.insert(root, 40);
        root = bst.insert(root, 70);
        root = bst.insert(root, 60);
        root = bst.insert(root, 80);
        // root = bst.delete(root, 50);
        // root = bst.delete(root, 60);
        // root = bst.delete(root, 30);

        // bst.inorder(root);
        System.out.println(bst.getSuccessor(root, 40).val);
        // System.out.println(bst.height(root));
        // System.out.println(bst.getMin(root).val);
        // System.out.println(bst.isBST(root));
    }
}

class Node {
    int val;
    Node left;
    Node right;

    Node(int val) {
        this.val = val;
        left = null;
        right = null;
    }
}

class BST {

    private Node root;

    public Node insert(Node root, int val) {
        if (root == null) {
            root = new Node(val);
            return root;
        }
        if (root.val > val)
            root.left = insert(root.left, val);
        else
            root.right = insert(root.right,val);

        return root;
    }

    public void inorder(Node root) {
        if (root != null) {
            inorder(root.left);
            System.out.println(root.val);
            inorder(root.right);
        }
    }

    public Node search(Node root, int val) {
        if (root == null)
            return root;

        if (root.val > val)
            return search(root.left, val);
        else if (root.val < val)
            return search(root.right, val);
        else
            return root;
    }

    public int height(Node root) {
        if (root == null)
            return 0;
        return Math.max(height(root.left), height(root.right))+1;
    }

    public Node getMin(Node root) {
        if (root == null)
            return null;

        while (root.left != null)
            root = root.left;

        return root;
    }

    public boolean isBST(Node root) {
        return isBSTUtil(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }

    public boolean isBSTUtil(Node root, int min, int max) {
        if (root == null)
            return true;
        return root.val > min && root.val < max && 
            isBSTUtil(root.left, Integer.MIN_VALUE, root.val) &&
            isBSTUtil(root.right, root.val, Integer.MAX_VALUE);
    }

    public Node delete(Node root, int val) {
        if (root == null)
            return root;
        if (root.val > val)
            root.left = delete(root.left, val);
        else if (root.val < val)
            root.right = delete(root.right, val);
        else {
            if (root.right == null && root.left == null)
                root = null;
            else if (root.left == null)
                root = root.right;
            else if (root.right == null)
                root = root.left;
            else {
                Node temp = getMin(root.right);
                root.val = temp.val;
                root.right = delete(root.right,temp.val);
            }
        }

        return root;
    }

    public Node getSuccessor(Node root, int val) {
        Node curr = search(root, val);

        if (curr == null)
            return root;

        if (curr.right != null)
            return getMin(root.right);
        else {
            Node successor = null;
            Node ancestor = root;

            while (ancestor != curr) {
                if (ancestor.val > val) {
                    successor = ancestor;
                    ancestor = ancestor.left;
                } else if (ancestor.val < val)
                    ancestor = ancestor.right;
            }

            return successor;
        }
    }

}


class Solution {
    public int[] dailyTemperatures(int[] T) {
        int[] result = new int[T.length];
        Stack<Integer> stack = new Stack<>(); // Make it a stack of indices.
        for (int i = 0; i < T.length; i++) {
            while (!stack.isEmpty() && 
                   T[i] > T[stack.peek()]) {
                
                int index = stack.pop();
                result[index] = i - index;
            }
            stack.push(i);
        }
        return result;
    }
}

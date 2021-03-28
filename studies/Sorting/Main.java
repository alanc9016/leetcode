public class Main {
    public static void main(String[] args) {
        int[] nums = {5,1,3,6,4,2,10,0,-1,4,30,-100};
        mergeSort(nums);
        for (int e : nums)
            System.out.print(e + " ");
        System.out.println();
    }

    public static void mergeSort(int[] nums) {
        int[] aux = new int[nums.length];
        mergeSortUtil(nums, aux, 0, nums.length - 1);
    }

    public static void mergeSortUtil(int[] nums, int[] aux, int low, int high) {
        if (low >= high)
            return;
        int mid = low + (high - low) / 2;
        mergeSortUtil(nums, aux, low, mid);
        mergeSortUtil(nums, aux, mid + 1, high);
        merge(nums, aux, low, mid, high);
    }

    public static void merge(int[] nums, int[] aux, int low, int mid, int high) {
        for (int i = low; i <= high; i++)
            aux[i] = nums[i];

        int i = low;
        int j = mid + 1;

        for (int k = low; k <= high; k++) {
            if (i > mid) nums[k] = aux[j++];
            else if (j > high) nums[k] = aux[i++];
            else if (aux[i] > aux[j]) nums[k] = aux[j++];
            else nums[k] = aux[i++];
        }
    }

    public static void quickSort(int[] nums) {
        quickSortUtil(nums, 0, nums.length - 1);
    }

    public static void quickSortUtil(int[] nums, int low, int high) {
        if (low > high)
            return;
        int p = partition(nums, low, high);
        quickSortUtil(nums, low, p - 1);
        quickSortUtil(nums, p + 1, high);
    }

    public static int partition(int[] nums, int low, int high) {
        int i = low - 1;
        int x = nums[high];

        for (int j = low; j <= high; j++) {
            if (x > nums[j]) {
                i++;
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
            }
        }

        int temp = nums[i+1];
        nums[i+1] = nums[high];
        nums[high] = temp;

        return i + 1;
    }
}


import java.util.Scanner;

public class Sorting{
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args)
    {
        // int[] arr1 = {1,23,24,34};
        // int[] arr2 = {1,2,3,12,12,15,17,19,20,22,24,43};

        int[] arr = {-1,2,3,6,5,48,6,32,16,61,66,11,6,61,16,6,661,1,1,1};
        // display(mergeArrays(arr1, arr2));
        display(mergeSort(arr, 0, 19));
    }
    public static void display(int[] arr) {
        for(int ele : arr)
        {
            System.out.print(ele + " ");
        }
        System.out.println();
    }
    public static int[] mergeArrays(int[] arr1, int[] arr2)
    {
        int[] arr = new int[arr1.length + arr2.length];
        int i = 0, j=0, k=0;        //one pointer on each array
        while(i < arr1.length || j< arr2.length)
        {
            if(i<arr1.length && j<arr2.length)
            {
                if(arr1[i] < arr2[j])
                arr[k++]=arr1[i++];
                else
                arr[k++]=arr2[j++];
            }
            else if(i<arr1.length)
            {
                arr[k++]=arr1[i++];
            }
            else if(j<arr2.length)
            {
                arr[k++]=arr2[j++];
            }
        }
        return arr;
    }

    public static int[] mergeSort(int[] arr, int li, int ri)
    {
        if(li == ri)
        {
            int[] base = new int[1];
            base[0] = arr[li];
            return base; 
        }

        int mid = (li + ri)>>>1;
        int[] left = mergeSort(arr, li, mid);
        int[] right = mergeSort(arr, mid+1, ri);

        return mergeArrays(left, right);
    }
}
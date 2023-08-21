public class Array{
    public static void main(String[] args)
    {
        int [] arr=new int[]{3,74,237,54,56};
        int max=arr[0];
        for (int i=0;i<arr.length;i++)
        {
            if (arr[i]>max)
            max =arr[i];
            
        }
        System.out.println("maximum element is "+max);
    }
}

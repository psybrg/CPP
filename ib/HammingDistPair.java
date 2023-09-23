import java.util.*;
class Solution {
    // DO NOT MODIFY THE ARGUMENTS WITH "final" PREFIX. IT IS READ ONLY
    public static int hammingDistance(final int[] A) {
         int ans = 0; // Initialize result
 
        // traverse over all bits
        for (int i = 0; i < 32; i++) {
             
            // count number of elements 
            // with i'th bit set
            int count = 0;
             
            for (int j = 0; j < A.length; j++)
                if ((A[j] & (1 << i)) == 0)
                    count++;
 
            // Add "count * (n - count) * 2" 
            // to the answer
            ans += (count * (A.length - count) * 2);
        }
         
        return ans;
}
	public static void main(String [] args)
	{
		Scanner inp=new Scanner (System.in);
		int n=inp.nextInt();
		int arr[]=new int[n];
		for(int i=0;i<n;i++)
		{
			arr[i]=inp.nextInt();
		}
		System.out.println(hammingDistance(arr));
	}
}

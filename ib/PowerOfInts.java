import java.util.*;
import java.lang.Math;
class Solution {
    public static int isPower(int A) {
        if(A==1)
        return 1;
        int a=2,p=2,n=(int)Math.pow((int)a,(int)p);
        while(n<=A)
        {    
            p=2;
            while(n<=A)
            {
                n=(int)Math.pow((int)a,(int)p);
                System.out.println(a+"\t"+p);
                if(n==A)
                    return 1;
                p++;
            }
            a++;p=2;
            n=(int)Math.pow((int)a,(int)p); 
        }
        return 0;
    }
    public static void main(String [] args)
	{
		Scanner inp=new Scanner (System.in);
		int n=inp.nextInt();
		/*int arr[]=new int[n];
		for(int i=0;i<n;i++)
		{
			arr[i]=inp.nextInt();
		}/**/
		System.out.println(isPower(n));
	}
}


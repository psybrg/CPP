import java.util.Scanner;
public class B339
{
    public static void main(String [] args)
    {
        Scanner inp = new Scanner(System.in);
        int n,m,i,t=1;
        long s=0;
        n = inp.nextInt();
        m = inp.nextInt();
        int arr[] = new int[m];
        for(i=0;i<m;i++)
        {
            arr[i] = inp.nextInt();
            if(arr[i]>=t)
                s=s+arr[i]-t;
            else
                s=s+arr[i]-t+n;
            t=arr[i];
        }
        System.out.println(s);
    }
}

import java.util.Scanner;
public class B467
{
    static byte k;
    static long fedor;
    public static boolean check(long a)
    {
        long d = a^fedor;
        if(Long.bitCount(d)>k)
            return false;
        else return true;
    }
    public static void main(String[] args)
    {
        Scanner inp = new Scanner(System.in);
        byte n = inp.nextByte();
        short m = inp.nextShort();
        k = inp.nextByte();
        long arr[] = new long[m];
        int i,t=0;
        for(i=0;i<m;i++)
            arr[i] = inp.nextLong();
        fedor = inp.nextLong();
        for(i=0;i<m;i++)
            if(check(arr[i]))
                t++;
        System.out.println(t);
    }
}

import java.util.Scanner;
public class B478
{
    public static void main(String[] args)
    {
        Scanner inp = new Scanner(System.in);
        long n = inp.nextLong();
        long m = inp.nextLong();
        long max = (n-m+1)*(n-m)/2;
        long min = (n%m)*(long)(n/m+1)*(long)(n/m)/2
                    +(m-n%m)*(long)(n/m-1)*(long)(n/m)/2; 
        System.out.println(min+" "+max);
    }
}

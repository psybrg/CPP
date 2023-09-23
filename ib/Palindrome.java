import java.util.*;

class Solution {
    public static int isPalindrome(int A)
    {
        int n=A,s=0;
        while(n>0)
        {
            s=s*10+n%10;
            n/=10;
        }
        System.out.println(s+"\t"+A);
        if(s==A)
            return 1;
        else
            return 0;
    }
    public static int reverse(int A)
    {
        int m,n=A,s=0,s1;
        while(n!=0)
        {
            s=s*10+n%10;
            n/=10;
        }
        m=s;
        s1=0;
        while(m!=0)
        {
            s1=s1*10+m%10;
            m/=10;
        }
        System.out.println(A+"\t"+s+"\t"+s1);
        if(A==s1)
            return s;
        if(A>=0)
            while(s1<A)
            {
                s1*=10;
                if(A==s1)
                    return s;
            }
        else
            while(s1>A)
            {
                s1*=10;
                if(A==s1)
                    return s;
            }
        return 0;
        /*if(A>0&&s>0)
            return s;
        else if(A<0&&s<0)
            return s;
        else
            return 0;/**/
    }

    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);
        int n=inp.nextInt();
        System.out.println(reverse(n));
        //System.out.println(isPalindrome(n));
    }
}

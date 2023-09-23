import java.util.*;

class Solution {
    public static String /*int/**/ titleToNumber(/*String /**/int A) {
        /*int i, n = A.length(), t, s = 0;
        for (i = n - 1; i >= 0; i--) {
            t = (int) A.charAt(i) - 64;
            s = s * 26 + t;
        }
        return s;
        /**/
        String s="";
        int r;
        while(A>0)
        {
            r=A%26;
            System.out.println(r+"\t"+A);
            if(r==0)
            {
                r=26;
                A-=26;
            }
            s=(char)(r+64)+s;
            A=A/26;
        }
        return s;
    }

    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);
        //String s = inp.next();
        //System.out.println(titleToNumber(s));
        int n=inp.nextInt();
        System.out.println(titleToNumber(n));
    }
}

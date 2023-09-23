import java.util.Scanner;
public class B448
{
    public static boolean check(String s1,String s2)
    {
        int i,j,l1=s1.length(),l2=s2.length();
        if(l2>l1)
            return false;
        int dp[][]=new int[l1+1][l2+1];
        for(i=0;i<=l1;i++)
            for(j=0;j<=l2;j++)
            {
                if(i==0||j==0)
                    dp[i][j]=0;
                else if(s1.charAt(i-1)==s2.charAt(j-1))
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=(dp[i][j-1]>dp[i-1][j])?dp[i][j-1]:dp[i-1][j];
            }
        if(dp[l1][l2]==((l1<l2)?l1:l2))
            return true;
        else
            return false;
    }
    public static void main(String[] args)
    {
        Scanner inp=new Scanner(System.in);
        String s=inp.nextLine();
        String t=inp.nextLine();
        boolean r1=false,r2=false;
        if(s.length()>=t.length())
        {
            int i;
            int a[]=new int[26];
            int b[]=new int[26];
            for (i=0; i<26; i++)
            b[i]=a[i]=0;
            for (i=0; i<s.length(); i++)
            {
                a[(int)s.charAt(i)-97]++;
                if(i<t.length())
                b[(int)t.charAt(i)-97]++;
            }
            for (i=0; i<26; i++)
            if(b[i]>a[i])
            break;
            if(i>=26)
            {
                r2=true;
                if(s.length()!=t.length())
                r1=true;
            }
        }
        if(check(s,t))
        {
            r1=true;
            r2=false;
        }
        if(r1==false&&r2==false)
        System.out.println("need tree");
        else if(r1==false&&r2==true)
        System.out.println("array");
        else if(r1==true&&r2==false)
        System.out.println("automaton");
        else
        System.out.println("both");
    }
}

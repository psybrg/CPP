import java.util.*;
public class B312
{
    public static void main(String[] args)
    {
        Scanner inp=new Scanner(System.in);
        double a=inp.nextDouble();
        double b=inp.nextDouble();
        double c=inp.nextDouble();
        double d=inp.nextDouble();
        double ll=1-a/b;
        double lr=1-c/d;
        double wl=a/b;
        double s=1-ll*lr;
        double pw=wl/s;
        System.out.println(pw);
    }
}

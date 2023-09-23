import java.util.Scanner;
import java.lang.Math;

public class B507 {
    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);
        long r = inp.nextLong();
        long x0 = inp.nextLong();
        long y0 = inp.nextLong();
        long x1 = inp.nextLong();
        long y1 = inp.nextLong();
        x1 = x1 - x0;
        x1 = x1 * x1;
        y1 = y1 - y0;
        y1 = y1 * y1;
        long z = x1 + y1;
        // System.out.println(x1 + "\t" + y1);
        System.out.println((long) Math.ceil(Math.sqrt((double) z) / (2 * r)));
    }
}

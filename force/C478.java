import java.util.Scanner;

public class C478 {
    static long mx(long r, long g, long b) {
        if (r < g)
            r = g;
        if (r < b)
            r = b;
        return r;
    }

    static long mn(long r, long g, long b) {
        if (r > g)
            r = g;
        if (r > b)
            r = b;
        return r;
    }

    static boolean valid(long r, long g, long b) {
        if ((r <= 0) && (g <= 0))
            return false;
        if ((b <= 0) && (g <= 0))
            return false;
        if ((r <= 0) && (b <= 0))
            return false;
        if (((r + g + b) / 3) <= 0)
            return false;
        return true;

    }

    public static void main(String[] args) {
        long r, g, b, hi, lo, mid, ans = 0, x, y, h1, l1, h2, l2;
        Scanner inp = new Scanner(System.in);
        r = inp.nextLong();
        g = inp.nextLong();
        b = inp.nextLong();
        while (valid(r, g, b)) {
            hi = mx(r, g, b);
            lo = mn(r, g, b);
            mid = r + g + b - hi - lo;
            x = (mid * hi) / (lo + mid);
            y = hi - x;
            // cout<<hi<<" "<<mid<<" "<<lo<<endl;
            if (lo == 0) {
                if (hi <= 2 * mid) {
                    ans += (hi + mid) / 3;
                    mid = 0;
                } else {
                    ans += mid;
                    mid = 0;
                }
            } else if ((hi + lo + mid) == 4) {
                ans++;
                mid = 0;
                lo = 0;
            } else {
                h1 = (x > mid) ? x : mid;
                l1 = (x + mid) - h1;
                if (h1 >= 2 * l1) {
                    h1 = h1 - 2 * l1;
                    ans += l1;
                    l1 = 0;
                } else {
                    ans += (l1 + h1) / 3;
                    if ((l1 + h1) % 3 == 0) {
                        l1 = h1 = 0;
                    } else if ((l1 + h1) % 3 == 2) {
                        l1 = h1 = 1;
                    } else {
                        h1 = 1;
                        l1 = 0;
                    }
                }

                h2 = (y > lo) ? y : lo;
                l2 = (y + lo) - h2;
                if (h2 >= 2 * l2) {
                    h2 = h2 - 2 * l2;
                    ans += l2;
                    l2 = 0;
                } else {
                    ans += (l2 + h2) / 3;
                    if ((l2 + h2) % 3 == 0) {
                        l2 = 0;
                        h2 = 0;
                    } else if ((l2 + h2) % 3 == 2) {
                        l2 = 1;
                        h2 = 1;
                    } else {
                        h2 = 1;
                        l2 = 0;
                    }
                }

                hi = h1 + h2;
                lo = l2;
                mid = l1;
            }
            r = hi;
            g = lo;
            b = mid;
        }
        System.out.println(ans);
    }
}

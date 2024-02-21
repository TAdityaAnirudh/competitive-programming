package AUG22;

import java.util.Scanner;

// https://www.codechef.com/submit/HLEQN
public class HELQN {
    public static void Solve() {
        Scanner ins = new Scanner(System.in);
        int t = ins.nextInt();
        while (t-- > 0) {
            double x = ins.nextInt();
            boolean found = false;
            for (int a = 1; a < Math.sqrt(x); a++) {
                double b = (x - 2*a)/(2 + a);
                if (b == (int)b && b != 0) {
                    found = true;
                    break;
                }
            }
            if (found) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}

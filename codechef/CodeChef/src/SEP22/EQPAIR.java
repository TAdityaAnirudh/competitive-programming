package SEP22;

import java.util.HashMap;
import java.util.Scanner;

public class EQPAIR {
    public static void Solve() {
        Scanner ins = new Scanner(System.in);
        int t = ins.nextInt();
        while (t-- > 0) {
            int n = ins.nextInt();
            HashMap<Integer, Integer> counts = new HashMap<>();
            for (int i = 0; i < n; i++) {
                int x = ins.nextInt();
                if (counts.containsKey(x)) {
                    counts.put(x, counts.get(x) + 1);
                } else {
                    counts.put(x, 1);
                }
            }
            long answer = 0;
            for (int key:counts.keySet()) {
                long count = counts.get(key);
                answer += (count * (count - 1)) / 2;
            }
            System.out.println(answer);
        }
    }
}

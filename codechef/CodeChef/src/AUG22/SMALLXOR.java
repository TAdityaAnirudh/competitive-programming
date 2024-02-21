package AUG22;

import java.util.PriorityQueue;
import java.util.Scanner;

public class SMALLXOR {
    public static void Solve() {
        Scanner ins = new Scanner(System.in);
        int t = ins.nextInt();
        while (t-- > 0) {
            int n = ins.nextInt();
            int x = ins.nextInt();
            int y = ins.nextInt();
            PriorityQueue<Integer> heap = new PriorityQueue<Integer>();
            for (int i = 0; i < n; i++) {
                int inp = ins.nextInt();
                heap.add(inp);
            }
            for (int i = 0; i < y; i++) {
                int num = heap.remove();
                num = num ^ x;
                heap.add(num);
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) {
                sb.append(heap.remove());
                sb.append(' ');
            }
            System.out.println(sb.toString());
        }
    }
}

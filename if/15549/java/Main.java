import java.util.*;

// 답 구하는 프로그램

public class Main {
    public static void main(String[] args) {
        int x = 0;
        while(true) {
            if (x != 0 && x == -x) {
                System.out.println(x);
                System.out.println("true");
                break;
            }
            
            x++;
        }
    }
}
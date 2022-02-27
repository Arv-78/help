import java.math.BigInteger;
import java.util.Scanner;

/**
 * java
 */

public class java {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    BigInteger a, b;

    int t;
    t = sc.nextInt();

    while ((t--) > 0) {
      a = BigInteger.valueOf(sc.nextInt());
      b = BigInteger.valueOf(sc.nextInt());

      System.out.println((a.compareTo(b) == 0) ? "=" : ((a.compareTo(b) > 0) ? ">" : "<"));

    }

  }
}

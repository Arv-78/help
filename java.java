import java.math.BigInteger;

public class java
{
    public static void main(String[] args) {
      String S = "line: a70 and z72 will be replaced,  aa24 and a872 will not";

      System.out.println(S.replaceAll("(^| )+[a-z][0-9][0-9]($| )+", "***"));
      
    }
} 
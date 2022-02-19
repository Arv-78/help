import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;
public class java
{
    public static void main(String[] args) throws ParseException {
     
      // Calendar c1 = Calendar.getInstance();
      // c1.set(Calendar.MONTH, 11);
      // c1.set(Calendar.DATE, 05);
      // c1.set(Calendar.YEAR, 1996);
      // Date date = c1.getTime();
      // String s = new SimpleDateFormat("EEEE").format(date);
      // System.out.println(s);

      String inputDate = "07/08/2001";
      SimpleDateFormat format1 = new SimpleDateFormat("dd/MM/yyyy");
      Date dt1 = format1.parse(inputDate);
      DateFormat format2 = new SimpleDateFormat("EEEE"); 
      String finalDay = format2.format(dt1);
      System.out.println(finalDay);
    }
} 
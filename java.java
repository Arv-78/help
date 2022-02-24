import java.math.BigInteger;
import java.util.Scanner;

import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;

public class java
{
    public static void main(String[] args) throws ScriptException {
     
      ScriptEngineManager mgr = new ScriptEngineManager();

      ScriptEngine engine = mgr.getEngineByName("JavaScript");

      Scanner sc = new Scanner(System.in);

      while(sc.hasNextLine()) System.out.println(engine.eval(sc.nextLine()));
      
    }
} 
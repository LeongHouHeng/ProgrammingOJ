import java.util.*; 
import java.io.*;

class Function {  
  String FirstReverse(String str) { 
  
    // code goes here   
    /* Note: In Java the return type of a function and the 
       parameter types being passed are defined, so this return 
       call must match the return type of the function.
       You are free to modify the return type. */
	String tmpStr = "";
    
    for(int i = str.length(); i > 0; i--){
    	tmpStr += str.substring(i-1, i);
    }
    str = tmpStr;
    
    return str;
    
  } 
  
  public static void main (String[] args) {  
    // keep this function call here     
    Scanner  s = new Scanner(System.in);
    Function c = new Function();
    System.out.print(c.FirstReverse(s.nextLine())); 
  }   
  
}








  

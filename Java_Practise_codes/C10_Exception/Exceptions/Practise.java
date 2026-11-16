public class Practise {

    // divide() throws a checked exception, which tells that the callers must catch it or pass it onward. 
    double divide(double a, double b) throws Exception{
        if(b==0) {
            throw new Exception("Divisor can't be zero!"); 
        }
        return a/b; 
    }


    // since divide throws a checked exception, we must either handle it or the caller function should throw an error and this error should be passed to that . 




    // Following function demonstrates the handling of the exception by try catch 

    // public static void main(String args[]) { 
    //     Practise calculator = new Practise(); 
        
    //     try {
    //         System.out.println(calculator.divide(15, 8)); 
    //     }
    //     catch(Exception e){
    //         System.out.println(e.getMessage()); 
    //     }
    // }

    // Following function demonstrates that the caller function throws an exception taking it from the divide() method 
    // instead of handling it with the try catch 


    // Now main() does not catch the exception -- it passes it to the JVM 
    public static void main(String args[]) throws Exception {
        Practise calculator = new Practise(); 


        System.out.println(calculator.divide(15, 0)); 
    }



}
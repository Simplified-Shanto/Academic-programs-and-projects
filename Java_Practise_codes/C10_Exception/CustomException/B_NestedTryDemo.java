class NestedTry {
    public static void main(String[] args) {
        try {
            try {
                int x = 10/0; 
            }
            catch(ArrayIndexOutOfBoundsException e) {
                System.out.println("inner"); 
            }
        }
        catch(ArithmeticException e) {
            System.out.println("outer"); 
        }
    }
}


// Here the inner catch does not match ArithmeticException, so the exception propageates outward and the otuer catch handles it. 
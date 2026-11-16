class A_Arithmetic_Exception{
    public static void main(String[] args){
        try{
            int x = 10/0; 
            System.out.println('A'); 
        }
        catch (ArithmeticException e) {
            System.out.println("B"); 
        }

        System.out.println("c"); 
    }
}
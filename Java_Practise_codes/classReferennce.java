class Test {
    static class Nested{
        void print() {
            System.out.println("Talking from a nested class"); 
        }
    }
}

class classReferennce{
    public static void main(String[] args){
        Test.Nested nestedtest = new Test.Nested(); 

        nestedtest.print();
    }

}

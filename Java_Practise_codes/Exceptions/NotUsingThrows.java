public Class NotUsingThrows{
    void demoMethod(){
        System.out.println("Inside demo method"); 
        throw IllegalAccessException("demo"); 
    }


    public static void main(String args[]){
        Not_using_throws practiseObject = new Not_using_throws(); 

        practiseObject.demoMethod(); 
    }
}
import java.util.*; 



/////////////////////  Hollow diamonds letters reversed  /////////////////////////////
class PatternPrinter{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in); 
        int a; a = input.nextInt(); 

        int cnt = 0; 
         
        for(int i = a; i>=1; i--)
        {
            for(int j = i-1; j>=1; j--) { System.out.print(" "); }
            if(i==a) { System.out.println((char)('Z'-(cnt++))); continue;  }
            else 
            {
                System.out.print((char)('Z'-(cnt++)));
            }


            for(int j = 1; j<= a-i-1; j++)
            {
              System.out.print("  "); 
            }
            

            System.out.println(" "+((char)('Z'-(cnt++))));
        }

        for(int i = 1; i<=a-1; i++)
        {
            for(int j = 1; j<=i; j++) { System.out.print(" "); }
            if(i==a-1){System.out.println(((char)('Z'-(cnt++)))); continue; }
            else 
            {
                System.out.print(((char)('Z'-(cnt++))));
            }
            
            for(int j = a - i-2; j>=1; j--) { System.out.print("  "); }
            System.out.println(" " + ((char)('Z'-(cnt++)))); 
        }

        
    }
}




























// //Diamond with letters and numbers 
// import java.util.Scanner; 

// class PatternPrinter{
//     public static void main(String[] args)
//     {
//         Scanner input = new Scanner(System.in); 
//         int a = input.nextInt(); 



//     for(int i = 0; i<=a/2; i++)
//     {
//         for(int j = 0; j<i; j+=1) { System.out.print("  "); }
//         char c = (char)('A' + i); 
//         System.out.print(c); 
//         for(int j = a - i*2-3; j>=0; j-=1) { System.out.print("  "); } 
//         System.out.print(" "); 
//         c = (char)('A' + a-i-1); 
//       if(i==a/2)  System.out.println(); 
//       else System.out.println(c); 
        

//     }

//     for(int i = a/2-1; i>=0; i--)
//     {
//         for(int j = 0; j<i; j++) {System.out.print("  "); }
//         char c = (char)('A'+i); 
//         System.out.print(c); 


//         for(int j = a - i*2-3; j>=0; j-=1) { System.out.print("  "); } 
//         System.out.print(" "); 

//         c = (char)('A' + a - i-1); 
//         System.out.println(c); 
//     }



    /////////////////////////////////  Pyramid with letters and numbers ///////////////////////
    // for(int i = a -1; i>=1; i--)
    // {
    //     for(int j = i; j>=1; j--) { System.out.print(" "); }
    //     char c = (char)('A' +  a - i -1); 
    //     System.out.print(c); 

    //     for(int j = a - i -1; j>=2; j--) { System.out.print(j); }
    //     if(i!=a-1) System.out.print(1); 
    //     for(int j = 2; j<=a-i -1; j++) { System.out.print(j); }

    //    if(i==a-1) System.out.println(); 
    //    else System.out.println(c); 

    // }












        ///////////////////////////   Diamond with letters and numbers ///////////////////////////////





        // for(int i = 0; i<=a-1; i++){  char c = (char)('A' + i);  System.out.print(c); }
        // for(int i = a-2; i>=0; i--) { char c = (char)('A' + i); System.out.print(c); }
        // System.out.println();


        // for(int j = 0; j<a-1; j++) 
        // {
        //     for(int i=0; i<a - j -1;  i++)
        //     {
        //         char c = (char)('A' + i ); 
        //         System.out.print(c); 
        //     }
               

        //     for(int i = j+1; i>=2; i--)
        //     {
        //         System.out.print(i); 
        //     }

        //     System.out.print(1); 

        //     for(int i = 2; i<=j+1; i++)
        //     {
        //         System.out.print(i); 
        //     }


        //      for(int i=a - j-2; i>=0;  i--)
        //     {
        //         char c = (char)('A' + i); 
        //         System.out.print(c); 
        //     }
        //     System.out.println(); 
        // }



        //  for(int j = 1; j<a-1; j++) 
        //  {
        //     for(int i=0; i<=j;  i++)
        //     {
        //         char c = (char)('A' + i ); 
        //         System.out.print(c); 
        //     }

        //     for(int i = a-1-j; i>=2; i--)
        //     {
        //         System.out.print(i); 
        //     }
        //     System.out.print(1); 
        //     for(int i = 2; i<=a-1 -j; i++)
        //     {
        //         System.out.print(i); 
        //     }

        //      for(int i=j; i>=0;  i--)
        //     {
        //         char c = (char)('A' + i); 
        //         System.out.print(c); 
        //     }
        //     System.out.println(); 
        // }




        // for(int i = 0; i<=a-1; i++){  char c = (char)('A' + i);  System.out.print(c); }
        // for(int i = a-2; i>=0; i--) { char c = (char)('A' + i); System.out.print(c); }
        // System.out.println();


        
//     }
// }
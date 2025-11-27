
// //Memory allocation with calloc()
// #include<stdio.h>
// #include<stdlib.h>

// int main()
// {
//     int *studentID;
//     int studentNumber = 12;
//     studentID = calloc(studentNumber, 2*sizeof(studentID)); // Allocating 2 * (4 byte for integer) memory for each student. First four byte representing one integer will store the studentID, the Second integer stores the age of the student. 

//     for (int i = 0; i < studentNumber; i++)
//     {
//         *(studentID + i*2) = i;
//         *(studentID + i * 2 + 1) = 12 * i; //Student's age.

//         printf("Student %d has id 20243310%d and age = %d\n", i + 1, *(studentID + i*2), *(studentID + i*2 + 1));
//     }
// }

// #include<stdlib.h>
// #include<stdio.h>
// //Create an array using malloc() and populate it.

// int main()
// {

//     int *ptr1;

//     ptr1 = malloc(10 * sizeof(int));

//     *ptr1 = 10;

//     for (int i = 0; i < 10; i++)
//     {
//         *(ptr1 + i) = i;
//     }

//     for (int i = 0; i < 10; i++)
//     {
//         printf("%d ", *(i + ptr1));
//     }

//         return 0;
// }

// #include <stdio.h>
// #include <String.h>
// #include <time.h>
// #include <ctype.h>
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     switch(n%2)
//     {
//         case 0:
//             printf("the number is even\n");
//         case 1:
//             printf("the number is odd\n");
//         default:
//             printf("Invalid input!");
//     }
//     return 0;
// }




//Print an array in reverse order using pointer
// #include <stdio.h>
// #include <String.h>
// #include <time.h>
// #include <ctype.h>

// int main()
// {
//     int n = 5;
//     int arr[5] = {4, 3, 2, 1, 0};
//     int *pointer = arr;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         printf("%d ", *(pointer+i));
//     }

//     return 0;
// }









// int vowel_count = 0;
// int consonant_count = 0;
// int digit_count = 0;
// char Str[100] = "Let's go back in 1971";

// void pString(int *v, int *c, int *d)
// {
//     int len = strlen(Str);
//     for (int i = 0; i < len; i++)
//     {
//         char h = tolower(Str[i]);
//         if('0' <= h && h <='9')
//             *d++;
//         else if(h=='a' || h=='e' || h == 'i' || h = 'o' || 'u')
//             *v++;

//     }
// }

// int main()
// {

//     pString(&vowel_count, &consonant_count, &digit_count);
//     printf("V: %d  C: %d  D: %d", vowel_count, consonant_count, digit_count);
//     return 0;
// }

// Find the starting index of a substring inside a string if present, otherwise no.

// int main()
// {
//     char str[100], substr[100];
//     scanf("%s %s", &str, &substr);
//     int lenA = strlen(str);
//     int lenB = strlen(substr);

//     for (int i = 0; i < lenA; i++)
//     {
//         int found = 1;
//         for (int j = 0; j < lenB; j++)
//         {
//             if(i+j >=lenA || str[i+j]!=substr[j]) {
//                 found = 0;
//              }
//         }

//         if(found)
//         {
//             printf("Substring found at index %d ", i);
//                 return 0;
//         }
//     }

//     printf("Substring not found\n");
//     return 0;
// }

//Implement the function strlen(), strcmp(), strcpy(), strcat()

// int stringlength(char str[100])
// {
//     int len = 0;
//     while (str[len] != '\0')
//     {
//         len++;
//     }

//     return len;
// }

// int strcompare(char str1[100], char str2[100])
// {
//     if (stringlength(str1) != stringlength(str2))
//     {
//         return 0;
//     }
//     for (int i = 0; i < strlen(str1); i++)
//     {
//         if (str1[i] != str2[i])
//             return 0;
//     }
//     return 1;
// }

// void copystring(char source[100], char destination[100])
// {
//     for (int i = 0; i < stringlength(destination); i++)  // In case the source string's length is smaller than the destination string's length, clearing full of the destination string, thus the overhead part of the destination string in those cases does not contain any character. 
//     {
//         destination[i] = ' ';
//     }

//     for (int i = 0; i < stringlength(source); i++)
//     {
//         destination[i] = source[i];
//     }
// }

// void concatenateString(char stra[100], char strb[100])
// {
//     int lenA = stringlength(stra);
//     for (int i = 0; i < stringlength(strb); i++)
//     {
//         stra[lenA + i-1] = strb[i];
//     }
// }

// int main()
// {
//     char str1[100], str2[100];
//     scanf("%s", &str1);
//     scanf("%s", &str2);
//     printf("Length of str1 = %d\n", stringlength(str1));
//     printf("Match result: %d\n", strcompare(str1, str2));
//     copystring(str1, str2);
//     printf("str2 is now %s\n", str2);
//     concatenateString(str1, str2);
//     printf("Combining the two we get: %s", str1);

//     return 0;
// }






















// //Implement insertion sort:

// Insertion sort is a simple sorting algorithm that works by iteratively inserting each element of an unsorted list into its correct position in a sorted portion of the list. It is like sorting playing cards in your hands. You split the cards into two groups: the sorted cards and the unsorted cards. Then, you pick a card from the unsorted group and put it in the right place in the sorted group.

// We start with the second element of the array as the first element is assumed to be sorted.
// Compare the second element with the first element if the second element is smaller then swap them.
// Move to the third element, compare it with the first two elements, and put it in its correct position
// Repeat until the entire array is sorted.
// Insertion-Sort--
// int main()
// {

//     // int n,  num[100];
//     // scanf("%d", &n);
//     int n = 8, num[8] = {3, 2, 1, 23, 11, 33, 0, 11};

//     // for (int i = 0; i < n; i++)
//     // {
//     //     scanf("%d", &num[i]);
//     // }

//     for (int i = 1; i < n; i++)
//     {
//         for (int j = i - 1; j >= 0; j--)
//         {
//             if(num[j] > num[j+1])
//             {
//                 int temp = num[j+1];
//                 num[j+1] = num[j];
//                 num[j] = temp;

//             }
//             else
//                 break;
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", num[i]);
//     }
//     return 0;
// }











// Take a string input from user and mention whether it is a palindrome or not.

// int main()
// {
//     char str[100];
//     scanf("%s", &str);

//     for (int i = 0; i < strlen(str) / 2; i++)
//     {
//         if(tolower(str[i])!=tolower(str[strlen(str) - i - 1]))
//         {
//             printf("The string is NOT palindrome!");
//             return 0;
//         }
//     }
//     printf("The string is a palindrome!");
//         return 0;
// }

// Getting used to structures in c

// struct yourStructure{
//     int myNum;
//     char myLetter;
// };

// int main()
// {
//     struct yourStructure mp3;
//     mp3.myNum = 420;
//     mp3.myLetter = 'B';

//     printf("my num: %d\n", mp3.myNum);
//     printf("My letter = %c", mp3.myLetter);

// }

// int main()
// {
//     int n = 4;
//     switch(n%2)
//     {
//         case 0:
//         printf("case 0\n");
//         case 1:
//         printf("case 1\n");
//         default:
//         printf("default case\n");
//     }
// }
















// Objective: Reverese a string using recursion

// void revString(char str[100], int l , int r)   // Recursion is being used to traverse half of the string without using loop - nothing fancy, just an alternative to loop. 
// {
//     if(l < r)
//     {
//         char temp = str[l];
//         str[l] = str[r];
//         str[r] = temp;
//         revString(str, l + 1, r - 1);
//     }
//     else
//     {
//         return;
//     }
// }

// int main()
// {
//     char str[100] = "Let's go";
//     revString(str, 0, strlen(str) - 1);
//     printf("%s", str);
// }





// // Convert a decimal number to hexadecimal number using recursion. 

// #include<stdio.h> 
// #include<string.h> 

// char hexDigits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

// char DecToHex(int dec, char output[100])
// {
//     if(dec/10==0)  // If the decimal value with which the function is being called is in range 0 to 9. 
//     {
//         return hexDigits[dec];
//     }
//     else
//     {
//         output[strlen(output)] =  hexDigits[dec % 16]; // strlen(output)  = size of the output string = index of the incoming hex digit. After this line, that size increases by 1. 
//         output[strlen(output)] = DecToHex(dec / 16, output); // We're trying to fill up the next unfulfilled place in the output string by the hexadecimal value of the remaining decimal value. 
//     }
// }

// int main()
// {
//     int dec = 1100;
//     char hex[100] = "";
//     DecToHex(dec, hex);
//     for (int i = strlen(hex) - 1; i>=0; i--)
//     {
//         printf("%c", hex[i]);
//     }
//         return 0;
// }








// Sum of digits of a number using recursion
//  int digitSum(int sum, int n)  // Recursion is being mainly used for traversing the number - which could be easily done with a loop. 
//  {
//      if(n==0)
//          return sum;
//      else
//          return digitSum(sum + n % 10, n / 10);
//  }

// int main()
// {
//     int n;
//     scanf("%d", &n);
//     printf("%d", digitSum(0, n));
//     return 0;
// }






// // Check palindrome number using recursion.
// int checkPalin(char str[100], int l, int r)
// {
//     if(l==r || l> r) // We are done checking the thing
//     {
//         return 1;
//     }
//     else if (str[l]==str[r]) // Still at this point, the part checked indicates it to be palindrome
//     {
//         return checkPalin(str, l + 1, r - 1);  // Mainly using recursion to traverse the string from its terminal and cutting it shorter and shorter from both sides. 
//     }
//     else // We've found at a mismatch at some index.
//     {
//         return 0;
//     }
// }

// int main()
// {
//     char num[100] = "5311221135";
//     //fgets(num, 100, stdin);
//     printf("%d", checkPalin(num, 0, strlen(num)-1));
//     return 0;
// }






// Take a string input from user and count the frequency of vowels in that string

// int main()
// {
//     char str[100];
//     fgets(str, 100, stdin);
//     //printf("%s", str);
//     int vowelCount[200] = {0};

//     for (int i = 0; i < strlen(str); i++)
//     {
//         vowelCount[str[i]]++;
//     }

//     printf(" a = %d\n e = %d \n i = %d \n o = %d \n u = %d \n", vowelCount['a'] + vowelCount['A'], vowelCount['e'], vowelCount['i'], vowelCount['o'], vowelCount['u']);

//     return 0;
// }

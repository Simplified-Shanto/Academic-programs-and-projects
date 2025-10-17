

// #include<stdio.h>
// #include<stdlib.h>

// int main()
// {
// // Allocate memory
// int *ptr;
// ptr = calloc(4, sizeof(*ptr));

// // Write to the memory
// *ptr = 2;
// ptr[1] = 4;
// ptr[2] = 6;

// // Read from the memory
// printf("%d\n", *ptr);
// printf("%d %d %d", ptr[1], ptr[2], ptr[3]);
// }

// //Memory allocation with calloc()
// #include<stdio.h>
// #include<stdlib.h>

// int main()
// {
//     int *studentID;
//     int studentNumber = 12;
//     studentID = calloc(studentNumber, sizeof(studentID));

//     for (int i = 0; i < studentNumber; i++)
//     {
//         *(studentID + i) = i;
//         printf("Student %d has id 20243310%d\n", i + 1, *(studentID + i));
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

// //Print an array in reverse order using pointer

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

// int x[3] = {5, 10, 15};

// int main()
// {
//     ++(*x);
//     printf("%d", *x);
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

// Implement the function strlen(), strcmp(), strcpy(), strcat()

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
//     for (int i = 0; i < stringlength(destination); i++)
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

// void revString(char str[100], int l , int r)
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

// char hexDigits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

// char DecToHex(int dec, char output[100])
// {
//     if(dec/10==0)
//     {
//         return hexDigits[dec];
//     }
//     else
//     {
//         output[strlen(output)] =  hexDigits[dec % 16];
//         output[strlen(output)] = DecToHex(dec / 16, output);
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
// #include<stdio.h> 

// void merge(int num[100],int l,int m,int r)
// {
//     int fp = l, sp = m + 1;
//     int temp[r-l+1];

//      int i = 0;
//      for (     ; i <r-l+1; i++)
//      {
//         if(fp <= m && sp <= r)
//         {
//             if(num[fp] < num[sp]) {  temp[i] = num[fp++]; }
//             else { temp[i] = num[sp++]; }
//         }
//         else if(fp<=m){ temp[i] = num[fp++]; }
//         else if(sp<=r)  temp[i] = num[sp++];
//     }
//      for (int i = l, j = 0; i <= r; i++, j++) {
//          num[i] = temp[j];
//          //printf("%d ", temp[i - l]);
//      }
// }


// //Implement merge sort
// void mergeSort(int num[100], int l , int r)
// {
//     if(l < r )
//     {
//         int mid = (l + r) / 2;
//         mergeSort(num, l, mid);
//         mergeSort(num, mid + 1, r);
//         merge(num, l, mid, r);
//     }
//     else
//     {
//         return;
//     }
// }

// int main()
// {
//     int n = 5;
//     int num[5] = { 23, 11, 15, 10, 9};
//     //merge(num, 0,(n-1)/2, n-1);

//     mergeSort(num, 0, n - 1);

//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", num[i]);
//     }
//     return 0;
// }

// Sum of digits of a number using recursion
//  int digitSum(int sum, int n)
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
//         return checkPalin(str, l + 1, r - 1);
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

Kassidy Maberry
2022/02/26
lab3
-----



Purposes
-----
lab3.c: calls upon array.c and prints out the stats of the given
array.

array.c: is a program that does various staticial functions on an array
including the sum, a sort and reversal, and a linear search

credit.c: is a program that gets a user input and tells the user if they gave
a valid card number.
-----



Pseudo-code
-----
Find elements greater than, less, or equal to:
-
// counts the number of elements in an array of N size
// Array is named a[] with N number of elements
list[3];
match = Z
// Z is a number being used to compare
// {less than, equal to, greater than}
for i = 1 to N
        if a[i] < Z
                list[1]++
        else if a[i] == Z
                list [2]++
        elif
                list[3]++
-
Reverse an array:
-
// a[] is an array with an N number of elements.
//tmp is a temporary variable that is meant to change.
for i = 1 to N/2
        tmp = a[i]
        a[N - i] = a[i]
        a[i] = tmp
-
Counting even terms:
-
//a[] is an array of N elements
total = 0
for i = 1 to N 
        // uses modulus to figure out if it is even or not.
        if a[i]%2 == 0
                total ++
-
Counting odd terms
-
//a[] is an array of N elements
total = 0
for i = 1 to N 
        // uses modulus to figure out if it is odd or not.
        if a[i]%2 == 1
                total ++
-
Counting divisible terms:
-
//a[] is an array of N elements with a dividor div
total = 0
for i = 1 to N 
        if a[i]%div == 0
                total ++
-
-----



Conclusion
-----
- I learned about array manipulation, sorting, and strings.

- Pair programming helped by having the original source code for credit.calls
prewritten

-I worked alone on the lab

- I encountered a problem in credit.c with printing out the string. It would
either be strange symbols or 0's. What was done is first fixed a logic error
with how it was copied to another one. In the process creating a new logic
error with its bug prevention method where it would defualt as zeros. I fixed
it by overhauling the function to not have bug prevention and work by
something more efficent.

- array.c could have some fucntions merged together making it easier to use
for multiple purposes.
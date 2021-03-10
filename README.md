# C-Programming-HW
Consists of programming modules found in starting out with C++ Tony Gladdius 5-6th edition.
This consists of content from Comp SCI II (Spring 2021 Semester)
This is also the first repository here on GitHub.

HW 2-4 is essentially refactored code based on online research.
HW 5/6 does not seem like its in the book.

HW - 2 

Write a program that lets the user enter a charge account number. The program should determine if the number if valid by checking for it in the given pre-sorted filePreview the    document using Binary Search. The numbers should be initialized into a vector (Links to an external site.).

If the user enters a number in the array, the program should display a message saying the number is valid.

If the user enters a number that is not in the array, the program should display a message indicating the number is invalid.

HW - 3

Write the following a functions:

One that accepts an ifstream and a pointer to an int array as arguments. The function should ask the user for the number of elements in said list,
create a dynamic array, and store the values from the file into it. The function should return the length of the new array.

One that accepts a pointer to an int array, and the array's size as arguments. The function should create a copy of the array, 
except that the elements should be be in reverse order in the copy. The function then returns a pointer to the new array.

Demonstrate both functions in a single program that reads numbers from a file and prints the reversed list on screen. Do not use
vectors. Remember that ifstream must be passed by reference.
 
HW - 4

Imagine you are developing a software package that requires users to enter their own package. Your software requires that users' passwords meet the following criteria:

The password should be at least six characters long.
The password should contain at least one uppercase and at least one lowercase letter.
The password should have at least one numeric digit.

Write a program that asks for a password then verifies that it meets the stated criteria. If it doesn't the program should display a message telling the user why and allow them to try again.

HW-5 (Also HW-6)

Write a program that simulates a soft drink machine. The program should use a structure that stores the following data:

   -Drink Name
   -Drink Cost
   -Number of Drinks in Machine

The program should create an array of five (5) structures. The elements should be initialized with the following data:

Each time the program runs, it should enter a loop that performs the following steps:
  1. A list of drinks is displayed on the screen, enumerated in the order they are shown.
  2. The user should be allowed to either quit the program or pick a drink by entering the number associated to each drink.
  3. If the user selects a drink that has sold out, a message should be displayed.
  4. If the drink is still available, one drink of that type is subtracted.
  5. The loop then repeats

When the user chooses to quit the program, it should display the total amount of money the machine earned.

*Did not notice if this was in the same chapter, also code is essentially cleanroom code since there are no real associated examples.

# Sorting Algorithms Analysis

This project demonstrates the implementation and efficiency analysis of four fundamental sorting algorithms: **Insertion Sort**, **Quicksort**, **Heapsort**, and **Merge Sort**. The analysis measures and compares the number of **comparisons** and **movements** for each algorithm when sorting arrays of different configurations.

---

# Project Design
This project performs an analysis of various sorting algorithms including Insertion Sort, Quick Sort, Merge Sort, and Heap Sort. By running both a random and ascending order array of 50,000 elements through each algorithm and adding the correct probing code, I was able to note how many comparisons and movements each algorithm made with the respective arrays. I implemented the algorithms in C++ using Code::Blocks. 
For this program, I began by importing three necessary header files including iostream for input/output streams, chrono class for timing for the algorithms, and alorithm class for copying arrays. Then, I initialized global variables for 4 integers: comparisons, movements, size of the array, and range for the elements in the random number array, as well as two integer arrays. After implementing the four pseudocodes for the algorithms, I tested them with a short random number array with 10 elements to test their functionality. After ensuring the algorithms worked as intended, I created an array with 50,000 random numbers ranging from 0 to 100, and ran them through each algorithm. By adding probing code, I was able to record the total number of comparisons and movements each algorithm took. I then repeated this process for an ReverseOrder array. 

---

# Challenges
I ran into two main challenges during this project. The first was during the creation of the ReverseOrder array. I wrote a short function named createInOrderArray() that made an ascending order array consisting of 50,000 elements. When I tried to apply the sorting algorithms for this array, the process was returning -1073741571 (0xC00000FD). I was able to find that this error code indicates a stack overflow in my program. I was able to fix this by changing the stack size for the program by modifying the linker settings in my project. I specifically used the code “-Wl,--stack,20971520” to increase the stack size to 20 MB. 
The next challenge I faced was for calculating the total time each algorithm took. Since I was using C++ for my code, I decided to use the chrono class to calculate the time each respective algorithm took for the ordered and random arrays. For accuracy in measurement time, I initially used nanoseconds to calculate the duration. However, upon testing the code multiple times, there were different results for each trial with the ordered array. I found that this could possibly be because of compiler optimizations, but unfortunately I could not resolve the issue by changing the compiler settings. Instead, I decided to use microseconds instead to have more accurate results.

---

# Results
After I successfully wrote my code, I ran the program one last time and noted down how much comparisons, movements, and time each sorting function took for both the inorder and random arrays. I have attached the experimental results in the next page. I boxed which functions had the most efficiency in the three categories. For a random array with 50,000 integers, Merge Sort had the most efficiency in the number of comparisons it took. Quick Sort had the least movements and approximate time it took. For the ordered array in ascending order, insertion sort took the least number of comparisons, movements, and time. In the following page, I will explain what each sorting function does, and how well each one performed for both the random and inorder arrays.

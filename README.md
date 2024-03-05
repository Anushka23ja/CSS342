<h1> LABS completed through CSS 342 course at University of Washington </h1>
<h3>LAB 1: TimeSpan </h3>
<p> 📌Learning Objective: Constructors, Operators, Stream I/O, Encapsulation and Abstraction </p>

Designed and implemented a TimeSpan class which represents a duration of time in hours, minutes,
and seconds. The order hours, minutes, and seconds should be respected in the constructor.
As an example
TimeSpan duration(1, 2, 3);
is a duration of time of 1 hour, 2 minutes and 3 seconds.

<h3>LAB 2: Recursion </h3>
<p> 📌Learning Objective: Catalan number problem, Tower of Hanoi</p>
<b>Catalan number problem</b>
<p>Wrote a program called Catalan which takes one argument and calls a recursive function which
computes the nth Catalan number. The program then prints out the result to std::out.
In this problem requires the utilization of command line arguments.
For instance,
Catalan 4
Would print out: 14
Catalan 10
Would print out: 16796
</p>

<b>Tower of Hanoi</b>
<p> Implemented a recursive algorithm for the solution of the Tower of Hanoi using n disks and using
3 rods, labeled A, B, and C. Call the function “hanoiMoves” and it has 4 input
parameters: n (number of disks), from, to, and extra. The last three are strings (A, B, C)
representing the rods. Keep track of the number of moves (counter), and the elapsed time in
microseconds. Demonstrates the moves to be taken for n=3.
The output for n=3 should have the following form (the function call in main is hanoiMoves
(3,'A', 'C', 'B')):</p>


<h3>LAB 3: </h3>
<p> 📌Learning Objective: Sorting algorithms,demonstrate the cost of O(n2) v. O(n logn) algorithms, show that algorithms with the same complexity
may have different running times </p>

<p>Wrote a program which implements the following sorts and compares the performance
for operations on arrays of integers of growing sizes (e.g., 10k, for k=1, 2, 3,...).
It is recommended that you use vectors of integers instead of arrays. The word “array” would
be used to describe a list of integers from here on.
Graph the performance of the different sorts as a function of the size of the array</p>

<h3>LAB 4: The List </h3>
<p> 📌Learning Objective: Dynamic memory, Pointers, Linked lists, File IO, templates, operator overloading, overloading, copy constructors</p>
<p> Built a class for a fully ordered list. The list class, called LinkedList, will be templatized so that
different types of objects can be stored in it.
<p>LinkedList<string> aListofStrings;</p>
<p>LinkedList<int> aListofInts;</p>
<p>LinkedList<Child> children;</p>
<p>LinkedList<MyRandomObj> myRO;</MyRandomObj</p>
</p>



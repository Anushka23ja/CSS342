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
LinkedList<string> aListofStrings;
LinkedList<int> aListofInts;
LinkedList<Child> children;
LinkedList<MyRandomObj> myRO;
The following member functions should be created for the LinkedList class. Please make sure
the signatures are exact or points will be deducted as the test programs will not compile. Also
make sure that the proper constructors/destructors are created for the class.
bool BuildList(string fileName) : Given a string which represents a file, open the file,
read the objects from file, and build an ordered list. Note that BuildList puts the responsibility
on the Object class to know how to read from a file. That is, do not have object specific logic in
the implementation. You can insert each item into the list as you read it from the file. If a list
already has items, add the new items to the list. Assume that the list passed in is well-formed
for the object being read into.
bool Insert( ItemType *obj ) : Insert an object in the list in the correct place. Return
true or false depending on whether the insert was successful. Duplicates of an object are not
allowed. If there is a duplicate the function should return false. Note that a pointer to the
object is passed in but the Insert should create a copy of the object to keep in the list.
bool Remove(ItemType target, ItemType &result): Remove the target item from the
list. Return the item using a second parameter that is passed in by reference. If the item was
found and removed return true, else return false.
bool Peek(ItemType target, ItemType &result) const: The same as Remove except the
item is not removed from the list. Again, the second item is returned by reference. Make sure
this function works correctly since it will be used frequently in testing your code.
bool isEmpty() const: Is the list empty?
void DeleteList(): Remove all items from the list. Deallocate all memory appropriately.
This includes not only the nodes in the list but the items being pointed to by the nodes.
bool Merge(LinkedList &list1): Takes a sorted list and merges into the calling sorted list
(no new memory should be allocated). At termination of function, the list passed in (list1)
should be empty (unless it is the calling list). No duplicates are allowed.
The following operators should be overloaded for the LinkedList<>. Please make sure signatures
are correct on overloads.
+, += : This should add two lists together. The lists are assumed to be sorted and the
returned list must also be sorted. Use an efficient sort algorithm and avoid unnecessary data
allocations. Duplicates are not allowed and expected.</p>



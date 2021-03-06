# Algorithms-Assignment
## Problem#1
Insertion Sort is a classical sorting technique.
As you probably already know, the algorithm can be really slow. To study this more, you want to find out
the number of times the swap operation is performed when sorting an array.<br />

Sample 1-Input:<br/>
1 1 1 2 2<br />
Sample 1-Output:<br/>
0<br/>
Sample 2-Input:<br/>
2 1 3 1 2<br/>
Sample 2-Output:<br/>
4
## Problem#2
Given an array A of integers and an integer k, you're to get the kth minimum integer in
this array.
Since the array size may be large, the array is not given as input. You've to generate it
yourself. To generate the array elements, consider this function that generates a random number:
You'll be given the initial values of m_w and m_z, and the array size N. Then you've to
call this function N times to generate the N array elements.<br/>
Input Format:
Every test case consists of 4 integers: N, K, m_w, m_z.
You can consider that N <= 10,000,000, 1 <= K <= N, 1 <= m_w,m_z <= 100.<br/>
Output Format:
For every test case print one integer: the kth minimum number<br/>

Sample 1-Input:2<br/>
3 1 1 2<br/>
Sample 1-Output:2<br/>
643275087<br/>
Sample 2-Input:2<br/>
3 2 1 2<br/>
Sample 2-Output:<br/>
692891904<br/>
## Problem#3
Given an array A of integers, you're to calculate the number of inversions in this array.
Number of inversions is the number of pairs (i,j) of array indices with i<j and A[i] > A[j] - (more info. https://www.youtube.com/watch?v=EJwR1FG8vGk)2<br/>
Input Format:
Every test case consists of two lines. The first line in N, the number of array
elements. The second line contains the array elements themselves.
You can guarantee that T <= 100, N <= 100,000 , and all array elements are
between 1 and 1,000,000,000<br/>
Output Format:
For every test case, you're to print one integer: the number of inversions.<br/>

Sample Input:<br/>
4<br/>
1 2 3 4<br/>
2<br/>
2 1<br/>
4<br/>
3 2 1 4<br/>
Sample Output:<br/>
0<br/>
1<br/>
3<br/>
## Problem#4
You have a multiset containing several integers. Initially, it contains a1 elements equal to
1, a2 elements equal to 2, ..., an elements equal to ????.
You may apply two types of operations:<br/>
??? choose two integers ???? and ???? (???????????), then remove one occurrence of ????, one occurrence of ????+1, ...,
one occurrence of ???? from the multiset. This operation can be applied only if each number from ????
to ???? occurs at least once in the multiset<br/>
??? choose two integers ???? and ???? (???????1), then remove ???? occurrences of ???? from the multiset. This
operation can be applied only if the multiset contains at least ???? occurrences of ????
What is the minimum number of operations required to delete all elements from the multiset?<br/>

Sample 1-Input:<br/>
1 4 1 1<br/>
Sample 1-Output:<br/>
2<br/>
Sample 2-Input:<br/>
1 0 1 0 1<br/>
Sample 2-Output:<br/>
3<br/>
--> Explanation of sample 1<br/>
    1 4 1 1<br/>
    a1 = number of occurrence for number 1 is 1<br/>
    a2 = number of occurrence for number 2 is 4<br/>
    a3 = number of occurrence for number 3 is 1<br/>
    a4 = number of occurrence for number 4 is 1<br/>
    This multiset equivalent to {1, 2,2,2,2, 3, 4}<br/>
    solution :<br/>
    - Use first operation from (l = 1 to r = 4) result: {2,2,2}<br/>
    - Use second operation (i = 2 and x= 3) result: {}    <br/>


## Problem#5
The worst case search time for a sorted linked list is O(n) as we can only linearly traverse the list and
cannot skip nodes while searching. For a Balanced Binary Search Tree, we skip almost half of the nodes
after one comparison with root. For a sorted array, we have random access and we can apply Binary
Search on arrays.
Can we augment sorted linked lists to make the search faster? The answer is Skip List. The idea is simple,
we create multiple layers so that we can skip some nodes.
Implement randomized SkipList insert, delete and search functions then write some test case to test
these functionalities
Create SkipList class with the following features:<br/>
??? Insert an element: skiplist.insert(num)<br/>
??? Search for an element and print the number of search steps if exists otherwise print -1<br/>
  ??? skipList.search(86) -> 3<br/>
  ??? skipList.search(16) -> 1<br/>
  ??? skipList.search(160) -> -1<br/>
??? Print number of layers<br/>
  ??? skipList.getlayers() -> 4<br/>
??? Print the numbers of certain layer ex: printLayer(int layerNum)<br/>
  ??? printLayer(1)<br/>
  ??? 2, 16 ,71, 89, 91<br/>
  ??? printLayer(4)<br/>
  ??? 16<br/>
  ??? printLayer(0)<br/>
  ??? 2,10,15,16,31,71,89,91,96<br/> 
## Problem#6 
Assume we have 2 tables Employees(ID, Name, Department) and Transactions(Sold Product, Sold By,Sold To). 
???Sold By??? in Transactions is a foreign key to ???ID??? in Employees. We would like to join the 2 tables.
Joining the 2 tables means we would like to know what each row in the Transactions table maps to in Employees table
Assuming the Employees table has N rows and Transactions M rows. We would like to build a list of size
M that maps a row in Transactions to the appropriate row in Employees. In this example we can see the
first 2 rows in map to row 0 and the last row to 1 (The appropriate indices in the table)<br/>
0<br/>
0<br/>
???<br/>
1<br/>
Usually this would entail doing a normal search through the records in both tables causing thecomplexity to be O(M * N). 
Can you propose a better way to know the joins? How would you store the tables accordingly and how would you do the search?


## Problem#7
In Computer Graphics transformations are applied on many vertices on the screen. Translation, Rotations
and Scaling.
Assume you???re operating on a vertex with 3 values (X, Y, 1). X, Y being the X Y coordinates and 1 is always
constant
A Translation is done on X as X = X + X??? and on Y as Y = Y + Y???
X??? and Y??? being the values to translate by
A scaling is done on X as X = aX and on Y as Y = bY
a and b being the scaling factors
Propose the best way to store these linear equations and an optimal way to calculate them on each
vertex. (This would need some googling to figure out or to refer to your graphics course)
Note: This doesn???t require complex code. You are free to write your thoughts and suggestions and the
answer with any code of your liking to showcase your idea.
## Problem#8
A toy factory found a defect in one of it???s equipment resulting in some toys being defective. The problem
however is that they don???t know which series of toys has that defect. Knowing that all toys are produced
in order with a special serial, propose a way to quickly find the serial number of the first defective toy.
## Problem#9
1) In this problem you are given two type of query
1. Insert an integer to the list.
2. Given an integer x, you're about to find an integer k which represent x's index if the list is sorted in ascending order. 
Note that in this problem we will use 1-based indexing.
As the problem title suggest, this problem intended to be solved using O(log2(n)) for both insertion and getting X???s index<br/>
Input<br/>
The first line contains an integer Q, which denotes how many queries that follows. The next Q lines will be
one of the type queries which follow this format:
1 x means insert x to the list
2 x means find x's index if the list is sorted in ascending order.<br/>
Output<br/>
For each query type 2, print a line containing an integer as the answer or print "-1" no quotes if the requested
number does not exist in the current list<br/>

Input Example:
10<br/>
1 100<br/>
1 74<br/>
2 100<br/>
2 70<br/>
1 152<br/>
1 21<br/>
1 33<br/>
2 100<br/>
2 21<br/>
2 1<br/>
Output:<br/>
2 -1 4 1 -1

## Problem#10 - (Extended of problem 9)
We extended previous Problem by adding extra queries:
This problem is simple. Initially, there is a list and it's empty. Then you are given four types of query.<br/>
1. Insert data to the list
2. Remove data from the list
3. Print an index (1-based) from a specified data after the list was sorted ascendingly
4. Print data from a specified index (1-based) after the list was sorted ascendingly
We want to make insertion, deletion, getting operations in O(log2(n)) <br/>
Input
Input contains several lines. Each line follows one of these formats.
1 n: Insert n (0 <= n <= 231
- 1) to the list
2 n: Remove n from the list. If n was not found, do nothing
3 n: Print n's index (1-based) after the list was sorted ascendingly
4 i: Print data on i-th index (1-based) after the list was sorted ascendingly (0 <= i <= 231- 1) 
-1: End of input<br/>
Output
For each query 3, print n's index in one line. If n was not found, just print -1
For each query 4, print data on i-th index in one line. If the index is not valid, just print -1<br/>
Example:<br/>
Input:<br/>
1 3<br/>
1 5<br/>
3 6<br/>
3 5<br/>
1 2<br/>
4 2<br/>
2 2<br/>
4 2<br/>
4 5<br/>
-1<br/>
Output:<br/>
-1<br/>
2<br/>
2<br/>
3<br/>
-1<br/>
## Problem#11
Given an array of integers, find the subset of non-adjacent elements with the maximum sum. Calculate
the sum of that subset. It is possible that the maximum sum is 0 , the case when all elements are negative.<br/>
Example<br/>
1) arr=[-2, 1, 3, -4, 5]
The following subsets with more than 1 element exist. These exclude the empty subset and
single element subsets which are also valid.<br/>

Subset Sum<br/>
[-2, 3, 5] 6<br/>
[-2, 3] 1<br/>
[-2, -4] -6<br/>
[-2, 5] 3<br/>
[1, -4] -3<br/>
[1, 5] 6<br/>
[3, 5] 8<br/>

The maximum subset sum is 8 . Note that any individual element is a subset as well.
2) arr = [-2, -3, -1]
In this case, it is best to choose no element: return 0.<br/>

Sample 1-Input:<br/>
3 7 4 6 5<br/>
Sample 1-Output:<br/>
13<br/>
Sample 2-Input:<br/>
3 5 -7 8 10 <br/>
Sample 2-Output:<br/>
15<br/>

Explanation sample 1<br/>
Our possible subsets are [3, 4, 5], [3, 4], [3, 6], [3, 5], [7, 6], [7, 5] and [4, 5].The largest subset sum is 13 from subset [7,6]
## Problem#12
We are given an array of n points in the plane, and the problem is to find out the closest pair of points in
the array. This problem arises in a number of applications. For example, in air-traffic control, you may
want to monitor planes that come too close together, since this may indicate a possible collision. Recall
the following formula for distance between two points p and q.
Euclidean distance d( p , q ) = sqrt[(qx ??? px)^2 + (qy ??? py)^2]
The Brute force solution is O(n^2), compute the distance between each pair and return the smallest. We
can calculate the smallest distance in O(nLogn) time using Divide and Conquer strategy.
## Problem#13
Given two arrays A and B, we can determine the array C = A B using the standard definition of matrix
multiplication:<br/>
The number of columns in the A array must be the same as the number of rows in the B array.
Notationally, let's say that rows(A) and columns(A) are the number of rows and columns, respectively, in
the A array. The number of individual multiplications required to compute the entire C array (which will
have the same number of rows as A and the same number of columns as B) is then rows(A) columns(B)
columns(A). For example, if Ais a array, and B is a array, it will take , or 3000 multiplications to compute
the C array.<br/>
To perform multiplication of more than two arrays we have a choice of how to proceed. For example, if
X, Y, and Z are arrays, then to compute X Y Z we could either compute (X Y) Z or X (Y Z). Suppose X is a
array, Y is a array, and Z is a array. Let's look at the number of multiplications required to compute the
product using the two different sequences:<br/>
(X Y) Z<br/>
  ??? multiplications to determine the product (X Y), a array.
  ??? Then multiplications to determine the final result.
  ??? Total multiplications: 4500.
X (Y Z)<br/>
  ??? multiplications to determine the product (Y Z), a array.
  ??? Then multiplications to determine the final result.
  ??? Total multiplications: 8750.<br/>
Clearly we'll be able to compute (X Y) Z using fewer individual multiplications.
Given the size of each array in a sequence of arrays to be multiplied, you are to determine an optimal
computational sequence. Optimality, for this problem, is relative to the number of individual
multiplications required<br/>

Sample 1-Input:<br/>
1 5<br/>
5 20<br/>
20 1<br/>
Sample 1-Output:<br/>
(A1 x (A2 x A3))<br/>
Sample 2-Input:<br/>
30 35<br/>
35 15<br/>
15 5<br/>
5 10<br/>
10 20<br/>
20 25<br/>
Sample 2-Output:<br/>
((A1 x (A2 x A3)) x ((A4 x A5) x A6))<br/>
## Problem#14
Given an unsorted integer array, find a pair with the given sum in it. We can use hashing to solve this
problem in linear time.For example,<br/>
Input:<br/>
nums = [8, 7, 2, 5, 3, 1]<br/>
target = 10<br/>
Output:<br/>
Pair found (8, 2) Or Pair found (7, 3)<br/>
Input:<br/>
nums = [5, 2, 6, 8, 1, 9]<br/>
target = 12<br/>
Output: Pair not found<br/>
## Problem#15
Given an integer array, find the minimum index of a repeating element in linear time and doing just a
single traversal of the array. We can use hashing to solve this problem in linear time. For example,<br/>
Input: { 5, 6, 3, 4, 3, 6, 4 }<br/>
Output: The minimum index of the repeating element is 1<br/>
Input: { 1, 2, 3, 4, 5, 6 }<br/>
Output: Invalid Input<br/>
## Problem#16
Given an unsorted integer array containing many duplicate elements, rearrange it such that the same
element appears together and the relative order of the first occurrence of each element remains
unchanged. For example,<br/>
Input: { 1, 2, 3, 1, 2, 1 }<br/>
Output: { 1, 1, 1, 2, 2, 3 }<br/>
Input: { 5, 4, 5, 5, 3, 1, 2, 2, 4 }<br/>
Output: { 5, 5, 5, 4, 4, 3, 1, 2, 2 }<br/>
## Problem#17
Determine MST using Prim's starting with vertex v1.
## Problem#18
The ackermann function is one of those very difficult functions to compute and it???s a prime
example of non-primitive recursive functions, meaning it can???t be de-recursed and
rewritten into a loop (Check this video for a fun watch). 
The naive recursive implementation suffers problems starting with ack(4, 1) and at the time of writing on a
machine with a 4.2GHz base CPU clock speed and 3200GHz 32GBs of DDR3 RAM is not
computable without further optimizations or settings applied.
The ackermann function is described using the equation below.
You are required to<br/>
1. Describe why the base Ackermann function is so heavy to compute<br/>
2. Write an optimization to make it???s calculation more efficient and possible for arguments starting Ack(4, 1) and above<br/>
Inputs: 2 integers m & n where m & n >= 0<br/>
Output: ack(m, n)<br/>

Sample Inputs:<br/>
3 3<br/>
4 1<br/>
Sample Outputs:<br/>
61<br/>
65533<br/>

Note: In the case you???re not able to optimize it please also submit a file with the naive
implementation describing at the very least the first step of the solution where you describe the problem with the Ackermann function itself
## Problem#19
Given an undirected weighted connected graph, find the Really Special SubTree in it. The
Really Special SubTree is defined as a subgraph consisting of all the nodes in the graph and:<br/>
??? There is only one exclusive path from a node to every other node.<br/>
??? The subgraph is of minimum overall weight (sum of all edges) among all such subgraphs.<br/>
??? No cycles are formed<br/>
To create the Really Special SubTree, always pick the edge with the smallest weight.
Determine if including it will create a cycle. If so, ignore the edge. If there are edges of equal
weight available:<br/>
??? Choose the edge that minimizes the sum u + v + wt where u and v are vertices and wt is the edge weight.<br/>
??? If there is still a collision, choose any of them.<br/>
Print the overall weight of the tree formed using the rules.
For example, given the following edges:<br/>
u v wt<br/>
1 2 2<br/>
2 3 3<br/>
3 1 5<br/>
First choose 1->2 at weight 2 . Next choose 2-> 3 at weight 3 . All nodes are connected without cycles for a total weight of 3 + 2 = 5.
Function Description<br/>
Complete the Kruskals function in the editor below. It should return an integer that
represents the total weight of the subtree formed.
kruskals has the following parameters:<br/>
??? g_nodes: an integer that represents the number of nodes in the tree<br/>
??? g_from: an array of integers that represent beginning edge node numbers<br/>
??? g_to: an array of integers that represent ending edge node numbers<br/>
??? g_weight: an array of integers that represent the weights of each edge<br/>
Input Format<br/>
The first line has 2 space-separated integers g_nodes and g_edges the number of nodes and
edges in the graphs
The next g_edges line each consists of 3 space-separated integers g_from, g_to and g_weight,
where g_from and g_to denote the 2 nodes between which the undirected edge exists and
g_weight denotes the weight of the edge.<br/>
Output Format<br/>
Print a single integer denoting the total weight of the Really Special SubTree.<br/>

Sample input:<br/>
4 6<br/>
1 2 5<br/>
1 3 3<br/>
4 1 6<br/>
2 4 7<br/>
3 2 4<br/>
3 4 5<br/>
Sample Output<br/>
12<br/>
## Problem#20
Given a set of activities and the starting and finishing time of each activity, find the
maximum number of activities that can be performed by a single person assuming that a person can only work on a single activity at a time.
This problem is called the activity selection problem, which concerns the selection of
non-conflicting activities to perform within a given time frame, given a set of activities each marked by a start and finish time.<br/>
Input:<br/>
{1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}<br/>
Output:<br/>
{1, 4}, {5, 7}, {8, 11}, {12, 14}
## Problem#21
Given an array of size n such that each element contains either a 'P' for policeman or a 'T'
for thief. Find the maximum number of thieves that can be caught by the police.
Keep in mind the following conditions :<br/>
1. Each policeman can catch only one thief.<br/>
2. A policeman cannot catch a thief who is more than K units away from him.<br/>
Example 1:<br/>
Input:<br/>
N = 5, K = 1<br/>
arr[] = {P, T, T, P, T}<br/>
Output: 2<br/>
Explanation: Maximum 2 thieves can be caught. First policeman catches the first thief and
the second policeman can catch either the second or third thief.<br/>

Example 2:<br/>
Input:<br/>
N = 6, K = 2<br/>
arr[] = {T, T, P, P, T, P}<br/>
Output: 3<br/>
Explanation: Maximum 3 thieves can be caught.


## Problem#22
There are n smtp servers connected by network cables. Each of the m cables connects two
computers and has a certain latency measured in milliseconds required to send an email
message. What is the shortest time required to send a message from server to server along a
sequence of cables.<br/>
Input<br/>
The first line of input gives the number of cases, N. N test cases follow. Each one starts with a
line containing n (number of servers), m (number of route), S (source) and T(destination). S != T.
The next m lines (routes) will each contain 3 integers: 2 different servers (in the range [0, n-1])
that are connected by a bidirectional cable and the latency (w)<br/>
Output<br/>
For each test case, output the line Case #x:, followed by the number of milliseconds required to
send a message from S to T. Print ???unreachable, if there is no route from S to T<br/>

Sample Input<br/>
3<br/>
2 1 0 1<br/>
0 1 100<br/>
3 3 2 0<br/>
0 1 100<br/>
0 2 200<br/>
1 2 50<br/>
2 0 0 1<br/>
Sample Output<br/>
Case #1: 100<br/>
Case #2: 150<br/>
Case #3: unreachable<br/>
## Problem#23
Alice wants to send an important message to Bob. Message a = (a1, ..., an) is a sequence of
positive integers (characters).<br/>
To compress the message Alice wants to use binary Huffman coding. We recall that binary Huffman
code, or binary prefix code is a function f, that maps each letter that appears in the string to some
binary string (that is, string consisting of characters '0' and '1' only) such that for each pair of
different characters ai and aj string f(ai) is not a prefix of f(aj) (and vice versa). The result of the
encoding of the message a1, a2, ..., an is the concatenation of the encoding of each character, that
is the string f(a1)f(a2)... f(an). Huffman codes are very useful, as the compressed message can be
easily and uniquely decompressed, if the function f is given. Code is usually chosen in order to
minimize the total length of the compressed message, i.e. the length of the string f(a1)f(a2)... f(an).
Because of security issues Alice doesn't want to send the whole message. Instead, she picks some
substrings of the message and wants to send them separately. For each of the given substrings ali...
ari she wants to know the minimum possible length of the Huffman coding. Help her solve this problem.<br/>
Input:<br/>
The first line of the input contains the single integer n (1 ??? n ??? 100 000) ??? the length of the initial
message. The second line contains n integers a1, a2, ..., an (1 ??? ai ??? 100 000) ??? characters of the
message.<br/>
Next line contains the single integer q (1 ??? q ??? 100 000) ??? the number of queries.
Then follow q lines with queries descriptions. The i-th of these lines contains two integers li and ri
(1 ??? li ??? ri ??? n) ??? the position of the left and right ends of the i-th substring respectively. Positions
are numbered from 1. Substrings may overlap in any way. The same substring may appear in the
input more than once.<br/>
Output:<br/>
Print q lines. Each line should contain a single integer ??? the minimum possible length of the
Huffman encoding of the substring ali... ari.<br/>

Example:<br/>
Input:<br/>
7<br/>
1 2 1 3 1 2 1<br/>
5<br/>
1 7<br/>
1 3<br/>
3 5<br/>
2 4<br/>
4 4<br/>
Output:<br/>
10<br/>
3<br/>
3<br/>
5<br/>
0<br/>
Note: ??? In the first query, one of the optimal ways to encode the substring is to map 1 to "0", 2 to "10" and 3 to "11".<br/>
      ??? It is correct to map the letter to the empty substring (as in the fifth query from the sample)
## Problem#24
Given an array of jobs where every job has a deadline and associated profit if the job is finished
before the deadline. It is also given that every job takes a single unit of time, so the minimum
possible deadline for any job is 1.<br/>
How to maximize total profit if only one job can be scheduled at a time. Time Complexity
less than exponential.<br/>

Examples:<br/>
Input:<br/>
Four Jobs with following deadlines and profits:<br/>
JobID Deadline Profit<br/>
a 4 20<br/>
b 1 10<br/>
c 1 40<br/>
d 1 30<br/>
Output:<br/>
Following is maximum profit sequence of jobs:<br/>
c, a<br/>

Input:<br/>
Five Jobs with following deadlines and profits:<br/>
JobID Deadline Profit<br/>
a 2 100<br/>
b 1 19<br/>
c 2 27<br/>
d 1 25<br/>
e 3 15<br/>
Output:<br/>
Following is maximum profit sequence of jobs:<br/>
c, a, e<br/>

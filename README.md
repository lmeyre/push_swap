# push_swap
push_swap project is about sorting list. It is very simple to understand and also look simple. There is a limited amount of possible action to apply on the list to sort it. Those limited possibility make it impossible to use well know and effective algorithm already created. 

The goal is to create one or many complex sorting algorithm to sort the list with the imposed move you can do. Sorting is easy, but using the optimal amount of action to do it isn't.

At the start, there is two list, list A is filled with the number you put as arguments, the list B is empty and used to perform our possible action on the lists. The goal is to end with A sorted.

**Usage**

To build:

```bash
$ make
```

To execute:

```
$ ./push_swap 6 1 78 92 34
```
This an example, you can put any list of number, but there shouldn't be any duplicate.

All possible actions:

  sa : swap the two first elements on top of pile A, doesn't do anything if there one or zero element in A.
 
  sb : swap the two first elements on top of pile B, doesn't do anything if there one or zero element in B.
  
  ss : sa & sb in one action.
  
  pa : take the first element of B and put it on top of A. Doesn't do anything if B is empty.
  
  pb : take the first element of A and put it on top of B. Doesn't do anything if A is empyt.

  ra : move every element of A one step above, the first element become the last, the 2nd become the first, etc.
  
  rb : move every element of B one step above, the first element become the last, the 2nd become the first, etc.

  rr : ra & rb in one action.
  
  rra : move every element of A one step lower, the first element become 2nd, the last become first, etc.
  
  rrb : move every element of B one step lower, the first element become 2nd, the last become first, etc.
  
  rrr : rra & rrb in one action.
  
  Note that every step that doesn't do anything in certain case will still trigger if they doesn't do anything, and add to the total amount of action the algorithm needed to sort the list.



Output:

The output will look like this

```
pb
pb
rra
rb
pa
pa
```
The program output is every action applied to the list of number. If the program is used with a sorted list or no list, it will exit.

Options:

-a : Will add the number of action the algorithm needed to sort the list.

usage : ./push_swap -a 6 1 78 92 34

-v : Will display the state of each list, after each action the algorithm called.

usage : ./push_swap -v 6 1 78 92 34

multiple options should be used like this : ./push_swap -a -v 6 1 78 92 34

Note :

The programm checker is made to verify that push_swap worked, but i already included it to push_swap, wich will display ERROR if push_swap fail to sort the list, wich will never happen.
You can use it like this :

```
./push_swap  6 1 78 92 34 | ./checker 6 1 78 92 34
```

There shouldn't be any push_swap option while using push_swap with checker, as checker will read the step made by push_swap to apply it to his list, and verify that it end up sorted. Both list of push_swap and checker must be the same.

For more informations you can look to the subject.fdf
 

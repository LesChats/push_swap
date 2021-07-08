Simple but sufficient "insert sort" style push_swap for 42 school.

# Algorithm

Update: The algorithm is decomposable in two main algorithm ; One based on "insertion sort" that operate on stack with size between 5 and 350, and another one
based on "quicksort" or at least over the idea of "partition" that operate on stack with size 350 and more.

The first algorithm work's like that:

1) Convert the input into a "stack". stack is implemented as a very simple double-linked list.

2) The slicing part:
  
    
    The goal here is to identify the biggest "already sorted sequence in the stack" considering that we can push bad elements into stack B.


3) The insert part:
  
    taking the elements pushed to stack B one by one we push them back to stack A in their expected final place as effectively that we can.
    
    
    
 The secound algoritm work's like that:
 
 1) "Normalize" the array, i.e converte any array to is "equivalent" array in rage \[0, n] ex : {0 3 1 -1 19} -> {1 3 2 0 4}
 2) Partion Stack A using is median; in A every element greather thant the median, in B every element smaller thant the median
 3) While Stack B is not empty Partion B using is median and reordering A if needed the goal is to start ordering smallest elements at the botom of A:  
    | 19  
    | 45  
    | _  
    | 2  
    | 1  
    | 0  
 5) Stack B is now empty. Partion Stack A again but ony the greater / non-sorted half
 6) Patitonning B again, at the End if B is we can find the next bottom element in B go back to step (3) else...
 7) Either the array is sorted or the next bottom element of the stack is somewhere in A in is greater / non sorted half. Push all this part in B and go to (5)
 8) The array is sorted --> stop

    
 I may try to add more detail about how the algorithm works in the future, but that was the general idea, in the meantime, just ask me.
  (abaudot)

# Result

Doing 500 random sample test: (cf tester)


**100 elements in stack**
- average:  541
- max:      621

**500 elements in stack**
- average:  4873
- max:      4982

# How to improve this work

~~As the structure of my src file reveal's as was originally planning to implement a different algorithm for a stack containing more than 300 elements~~

~~Something inspired by _**quicksort**_ should be able to be much more effective when dealing whit bigger stacks.~~

~~Too bad, discovering that y was already meeting the requirement for the maximum mark I didn't find the motivation to go for better performance.~~  

Update: I've done this. I Still can improve the algorhim for small (size < 6) stack's Today the maximum operation for 5 elements stack is 10.  
# Bonus

make bonus

and you get a checker

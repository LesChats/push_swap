Simple but sufficient "insert sort" style push_swap for 42 school.

# Algorithm

The algorithm work's like that:

1) Convert the input into a "stack". stack is implemented as a very simple double-linked list.
2) The slicing part:
  The goal here is to identify the biggest "already sorted sequence in the stack" considering that we can push bad elements into stack B.
3) The insert part:
  taking the elements pushed to stack B one by one we push them back to stack A in their expected final place as effectively that we can
  
 I may try to add more detail about how the algorithm works in the future, but that was the general idea, in the meantime, just ask me.
  (abaudot)

# Result

Doing 500 random sample test: (cf tester)


**100 elements in stack**
- average:  541
- max:      621

**500 elements in stack**
- average:  5050
- max:      5470

# How to improve this work

As the structure of my src file reveal's as was originally planning to implement a different algorithm for a stack containing more than 300 elements

Something inspired by _**quicksort**_ should be able to be much more effective when dealing whit bigger stacks.

Too bad, discovering that y was already meeting the requirement for the maximum mark I didn't find the motivation to go for better performance.

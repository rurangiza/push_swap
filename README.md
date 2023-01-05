# push_swap [work in progress]

> A program that sorts data on a stack with specific constrains

<img src="./assets/quicksort_anim.gif" width="100%" alt="Animation of a sorting algorithm"/>

## 🚫 Constrains
### ~ in structure 
We receive a list of unordered numbers and we have to sort them with the least operations possible.
- **2 stacks** : for the sorting, we have 2 stacks at our disposal. At the beginning, all numbers are on stack A abd stack B is empty. We can use stack B as temporary storage but after the sorting all numbers must be back in stack A. It's also worth noting that the stack must be created and can be a data structure of our choosing (array, linked-list,...)
- **11 possible operations**: the only operations we can perform to sort the numbers are the following:
    - <code>pa</code>, <code>pb</code> : pushing the value at the top of stack_A to the the top of stack_A or the inverse
    - <code>sa</code>, <code>sb</code>, <code>ss</code> : swapping the first two values at the top of stack_A, stack_B or both
    - <code>ra</code>, <code>rb</code>, <code>rr</code> : sending the value at the bottom of stack_A, stack_B or both at the bottom
    - <code>rra</code>, <code>rrb</code>, <code>rrr</code> : sending the value at the bottom of stack_A, stack_B or both over their top
### ~ in performance
Depending on the size of the list, the program must be below a certain number of operations:
- For a list of **3 numbers**: we need to sort it with not more than 3 instructions
- For a list of **5 numbers**: we need to sort it with not more than 12 instructions
- For a list of **100 numbers**:
    - 5 points if the size of the list of instructions is less than 700
    - 4 points if the size of the list of instructions is less than 900
    - 3 points if the size of the list of instructions is less than 1100
    - 2 points if the size of the list of instructions is less than 1300
    - 1 points if the size of the list of instructions is less than 1500    
- For a list of **500 numbers**:
    - 5 points if the size of the list of instructions is less than 5500
    - 4 points if the size of the list of instructions is less than 7000
    - 3 points if the size of the list of instructions is less than 8500
    - 2 points if the size of the list of instructions is less than 10000
    - 1 points if the size of the list of instructions is less than 11500

## 📝 Implementation
### ~ Storing the numbers in a doubly-linked list
Check if the numbers are valid, two ways of receiving numbers, storing in matrix, why a doubly-linked list, figma for visualizations especially for operations (pa, ra, sa,...)
### ~ Handling lists of size 3
### ~ Handling lists of size 5
### ~ Handling lists of size 100
For larger lists, I chose the quicksort algorithm. It has an average time complexity of __n*log(n)__

How quicksort works ->

1. Finding the pivot:
The ideal pivot will seperate your list in half.
To do so, I wrote a function <code>__find_pivot__</code> which calculates the average of all numbers of the list then finds in the list the closest number to that average, which becomes the pivot. 
It works perfectly when the list contains numbers close to each other or seprated evenly, but when there are multiple numbers close to each other and a few that are bigger, the function doesn't seperate the list quite as well. 
Ex:

```C
int list_A[] = {12, 4, 6, 1, 8, 18, 10}; // 6 is the pivot

int list_B[] = {12, 4, 6, 1, 8, 1801, 244}; // 244 is the pivot
```

2. Partitioning: 
> In computer science, partitioning refers to the division of a computer's hard drive, or other data storage device, into separate areas where data can be stored. These separate areas are called "partitions."
Key terms: partitioning, pivot, D&C (Devide and Conquer)

## ~ Optimizations
- Check if partitions are sorted before feeding them to the recursive quicksort algorithm. This logic cut in half the operations needed to sort the stack, from 10,000 to 5,000

## 💡 Learnings

- Sorting algorithms
- Big O notation and complexity in algorithms
- Data structure: implementing and manipulating a doubly-linked list

## 🫡 Final thoughts

# Notes


## Optimizations
### ~ Handle 100 numbers
- 10000 -> 5000 : before calling the quicksort algorithm recursively, I added a condition that check whether the list is already sorted, if it's the case, I stop there
- 5000 -> 2500 : added a function that replaces quicksort when the list has less then 50 elements in it. That function pushes all elements to stack_b, and once they're all there, pushes them back to stack_b from largest to smallest
    - after every push to stack_b, swap top of stack_b to keep largest numbers on top (if its top element is smaller than the second from the top)
        for a list of 20 numbers, 134 op -> 112 op
    - before pushing to stack_b, swap top of stack_a top to have the smallest go first (if its top element is bigger than the second from the top)
- 2500 -> 2300 : improved the pivot selection. Before I was using the "middle of three" method but since the exercice only care about the required operations, I wrote a function that find the exact median of every list by sorting it first in an array, then cutting the index in half and return the number that is at that position
- 1300 -> 1100 : after I pushed all numbers smaller than the pivot to stack_b, instead of simply pushing them back from top to bottom to stack_a, I pushed the largest numbers first. That way, when they get to stack_a, they're already sorted
    - move_pivot_ontop() : check whether it's closer to the top or bottom, and do ra or rra based on that
- 1100 -> 950 : removed an extra step when partinioning. In the first iteration of quicksort, after I found the pivot, I would send every number smaller than the pivot to stack_b with the pb function, and the other numbers would be sent to the bottom of stack_a, then repositioned at the top of stack_a. That last step was useful when I called the quicksort algorithm multiple times but since I only use if once, to cut the list in two, then I use selection sort, than that last step was not necessary.
- 950 -> 750 : rewrote the function that sort 100 numbers. Here is how it works: 
    1. I push all numbers of stack_a to stack_b leaving only 5. I do that by finding the median, pushing everything below that median to stack_b, repeating this action until there is only 5 numbers in stack_a.
    2. Then I sort the 5 remaining numbers with handle_5(). 
    3. And finaly, I push all numbers in stack_b to stack_a (largest first).
- 750 -> 725 (best < 700) : instead of using a median as pivot, I'm using a quartile (number that seperates a list of numbers in 4 equal parts)
- 725 -> 690 (average) : remove the piece of code that "pushes pivot instead of last pushable". It was useless and added unecessary operations

### ~ Handle 500 numbers
Using the same algorithm as the one for 100 numbers, I got 7913 operations (average of 5).
- 7913 -> 6998 : use octile as pivot until the size of stack_a falls below 100. At that point, I use quartiles as pivots. 

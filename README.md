# push_swap

### A program that sorts data on a stack with specific constrains

## 🚫 Constrains
### ~ in structure 
We receive a list of unordered numbers and we have to sort them with the least operations possible.
- 2 stacks : for the sorting, we have 2 stacks (stack A and stack B) at our disposal. They can be an array or a linked list
- 11 operations: the operations we can perform to sort the numbers are the following:
    - Pushing the topmost value of a stack to the next stack ( pa, pb )
    - Swapping both topmost values of stack a, stack b or both ( sa, sb, ss )
    - Rotating the topmost value of stack a, stack b or both under their bottom ( ra, rb, rr )
    - Rotating the bottommost value of stack a, stack b or both over their top ( rra, rrb, rrr )
### ~ in performance
Depending on the size of the list, the program must be below a certain number of operations:
- For a list of 3 numbers: we need to sort it with not more than 3 instructions
- For a list of 5 numbers: we need to sort it with not more than 12 instructions
- For a list of 100 numbers:
    - 5 points if the size of the list of instructions is less than 700
    - 4 points if the size of the list of instructions is less than 900
    - 3 points if the size of the list of instructions is less than 1100
    - 2 points if the size of the list of instructions is less than 1300
    - 1 points if the size of the list of instructions is less than 1500    
- For a list of 500 numbers:
    - 5 points if the size of the list of instructions is less than 5500
    - 4 points if the size of the list of instructions is less than 7000
    - 3 points if the size of the list of instructions is less than 8500
    - 2 points if the size of the list of instructions is less than 10000
    - 1 points if the size of the list of instructions is less than 11500

## 📝 Implementation

## 💡 Learnings

- Learn about sorting algorithms
- Learn about big O notation and complexity in algorithms
- Data structure: implementing a doubly-linked list

## 🫡 Final thoughts

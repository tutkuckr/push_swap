# push_swap

#### Used Algorithm: Turk Algorithm

## Goals
The aim of the project is to test the understanding of various sorting algorithms, their corresponding complexities and data structures, and the ability to implement this in code.

```sh
make
./push_swap 24 -1 5673 -298 69 420
```

## Instructions
To sort the input arguments, the Push Swap program uses two stacks (Stack A and B) and a set of allowed operations. It starts with all the numbers in stack A, and an empty stack B. The allowed operations include:

* ```sa:``` swap a - swap the first two elements of stack A
* ```sb:``` swap b - swap the first two elements of stack B
* ```ss:``` swap both - swap the first two elements of both stacks A and B
* ```pa:``` push a - take the first element from stack B and put it on top of stack A
* ```pb:``` push b - take the first element from stack A and put it on top of stack B
* ```ra:``` rotate a - shift all elements of stack A up by one. The first element becomes the last one
* ```rb:``` rotate b - shift all elements of stack B up by one. The first element becomes the last one
* ```rr:``` rotate both - rotate both stacks A and B at the same time
* ```rra:``` reverse rotate a - shift all elements of stack A down by one. The last element becomes the first one
* ```rrb:``` reverse rotate b - shift all elements of stack B down by one. The last element becomes the first one
* ```rrr:``` reverse rotate both - reverse rotate both stacks A and B at the same time

The goal is to sort the integers in Stack A in ascending order, using only the allowed moves listed above in the least amount of moves. The program will write each executed move to the STDOUT followed by a '\n. After running push swap, Stack A should be sorted and Stack B empty.

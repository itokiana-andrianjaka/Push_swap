*This project has been created as part of the 42 curriculum by tiana-an, trakotoz.*

# Push_swap
> Because Swap_push doesn’t feel as natural.

## Description

push_swap is an algorithmic project that involves sorting a list of integers using two stacks and a limited set of predefined instructions.

> The objective is to obtain the sequence sorted in ascending order with the minimum possible operations, optimizing the complexity and the sorting strategy.

### Project objectives

-   Implement an efficient sorting algorithm.

-   Handle two batteries (a and b) with specific operations.

-   Generate the shortest sequence of instructions possible.

-   Manage errors (duplicates, invalid characters, int overflow / underflow, no arguments)

### Authorized operations

-   `sa` / `sb`: swap the first two elements of the a/b stack

-   `ss`: sa and sb at the same time

-   `pa` / `pb`: push from b to a / from a to b

-   `ra` / `rb`: upward rotation

-   `rr`: ra and rb at the same time

-   `rra` / `rrb`: downward rotation

-   `rrr`: rra and rrb at the same time.

## Team Contributions

### tiana-an
- Implementation of stack operations (`sa`, `sb`, `ra`, `rra`, etc.)
- Development of the medium and adaptive strategy (`chunked_based_sort`)
- Participation in the design of `minmax_sort`
- Co-development of `compute_disorder`

### trakotoz
- Error handling and argument parsing
- Implementation of the complex strategy (`radix_lsd_sort`)
- Benchmark implementation and performance testing
- Participation in the design of `minmax_sort`
- Co-development of `compute_disorder`

> The simple strategy (**minmax_sort**), the disorder computation logic and the remaining implementation details were designed and implemented collaboratively.

## Instruction
The compilation is done using a **`Makefile`** with the `cc` compiler followed by the following flags:  
- `-Wall`: main warnings;  
- `-Wextra`: additional warnings;  
- `-Werror`: turns warnings into errors.

The Makefile includes the following rules: $(NAME), all, clean, fclean, and re.

-   Build:
```bash
    make
    # or
    make all
```
Compiles the project and generates the executable: **push_swap**.

---
-   Clean object files:
```bash
    make clean
```
Removes all compiled object files (.o).

---
-   Full clean:
```bash
    make fclean
```
Removes all object files (.o) as well as the generated library libft.a.

---
-   Rebuild:
```bash
    make re
```
Performs a complete rebuild of the project (equivalent to fclean followed by all).

---
### This is an usage example:
***Compilation***:
```bash
    make
```
***run the executable***:
```bash
    ARG="4 67 3 87 23"; ./push_swap --simple $ARG
```

### Program Behavior
When executing the program, it will output the list of instructions required to sort the given stack.

> If an error condition is detected, the program will instead display: **"Error"**.

## Resources
The following resources were helpful for understanding sorting algorithms, stack operations, and optimization strategies:

-   [Sorting Algorithms — Visualgo](https://visualgo.net/en/sorting)
-   [Youtube/push_swap tutorial](https://www.youtube.com/watch?v=4dMsuxfqufg&t=23s)
-   [PUSH_SWAP VISUALIZER](https://push-swap42-visualizer.vercel.app/)
>***AI usage:***  
    AI tools were used solely for conceptual explanations and learning support. The design, implementation, and final code were developed independently.

## Algorithm Selection and Justification
>**`1/`** Simple Algorithm — O(n²)

-   Method: Min/Max Extraction Strategy

    For small datasets or nearly sorted inputs, a simple selection-based approach is used.

-   The algorithm repeatedly:

    Finds the minimum (or maximum) value in stack A

    Pushes it to stack B

    Restores the sorted order back to stack A

-   **Justification**:

    Easy to implement and highly reliable

    Efficient for small input sizes

    Low overhead in instruction management

    Suitable when the disorder level is very low

    Although its theoretical complexity is O(n²), it performs well when the dataset is small or almost sorted.

---
>**`2/`** Medium Algorithm — O(n√n)

-   Method: Chunk-Based Sorting (√n chunks)

    For moderately sized datasets, the stack is divided into approximately √n chunks based on indexed values.

-   The algorithm:

    Pushes elements chunk by chunk from A to B

    Organizes elements strategically in B

    Pushes them back to A in sorted order

-   **Justification**:

    Reduces unnecessary rotations

    Balances instruction count and execution time

    More efficient than quadratic methods for medium inputs

    Chunking significantly reduces total operations compared to naive selection strategies.

---
>**`3/`** Complex Algorithm — O(n log n)

-   Method: Radix Sort Adaptation (LSD or MSD)

    For large datasets, a binary radix sort adaptation is used.

-   Steps:

    Normalize values through indexing

    Sort numbers bit by bit

    Use stack operations to simulate bucket distribution

-   **Justification**:

    Deterministic performance

    Highly scalable

    Well-suited for push_swap constraints

    Efficient instruction count for large n

    Radix sort ensures predictable O(n log n) complexity within the stack-based operation model.

---
>**`4/`** Custom Adaptive Algorithm — Disorder-Based Strategy

A custom adaptive strategy was designed to dynamically select the most appropriate internal algorithm depending on the measured disorder level of the input.

-   Disorder Measurement

    Disorder is evaluated as the ratio of misplaced elements relative to the total size.
---

## Bonus – Checker (push_swap)

>Objective:

-   The bonus consists of implementing a checker program that:

    Takes a list of integers as arguments (same as push_swap)

    Reads a sequence of instructions from standard input (stdin)

    Applies these instructions to the stacks

    Checks whether the stack is correctly sorted at the end

>Compilation:
To compile the bonus part, as the `push_swap` project, we use `Makefile`:
```bash
    make bonus # This will generate the checker
```

>Implementation Method:

**`1`** Reading Instructions

We use:

get_next_line(0);  
***0 corresponds to standard input (stdin)***

Each line read represents one instruction (sa, pb, ra, etc.)

Each instruction is validated and applied immediately

---
**`2`** Applying Instructions

For each instruction read:

-   We compare it with the list of valid instructions

-   If valid → apply it to stack_a and/or stack_b

-   If invalid → display Error and exit

-   Supported instructions:

```
sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr
```
---

**`3`** Final Checks

After executing all instructions, we perform the following checks:

- Stack A must be sorted in ascending order  
    If not sorted → KO

- Stack B must be empty  
    If stack_b still contains elements → KO

- Stack A must not be empty  
    If stack_a is NULL → KO
---

>Validation Logic

-   Pseudo-algorithm:

    Read instructions using get_next_line  
        -> Validate instruction  
        -> Apply instruction `(Final checks)`
---

>Example Usage

```bash
./push_swap 3 2 1 | ./checker 3 2 1
```

Expected output:  
**OK**

>Data Structures

We use:

Two linked list stacks (stack_a and stack_b)  
An is_sorted() function to check ascending order  
Dedicated functions to apply each instruction

>Summary

Our checker:

- Reads instructions from stdin  
- Applies them sequentially  
- Verifies:  
    stack_a is sorted  
    stack_b is empty  
    Prints OK or KO
---

>***Project completed in accordance with 42 School standards.***

*This project has been created as part of the 42 curriculum by trakotoz.*

# ft_printf: Because ft_putnbr() and ft_putstr() aren’t enough

## Description :
`ft_printf` is a project that can be described as fun but in other way painful.
Reproducing and reimplementing the legendary `printf` behavior in the standard library of the C programming language.
This project uses the library `libft`.

### Prototype:
`ft_printf` reproduces a subset of the behaviro of the standard `printf`, printing the in the "standard output" or `stdout` knowing as 'file_descriptor = 1'.
- Prototype: 
```c
int  ft_printf(const char *format, ...);
```
So, the function return an integer representing the number of character printed. Taking as parameter multiple argument, result of using the library `<stdarg.h>`.
`format`, type string, must be entered, and the conversion of printing the other argument start after the program have found the character `%`.

### How does it work?
After the program find the specific character `%`. It start the conversion by evaluating the next character.
`ft_printf` manage this type of conversion:
- 'c': print char.
- 's': print 'char *' or string.
- '%': special case, if after the '%' it's still a '%' then it print '%'.
- 'd' and 'i': this two conversion type have the same behavior, printing number ('d' for decimal and 'i' for integer), but it's the same.
- 'u': it print number too, but a little special with, only unsigned number.
- 'x' and 'X': the famous hexadecimal output, taking data type 'unsigned int' and printing it's value as hexadecimal, 'x' then lowercase and 'X' uppercase.
- 'p': it take `void *` data type, and print it's address in the memory.

This assume that the next argument if the same as the conversion type and print it to the stdout.
=> If an unsupported conversion is encountered, the behavior is undefined (as specified by C standard).

### Bonus part
We have talk about the mandatory part, now let's take a look about the bonus part.
Mandatory part manage conversion, bonus part manage flags and elegant printing.
After the special character '%', before the conversion can be other character called flags.
There are 6 flags:
- digit: specifies the minimum field width.
- '-' : left-aligns the output within the given field width.
- '0' : the two above fill with space, this one fill with the '0' character, execpted it's ignore whene '-' is already there.
- '.' : precision, the painful one, the one manage the number of character printed using the value after '.'.
- '#' : adding `0x` or `0X` in front of the hexadecimal value.
- ' ' : print space is the number is positive.
- '+' : always print sign for positive numbers.

## Instructions :
This project is a library, compile with Makefile (that you can find in the root of the project), so it can be manipulated but the command `make`:

1. Installation:
To create the library `libftprintf.a`:
```bash
    # This two have exactly the same functionality
    make
    make all
```
2. Cleaning:
When compiling the project, it create several binary file `.o` and the library itself `libftprintf.a`.
You can clean it using:
```bash
    make clean      # Remove every .o files
    make fclean     # Remove every .o files and the library too `libftprintf.a`
```
3. Rebuild:
The Makefile can fully clean and rebuild the program for you, just do
```bash
    make re
```
4. Bonus:
For the bonus part, you can compile it with:
```bash
    make bonus
```
Everything else stay the same.

5. Help library:
=> This project use an external library `libft`, all the command above already manage the compilation of it.

## Resources :
Creating this project is not done if there is no helper.
- A little of Linus manual page : man printf.
- [Geeks for geeks](https://www.geeksforgeeks.org/c/printf-in-c): This the main helper, help on understanding how printf work.
- [C-Cpp-Reference](https://documentation.help/C-Cpp-Reference/printf.html)
- AI too for bringing lesson and explanation about some functionality.

### AI usage
AI was use in this project, not by creating the project, but to giving lesson and explanation about some functionality and execpted bahavior.
- ChatGPT
- ClaudeAI

## Detailed explanation and justification of the chosen algorithm and data structure :
The project follow a rule to display and returning the argument.
Some function is modified inside the `ft_printf` project to return the exact value of the displayed character, the library `libft` stay untouched.
So everything is printed as their primary data type:
- int printed as int
- char printed as char
- string printed as string
for 'xXp', they are printed as string after the conversion to the exact execpted value.

### Algorithm used:
The algorithm used in this project is likely a parsing strategy using a count variable to stock the value of printed character:
- Loop through format, character by character
- If no special character '%' found, print character and count + 1
- If '%' found then manage print with the specified conversion
- If the conversion match then take the next argument and print it, return the count value
- If not, then undefined behavior as the true `printf` do
- Return count

Ex: ft_printf("Hello %s, number = %d\n", "world", 42); => Hello world, number = 42

### Algorithm used (bonus part):
The Bonus part behave exactly the same, just that instead of handling the argument immediatly it parse the flags before, so:
- If '%' found, parse the flags and stock it
- If no more flags, evaluate if the actual character is a conversion character
- If yes then printf the value matching with the format
- If not then it can be an undefined behavior, for the case of Clang or GCC it print the value but still an undefined behavior
- Then manage print with specified conversion and the flags with it.
- Return count

Ex: ft_printf("Hello %.3s, number = %05d\n", "world", 42); => Hello wor, number = 00042

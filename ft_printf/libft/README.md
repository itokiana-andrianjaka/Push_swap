*This project has been created as part of the 42 curriculum by trakotoz.*

# LIBFT : Very first own library

## Description

`Libft` is a project in the 42 curriculum based on the C programming language.
This project is a custom of the C standard library that create and enhance some C functions.
The goal of this project is to have a deep and better understanding of the memory management,
list management, string manipulation, pointer and algorithmic thinking in C.
This library provides a collections of functions that can be reused in other projects:
```
    ft_isalpha        ft_isdigit          ft_isalnum      ft_isascii 
    ft_isprint        ft_strlen           ft_memset       ft_bzero
    ft_memcpy         ft_memmove          ft_strlcpy      ft_strlcat
    ft_toupper        ft_tolower          ft_strchr       ft_strrchr
    ft_strncmp        ft_memchr           ft_memcmp       ft_strnstr
    ft_atoi           ft_calloc           ft_strdup       ft_substr
    ft_strjoin        ft_strtri           ft_split        ft_itoa
    ft_strmapi        ft_striteri         ft_putchar_fd   ft_putstr_fd
    ft_putendl_fd     ft_putnbr_fd        ft_lstnew       ft_lstadd_front
    ft_lstsize        ft_lstlast          ft_lstadd_back  ft_lstdelone
    ft_lstclear       ft_lstiter          ft_lstmap
```
This can be serve as a fundation for more complexe developpement tasks.


## Instructions

### Compilation

The project uses `Makefile` for automate compilation.
Go to the root of the project and run the command:
```bash
    make
    # or
    make all
```
This will generate the archive `libft.a`, a static library file.

### Usage

To use the library:
- Include the header `#include "libft.h"` in .c files (depending of the project configuration)

- the archive generated must be compile with the rest of the .c files
```bash
    cc main.c libft.a -I.

    # or in other form depending on the structure of the project
```

### Cleaning

To remove files, or to clean the repo, use:
```bash
    make clean      # to clean the objects files
    make fclean     # to clean the objects files with the generated library
    make re         # to full clean and rebuild the project
```
## Resources

- Linux man page : manual of the C standard library (ex: man strdup)
- 42 curriculum: Libft subject

### AI usage

AI tools were used only to provide a structural template for this README file.
The content, the wording and explanations is written manually, and mention that no AI was use to create the project itself.

## Library Details

`Libft` is design to be a reusable static library that reimplements a subset function of the C standard library while also
implement some additional utility functions that are frequently require is C project.
All funtions are declare in the single public header file `libft.h` and follow a consitent naming convention using the `ft_` prefix.

This library is divided into several logical groups:
- Functions for character checks and convertions
- Functions for memory allocation and operations
- Functions for string manipulation and parsing
- Functions for file descriptor (output)
- Functions for linked list manipulation

The function obeys in some strict rules and manage error as Segfault and more.

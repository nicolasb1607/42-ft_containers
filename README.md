# Project ft_containers

## Introduction

In this project, you will implement a few container types of the C++ standard template library. Your task is to adhere to the following guidelines and objectives:

### Compiling

- Compile your code with `c++` and the flags `-Wall -Wextra -Werror`.
- Your code should still compile if you add the flag `-std=c++98`.
- Provide a Makefile that compiles your source files without relinking.
- Your Makefile must include at least the following rules: `$(NAME)`, `all`, `clean`, `fclean`, and `re`.

### Formatting and Naming Conventions

- Goodbye Norminette! No specific coding style is enforced; you can follow your preferred coding style. However, prioritize writing clean and readable code.
- Use appropriately named class files for each container.

### Allowed/Forbidden

- You are allowed to use everything from the C++ standard library. Utilize C++-ish versions of C functions where possible.
- Do not use any external libraries such as C++11, C++17, or Boost libraries.
- Forbidden functions include `*printf()`, `*alloc()`, and `free()`. Usage of these functions will result in a grade of 0.

### Design Requirements

- Avoid memory leaks when allocating memory.
- Any function implementation put in a header file (except for function templates) will result in a grade of 0.
- Ensure that each header file can be used independently from others and include all necessary dependencies. Prevent double inclusion with include guards.

### Additional Notes

- You may add additional files if needed to organize your code.
- Remember that you cannot use the STL containers to implement your own containers, as your task is to recode the STL containers from scratch.

By following these guidelines and objectives, you will successfully implement your own C++ containers in adherence to the C++98 standard.

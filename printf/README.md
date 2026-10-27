*This project has been created as part of the 42 curriculum by bsarkoez.*

# ft_printf

## Description

**ft_printf** is a recreation of the C standard library function `printf()`. The goal is to learn how **variadic functions** work in C (`va_list`, `va_start`, `va_arg`, `va_end`) and how to write clean, extensible code.

The project builds a static library, `libftprintf.a`, that contains `ft_printf()`:

```c
int ft_printf(const char *format, ...);
```

It returns the number of characters printed, like the original `printf()`.

### Supported conversions

| Specifier | Output |
|-----------|--------|
| `%c` | A single character |
| `%s` | A string (prints `(null)` if the pointer is NULL) |
| `%p` | A `void *` pointer in hexadecimal (`0x...`, or `(nil)` if NULL) |
| `%d` / `%i` | A signed decimal integer |
| `%u` | An unsigned decimal integer |
| `%x` | A number in lowercase hexadecimal |
| `%X` | A number in uppercase hexadecimal |
| `%%` | A percent sign |

The buffer management of the original `printf()` is not implemented. Output is written directly with `write()`.

### Project structure

```
.
├── Makefile
├── README.md
├── ft_printf.h
├── ft_printf.c        # ft_printf and the specifier dispatcher
├── ft_print_char.c    # ft_putchar, ft_putstr (%c, %s, %%)
├── ft_print_nbr.c     # ft_putnbr, ft_puthex, ft_putptr (%d, %i, %u, %x, %X, %p)
└── libft/             # libft sources and its Makefile
```

## Instructions

### Compilation

```bash
make        # builds libftprintf.a at the root of the repository
make clean  # removes object files
make fclean # removes object files and libftprintf.a
make re     # fclean + all
```

The project is compiled with `cc -Wall -Wextra -Werror`. The Makefile first builds `libft` using its own Makefile, then builds the project and creates the library with `ar`.

### Usage

Include the header in your program and link against the library:

```c
#include "ft_printf.h"

int main(void)
{
	ft_printf("Hello %s, you are %d years old (0x%x)\n", "42", 42, 42);
	return (0);
}
```

```bash
cc main.c libftprintf.a -I. -I libft -o test
./test
```

## Algorithm and data structure

### Parsing

`ft_printf` reads the format string one character at a time with an index `i`:

- If the current character is `%` and there is a character after it, that next character is the **specifier**. It is sent to a dispatcher function (`ft_next`), and the index jumps forward by 2 to skip both characters.
- Otherwise, the character is printed as is, and the index moves forward by 1.

A single pass over the string is enough, so the complexity is O(n) for a format string of length n. No dynamic memory is needed, so there is nothing to free and no risk of memory leaks.

### Dispatching

`ft_next` receives the specifier, the `va_list`, and a pointer to the counter. It uses a chain of `if` conditions (the Norm forbids `switch`) to pick the right helper and reads the argument with `va_arg` using the matching type:

- `int` for `%c`, `%d`, `%i` (`char` is promoted to `int` in variadic calls)
- `char *` for `%s`
- `unsigned int` for `%u`, `%x`, `%X`
- `void *` for `%p`

This keeps the code extensible: supporting a new specifier only needs one new condition and one new helper.

### Character counter

The total length is stored in an `int count` declared in `ft_printf`. Its **address** is passed down to every helper, and every helper increases it through the pointer. All output goes through `ft_putchar` or `ft_putstr`, so the counter is only updated in two places. This makes it simple to keep the returned value correct.

I chose a pointer counter instead of return values because it avoids adding up return values in every function and keeps the helpers simple.

### Number conversion

Numbers are printed with **recursion**: a function divides the number by the base until the value is smaller than the base, then prints the digits on the way back. This prints the most significant digit first without needing a buffer.

- `ft_putnbr` takes a `long`, so `INT_MIN` (where `-n` would overflow an `int`) and all `unsigned int` values for `%u` are handled without special cases.
- `ft_puthex` takes an `unsigned long` and a base string (`"0123456789abcdef"` or `"0123456789ABCDEF"`). Passing the base string as an argument means `%x` and `%X` share one function, and `%p` uses the same function with an `unsigned long` so it works with 64-bit addresses.
- `%p` prints `0x` followed by the hexadecimal address. A NULL pointer prints `(nil)`, which matches the behavior of `printf` on Linux.

## Resources

### References

- `man 3 printf`: behavior of the original function
- `man 3 stdarg`: `va_start`, `va_arg`, `va_copy`, `va_end`
- `man 2 write`
- The 42 Norm (coding style)

### Use of AI

AI was used as a support tool during this project, for the following tasks:

- Explaining how to convert a number to hexadecimal and how `va_arg` works
- Helping with the structure of the Makefile and of the README

I reviewed, tested and understood the final code.

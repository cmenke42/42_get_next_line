# 📄 42 Get Next Line

A function designed to read line-by-line from a given file descriptor. This function comes in handy when you need to process a file in a line-by-line fashion.

## 📖 Table of Contents
- [📝Function Description](#-function-description)
- [⚙️Function Prototype](#️-function-prototype)
- [↩️Return Value](#️-return-value)
- [🚀Getting Started](#-getting-started)
- [💡Usage Example](#-usage-example)
- [🛑 Common Pitfalls](#-common-pitfalls)

## 📝 Function Description
The `get_next_line` function reads a line from a `fd` (file descriptor). A line is defined as a sequence of characters terminated by `\n` (newline character) or `EOF` (end of file). The ammount of bytes read is limited by the `BUFFER_SIZE` parameter `-DBUFFER_SIZE=10`. The `base` version is capable of handling one fd at a time. The `bonus` version is capable of handling multiple fds at the same time `(fd < 0 || fd > 1023)`.

## ⚙️ Function Prototype
```c
char	*get_next_line(int fd);
```

## ↩️ Return Value
- `NULL` if an `error` occured or `EOF` is already reached.
- A `pointer` to the line read from the fd (may include `\n`).

## 🚀 Getting Started
The easiest way to use the `get_next_line` function is to use the `42_libft` library. The library contains the `bonus` version of the `get_next_line` function and other useful functions. To use the library, follow the instructions in the [Getting Started](https://github.com/cmenke42/42_libft/tree/main?tab=readme-ov-file#-getting-started) section of the [42_libft](https://github.com/cmenke42/42_libft.git) repository.

## 💡 Usage Example
```c
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "42_libft/includes/libft.h"

int main(void)
{
    int     fd;
    char    *line_read;

    fd = open("example.txt", O_RDONLY);
    if (fd == -1)
    {
        ft_putendl_fd("Error opening the file", 2);
        return 1;
    }

    while ((line_read = get_next_line(fd)) != NULL)
    {
        ft_printf("%s", line_read);
        free(line_read);
    }
    close(fd);
    return 0;
}
```

## 🛑 Common Pitfalls
1. **Incomplete File Reading**: Stopping before `EOF` can leave residual data in the static buffer, causing `unexpected behavior` when reading from another file that uses the same fd number. It can also lead to `memory leaks` if the program terminates prematurely.

2. **Memory Management**: The function allocates memory for each line it returns. It's crucial to free this memory after use to prevent `memory leaks`.

3. **Buffer Size Implications**: The `BUFFER_SIZE`, defined at compilation time (e.g., `-DBUFFER_SIZE=10`), affects both `performance` and `memory usage`. A larger buffer size may improve performance for large files but increases memory usage.

4. **File Descriptor Limits**: The bonus version can handle multiple fd's. Be aware of the range limitations `(fd < 0 || fd > 1023)`. 

5. **Error Handling**: The function returns `NULL` for both errors and EOF conditions. It's important to check for specific error conditions (like invalid fd's) in the main program.

6. **Line Termination**: The function treats both `\n` and `EOF` as line terminators. Therefore the last returned line may not end with `\n`.
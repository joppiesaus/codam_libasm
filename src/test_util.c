#include <stddef.h> /* size_t */
#include <stdio.h> /* printf */
#include <stdlib.h> /* malloc */
#include <string.h> /* memcpy */

// returns true if n bytes in s are all equal to value
int check_bytes(const char *s, const char value, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        if (s[i] != value)
        {
            return 0;
        }
    }
    return 1;
}

void check_result(int result)
{
    if (result)
    {
        printf("...\tgood\n");
    }
    else
    {
        printf("...\tBAD!\n");
    }
}


// static void print_byte(const unsigned char b)
// {
//     printf("%x%x", b >> 4, b & 0x0f);
// }

// static void print_int(void *i)
// {
//     const char *buf = i;

//     print_byte(buf[0]);
//     printf(" ");
//     print_byte(buf[1]);
//     printf(" ");
//     print_byte(buf[2]);
//     printf(" ");
//     print_byte(buf[3]);
//     printf("\n");
// }

// returns the "sign" of the number
int ft_sign(int n)
{
    if (n < 0)
    {
        return -1;
    }
    else if (n > 0)
    {
        return 1;
    }
    return 0;
}

/* generates and returns a BIG string */
char    *generate_big_string()
{
    #define BIG_STRING_SIZE (1 << 16)

    char *big = malloc(BIG_STRING_SIZE);

    if (!big)
    {
        perror("malloc");
    }
    else
    {
        memcpy(big, "<big string>...", 15);
        for (size_t i = 15; i < BIG_STRING_SIZE; i++)
        {
            big[i] = (i & 0x3f) + ' ';
        }
    }
    return big;
}

// // prints all bytes as chars to the to the terminal, with null terminators as 0
// // up to n chars.
// static void print_bytes(const char *s, size_t n)
// {
//     for (size_t i = 0; i < n; i++)
//     {
//         char c = s[i];
//         if (c == 0)
//         {
//             c = '0';
//         }
//         write(1, &c, 1);
//     }
// }

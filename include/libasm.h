#ifndef LIBASM_H
#define LIBASM_H

#include <sys/types.h> /* ssize_t */

extern size_t   ft_strlen(const char *str);
extern int      ft_strcmp(const char *s1, const char *s2);
extern char     *ft_strdup(const char *str);
extern char     *ft_strcpy(char *dst, const char *src);

extern ssize_t  ft_write(int fd, const void *buf, size_t count);
extern ssize_t  ft_read(int fd, void *buf, size_t count);


// TODO: seperate to bonus

typedef struct  s_list
{
    void            *data;
    struct s_list   *next;
}               t_list;

void    ft_list_push_front(t_list **head, const t_list *entry);
size_t  ft_list_size(const t_list *lst);

#endif

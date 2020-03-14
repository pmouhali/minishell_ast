#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    char *line;
    int fd;

    fd = open("libft.h", O_RDONLY);
    get_next_line(fd, &line);
    get_next_line(fd, &line);
    ft_fprintf(1, "%s\n", line);
    // ft_fprintf(1, "caca\n");
    ft_strdel(&line);
}
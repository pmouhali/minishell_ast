// 42 HEADER

#include "minishell.h"

int		close_pipe(int *read_end, int *write_end)
{
	int r;

	r = 0;
	if (*read_end != -1)
		r = close(*read_end);
	if (*write_end != -1)
		r += close(*write_end);
	*read_end = -1;
	*write_end = -1;
	return (r);
}

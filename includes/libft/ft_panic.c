/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_panic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:08:02 by mstrauss          #+#    #+#             */
/*   Updated: 2024/07/30 15:08:18 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../minishell.h"

void	ft_panic(char *err_msg, int exit_stat)
{
	ft_putstr_fd("ERROR: ", 2);
	ft_putstr_fd(err_msg, 2);
	ft_putchar_fd('\n', 2);
	ft_set_errno(exit_stat);
	ms_exit(exit_stat);
}

void	ft_set_errno(int exit_stat)
{
	if (exit_stat == 1)
		errno = ENOMEM;
}
// add additional exit_stats using 'else if'

/*
OUR OWN CODES
0	=	SUCCESS
1	=	MALLOC_FAILED	: ENOMEM
2	=	LIBFT_FAILURE
3	=	ENV_FAILURE
4	=	EXEC_FAILURE
5	=
6	=
*/

/*
ERRNOS:
1.	EACCES = 13 : Permission denied
2.	EADDRINUSE = 98 : Address already in use
3.	EADDRNOTAVAIL = 99 : Address not available
4.	EAFNOSUPPORT = 97 : Address family not supported
5.	EAGAIN = 11 : Resource temporarily unavailable (or EWOULDBLOCK)
6.	EBADF = 9 : Bad file descriptor
7.	EBUSY = 16 : Device or resource busy
8.	ECONNABORTED = 103 : Connection aborted
9.	ECONNREFUSED = 111 : Connection refused
10.	ECONNRESET = 104 : Connection reset
11.	EDEADLK = 35 : Resource deadlock avoided
12.	EDESTADDRREQ = 89 : Destination address required
13.	EDOM = 33 : Mathematics argument out of domain of function
14.	EDQUOT = 122 : Disk quota exceeded
15.	EEXIST = 17 : File exists
16.	EFAULT = 14 : Bad address
17.	EFBIG = 27 : File too larges
18.	EHOSTUNREACH = 113 : Host is unreachable
19.	EIDRM = 43 : Identifier removed
20.	EILSEQ = 84 : Illegal byte sequence
21.	EINPROGRESS = 115 : Operation in progress
22.	EINTR = 4 : Interrupted function call
23.	EINVAL = 22 : Invalid argument
24.	EIO = 5 : Input/output error
25.	EISCONN = 106 : Socket is connected
26.	EISDIR = 21 : Is a directory
27.	ELOOP = 40 : Too many levels of symbolic links
28.	EMFILE = 24 : Too many open files
29.	EMLINK = 31 : Too many links
30.	EMSGSIZE = 90 : Message too long
31.	ENAMETOOLONG = 36 : Filename too long
32.	ENETDOWN = 100 : Network is down
33.	ENETRESET = 102 : Network dropped connection on reset
34.	ENETUNREACH = 101 : Network is unreachable
35.	ENFILE = 23 : Too many open files in system
36.	ENOBUFS = 105 : No buffer space available
37.	ENODEV = 19 : No such device
38.	ENOENT = 2 : No such file or directory
39.	ENOEXEC = 8 : Exec format error
40.	ENOLCK = 37 : No locks available
41.	ENOMEM = 12 : Not enough space
42.	ENOSPC = 28 : No space left on device
43.	ENOSYS = 38 : Function not implemented
44.	ENOTCONN = 107 : Socket is not connected
45.	ENOTDIR = 20 : Not a directory
46.	ENOTEMPTY = 39 : Directory not empty
47.	ENOTSOCK = 88 : Not a socket
48.	ENOTSUP = 95 : Operation not supported
49.	ENOTTY = 25 : Inappropriate I/O control operation
50.	ENXIO = 6 : No such device or address
51.	EOPNOTSUPP = 95 : Operation not supported on socket
52.	EOVERFLOW = 75 : Value too large to be stored in data type
53.	EPERM = 1 : Operation not permitted
54.	EPIPE = 32 : Broken pipe
55.	EPROTO = 71 : Protocol error
56.	EPROTONOSUPPORT = 93 : Protocol not supported
57.	EPROTOTYPE = 91 : Protocol wrong type for socket
58.	ERANGE = 34 : Result too large
59.	EROFS = 30 : Read-only file system
60.	ESPIPE = 29 : Invalid seek
61.	ESRCH = 3 : No such process
62.	ETIME = 62 : Timer expired
63.	ETIMEDOUT = 110 : Connection timed out
64.	ETXTBSY = 26 : Text file busy
65.	EWOULDBLOCK = 11 : Operation would block (same as EAGAIN)
66.	EXDEV = 18 : Cross-device link
*/
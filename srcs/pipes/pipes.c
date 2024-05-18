#include <../../includes/minishell.h>

// EPIPE -- Error code for pipe errors

int	main(int ac, char *av[])
{
	int		fd[2];
	pid_t	pid;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		execlp("ls", "ls", NULL);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		execlp("wc", "wc", "-l", NULL);
	}
}

// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     char *line = NULL;
//     size_t len = 0;
//     ssize_t read;

//     printf("Please enter a line: ");

//     read = getline(&line, &len, stdin);
//     if (read == -1) {
//         printf("No line was entered.\n");
//     } else {
//         printf("You entered: %s", line);
//     }

//     ft_free(line);
//     return (0);
// }

/* -------------------------------------------------------------------------- */
/*                              USEFUL FUNCTIONS                              */
/* -------------------------------------------------------------------------- */
/*
pipe

fork() causes creation of a new process.  The new process (child process) is an exact copy of the calling process (parent process) except for the follow-
		ing:

			o   The child process has a unique process ID.

			o   The child process has a different parent process ID (i.e.,
				the process ID of the parent process).

			o   The child process has its own copy of the parent's descriptors.  These descriptors reference the same underlying objects,
				so that, for instance,
				file pointers in file objects are shared between the child and the parent,
					so that an lseek(2) on a descriptor in the child process can affect a
				subsequent read or write by the parent.  This descriptor copying is also used by the shell to establish standard input and output for newly cre-
				ated processes as well as to set up pipes.

			o   The child processes resource utilizations are set to 0; see setrlimit(2).

RETURN VALUES
		Upon successful completion,
			fork() returns a value of 0 to the child process and returns the process ID of the child process to the parent process.  Oth-
		erwise, a value of -1 is returned to the parent process,
			no child process is created,
			and the global variable errno is set to indicate the error.
dup
	dup() duplicates an existing object descriptor and returns its value to the calling process (fildes2 = dup(fildes)).
dup2
	the value of the new descriptor fildes2 is specified.  If fildes and fildes2 are equal,
		then dup2() just returns fildes2; no other changes are
		made to the existing descriptor.  Otherwise,
			if descriptor fildes2 is already in use,
			it is first deallocated as if a close(2) call had been done first.
fork

open
read
close
*/
# Minishell

## Table of Contents
- [Fetch Changes](#fetch-changes)
- [Useful Links](#useful-links)
- [Must-haves](#musthaves)
- [Allowed Functions Explained](#allowed-functions-explained)
- [Tokenisation](#tokenisation)

## Fetch Changes
To fetch the newest changes, use the following commands:
```bash
git fetch origin
git checkout 1-parsing
git merge <name>
git pull
```

## Useful Links

https://www.gnu.org/software/bash/manual/bash.html


##  Must-haves
• Display a prompt when waiting for a new command.

• Have a working history.

• Search and launch the right executable (based on the PATH variable or using a
relative or an absolute path).

• Avoid using more than one global variable to indicate a received signal.
Consider
the implications: this approach ensures that your signal handler will not access your
main data structures.

• Not interpret unclosed quotes or special characters which are not required by the
subject such as \ (backslash) or ; (semicolon).

• Handle ’ (single quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence.

• Handle " (double quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence except for $ (dollar sign).

• Implement redirections:
◦ < should redirect input.
◦ > should redirect output.
◦ << should be given a delimiter, then read the input until a line containing the
delimiter is seen. However, it doesn’t have to update the history!
◦ >> should redirect output in append mode.
• Implement pipes (| character). The output of each command in the pipeline is
connected to the input of the next command via a pipe.

• Handle environment variables ($ followed by a sequence of characters) which
should expand to their values.

• Handle $? which should expand to the exit status of the most recently executed
foreground pipeline.

• Handle ctrl-C, ctrl-D and ctrl-\ which should behave like in bash.

• In interactive mode:
◦ ctrl-C displays a new prompt on a new line.
◦ ctrl-D exits the shell.
◦ ctrl-\ does nothing.

• Your shell must implement the following builtins:
◦ echo with option -n
◦ cd with only a relative or absolute path
◦ pwd with no options
◦ export with no options
◦ unset with no options
◦ env with no options or arguments
◦ exit with no options
____________________________________________________________________________________________________________

The readline() function can cause memory leaks. You don’t have to fix them. But
that doesn’t mean your own code, yes the code you wrote, can have memory
leaks.
____________________________________________________________________________________________________________


## Allowed Functions Explained


readline: This function is used to read a line of text from the standard input. It's commonly used for creating interactive command-line interfaces.

rl_clear_history: Clears the history maintained by the readline library.

rl_on_new_line: Notifies readline that a new line has been started.

rl_replace_line: Replaces the current line of input in the readline buffer with a new line.

rl_redisplay: Redraws the current line in the readline buffer.

add_history: Adds a line to the history maintained by the readline library.

printf: Prints formatted output to the standard output.

malloc: Allocates memory dynamically on the heap.

free: Frees memory allocated dynamically with malloc, calloc, or realloc.

write: Writes data to a file descriptor.

access: Checks whether a file exists and the user has the necessary permissions to access it.

open: Opens a file or device for reading or writing.

read: Reads data from a file descriptor.

close: Closes a file descriptor.

fork: Creates a new process by duplicating the existing process.

wait, waitpid, wait3, wait4: Functions for waiting for child processes to terminate and retrieving their status.

signal, sigaction, sigemptyset, sigaddset, kill: Functions for handling signals in UNIX-like operating systems.

exit: Terminates the calling process and returns an exit status to the operating system.

getcwd: Gets the current working directory.

chdir: Changes the current working directory.

stat, lstat, fstat: Functions for retrieving file status information.

unlink: Deletes a name from the filesystem.

execve: Executes a program.

dup, dup2: Duplicates file descriptors.

pipe: Creates a pipe, which is a unidirectional communication channel.

opendir, readdir, closedir: Functions for working with directories.

strerror: Returns a string describing the error code passed to it.

perror: Prints a descriptive error message to the standard error.

isatty, ttyname, ttyslot, ioctl: Functions related to terminal I/O.

getenv: Retrieves the value of an environment variable.

tcsetattr, tcgetattr: Functions for setting and getting terminal attributes.

tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs: Functions for interacting with the terminal database (terminfo), used for obtaining terminal capabilities and controlling terminal behavior in a platform-independent manner.

____________________________________________________________________________________________________________
### TOKENISATION
look at strtok and build it
https://cplusplus.com/reference/cstring/strtok/

readline
rl_clear_history
rl_on_new_line
rl_replace_line
rl_redisplay
add_history
printf
malloc
free
write
access
open
read
close
fork
wait
waitpid     apparently preffered in modern programs over wait3 and wait4
    wait3
    wait4
signal
sigaction
sigemptyset
sigaddset
kill
exit
getcwd
    These functions return a null-terminated string containing an
    absolute pathname that is the current working directory of the
    calling process.
chdir

{   get info about file
stat    by path
lstat   symbolic link
fstat   by file descriptor
}

unlink

execve
    execve() executes the program referred to by pathname.  This
       causes the program that is currently being run by the calling
       process to be replaced with a new program, with newly initialized
       stack, heap, and (initialized and uninitialized) data segments.
dup
dup2
pipe
opendir
readdir
closedir
strerror
perror
isatty
ttyname
ttyslot
ioctl
getenv
tcsetattr
tcgetattr
tgetent
tgetflag
tgetnum
tgetstr
tgoto
tputs



## HISTORY
  Commands for Manipulating the History
       accept-line (Newline, Return)
              Accept the line regardless of where the cursor is.  If
              this line is non-empty, it may be added to the history
              list for future recall with add_history().  If the line is
              a modified history line, the history line is restored to
              its original state.
       previous-history (C-p)
              Fetch the previous command from the history list, moving
              back in the list.
       next-history (C-n)
              Fetch the next command from the history list, moving
              forward in the list.


# TOKEN TYPES

>> Append
<< Heredoc
< input
> output
  word



# Command Table

- Command
- Arguments
- Redirections
- Index
- Heredoc names
- **char ARGS






# STRUCTURE

## ARGC Check

## MINISHELL Loop
- read input (readline)

## LEXER
- check for false input
       - wrong redis
       - wrong pipes
       - empty input / strings
       - Quotes
              - double quote
              - single quote
                     - check amount
                            = odd -> error
                            = even -> ignore inside

## PARSER
### Tokenizer
       - split prompts @ pipes
       - convert split prompts into tokens
         TOKENS:
              >> Append
              << Heredoc
              < input
              > output
                word
         COMMAND TABLE
              - Command
              - Arguments
              - Redirections
              - Index
              - Heredoc names
              - **char ARGS

### Expander
replace:
       - $
       - $?
       - $$
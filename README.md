Minishell Project :
===================

Welcome to the Minishell project !

This project focuses on writting your own shell (at least a mini version of one)

Project Description
-------------------

The Minishell project ask you to imitate "bash --posix" and some builtins:

1.  **Parsing:**
    * Handle redirection.
    * Handle double/simple quotes.
    * Handle heredoc.
    * Handle pipes.
    * Handle env.
2.  **Other & Builtins:**
    * Ctrl+C - Ctrl+D - Ctrl+\\.
    * Builtins:
      * echo with -n
      * cd with only a relative or absolute path
      * pwd with no options
      * export with no options
      * unset with no options
      * env with no options or arguments
      * exit with no options
    

Project Requirements
--------------------

* Most important -> Execution must be done in parralel !
* Only one global variable.
* Search and launch the right executable.
* Have a working history.
* Handle "$?" which return the last exit status code.

Getting Started
---------------

1.  First of all, I would say that 80% of minishell is parsing so make sure you are making a clean structure.
2.  Keep in mind that the execution must be done in parallel, this means "sleep 3 | sleep 3" will only sleep 3.
3.  Make sure to handle the "cd" options -> "..", ".", "-", "~".
4.  The global variable will be the exit status which will be updated frequently.
5.  For the heredoc, you can use a pipe to stock the lines instead of a tmp fd.
6.  To nkow how the parsing and lexer should be done, refer to the bash posix man lexer

Resources
---------

* [Bash --posix](https://www.gnu.org/software/bash/manual/html_node/Bash-POSIX-Mode.html)
* [Heredoc](https://tldp.org/LDP/abs/html/here-docs.html)

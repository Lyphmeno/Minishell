<!DOCTYPE html>
<html>
<body>
  <h1>Minishell Project : <a href="https://github.com/JaeSeoKim/badge42"><img src="https://badge42.vercel.app/api/v2/cljbd5ceo007308mltneinai5/project/2353766" alt="hlevi's 42 minishell Score" /></a></a></h1>
  <p>Welcome to the Minishell project !</p>
  <p>This project focuses on writting your own shell (at least a mini version of one)</p>
  
  <h2>Project Description</h2>
  <p>The Minishell project ask you to imitate "bash --posix" and some builtins:</p>
  <ol>
    <li>
      <strong>Parsing:</strong>
      <ul>
        <li>Handle redirection.</li>
        <li>Handle double/simple quotes.</li>
        <li>Handle heredoc.</li>
        <li>Handle pipes.</li>
        <li>Handle env.</li>
      </ul>
    </li>
    <li>
      <strong>Other & Builtins:</strong>
      <ul>
        <li>Ctrl+C - Ctrl+D - Ctrl+\.</li>
        <li>Builtins:</li>
        <ul>
          <li>echo with -n</li>
          <li>cd with only a relative or absolute path</li>
          <li>pwd with no options</li>
          <li>export with no options</li>
          <li>unset with no options</li>
          <li>env with no options or arguments</li>
          <li>exit with no options</li>
        </ul>
      </ul>
    </li>
  </ol>

  <h2>Project Requirements</h2>
  <ul>
    <li>Most important -> Execution must be done in parralel !</li>
    <li>Only one global variable.</li>
    <li>Search and launch the right executable.</li>
    <li>Have a working history.</li>
    <li>Handle "$?" which return the last exit status code.</li>
  </ul>

  <h2>Getting Started</h2>
  <ol>
    <li>First of all, I would say that 80% of minishell is parsing so make sure you are making a clean structure.</li>
    <li>Keep in mind that the execution must be done in parallel, this means "sleep 3 | sleep 3" will only sleep 3.</li>
    <li>Make sure to handle the "cd" options -> "..", ".", "-", "~".</li>
    <li>The global variable will be the exit status which will be updated frequently.</li>
    <li>For the heredoc, you can use a pipe to stock the lines instead of a tmp fd.</li>
    <li>To nkow how the parsing and lexer should be done, refer to the bash posix man lexer</li>
  </ol>

  <h2>Resources</h2>
  <ul>
    <li><a href="https://www.gnu.org/software/bash/manual/html_node/Bash-POSIX-Mode.html">Bash --posix</a></li>
    <li><a href="https://tldp.org/LDP/abs/html/here-docs.html">Heredoc</a></li>
</body>
</html>

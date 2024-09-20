# Pipex

## Overview
**Pipex** is a project that simulates the behavior of shell piping (`|`). The program takes two commands and pipes the output of the first command into the input of the second command. This project will help you better understand how pipes work in UNIX systems.

## Features
- Executes two commands in sequence using a pipe.
- Simulates the shell command:  
  ```bash
  < file1 cmd1 | cmd2 > file2
##Usage
  ```
make
./pipex file1 cmd1 cmd2 file2
./pipex infile "ls -l" "wc -l" outfile


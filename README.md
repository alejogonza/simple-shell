## My simple_shell in c

<p align="center"><img width="250" src="https://i.ibb.co/vqLyKFm/1.png" alt="printf logo"></a></p>

## Description

This repository contains a version of shell in c language, which maintains the main functions of this basic function. This project is a project requested by [Holberton School](https://www.holbertonschool.com/)

## Prerequisites 📋

you must have the gcc compiler and a 64-bit system installed for greater reliability:

### In linux:

`$ sudo apt install gcc`

`$ gcc --version`

`gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
Copyright (C) 2017 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.`

### In windows:

[Follow the platzi tutorial](https://platzi.com/tutoriales/1469-algoritmos/1901-como-instalar-gcc-para-compilar-programas-en-c-desde-la-consola-en-windows/)


### Options :mag_right:

The following conversion operators are available:

- **ls** = lists information about files and directories.

- **exit** = quits the program.

- **env** = prints the environment variables.

## Running the tests ⚙

Clone the repo:

`$ git clone https://github.com/alejogonza/simple_shell.git`

Run this command:

`$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`

And run the shell:

`$ ./hsh`

## Example :boom:
```
$ ./hsh
$ ls -la
total 2608
drwxrwxr-x  3 vagrant vagrant    4096 Aug 28 03:01 .
drwxr-xr-x 15 vagrant vagrant    4096 Aug 28 03:00 ..
drwxr-xr-x  8 root    root       4096 Aug 28 03:01 .git
-rw-r--r--  1 root    root         19 Aug 28 02:56 .gitignore
-rw-r--r--  1 root    root        171 Aug 16 01:06 AUTHORS
-rw-r--r--  1 root    root         23 Aug 28 02:56 README.md
-rwxr-xr-x  1 root    root      13521 Aug 28 03:01 a.out
-rw-r--r--  1 root    root       1463 Aug 28 03:01 execute.c
-rw-r--r--  1 root    root       1016 Aug 28 03:01 functions_1.c
-rwxr-xr-x  1 root    root        490 Aug 16 01:08 git.sh
-rw-r--r--  1 root    root        994 Aug 28 03:01 looper.c
-rw-r--r--  1 root    root        180 Aug 28 03:01 shell.c
-rw-r--r--  1 root    root        795 Aug 28 03:01 shell_header.h
-rw-r--r--  1 root    root    2615216 Aug 28 03:01 shell_header.h.gch
-rw-r--r--  1 root    root       1992 Aug 28 03:01 split.c
$
```

## The pseudocode :pencil:

<h4 align="center">Flowchart</h4>

<h4 align="center">Version 1</h4>
<p align="center"><img src="https://i.ibb.co/4M3CPyh/Deepin-Screenshot-20190827221737.png" alt="shell v1"></a></p>
<br>
<h4 align="center">Version 2</h4>
<p align="center"><img src="https://i.ibb.co/THx7n9z/1.png" alt="shell v2"></a></p>


**complex pseudo**

[PSEUDO](https://miro.com/app/board/o9J_kwnTpS0=/)

## Authors :copyright:

* **Alejandro Gonzalez Serna** - [Github](https://github.com/alejogonza/)

* **Dilan rincon** - [Github](https://github.com/dilanrinconhbtn)

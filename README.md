# editor
This project is an attempt to implement a version of ed, a line-oriented text editor, using C.

## Reference:
"GNU ed is a line-oriented text editor. It is used to create, display, modify and otherwise manipulate text files, both interactively and via shell scripts. A restricted version of ed, red, can only edit files in the current directory and cannot execute shell commands. Ed is the 'standard' text editor in the sense that it is the original editor for Unix, and thus widely available. For most purposes, however, it is superseded by full-screen editors such as GNU Emacs or GNU Moe. "

[https://www.gnu.org/software/ed/manual/ed_manual.html](https://www.gnu.org/software/ed/manual/ed_manual.html)

## Implemented Commands:
```
(.)a
E <file>
h
(1,$)w <file>
($)=
.
```

## How to use:
Simply run make to build the program and then ./ed in the terminal can be used the same as ed.
Example:

```
$ make
$ ./ed testing/file_tests/hi.txt
337
=
35
4a
Hello how are you?

abcdefg
.
w
365
q
```


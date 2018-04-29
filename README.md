# Hello World For Classic Macintoshes in C

Hello World example using Think C 5.0, for Classic Macintosh System 7. 

This basic example demonstrates initializing the Macintosh Toolbox routines, QuickDraw, and painting "Hello World" in a window built from a WIND resource defintion. The application quits on any button press, and does not attempt to build menus via the Menu Manager, nor handle any events. 

This is essentially the minimum boilerplate required to launch an application, and paint a string in a window. Demonstrates building a Window from a WIND definition via Toolbox's `GetNewWindow()`. Uses QuickDraw's `ShowWindow()`, `SetPort()` and `MoveTo()` and `DrawString()`. Demonstrates loading a font by name via `GetFNum()` and use of the `\p` escape sequence for Pascal-style string literals (Pascal-style strings are a requirement of the Toolbox routines).

This example is based off one found on page 69 of `The Macintosh C Programming Primer` by Dave Mark & Cartwright Reed (ISBN: 0-20160838-3 v.1) Published in 1992.

### A Note on Resource Forks:

Think C Project files (*.π) and Think C External Resource Files (*.π.rsrc) actually keep thier data in the resource fork on  HFS macintosh filesystems (ie classic macintosh filesystems). Git does not provide a facility for the preservation of this information. However, it is possible to use the `xbup` suite of command line utilities to transfer the resource forks of each file into a file that Git will notice. The reverse is also possible, taking the resource forks and merging them back into the original files. I'm using Mac OS X 10.13.4 with `xbup` version 2.1 to generate or restore these 'split' resource files.

https://github.com/invariablyafk/xbup-macosx-backup-tools

### Cloning Repository & Restoring Restoring Forks

```
git clone https://github.com/invariablyafk/thinkc-mac-classic-helloworld.git
cd thinkc-mac-classic-helloworld
git config --local include.path ../.gitconfig
join_xattr Hello\ World\ 2 Hello\ World\ 2-xattrs
```

The `join_xattr` command will take the resource forks in `Hello World 2-xattrs` and merge them back into the matching files inside `Hello World 2`. Any swapping of branches or file operations (ie `git checkout`) performed by git should be followed by a subsequent `join_xattr` to merge resource forks. The git config command only needs to be run once, and will handle swapping Mac-style CR line endings for Unix-style LF line endings (see below). 

### Generating the Resource Fork files Before Commits

As git normally ignores the _extremely important_ resource forks, preserving them requires running the following command before commiting any changes.

`split_xattr Hello\ World\ 2 Hello\ World\ 2-xattrs`

### Compiling

The Think C project should be intact, but in the event it needs to be recrated: This project includes the `MacTraps` library and the `hello2.c` file. Think C knows `HelloWorld2.π.rsrc` will be part of the `HelloWorld2.π` project, so naming of the project file matters. Selecting `Build application.. ` from the `Project` menu should compile the application from source.

### About Macintosh Line Endings (CR) in Git

Git lacks support for Macintosh-style text files that end in a carriage return with each line. Unix standard is LF, and Windows uses CRLF. This repository stores the files in Unix standard Line-Feed terminated (LF) format. A filter is included to on-the-fly convert from LF to CR at checkout and check in, making this process transparent. Run this command after cloning the repository for the first time:

`git config --local include.path ../.gitconfig`

This will install the filter defined in `.gitconfig` and called from `.gitattributes` into your local copy so that you can ignore the CR/LF compatibility issue. Files will appear to you as CR terminated, and will exist in git as LF terminated.

### To Do:

Investigate filters/hooks for running `xbup` tools automagically. 

Possible avenues:

 * https://stackoverflow.com/questions/3284292/can-a-git-hook-automatically-add-files-to-the-commit





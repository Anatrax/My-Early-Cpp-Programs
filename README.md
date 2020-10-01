# My-Early-Cpp-Programs
A collection of programs I created to learn C++

## Setup
1. Compile the programs using [Borland's Turbo C++ compiler](http://forms.embarcadero.com/BCC32CompilerDownload).

- ### Turbo C++
  Make sure to the compiler executables are added to the PATH:
  ```
  C:\Users\MyUser> set PATH=%PATH%;C:\Borland\bcc55\bin
  ```
  Navigate to the folder where this repo is cloned. For me, the folder is in the Documents folder so the command is as follows:
  ```
  C:\Users\MyUser>cd C:\Users\MyUser\Documents\My-Early-Cpp-Programs
  ```
  
  The programs are compiled as follows:
  ```
  C:\Users\MyUser\Documents\My-Early-Cpp-Programs>bcc32 myprogram.cpp
  ```

2. Change the path in "Settings.txt" to the folder where this repo is cloned.

3. Move "Settings.txt" and "codeNow.exe" to your home folder (the folder that command prompt opens up in).

## Usage
Open Command Prompt and type "codeNow":
```
C:\Users\MyUser>codeNow
```
This will set up the command line environment according to the "Settings.txt" file.

- The menu lives in the "programList.txt" file. This is where "Menu.exe" will read from.
- The "new.exe" program guides you through creating a program, adds it to "programList.txt", and creates a C++ file with a simple hello-world program.

## Background Info
Programs were created on a Windows machine using Notepad (not even Notepad++) and compiled with the Borland C++ compiler called Turbo C++ (I hadn't found the GNU Compiler Collection yet).

The purpose of this repo is primarily to document my early attemps at programming but also to provide some motivation for my future self because my early C++ programs show how I was able to solve different problems despite my limited knowledge and experience. Obviously, they were not exactly the best or "prettiest" solutions, but they worked.

Two of the biggest challenges I had while creating these programs were typing commands to the console from a C++ program and viewing the contents of a file in the console. I eventually was able to create VirtualTyper.cpp and Quine.cpp to solve these problems. Only later did I find out that you can use "system();" to run commands in the console and the "type" command to output the contents of a file (I was also just learning to use the command line at that time).

For all those new programmers out there, keep it up! Try hard things.

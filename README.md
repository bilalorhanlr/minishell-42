# Mini Shell - Ecole 42 Project
This repository contains the solution to the mini shell project, part of the curriculum at Ecole 42.

## Introduction
The goal of this project is to create a basic shell that can interpret and execute commands entered by the user. The shell should support basic functionality such as executing programs, handling signals, and handling errors. This project will help you understand the basics of how shells work and reinforce your understanding of system calls and process management in the Unix operating system.

## Advice for students of Ecole 42
- You need to understand this project well at first, especially in 2 stages. Stage 1 is the stage where we divide the data we have in our hands into parts, which I call "pars". In this stage, never forget what the data is, why it is, and that the format given to you has a structure. This is a product of science and there is already a structure in it. Over time, you will learn the accumulations that come one on top of the other. Do not only think of this project as a shell program, that would be a big mistake. So what should you do? Before starting the project, you need to understand what you will be dealing with for at least 3 days, I think more than a week. Read a lot and test a lot. Don't re-discover America. Just read, learn, and divide the data into as many parts as possible in the first stage. This division will be very beneficial for you in your first attempt.

- It is true that this project teaches you to use a shell, but what I think it teaches is the pipe method, which is part of interprocess communication. When you finish this project, you will also have learned the fifo pipe structure. In future projects, you will also learn other interprocess communication techniques.

- The hard parts of the project are excessively many, and they all come from ignorance.

- The second part, or the "execute" stage, is the part where you allocate interprocess communication. In this stage, the number of independent tests you make is what you need to pay attention to. You will need to use a lot of different functions together. Before starting this stage, be sure to take the RANK 4 exam, which is the fourth exam at Ecole 42.

- The error control part is a section where the number of tests you perform and the number of different sources you read will benefit you greatly. This part is easy compared to the rest of the project.

- Signals are also a part that you need to use. This is a part that I think you will not have any trouble integrating into your code when you attach great importance to it, but you need to be able to give a clear answer to the question of what EOF is by the end of the project.

## Usage
To use the MiniShell program, compile the code and run the executable. The prompt will display, and you can start entering commands. For example:

'''
```
$ make
$ ./minishell
minishell$ ls
...
minishell$ cd Documents
minishell$ pwd
...

```
## Features
The mini shell supports the following features:

- Execution of programs: The shell can execute programs and display their output.
- Signal handling: The shell can handle signals such as SIGINT and SIGQUIT.
- Error handling: The shell can handle errors such as command not found and permission denied.

## Resources
Here are a few resources that may be useful while working on this project:

- Unix man pages
- Advanced Programming in the Unix Environment by W. Richard Stevens

## Conclusion
I hope that this project was a valuable learning experience for you. If you have any questions or feedback, feel free to reach out to me on Github.




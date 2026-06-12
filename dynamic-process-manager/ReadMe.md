# Dynamic Process Manager (C)

## Description
A console-based system written in C that simulates process management using dynamic memory allocation. It allows users to create, view, search, delete, and persist process data using file handling.

## Features
- Add new processes dynamically
- View all stored processes
- Search process by PID
- Delete processes
- Save processes to file
- Load processes from file
- Dynamic memory allocation using malloc and realloc

## How It Works
- Processes are stored in dynamically allocated memory (heap)
- Data can be saved to a file for persistence
- On startup, saved data can be loaded back into memory
- User interacts through a menu-driven interface

## How to Run
1. Compile the program:
   gcc main.c -o process_manager

2. Run the program:
   ./process_manager

## What I Learned
- Dynamic memory allocation in C
- Pointer manipulation and memory management
- Struct-based data modeling
- File handling for persistence
- Basic system design concepts
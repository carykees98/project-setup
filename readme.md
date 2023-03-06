# Project Setup

C++ program to create C++ project folders. 

## Usage

```
$ project-setup --help

$ project-setup aurelia

$ project-setup aurelia ~/projects/aurelia
```

The program takes up to two arguments: 
  - The being the project name, `aurelia` in this example
  - The path to where you want the project to be placed. A directory will be created in that location with the name of the project.

The file structure created is: 
```
.
├── .gitignore
├── license
├── makefile
├── readme.md
├── build
└── src
    └── main.cpp
```

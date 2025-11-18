# Student-Management-System-ITI-
This repo contains the project of C++ and SQL Courses Final Project in ITI

# Install Libraries
First i had to install this library that connects C++ with mysql (C++ is by default installed and i had installed mysql in the Database course)

```bash
sudo apt update
sudo apt install build-essential default-libmysqlclient-dev
```

# Building main.cpp
To build the main.cpp, I was running the following command.
```bash
g++ main.cpp database_models/MyDatabase.cpp models/Student.cpp services/StudentService.cpp -o main $(/usr/bin/mysql_config --cflags --libs)
```
This command creates an executable file main from main.cpp and using the mysql_config file

To run this file, just cd to the directory and type:
```bash
./main
```

# Creating my own header files
I have used these references to help me create my own header files:
- https://stackoverflow.com/questions/20015656/how-to-create-my-own-header-file-in-c
- https://cplusplus.com/forum/articles/10627/


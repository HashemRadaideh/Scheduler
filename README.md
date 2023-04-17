# Simple cross-platform C++ project development, testing and deployment template

## (Optional) first you need to generate the docker image

```bash
# to build the docker image
docker build -t scheduler .

# to run the container
docker run -it --rm -v `pwd`:/work scheduler
```

## then to build the project you can either use cmake or makefile

```bash
# to build the project with cmake
cmake -B ./build && cmake --build ./build

# to build the project with makefile
make

# to run the program
./build/scheduler
```

---

# Project descrtiption

In this assignment, you will implement a simple OS scheduler using C/C++. The scheduler’s task is to 
receive a set of processes and their details, and then decide the order of executing these processes 
based on the chosen algorithm. Finally, the scheduler will output the order of process execution, in 
addition to some stats about each of the processes.

The scheduling algorithm chosen for this assignment will be LJF (Longest Job First). This made-up 
algorithm is the exact opposite of the SJF algorithm you learned in class; It is a non-preemptive 
algorithm that gives more priority for the longest jobs first. In the assignment, the input will start with 
an integer N, representing the number of processes, followed by N lines (one for each process). For each 
line i, the line will start with a string s, representing the process name, followed by 2 numbers 
representing the arrival time and processing time for the ith process, respectively. These values will be 
separated by tabs (i.e. ‘\t’). The values for input numbers can be up to 100,000,000.

Your program should print a line indicating the order of executing the processes. Moreover, for each 
process, the program should print a line showing the process’s name, response time, turnaround time, 
and delay. See the sample output below for details.

The input will be read from a file (in.txt), and the output should be written to a file (out.txt). The output 
format must strictly match the formatting shown in the sample output. 

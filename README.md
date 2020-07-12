# CodingProblems
In this repository there are several practise coding problems solved. All the problems are solved using C++. 
Bandit is used to run unit tests and ubench is used for running benchmarks

## Cloning
This repository uses bandit for unit tests and bandit is incorporated as a git submodule. To clone the repository run
the following command

```bash
git clone --recurse-submodules  https://github.com/selvakumarjawahar/CodingProblems.git
```

If you already cloned but forgot to get the submodules, then do the following

```bash
cd <cloned directory>
git submodule update --init --recursive
```

## Compiling

### Linux systems
```bash
cd <cloned repo>
mkdir build
cd build
cmake ..
make
```

### Windows systems
```bash
cd <cloned repo>
mkdir build
cd build
cmake ..
# by default will create VS solution files, open them in visual studio and build
```

## Running the tests and benchmarks
cmake creates 3 targets 
* solutions - This is the static library with all the solutions
* runtests - This is the executable which will run tests
* runbenchmark - This is the executable which will run benchmarks
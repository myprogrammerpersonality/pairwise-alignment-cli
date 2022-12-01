## Fast C++ Implementation of Needleman-Wunch Algorithm for Pairwise Sequence Alignment
The Needleman-Wunch algorithm is a well-known dynamic programming algorithm for aligning two sequences. This repository contains a fast C++ implementation of the algorithm, along with a command-line interface (CLI) tool for running pairwise sequence alignments.

## Building the CLI Tool
To build the CLI tool, you will need a C++ compiler and the CMake build system.

First, clone this repository and navigate to the root directory:
```
$ git clone https://github.com/USERNAME/needleman-wunch.git
$ cd needleman-wunch
```
Next, create a build directory and run CMake to generate the build files:
```
$ mkdir build
$ cd build
$ cmake ..
```
Finally, build the project using your C++ compiler:
```
$ make
```
This will create the nw-align executable in the build directory.

## Running the CLI Tool
To run the nw-align tool, use the following command:
```
$ ./nw-align <seq1> <seq2> [options]
```
where seq1 and seq2 are the sequences to be aligned.

## Options
The nw-align tool supports the following options:
* -g: Specifies the gap penalty. The default value is -1.
* -m: Specifies the match score. The default value is 1.
* -d: Specifies the mismatch score. The default value is -1.
* -o: Specifies the output file for the alignment. If not provided, the alignment will be printed to standard output.

## Example
To align the sequences AAACCTTGG and ACACTGTGG using a gap penalty of -1, a match score of 1, and a mismatch score of -2, and save the alignment to a file called alignment.txt, use the following command:
```
$ ./nw-align AAACCTTGG ACACTGTGG -g -1 -m 1 -d -2 -o alignment.txt
```
The resulting alignment file will contain the following:
```
AAACCTTGG
AA-CCTTGG
```

## License
This project is licensed under the MIT License. See the LICENSE file for details.
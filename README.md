# Arraymaker

Arraymaker is used to create very large arrays of random numbers that are randomly sorted for the purpose of using them to learn about timing with sorting algorithms. Arraymaker has built in timing.

You can easily manually write small arrays to test your algorithms to see if they work, however, small arrays are not so helpful to see the timing differences between algorithms.

The bigger the arrays to sort are, the more noticable the time differences can be.

Arraymaker creates arrays that are sized based on user input so they can be 20 elements or 400,000 elements and potentially more. Since the program saves the array, the same unsorted array can used with different algorithms to return more useful times when comparing them.

## installation
```
$ git clone https://github.com/breakthatbass/arraymaker.git
```

#### compile
```
$ make arraymaker
```

#### install
```
$ make install
```

## Usage

Once installed, Arraymaker can be used from any directory like any other command, however, the number file you create and use must be in the directory you are executing the commands from. 

### commands:

#### create

```create``` creates the file which holds the numbers to load into the array. This is the first step and has to be done before using the ```sort``` command.

```
$ arraymaker create num-of-elements file.txt
```
```num-of-elements```: this is where you put the amount of elements you want. It's just a number. There is limit to the array length because of memory restrictions. This limit will be different on each system. My system, which has 8GB of RAM, faults with anything over 410,000 lines. 

```file.txt```: you can name this anything you want and it doesn't necessarily need to be a ```.txt```...but why do any other type?

#### sort

```sort``` loads the numbers from the ```.txt``` file into an array then uses it with the algorithm in the argument.

```
$ arraymaker sort file.txt algorithm
```
The ```algorithm``` file is your file that has the algorithm in it.

There is a directory called 'algorithms' that holds the algorithms. You can add your own to the folder. Just add the function to the ```helpers.h``` file and the ```Makefile```. And lastly, add it to the commands in the ```main.c``` file.

To get a sense of how this works, comparing the shell sort and bubble sort algorithms, shell sort is able to sort an array of 400,000 elements in about 0.5 seconds while bubblesort takes about 1.5 minutes to sort the same array. 

Currently, the algorithms available for use are bubblesort, shellsort, gnomesort, and quicksort. 

### TODO:
Add more algorithms

Make it possible to create and test partially sorted arrays and mostly sorted arrays

add print ability to be turned on or off
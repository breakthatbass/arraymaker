# Arraymaker

Arraymaker is used to create very large arrays of random numbers that are randomly sorted for the purpose of using them to learn about timing with sorting and searching algorithms. Arraymaker is meant to be used alongside the UNIX Time command.

You can manually write arrays of 10 or so elements to test your algorithms to see if they work, however, small arrays are not so helpful to see the timing differences between algorithms.

The bigger the arrays to sort are, the more noticable the timing differences can be.

Arraymaker creates arrays that are sized based on user input so they can be 20 elements or 10,000 elements or more. Since the program saves the array, the same unsorted array can used with different algorithms to return more useful times when comparing them.

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

Once installed, Arraymaker can be used from any directory like any other command.

### commands:
There a few actions to be done before loading up your algorithms...

#### create

```create``` creates the numbers to load into the array. It stores them in a seperate file to pull from when loading it into the array. This way you can use the same numbers to sort between different algorithms to more accurately judge timing.

```
$ arraymaker create num-of-elements file.txt
```
```num-of-elements```: this is where you put the amount of elements you want. There is limit to the array length because of memory restrictions. This limit will be different on each system. My system, which has 8GB of RAM, faults with anything over 410,000 lines. 

```file.txt```: you can name this anything you want and it doesn't necessarily need to be a ```.txt```...but why do any other type?

#### load

```load``` loads in the numbers from the ```.txt``` file and stores them into an array.

```
$ arraymaker load file.txt algorithm
```
The ```algorithm``` file is your file that has the algorithm in it.

There is a directory called 'algorithms' that currently has a shell sort file and a bubble sort file. You can add your own to the folder. Just add the function to the ```helpers.h``` file and the ```Makefile```. 

To get a sense of how this works, comparing the shell sort and bubble sort algorithms, shell sort is able to sort an array of 400,000 elements in about 0.5 seconds while bubblesort takes about 1.5 minutes to sort the same array. 

### TODO
1. Build connection to outside files

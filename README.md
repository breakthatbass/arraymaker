![ArayMaker logo](logo.png)


# Arraymaker

Arraymaker is used to create very large arrays of random numbers that are randomly sorted for the purpose of using them to learn about timing with sorting algorithms. Arraymaker has built in timing.

You can easily manually write small arrays to test your algorithms to see if they work, however, small arrays are not so helpful to see the timing differences between algorithms.

The bigger the arrays to sort are, the more noticable the time differences can be.

Arraymaker creates arrays that are sized based on user input so they can be 20 elements or 400,000 elements and potentially more. Since the program saves the array in a file, the same unsorted array can used with different algorithms to return more useful times when comparing them.

Read the article about it [here](https://breakthatbass.github.io/portfolio2020/blog/arraymaker.html).

## installation
```
$ git clone https://github.com/breakthatbass/arraymaker.git

$ cd arraymker

$ make install
```

## Usage

Once installed, Arraymaker can be used from any directory like any other command, however, the number file you create and use must be in the directory you are executing the commands from. 

The program is run with the shortened name ```arrmkr```

## Commands

```
arrmkr <options> [arg-file] [arg2]
```

In short, the options are ```-c``` for create and ```-s``` for sort. The first argument is always the file to be used/created. The second argument depends on the command. If ```-c``` then [arg2] will be the array length. If ```-s``` then [arg2] will be the algorithm chosen to sort the array.

### create

```-c``` creates the file which holds the numbers to load into the array. This is the first step and has to be done before using the ```-c``` option.

```
$ arrmkr -c file array-length
```

```file```: you can name this anything you want. It becomes the name of the file created that hold the numbers for reusing the array. You don't need to use a file extension but you can if you want to. Most file types seem to work fine.

```array-length```: this is where you put the amount of elements you want in the array. It's just a number. There is limit to the array length because of memory restrictions. This limit will be different on each system. My system, which has 8GB of RAM, faults with anything over ~1,300,000 lines. You don't need a million elements to get a sense of timing differences though. 100,000 elements works well enough as anymore than that really causes the slower algorithms to take a painfully long time to sort. 

### sort

```-s``` loads the numbers from the number file into an array then uses it with the algorithm in the argument.

```
$ arrmkr -s file algorithm
```
```algorithm``` is just the name of the algorithm to use. Currently, the algorithms available for use are bubblesort, shellsort, gnomesort, and quicksort. So type any of those in and as long and there's no typo, it'll sort accordingly.

### Adding more algorithms

There is a directory called 'algorithms' that holds the algorithms. You can add your own to the folder or change what I have there. To add your own, you'll need to add the function prototype to the ```arraymaker.h``` file, you don't need to add the file name to the ```Makefile```, and lastly, add it to the commands in the ```main.c``` file.

To get a sense of how this works, comparing the quicksort and bubble sort algorithms, quicksort is able to sort an array of 400,000 elements in about 0.5 seconds while bubblesort takes about 108 seconds to sort the same array. 

### TODO:
- create a function to call the sorting functions in order to clean up main.c

- have the algorithm files act as libraries/plugins rather than something that needs to be part of the program

- Add more algorithms

- Make it possible to create and test partially sorted arrays and mostly sorted arrays.

- Add searching algorithm functionality

# Arraymaker

Arraymaker is used to create very large arrays of random numbers that are randomly sorted for the purpose of using them to learn about timing with sorting and searching algorithms. Arraymaker is meant to be used alongside the UNIX Time command.

You can manually write arrays of 10 or so elements to test your algorithms to see if they work, however, small arrays are not so helpful to see the timing differences between algorithms.

The bigger the arrays to sort are, the more noticable the timing differences can be.

Arraymaker creates arrays that are sized based on user input so they can be 20 elements or 10,000 elements or more.

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
```num-of-elements```: this is where you put the amount of elements you want.

```file.txt```: you can name this anything you want and it doesn't necessarily need to be a ```.txt```...but why do any other type?

#### load

```load``` loads in the numbers from the ```.txt``` file and stores them into an array.

```
$ arraymaker load file.txt algorithm.c
```
The ```algorithm.c``` file is your file that has the algorithm in it.

At this moment, however, the program is not finished but it is still somewhat useable.
The ```create``` command is fully usable but the ```load``` command is only partially built.

Right now, the ```load``` command can be used like this:
```
$ arraymaker load file.txt
```
It will take in the file you've created and print each line in the terminal.

### TODO
1. Build connection to outside files

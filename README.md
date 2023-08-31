# 5-6

This is a repository with my files somehow related to solving
the quadratic equation in the probably most difficult way 
possible. It was really useful to me and will probably be so to you, too

# Compiling

## Using makefile

	.cpp files can compiled using makefile.txt; in such case,
	Make utility is required on your PC. If you want to compile
	without using a test file, you should enter this in console:

	```
	make -f makefile.txt
	```

	Or just in case you want to test a program first, enter:

	```
	make test -f makefile.txt
	```

	After compiling you may want to get rid of .o files. This is
	when you paste/type in this:

	```
	make clean -f makefile.txt
	```

## Without makefile

	In case you don't want (or are unable) to use makefile, you're
	free to do this by using:

	```
	g++ -DTEST main2.cpp functions2.cpp
	```

	And, if you don't want to test the program, use the same text
	but without "-DTEST".

## .bat files

	Use any of these files to compile without typing anything into
	the command prompt (you can't test on your own .txt file when
	using .bat!)

# Launching the program

After the program has compiled successfully, you are free to launch
it. The longest text you can enter to do so is

```
<name of executable file(default is a.exe)> --test <path to .txt test file>
```

This will allow you enable testing (if you compiled with tests) and also 
define your own test file. If you don't enter a path to it, test file will 
be "tests.txt". If you only enter name of .exe file, the tests will be skipped

# Input

Program will ask you to enter three coefficients. They'll be saved in memory
in "double" format no matter what number you enter- integer, float or exponential.
After that, program will output the type of equation with coefficients you've 
entered and what are the roots (if they exist).

# html folder

Contains all the documentation on functions and constants used in the program.

# functions1.cpp, main1.cpp, header1.cpp

The older version of program. Is made using Russian language
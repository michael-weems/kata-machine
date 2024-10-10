# Kata Machine - Work in Progress

Practice writing and re-writing Data Structures and Algorithms.

## Using this repo

### Dependencies

TODO: ensure people can just pull this down and run it
```bash
sudo apt install gcc
```

### How to practice

Open any `.c` file that doesn't start with `_` and doesn't end with `_tests.c` or `_golden.c`. You'll be greeted with the scaffolding necessary to write an implementation for that problem. 

For example, if you open `bubblesort.c`, you'll be able to write your solution for bubblesort there. 

To check your work, run the below command:

```bash
make bubblesort

# or, more generally
make <filename-without-extension>

# example: good
make linearsearch

# example: bad
make linearsearch_golden
```

If you need a refresher, you can checkout an existing implementation in the `_golden.c` files.

### Cleaning up

If you implement a solution and want to make sure you can do it again, just run:

```bash
git reset --hard
```

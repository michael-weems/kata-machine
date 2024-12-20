# DSA Katas - Work in Progress

Practice writing and re-writing Data Structures and Algorithms.

## Using this repo

### Dependencies

TODO: ensure people can just pull this down and run it
```bash
sudo apt install gcc # todo: add necessary dependency installation here

git submodule init
git submodule update --remote tools/queue
./init
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

### Utilities

If you want to utilize a psuedo-random queue of katas, you're free to use the tool located at `tools/queue`.

Example usage:

```bash
# NOTE: only have to run this once, unless the submodule updates
./init

# get next kata to do
./kq -f ./kata.db -d

# generate new queue of katas to perform
./kq -f ./kata.db -g

# add a new kata to the database
./kq -f ./kata.db -a "text description of kata"

# list all katas available 
./kq -f ./kata.db -k

# list all "on-deck" katas in your queue
./kq -f ./kata.db -q
```

### Cleaning up

If you implement a solution and want to make sure you can do it again, just run:

```bash
git reset --hard
```

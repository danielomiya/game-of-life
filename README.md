# game-of-life

A simulator of the cellular automaton designed by John Conway in 1970.

## Contributors

- Daniel Omiya - 41995449
- Hugo Amorim Martins - 41991184
- Nicole Martins dos Santos - 41990277

## Built with

- C language
- CMake

## Rules

The function for creating new generations follows some basic rules:

- Live cells with:
    - fewer than two live neighbours dies, as if by underpopulation. (< 2)
    - two or three live neighbours lives on to the next generation.
    - more than three live neighbours dies, as if by overpopulation. (> 3)

- Dead cells with exactly three live neighbours becomes a live cell, as if by reproduction


## How to run it

Clone the repository and cd into it:

    $ git clone https://github.com/gwyddie/game-of-life
    $ cd game-of-life

Build and run the container:

    $ docker-compose build
    $ docker-compose run app

Or, instead of using Docker, you can also build it in your own machine, using:

    $ mkdir build && cd $_
    $ cmake ..
    $ make

The executable will be available at `./main`.

---

That's all, thanks! :p

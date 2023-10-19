# Monty Language Interpreter 🚀

This project is a custom-built interpreter for Monty ByteCodes files, a scripting language that is first compiled into Monty byte codes. The Monty program runs the bytecodes line by line and stops if either it executed every line of the file, it finds an error in the file, or an error occurred.

This project was carried out by Ewedairo Israel, a student at Alx Africa, under the supervision of Julien Barbier.

## Features 🎈

- The Monty program is executed with the following command: `monty file`, where `file` is the path to the file containing Monty byte code.
- The program handles various opcodes, including `push`, `pall`, `pint`, `pop`, `swap`, `add`, `nop`, `sub`, `div`, `mul`, `mod`, `pchar`, `pstr`, `rotl`, `rotr`, `stack`, and `queue`.
- The program can operate in either stack (LIFO) or queue (FIFO) mode, depending on the opcode.

## Getting Started 🏁

To get a local copy up and running, follow these simple steps:

1. Clone the repository to your local machine.
2. Navigate to the project directory.
3. Compile the program using `gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty`.
4. Run the program with a Monty byte codes file: `./monty test/00.m`.

## Built With 🛠️

- C programming language
- Ubuntu 20.04 LTS

## Authors ✒️

**Ewedairo Israel** - [GitHub](https://github.com/Israelshecktar)

## Acknowledgments 🎁

- Julien Barbier, for his supervision and guidance throughout the project.
- Alx Africa, for providing the platform for learning and growth.

## License 📄

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.

## Show your support ⭐

Give a ⭐️ if this project helped you!

![Monty Interpreter](https://miro.medium.com/max/1200/1*OohqW5DGh9CQS4hLY5FXzA.png)


This README was created with ❤️ by Ewedairo Israel.

# my_mastermind

## Project Description

```
Mastermind is a game composed of 8 pieces of different colors.
A secret code is then composed of 4 distinct pieces.

The player has 10 attempts to find the secret code.
After each input, the game indicates to the player
the number of well placed pieces and the number of misplaced pieces.

Pieces will be '0' '1' '2' '3' '4' '5' '6' '7'.

If the player finds the code, he wins, and the game stops.
A misplaced piece is a piece that is present in the secret
code butthat is not in a good position.

You must read the player's input from the standard input.

Your program will also receive the following parameters:
-c [CODE]: specifies the secret code. If no code is specified,
a random code will be generated.
-t [ATTEMPTS]: specifies the number of attempts; by default,
the playerhas 10 attempts.
```

## Steps to Reproduce

---

### Compile

-   `make`: To build the project
-   `make re`: To rebuild the project
-   `make clean`: Clean the executable

### Run

-   Executable: `./my_mastermind`
-   Options: `-c + <Secret Code>`, `-t + <No. of Attempts>` (Default is 10)
-   Code: Enter a 4 digit code
-   Example Command: `./my_mastermind -c 0123 -t 4`

### EXAMPLE

---

```
> ./my_mastermind -c "0123"
Will you find the secret code?

Round 0
> 1456
Well placed pieces: 0
Misplaced pieces: 1

Round 1
> tata
Wrong input!
-> 4132
Well placed pieces: 1
Misplaced pieces: 2

Round 2
> 0123
Congratz! You did it!
```

### NOTES

---

1. Check for `-c` OR `-t` options
    - If found, then parse it
    - Else generate a random code, and set attempts to 10.
2. Loop through attempts: `while tries < total tries`
3. Prompt the user to enter the code
4. Compare the code entered with the specified code
5. Check if it's a match. If found, end the session after a success msg.
6. If not, hint the user and ask to enter again.

### BUGS TO FIX

---

1. Handle error when code digit is 8 or 9
2. Handle errors in repeating digits.

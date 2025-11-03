# Hi-Lo
Implementation of a game of [Hi-Lo](http://en.wikipedia.org/wiki/Sic_bo). 

**RULES**

First, the program will pick a random integer between 1 and 100. The player is given 7 tries to guess the number.

If the player cannot guess the correct number, the program will give them a hint, telling them whether their guess is too high or too low. 

If the player can guess the right number, they win. 

If the player runs out of guesses, they lose. In that case, the program will tell them what the correct number is.

**EXAMPLE OUTPUT**

```
Hi-Lo v1.0.0
By Itosh1key

Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.
Guess #1: 50
Your guess is too high.
Guess #2: 30
Your guess is too high.
Guess #3: 10
Your guess is too low.
Guess #4: 26
Your guess is too low.
Guess #5: 28
Your guess is too high.
Guess #6: 27 
Correct! You win!
Would you like to play again (y/n)? n

Thank you for playing.
```

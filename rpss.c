#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get computer's random choice
int computerChoice() {
    int choice = rand() % 3;
    switch (choice) {
        case 0: return 1; // Rock
        case 1: return 2; // Paper
        case 2: return 3; // Scissors
    }
    return 0;
}

// Function to determine winner
int winner(int userChoice, int computerChoice) {
    if (userChoice == computerChoice) {
        return 0; // Tie
    } else if ((userChoice == 1 && computerChoice == 3) || 
               (userChoice == 2 && computerChoice == 1) || 
               (userChoice == 3 && computerChoice == 2)) {
        return 1; // User wins
    } else {
        return -1; // Computer wins
    }
}

int main() {
    int userChoice;
    int computerChoiceValue;
    int userScore = 0;
    int computerScore = 0;

    printf("Welcome to Rock Paper Scissors #Best of 3!\n");
    printf("1 = Rock\n2 = Paper\n3 = Scissors\n");

    srand(time(0)); // Seed for random number generator

    for (int round = 1; round <= 3; round++) {
        printf("\nRound %d\n", round);

        // Input validation loop
        do {
            printf("Enter your choice (1-Rock, 2-Paper, 3-Scissors): ");
            scanf("%d", &userChoice);
        } while (userChoice < 1 || userChoice > 3);

        computerChoiceValue = computerChoice();
        printf("Computer chose: %d\n", computerChoiceValue);

        int result = winner(userChoice, computerChoiceValue);

        if (result == 1) {
            printf("You win this round!\n");
            userScore++;
        } else if (result == -1) {
            printf("Computer wins this round!\n");
            computerScore++;
        } else {
            printf("This round is a tie!\n");
        }

        printf("Score: You %d - Computer %d\n", userScore, computerScore);
    }

    // Final Result
    printf("\nFinal Result: ");
    if (userScore > computerScore) {
        printf("Congratulations! You win the game!\n");
    } else if (computerScore > userScore) {
        printf("Computer wins the game! Better luck next time!\n");
    } else {
        printf("The game is a tie!\n");
    }

    return 0;
}


#include <stdio.h>

int main() {
    int score;

    while(1) {
        // Prompt the user for input.
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        // End the loop if input is less than or equal to 1.
        if (score <= 1) {
            break;
        }

        printf("Possible combinations of scoring plays if a team's score is %d:\n", score);
        
        // Scoring Plays:
        // Touchdown with 2-point conversion (8 points) TD2
        // Touchdown with 1-point field goal (7 points) TD1
        // Touchdown (6 points)                         TD
        // Field Goal (3 points)                        FG
        // Safety (2 points)                            SAF

        // Iterate through possible combinations of the scoring plays.
        // Find the maximum number of each scoring play by dividing the score by the points for that play.
        // Start from the lowest scoring play (Safety 2pt) to 
        //  the highest scoring play (Touchdown with 2-point conversion 8pt).
        for (int TD2 = 0; TD2 <= score / 8; TD2++) {
            for (int TD1 = 0; TD1 <= score / 7; TD1++) {
                for (int TD = 0; TD <= score / 6; TD++) {
                    for (int FG = 0; FG <= score / 3; FG++) {
                        for (int SAF = 0; SAF <= score / 2; SAF++) {
                            if (8 * TD2 + 7 * TD1 + 6 * TD + 3 * FG + 2 * SAF == score) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", TD2, TD1, TD, FG, SAF);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
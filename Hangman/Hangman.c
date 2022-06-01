#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void append(char* s, char c)
{
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}

int checkGame(int count, char *word)
{
    int i = 0;
    switch (count)
    {
    case 6:
        printf("\n O\n");
        printf("/|\\\n");
        printf("/ \\\n");
        i++;
        break;
    case 5:
        printf("\n O\n");
        printf("/|\\\n");
        printf("/\n");
        break;
    case 4:
        printf("\n O\n");
        printf("/|\\\n");
        break;
    case 3:
        printf("\n O\n");
        printf("/|\n");
        break;
    case 2:
        printf("\n O\n");
        printf(" |\n");
        break;
    case 1:
        printf("\n O\n");
        break;
    default:
        break;
    }
    return i;
}

void guess(char *guesses, char *total, char *word, int count)
{
    int j, k, g;
    int c = 0;
    int repeat = 0;
    int n = strlen(word);
    char letter, d;
    printf("Next Letter to Guess: \n");
    scanf("%c", &letter);
    append(guesses, letter);
    while((d = getchar()) != '\n' && d != EOF); // need to discard previous scanf value, using dummy d
    for (k = 0; k < n - 1; k++) {
        if(word[k] == toupper(letter) || word[k] == tolower(letter)) {
            c++;
            total[k] = letter;
        }
    }
    if (c == 0) {
        count++;
    }
    printf("Guessed Letters: %s\n", guesses);
    printf("Current Word: %s\n", total);
    g = checkGame(count, word);
    for (j = 0; j < n - 1; j++) {
        if (total[j] == *"-") {
            repeat++;
        }
    }
    if (g > 0) {
        printf("Game Over. Word was: %s", word);
        return;
    }
    else if (repeat == 0) {
        printf("\nGG\n");
        return;
    }
    guess(guesses, total, word, count);
}

int main()
{
    int i;
    char a;
    static int count = 0;
    static char guesses[100];
    static char total[100];
    static char word[100];
    printf("Enter your word Plz: \n");
    fgets(word, 100, stdin);
    int n = strlen(word);
    for (i = 0; i < n - 1; i++) {
        if (word[i] == *" ") {
            append(total, *" ");
        }
        else {
            append(total, *"-");
        }
    }
    printf("Press Enter to play");
    scanf("%c", &a);
    printf("\n\n\n\n\n\n\n\n\n");
    printf("%s\n", total);
    guess(guesses, total, word, count);
    return 0;
}

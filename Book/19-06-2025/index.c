#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

// print the longest input line
int main(int argc, char *argv[])
{
    int len;                // currrent line length
    int max;                // maximum length seen so far
    char line[MAXLINE];     // current input line
    char longest[MAXLINE];  // longest line saved here

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0) // there was a line
        printf("%s\n", longest);
    return 0;
}

// getline: read a line into s, return length
int get_line(char s[], int lim)
{
    // TODO: Counter the lenght regardless of buffer size.
    int c, i;
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)    
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    } 
    s[i] = '\0';
    return i;
}

// copy: copy 'from' into 'to'; assume to is big enough;
void copy(char to[], char from[]) 
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}












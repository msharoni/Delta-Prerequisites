#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void read_file(char* filepath) {
    FILE *file = fopen(filepath, "r");
    if (file == NULL) {
        printf("Error opening file");
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }
    printf("\n");
    fclose(file);
}

void copy_file(char* src, char* dest) {
    FILE *source = fopen(src, "r");
    if (source == NULL) {
        printf("Error opening source file");
        return;
    }

    FILE *destination = fopen(dest, "w");
    if (destination == NULL) {
        printf("Error opening destination file");
        fclose(source);
        return;
    }

    char ch;
    while ((ch = fgetc(source)) != EOF) {
        fprintf(destination, "%c", ch);
    }

    fclose(source);
    fclose(destination);
}

void analyze_file(char* filepath) {
    FILE *file = fopen(filepath, "r");
    if (!file) {
        printf("Error opening file");
        return;
    }

    char ch, prev = ' ';
    int letters = 0, words = 0, lines = 0;

    while ((ch = fgetc(file)) != EOF) {
        // Count letters
        if (isalpha(ch))
            letters++;

        // Count words
        if (isspace(ch) && !isspace(prev))
            words++;

        // Count lines
        if (ch == '\n')
            lines++;

        prev = ch;
    }

    // Handle last word if file doesn't end with space
    if (!isspace(prev))
        words++;

    // Handle last line if file doesn't end with newline
    if (prev != '\n')
        lines++;

    fclose(file);

    printf("Letters: %d\n", letters);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);
}

void remove_line(char* filepath, int line_number) {
    FILE *file = fopen(filepath, "r");
    if (!file) {
        printf("Error opening file");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (!temp) {
        printf("Error creating temporary file");
        fclose(file);
        return;
    }

    char ch;
    int current_line = 1;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n')
            current_line++;

        if (current_line != line_number)
            fprintf(temp, "%c", ch);
    }

    fclose(file);
    fclose(temp);

    remove(filepath);
    rename("temp.txt", filepath);
}

void string_match_infile(char* filepath, char* target) {
    FILE *file = fopen(filepath, "r");
    if (!file) {
        printf("Error opening file");
        return;
    }

    int len = strlen(target);
    int match_index = 0;

    char ch;
    int found = 0;

    while ((ch = fgetc(file)) != EOF) {
        if(match_index < strlen(target) && ch == target[match_index]) 
            match_index++;
        else {
            match_index = 0;
        }
        if(match_index == strlen(target)) {
            found++;
            match_index = 0;
        }        
    }

    printf("found %d times\n", found);

    fclose(file);
}
int main() {
    char src_filename[100], dest_filename[100];
    read_file("check.txt");
    copy_file("check.txt", "copy.txt");
    read_file("copy.txt");
    analyze_file("check.txt");
    remove_line("copy.txt", 2);
    read_file("copy.txt");
    string_match_infile("check.txt", "test");

    return 0;
}
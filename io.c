//
// Created by 24029135 on 08/04/2026.
// Requirement

#include "io.h"

#include <stdio.h>

int countRows(char *fileName){
    FILE *file = fopen(fileName, "r");
        if (file == NULL) {
            printf("Error opening file. \n");
            return 1;
        }
    int totalCount = 0;
    char line[256];
        //skip header
    fgets(line,sizeof(line),file);
        //counting rows
    while (fgets(line,sizeof(line), file) != NULL) {
        totalCount++;
    }
    fclose(file);
    return totalCount;
}
//
// Created by 24029135 on 08/04/2026.
// Requirement

#include "io.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "waveform.h"

int countRows(char *fileName){
    FILE *file = fopen(fileName, "r");
        if (file == NULL) {
            printf("Error opening file. \n");
            return -1;
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

waveformSample *loadData(char *fileName, int totalCount) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file. \n");
        return NULL;
    }
        //allocate memory
    waveformSample *data = malloc(totalCount * sizeof(waveformSample));
    if (data == NULL) {
        printf("Error allocating memory. \n");
        fclose(file);
        return NULL;
    }
        //•	To fix bug where an empty file would cause a random output
    if (totalCount == 0) {
        printf("No data found. \n");
        return NULL;
    }

    char line[256];
        //skip header
    fgets(line,sizeof(line),file);

    for (int i = 0; i < totalCount; i++) {
        fgets(line,sizeof(line), file);

        char *token;

        token = strtok(line, ",");
        data[i].timestamp = atof(token);

        token = strtok(NULL, ",");
        data[i].phase_A_voltage = atof(token);

        token = strtok(NULL, ",");
        data[i].phase_B_voltage = atof(token);

        token = strtok(NULL, ",");
        data[i].phase_C_voltage = atof(token);

        token = strtok(NULL, ",");
        data[i].line_current = atof(token);

        token = strtok(NULL, ",");
        data[i].frequency = atof(token);

        token = strtok(NULL, ",");
        data[i].power_factor = atof(token);

        token = strtok(NULL, ",");
        data[i].thd_percent = atof(token);
    }

    fclose(file);
    return data;
}



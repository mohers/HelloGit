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

int writeFile(char *fileName, double rmsA, double meanA, double peak2PeakA, int clippingDetectionA, int toleranceComplianceA,
                              double rmsB, double meanB, double peak2PeakB, int clippingDetectionB, int toleranceComplianceB,
                              double rmsC, double meanC, double peak2PeakC, int clippingDetectionC, int toleranceComplianceC) {
    FILE *file = fopen("results.txt", "w");
    if (file == NULL) {
        printf("Error creating file. \n");
        return 1;
    }
    fprintf(file, "%s Analysis Report\n", fileName);

    // Phase A
    fprintf(file, "Phase A:\n\n");
    fprintf(file, "RMS is: %.2f V\n", rmsA);
    fprintf(file, "Mean is: %.2f V\n", meanA);
    fprintf(file, "Peak to Peak is: %.2f V\n", peak2PeakA);
    if (clippingDetectionA == 1) {
        fprintf(file, "Clipping Detection: Clipping Detected\n");
    }
    else {
        fprintf(file, "Clipping Detection: No Clipping\n");
    }
    if (toleranceComplianceA == 1) {
        fprintf(file, "Tolerance Compliance: Passed\n\n\n");
    }
    else {
        fprintf(file, "Tolerance Compliance: Failed\n\n\n");
    }

    // Phase B
    fprintf(file, "Phase B:\n\n");
    fprintf(file, "RMS is: %.2f V\n", rmsB);
    fprintf(file, "Mean is: %.2f V\n", meanB);
    fprintf(file, "Peak to Peak is: %.2f V\n", peak2PeakB);
    if (clippingDetectionB == 1) {
        fprintf(file, "Clipping Detection: Clipping Detected\n");
    }
    else {
        fprintf(file, "Clipping Detection: No Clipping\n");
    }
    if (toleranceComplianceB == 1) {
        fprintf(file, "Tolerance Compliance: Passed\n\n\n");
    }
    else {
        fprintf(file, "Tolerance Compliance: Failed\n\n\n");
    }

    // Phase C
    fprintf(file, "Phase C:\n\n");
    fprintf(file, "RMS is: %.2f V\n", rmsC);
    fprintf(file, "Mean is: %.2f V\n", meanC);
    fprintf(file, "Peak to Peak is: %.2f V\n", peak2PeakC);
    if (clippingDetectionC == 1) {
        fprintf(file, "Clipping Detection: Clipping Detected\n");
    }
    else {
        fprintf(file, "Clipping Detection: No Clipping\n");
    }
    if (toleranceComplianceC == 1) {
        fprintf(file, "Tolerance Compliance: Passed\n\n\n");
    }
    else {
        fprintf(file, "Tolerance Compliance: Failed\n\n\n");
    }
    fclose(file);
    return 0;
}
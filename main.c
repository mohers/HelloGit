#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "waveform.h"
#include "io.h"

int main(void) {
    printf("Please enter name of the file:\n");
    char fileName[256];
    scanf("%s", fileName);
    int totalCount = countRows(fileName);
    if (totalCount == -1) {
        printf("Error reading file. \n");
        return 0;
    }

    printf("The total number of rows is: %d\n", totalCount);
    waveformSample *data = loadData(fileName, totalCount);
    if (data == NULL) {
        printf("Error reading file. \n");
        return 1;
    }

/*    printf("The first 3 waveform samples are:\n");
    for (int i = 0; i < 3; i++) {
        printf("\n%d.\nTimestamp: %f,\nPhase A Voltage: %f, \nPhase B voltage: %f, "
               "\nPhase c voltage: %f, \nLine Current: %f, \nFrequency: %f, \nPower Factor: %f, \nTHD Percent: %f\n",i +1 ,  data[i].timestamp, data[i].phase_A_voltage, data[i].phase_B_voltage, data[i].phase_C_voltage,
               data[i].line_current, data[i].frequency, data[i].power_factor, data[i].thd_percent);
    }
    free(data);*/
    double *phaseA = malloc(totalCount * sizeof(double));
    double *phaseB = malloc(totalCount * sizeof(double));
    double *phaseC = malloc(totalCount * sizeof(double));

    if (phaseA == NULL || phaseB == NULL || phaseC == NULL) {
        printf("Error allocating memory. \n");
        free(data);
        return 1;
    }

    for (int i = 0; i < totalCount; i++) {
        phaseA[i] = data[i].phase_A_voltage;
        phaseB[i] = data[i].phase_B_voltage;
        phaseC[i] = data[i].phase_C_voltage;
    }

    //Phase A calculations
    double rmsA = calculateRMS(phaseA, totalCount);
    double meanA = calculateMean(phaseA, totalCount);
    double peak2PeakA = calculatePeak2Peak(phaseA, totalCount);
    int clippingDetectionA = clippingDetection(phaseA, totalCount);
    int toleranceComplianceA = toleranceCompliance(rmsA);

    //Phase B Calculations
    double rmsB = calculateRMS(phaseB, totalCount);
    double meanB = calculateMean(phaseB, totalCount);
    double peak2PeakB = calculatePeak2Peak(phaseB, totalCount);
    int clippingDetectionB = clippingDetection(phaseB, totalCount);
    int toleranceComplianceB = toleranceCompliance(rmsB);

    //Phase C Calculations
    double rmsC = calculateRMS(phaseC, totalCount);
    double meanC = calculateMean(phaseC, totalCount);
    double peak2PeakC = calculatePeak2Peak(phaseC, totalCount);
    int clippingDetectionC = clippingDetection(phaseC, totalCount);
    int toleranceComplianceC = toleranceCompliance(rmsC);

    int finalMessage = writeFile(fileName, rmsA, meanA, peak2PeakA, clippingDetectionA, toleranceComplianceA,
                                           rmsB, meanB, peak2PeakB, clippingDetectionB, toleranceComplianceB,
                                           rmsC, meanC, peak2PeakC, clippingDetectionC, toleranceComplianceC);
    if (finalMessage == 0) {
        printf("Analysis Report Generated");
    }
    else {
        printf("Please Restart Program");
    }
    free(phaseA);
    free(phaseB);
    free(phaseC);
    free(data);
    return 0;
}
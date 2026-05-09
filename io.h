//
// Created by 24029135 on 08/04/2026.
//Requirements
#ifndef IO_H
#define IO_H
#include "waveform.h"
//Functions
// count rows in file
int countRows(char *fileName);

// loads data from file into array
waveformSample *loadData(char *fileName, int totalCount);


int writeFile(char *fileName, double rmsA, double meanA, double peak2PeakA, int clippingDetectionA, int toleranceComplianceA,
                              double rmsB, double meanB, double peak2PeakB, int clippingDetectionB, int toleranceComplianceB,
                              double rmsC, double meanC, double peak2PeakC, int clippingDetectionC, int toleranceComplianceC);
#endif //IO_H

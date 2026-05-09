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


int writeFile(char *fileName, double rmsA, meanA, peak2PeakA, int clippingDetectionA, toleranceComplianceA,
                              double rmsB, meanB, peak2PeakB, int clippingDetectionB, toleranceComplianceB,
                              double rmsC, meanC, peak2PeakC, int clippingDetectionC, toleranceComplianceC);
#endif //IO_H

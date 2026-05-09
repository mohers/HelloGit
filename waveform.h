//
// Created by 24029135 on 08/04/2026.
// Requirement 1 - define a waveform sample struct
// Requirement 5/6/7/8 - RMS, P2P, DC offset, detect clipping

#ifndef WAVEFORM_H
#define WAVEFORM_H

typedef struct {
    double timestamp;
    double phase_A_voltage;
    double phase_B_voltage;
    double phase_C_voltage;
    double line_current;
    double frequency;
    double power_factor;
    double thd_percent;
} waveformSample;


// functions
double calculateRMS (double *values, int totalCount);
double calculateMean (double *values, int totalCount);
double calculatePeak2Peak (double *values, int totalCount);
int clippingDetection (double *values, int totalCount);
int toleranceCompliance(double rms);
#endif //WAVEFORM_H

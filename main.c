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

}
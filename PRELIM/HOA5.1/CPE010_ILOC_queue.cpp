#include <iostream>
#include "HOA5p1_ILOC_printer.h"

int main() {
    //create a printer
    Printer printer;

    //add printing jobs
    printer.AddJob(Job(1, "Jave ", 5));
    printer.AddJob(Job(2, "Mike", 10));
    printer.AddJob(Job(3, "Yazi", 3));
    printer.AddJob(Job(4, "Dane", 7));

    //process all jobs
    printer.ProcessJobs();

    return 0;
}
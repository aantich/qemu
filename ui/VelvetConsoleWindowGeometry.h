/* SPDX-License-Identifier: MIT */
#ifndef VELVET_CONSOLE_WINDOW_GEOMETRY_H
#define VELVET_CONSOLE_WINDOW_GEOMETRY_H

typedef struct {
    double width;
    double height;
} VelvetConsoleSize;

/* Both inputs are in AppKit points. AppKit applies the current backing scale. */
static inline VelvetConsoleSize VelvetConsoleFit(VelvetConsoleSize preferred,
                                                 VelvetConsoleSize available)
{
    if (preferred.width <= 0 || preferred.height <= 0 ||
        available.width <= 0 || available.height <= 0) {
        return preferred;
    }
    double widthFit = available.width / preferred.width;
    double heightFit = available.height / preferred.height;
    double fit = widthFit < heightFit ? widthFit : heightFit;
    if (fit >= 1) {
        return preferred;
    }
    return (VelvetConsoleSize){preferred.width * fit, preferred.height * fit};
}

#endif

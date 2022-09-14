#pragma once

typedef struct {
    unsigned char r, g, b;
} PPMPixel;

typedef struct {
    int x, y;
    PPMPixel* data;
} PPMImage;
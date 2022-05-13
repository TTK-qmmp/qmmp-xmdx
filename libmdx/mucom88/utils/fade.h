#pragma once

#include <stdio.h>

class Fade
{
public:
    Fade();
    Fade(int audioRate, int startSeconds);
    void Step(int frames);
    double volume;

    bool enable;
private:
    int start;
    int count;
    int rate;
    int length;

    bool mode;
    int left;
};



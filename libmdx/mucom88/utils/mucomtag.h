#pragma once

#include <string>

class CMucom;

class MucomTag
{
public:
    MucomTag();
    ~MucomTag();

    void LoadTag(CMucom*);
    const char* GetTagInternal(CMucom* mucom, const char* tag);

    std::string composer;
    std::string title;
    std::string author;
    std::string time;
};


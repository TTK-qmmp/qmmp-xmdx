#include "utils/mucomtag.h"
#include "../cmucom.h"

MucomTag::MucomTag()
{
	composer = "";
	title = "";
	author = "";
	time = "";
}

void MucomTag::LoadTag(CMucom *mucom)
{
	if (!mucom) return;

	composer = GetTagInternal(mucom, "composer");
	title = GetTagInternal(mucom,"title");
	author = GetTagInternal(mucom,"author");
	time = GetTagInternal(mucom,"time");
}

const char* MucomTag::GetTagInternal(CMucom* mucom, const char* tag)
{
	return mucom->GetInfoBufferByName(tag);
}

MucomTag::~MucomTag()
{
}



#pragma once

#include "Text.h"
#include <iostream>

using namespace std;

class FixedText : public Text {
public:
	FixedText();

	void append(string _extra) override;
};
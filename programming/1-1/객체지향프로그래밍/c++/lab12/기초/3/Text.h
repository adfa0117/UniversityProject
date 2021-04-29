#pragma once

#include <string>
#include <iostream>

using namespace std;

class Text{
private:
	string text;
public:
	Text(string _t);
	
	virtual string get() const;
	
	virtual void append(string _extra);
};
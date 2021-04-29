#include "Text.h"

Text::Text(string _t) : text(_t) {}

string Text::get() const{
	return this->text;
}
	
void Text::append(string _extra){
	this->text += _extra;
}


#include "TextEditor.h"

TextEditor::TextEditor()  // Class constructor
{
	LineType* header = new LineType;
	LineType* trailer = new LineType;

	char head[] = "---Top of file---";
	char tail[] = "---Bottom of file---";

	int i = -1;

	for (char c : head)
	{
		header->info[++i] = c;
	}

	i = -1;

	for (char c : tail)
	{
		trailer->info[++i] = c;
	}

	header->next = trailer;
	header->back = NULL;
	trailer->next = NULL;
	trailer->back = header;

	listData = header;
	currentLine = header;
	length = 0;
}

TextEditor::~TextEditor()
// Class destructor
{
	MakeEmpty();
}

bool TextEditor::IsFull() const
// Returns true if there is no room for another ItemType 
//  on the free store; false otherwise.
{
	LineType* location;
	try
	{
		location = new LineType;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		return true;
	}
}

int TextEditor::LengthIs() const
// Post: Number of items in the list is returned.
{
	return length;
}

void TextEditor::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	LineType* tempPtr;

	while (listData != NULL)
	{
		tempPtr = listData;
		listData = listData->next;
		delete tempPtr;
	}
	length = 0;
}


void TextEditor::InsertItem(ItemType* newline)
// item is in the list; length has been incremented.
{
	LineType* newLine = new LineType;
	int pos = -1;
	while (newline[++pos] != '\0')
	{
		newLine->info[pos] = newline[pos];
	}
	newLine->info[pos] = newline[pos];

	if (currentLine->next != NULL)
	{
		newLine->next = currentLine->next;
		newLine->back = currentLine;
		currentLine->next->back = newLine;
		currentLine->next = newLine;
	}
	else
	{
		newLine->next = currentLine;
		newLine->back = currentLine->back;
		currentLine->back->next = newLine;
		currentLine->back = newLine;
	}

	currentLine = newLine;
	++length;
}



void TextEditor::ResetList()
// Post: Current position has been initialized.
{
	currentLine = listData;
}


void TextEditor::GetNextItem(ItemType* item)
// Post:  Current position has been updated; item is current item.
{
	if (currentLine == NULL)
		currentLine = listData;
	else
		currentLine = currentLine->next;
	int i;
	for (i = 0; currentLine->info[i] != '\0'; i++)
		item[i] = currentLine->info[i];
	item[i] = '\0';
}

void TextEditor::GoToTop() {
	while(currentLine->back != NULL)
	{
		currentLine = currentLine->back;
	}
	currentLine = currentLine->next;
}

void TextEditor::GoToBottom() {
	// implement
	while (currentLine->next != NULL)
	{
		currentLine = currentLine->next;
	}
	currentLine = currentLine->back;
}
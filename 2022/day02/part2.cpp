#include <iostream>

int main() {
	std::string line;
	int score = 0;
	char oR = 'A';
	char oP = 'B';
	char oS = 'C';

	while (std::getline(std::cin, line)) {
		if  (line[2] == 'X') {
			if (line[0] == oR)
				score += 3;
			else if (line[0] == oS)
				score += 2;
			else if (line[0] == oP)
				score += 1;
		} else if (line[2] == 'Y') {
			score += 3;
			if (line[0] == oR)
				score += 1;
			else if (line[0] == oS)
				score += 3;
			else if (line[0] == oP)
				score += 2;
		} else if (line[2] == 'Z') {
			score += 6;
			if (line[0] == oR)
				score += 2;
			else if (line[0] == oS)
				score += 1;
			else if (line[0] == oP)
				score += 3;
		}
	}
	
	std::cout << score << std::endl;
	return 0;
}
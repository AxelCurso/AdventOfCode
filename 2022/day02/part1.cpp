#include <iostream>

int main() {
	std::string line;
	int score = 0;

	while (std::getline(std::cin, line)) {
		switch (line[2]) {
			case 'X':
				score += 1;
				if (line[0] == 'A')
					score += 3;
				else if (line[0] == 'C')
					score += 6;
				break;
			case 'Y':
				score += 2;
				if (line[0] == 'B')
					score += 3;
				else if (line[0] == 'A')
					score += 6;
				break;
			case 'Z':
				score += 3;
				if (line[0] == 'C')
					score += 3;
				else if (line[0] == 'B')
					score += 6;
				break;
		}
	}
	
	std::cout << score << std::endl;
	return 0;
}
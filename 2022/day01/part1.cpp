#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	int res = 0;
	int tmp = 0;
	std::string line;

	while (std::getline(std::cin, line)) {
		if (line.size() < 1) {
			// empty line
			if (tmp > res)
				res = tmp;
			tmp = 0;
		} else {
			tmp += atoi(line.c_str());
		}
	}
	if (tmp > res)
		res = tmp;

	std::cout << res << std::endl;

	return 0;
}
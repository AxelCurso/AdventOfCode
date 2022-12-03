#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
	std::vector<int>	res;
	int	tmp = 0;
	std::string line;

	while (std::getline(std::cin, line)) {
		if (line.size() < 1) {
			// empty line
			res.push_back(tmp);
			tmp = 0;
		} else {
			tmp += atoi(line.c_str());
		}
	}
	res.push_back(tmp);
	std::sort(res.begin(), res.end(), std::greater<int>());

	std::cout << res[0]+res[1]+res[2] << std::endl;

	return 0;
}
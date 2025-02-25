#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>

void randArr(std::vector<int>& arr, const int gap, const int size) {
	for (int i = 0; i < size; ++i) {
		arr.push_back(rand() % gap + 1);
		/*std::cout << '[' << arr[i] << "], ";*/
	}
	/*std::cout << std::endl;*/
}

void randFile(std::string fileName, const int gap, const int size) {
	std::vector<int> vector;
	randArr(vector, gap, size);
	std::fstream file(fileName);
	for (int i = 0; i < size; ++i) {
		file << vector[i] << " ";
	}
}

void split(std::string fromFile, std::string file1, std::string file2) {
	std::fstream from(fromFile);
	std::fstream fileA(file1);
	std::fstream fileB(file2);
	int a, b;
	from >> a >> b;
	while (!from.eof()) {
		while (a < b && !from.eof()) {
			fileA << a << " ";
			a = b;
			from >> b;
		}
		fileA << a << " " << -1 << " ";
		from >> a >> b;
		while (a < b && !from.eof()) {
			fileB << a << " ";
			a = b;
			from >> b;
		}
		fileB << a << " " << -1 << " ";
		from >> a >> b;
	}
}

void merge() {

}

int main() {
	srand(time(0));
	std::ofstream f("f.txt");
	f.close();
	randFile("f.txt", 1000, 100);
	std::ofstream fa("fa.txt");
	fa.close();
	std::ofstream fb("fb.txt");
	fb.close();
	split("f.txt", "fa.txt", "fb.txt");
}
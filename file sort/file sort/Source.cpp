#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>

void randArr(std::vector<int>& arr, const int gap,const int size) {
	for (int i = 0; i < size; ++i) {
		arr.push_back(rand() % (gap + 1));
		/*std::cout << '[' << arr[i] << "], ";*/
	}
	/*std::cout << std::endl;*/
}

void arrToFile(std::vector<int>& arr, std::fstream& filename) {
	filename << arr[0];
	for (int i = 0; i < arr.size(); ++i) {
		filename << " " << arr[i];
	}
} 

void merge(std::fstream fileA, std::fstream fileB, std::fstream mergeFile) {
	int a;
	int b;
	fileA >> a;
	fileB >> b;
	while (!fileA.eof() || !fileB.eof()) {
		while (a != -1 && b != -1) {
			if (a < b) {
				mergeFile << a << " ";
				fileA >> a;
			}
			else {
				mergeFile << b << " ";
				fileB >> b;
			}
		}
		mergeFile << -1 << " ";
		fileA >> a;
		fileB >> b;
	}
	if (fileA.eof()) {
		while (!fileB.eof()) {
			fileB >> b;
			mergeFile << b << " ";
		}
	}
	else {
		while (!fileA.eof()) {
			fileA >> a;
			mergeFile << a << " ";
		}
	}
}

void split(std::fstream mergeFile, std::fstream fileA, std::fstream fileB) {
	int a, b;
	mergeFile >> a >> b;
	while (!mergeFile.eof()) {

	}
}

//bool isFileSorted(const std::fstream& filename) {
//
//}
//

int main() {
	std::ofstream file("f.txt");
	file.close();
	std::ofstream file_a("fa.txt");
	file_a.close();
	std::fstream file_b("fb.txt");
	file_b.close();
	std::fstream file_c("fc.txt");
	file_c.close();
	std::fstream f("f.txt");
	std::fstream fa("fa.txt");
	std::fstream fb("fb.txt");
	std::fstream fc("fc.txt");
	int size = 100;
	std::vector<int> array;
	int gap = 1000;
	randArr(array, gap, size);
	arrToFile(array, f);
}
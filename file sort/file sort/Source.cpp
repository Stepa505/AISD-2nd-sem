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

void merge(std::string nameA, std::string nameB, std::string nameOfMergeFile) {
	int a;
	int b;
	std::fstream fileA(nameA);
	std::fstream fileB(nameB);
	std::fstream mergeFile(nameOfMergeFile);
	fileA >> a;
	fileB >> b;
	while (!fileA.eof() || !fileB.eof()) {
		while (a != -1 && b != -1) {
			if (a < b && a != -1) {
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
		mergeFile << -1 << " ";
	}
	else {
		while (!fileA.eof()) {
			fileA >> a;
			mergeFile << a << " ";
		}
		mergeFile << -1 << " ";
	}
}

void split(std::string nameOfMergingFile, std::string nameA, std::string nameB) {
	int a, b;
	std::fstream writingFileA(nameA);
	std::fstream mergingFile(nameOfMergingFile);
	std::fstream writingFileB(nameB);
	mergingFile >> a >> b;
	while (!mergingFile.eof()) {

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
	for (int i = 0; i < size; ++i) {
		int a, b;
		f >> a >> b;
		if (a > b) {
			fa << a << " ";
			a = b;
			f >> b;
		}
		else {
			fa << a << " " << -1 << " ";
			a = b;
			f >> b;
		}
	}
}
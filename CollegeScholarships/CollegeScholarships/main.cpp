//
// main.cpp
// CollegeScholarships
//
// Created by Alex Smarandache on 10/03/2021
// Copyright © Alex Smarandache. All rights reserved. 
//

#include "Faculty.h"

int main(int argc, char* argv[]) 
{
	sma::Faculty best_faculty("in_students.txt", "in_scholarships.txt", "out_scholarship.txt",
		"out_excellence.txt", "out_social.txt");

	try {
		best_faculty.importData();
		best_faculty.exportScholarships();
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}

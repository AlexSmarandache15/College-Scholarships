//
// Scholarship.cpp
// CollegeScholarships
//
// Created by Alex Smarandache on 10/03/2021
// Copyright © Alex Smarandache. All rights reserved. 
//

#include "Scholarship.h"

bool sma::Scholarship::addStudent(const Student& student)
{
	try {
		if (!student.isEligibleForScholarship(min_average)) {
			throw student.getGDPR() + " connot apply for " + this->type;
		}
	}
	catch (std::string e) {
		std::cout << e << std::endl;
		return false;
	}

	students.insert(std::make_pair(student.getAverage(), student));
	return true;
}

void sma::Scholarship::selectFinalList()
{
	auto student = std::begin(students);
	for (; student != std::end(students) && total_sum >= amount; student++) {
		total_sum -= amount;
	}

	if (student != std::end(students)) {
		students.erase(student, std::end(students));
	}
}

void sma::Scholarship::display(std::ostream& out, unsigned int& counter) const
{
	for (auto student = std::begin(students); student != std::end(students); student++) {
		out << ++counter << "\t";
		student->second.printForScholarship(out);
		out << '\n';
	}
}
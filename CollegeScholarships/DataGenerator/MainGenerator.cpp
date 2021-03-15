//
// MainGenerator.cpp
// CollegeScholarships
//
// Created by Alex Smarandache on 12/03/2021
// Copyright © Alex Smarandache. All rights reserved. 
//

#include "Generator.h"
#include <fstream>
#include  <map>
#include <iostream>

using sma::Generator;

int main(int argc, char* argv[]) 
{
	std::map<std::string, std::vector<std::pair<std::string, std::vector<unsigned int>>>> students_map;

	std::vector<std::pair<std::string, std::vector<unsigned int>>> students_spec;

	std::string output_file = "input.txt";
	std::ofstream out(output_file);
	std::string cycles[2] = {"License", "Master"};
	std::string spec[] = { "CR", "CEN", "AIA", "ELA", "ISM", "MR", "TIIS", "ISB", "SCR", "SAI", "IS", "ICC" };
	unsigned int no_students = 0;

	std::vector<unsigned int> years = { 75, 155, 220, 275 };
	students_spec.push_back(std::make_pair(spec[0], years));

	years.clear();
	years = { 75, 151, 213, 265 };
	students_spec.push_back(std::make_pair(spec[1], years));

	years.clear();
	years = { 80, 153, 218, 260 };
	students_spec.push_back(std::make_pair(spec[2], years));

	years.clear();
	years = { 32, 61, 92, 110 };
	students_spec.push_back(std::make_pair(spec[3], years));

	years.clear();
	years = { 31, 58, 90, 105 };
	students_spec.push_back(std::make_pair(spec[4], years));

	years.clear();
	years = { 25, 48, 73, 95 };
	students_spec.push_back(std::make_pair(spec[5], years));

	students_map.insert(std::make_pair(cycles[0], students_spec));
	students_spec.clear();

	years.clear();
	years = { 28, 50 };
	students_spec.push_back(std::make_pair(spec[6], years));

	years.clear();
	years = { 27, 48 };
	students_spec.push_back(std::make_pair(spec[7], years));

	years.clear();
	years = { 18, 35 };
	students_spec.push_back(std::make_pair(spec[8], years));

	years.clear();
	years = { 24, 43 };
	students_spec.push_back(std::make_pair(spec[9], years));

	years.clear();
	years = { 29, 52 };
	students_spec.push_back(std::make_pair(spec[10], years));

	years.clear();
	years = { 28, 47 };
	students_spec.push_back(std::make_pair(spec[11], years));

	students_map.insert(std::make_pair(cycles[1], students_spec));
	students_spec.clear();

	std::vector<sma::MinimalStudent> students;
	std::shared_ptr<Generator> my_generator = my_generator->getGenerator();
	
	my_generator->generateStudents(students, students_map);

	while (students.size() > 1) {
		auto index = my_generator->generateInt(0, students.size() - 1);
		out << students[index] << "\n\n";
		students.erase(std::begin(students) + index);
	}

	out << students[0];

	return 0;
}
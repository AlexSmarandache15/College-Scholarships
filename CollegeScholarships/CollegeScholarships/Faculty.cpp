//
// Faculty.cpp
// CollegeScholarships
//
// Created by Alex Smarandache on 12/03/2021
// Copyright © Alex Smarandache. All rights reserved. 
//

#include "Faculty.h"

sma::Faculty::Faculty(const std::string& students_input, const std::string& scholarships_input, 
	const std::string& scholarship_output, const std::string& excellence_output, const std::string& social_output)
{
	this->students_input = students_input;
	this->scholarships_input = scholarships_input;
	this->outputs = std::make_tuple(social_output, excellence_output, scholarship_output);
	
	this->amounts = std::make_tuple(0, 0, 0);
	this->min_average = 0.0;
	this->max_income = 1350;

	this->excellence = nullptr;
	this->scholarship = nullptr;
	this->social = nullptr;

	all_students = std::make_unique<std::unordered_map<Triplet<std::string, std::string, unsigned int>, unsigned int,
		sma::hash_triplet>>();
}

void sma::Faculty::importData() throw(std::exception)
{
	std::ifstream in(scholarships_input);
	if (!in.is_open()) {
		throw std::exception("scholarship_input not found");
	}
	
	in.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	
	try {
		in >> money;
		in >> std::get<1>(types);
		in >> std::get<1>(amounts);
		in >> std::get<0>(types);
		in >> std::get<0>(amounts);
		in >> max_income;
		in >> std::get<2>(types);
		in >> std::get<2>(amounts);
		in >> min_average;
	}
	catch (std::ifstream::failure e) {
		std::cout << "Wrong input to " << scholarships_input << std::endl;
		in.close();
		return;
	}

	in.close();

	in.open(students_input);
	Student student;
	if (!in.is_open()) {
		throw std::exception("student_input not found");
	}

	try {
		while (!in.eof()) {
			in >> student;
			if (student.isEligibleForScholarship(min_average)) {
				queue_of_scholarship.push(student);
			}
			if (student.isEligibleForExcellence()) {
				deque_of_excellence.push_back(student);
			}
			if (student.isEligibleForSocial(max_income)) {
				stack_of_social.push(student);
			}
			auto index = make_triplet(student.getCycle(), student.getSpecialization(), student.getYear());
			(*all_students)[index]++;
		}
	} catch (std::ifstream::failure e) {
		std::cout << "Wrong input to " << students_input << std::endl;
		in.close();
		return;
	}
	
	in.close();
}

void sma::Faculty::exportScholarships()
{
	std::ofstream out(std::get<0>(outputs));
	double amount = (PERCENT * money) / 100.0;
	money -= amount;
	social = std::make_unique<ListOfPotentialSocialScholarshipHolders>(std::get<0>(amounts), amount, std::get<0>(types), max_income);
	while (!stack_of_social.empty()) {
		social->add(stack_of_social.top());
		stack_of_social.pop();
	}
	social->displayList(out);
	out.close();

	money += social->getTotalSum();

	out.open(std::get<1>(outputs));
	excellence = std::make_unique<ListOfPotentialExcellenceScholarshipHolders>(std::get<1>(amounts), money, std::get<1>(types));
	while (!deque_of_excellence.empty()) {
		excellence->add(deque_of_excellence.front());
		deque_of_excellence.pop_front();
	}
	excellence->displayList(out);
	out.close();

	money = excellence->getTotalSum();
	out.open(std::get<2>(outputs));
	scholarship = std::make_unique<ListOfPotentialScholarshipHolders>(std::get<2>(amounts), money, std::get<2>(types), min_average);
	while (!queue_of_scholarship.empty()) {
		scholarship->add(queue_of_scholarship.front());
		queue_of_scholarship.pop();
	}
	scholarship->calculateDistribution(*all_students);
	scholarship->displayList(out);
	out.close(); 

}
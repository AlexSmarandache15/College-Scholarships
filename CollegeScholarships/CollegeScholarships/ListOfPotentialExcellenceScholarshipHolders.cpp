//
// ListOfPotentialExcellenceScholarshipHolders.cpp
// CollegeScholarships
//
// Created by Alex Smarandache on 11/03/2021
// Copyright © Alex Smarandache. All rights reserved. 
//

#include "ListOfPotentialExcellenceScholarshipHolders.h"

void sma::ListOfPotentialExcellenceScholarshipHolders::add(const Student& student)
{
	auto first = make_triplet(student.getCycle(), student.getSpecialization(), student.getYear());
	auto pos = potentially_students->find(first);
	if (pos == std::end((*potentially_students))) {
		auto second = std::shared_ptr<ExcellenceScholarship>(new ExcellenceScholarship(amount, total_sum, type));
		potentially_students->insert(std::make_pair(first, second));
		pos = potentially_students->lower_bound(first);
	}
	pos->second->addStudent(student);
}

void sma::ListOfPotentialExcellenceScholarshipHolders::displayList(std::ostream& out)
{
	out << this->type << std::endl;
	unsigned int counter = 0;
	std::string _cycle = "", _spec = "";
	int year = -1;
	for (const auto& iterator : *potentially_students) {
		if (_cycle != iterator.first.first) {
			_cycle = iterator.first.first;
			out << "\nCycle: " + _cycle << "\n\n";
		}
		if (_spec != iterator.first.second) {
			_spec = iterator.first.second;
			out << "\nSpecialization: " + _spec << "\n\n";
			counter = 0;
		}
		if (year != iterator.first.third) {
			year = iterator.first.third;
			out << "Year: " << year << "\n";
			out << "Nr\tCode GDPR" << "\tPoints:\n";
		}
		
		iterator.second->setTotalSum(total_sum);
		iterator.second->selectFinalList();
		iterator.second->display(out, counter);
		total_sum = iterator.second->getTotalSum();
	}
}

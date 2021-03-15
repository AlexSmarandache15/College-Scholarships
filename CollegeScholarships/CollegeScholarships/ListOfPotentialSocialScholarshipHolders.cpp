//
// ListOfPotentialSocialScholarshipHolders.cpp
// CollegeScholarships
//
// Created by Alex Smarandache on 11/03/2021
// Copyright © Alex Smarandache. All rights reserved. 
//

#include "ListOfPotentialSocialScholarshipHolders.h"

void sma::ListOfPotentialSocialScholarshipHolders::add(const Student& student)
{
	selected_students.push(student);
}

void sma::ListOfPotentialSocialScholarshipHolders::displayList(std::ostream& out)
{
	unsigned int _total_sum = total_sum;
	while (!selected_students.empty() && total_sum >= amount) {
		total_sum -= amount;
		auto first = sma::make_triplet(selected_students.top().getCycle(), selected_students.top().getSpecialization(),
			selected_students.top().getYear());
		auto pos = potentially_students->find(first);
		if (pos == std::end((*potentially_students))) {
			auto second = std::shared_ptr<SocialScholarship>(new SocialScholarship(max_income, amount, total_sum, type));
			potentially_students->insert(std::make_pair(first, second));
			pos = potentially_students->lower_bound(first);
		}
		pos->second->addStudent(selected_students.top());
		selected_students.pop();
	}

	out << this->type << std::endl;
	std::string _cycle = "", _spec = "";
	int year = -1;
	total_sum = _total_sum;
	unsigned int counter = 0;
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
			out << "Nr\tCode GDPR" << "\tIncome:\n";
		}
		iterator.second->setTotalSum(total_sum);
		iterator.second->selectFinalList();
		iterator.second->display(out, counter);
		total_sum = iterator.second->getTotalSum();
	}


}
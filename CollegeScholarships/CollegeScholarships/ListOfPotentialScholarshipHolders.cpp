//
// ListOfPotentialScholarshipHolders.cpp
// CollegeScholarships
//
// Created by Alex Smarandache on 11/03/2021
// Copyright © Alex Smarandache. All rights reserved. 
//

#include "ListOfPotentialScholarshipHolders.h"

void sma::ListOfPotentialScholarshipHolders::add(const Student& student)
{
	auto first = make_triplet(student.getCycle(), student.getSpecialization(), student.getYear());
	auto pos = potentially_students->find(first);
	if (pos == std::end((*potentially_students))) {
		auto second = std::shared_ptr<Scholarship>(new Scholarship(min_average, amount, total_sum, type));
		potentially_students->insert(std::make_pair(first, second));
		pos = potentially_students->lower_bound(first);
	}
	pos->second->addStudent(student);
}

void sma::ListOfPotentialScholarshipHolders::displayList(std::ostream& out)
{
	out << this->type << std::endl;
	std::string _cycle = "", _spec = "";
	int year = -1;
	unsigned int counter = 0;
	auto list_it = std::begin(money_for_spec);
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
			out << "Nr\tCode GDPR" << "\tAverage:\n";
		}
		iterator.second->setTotalSum(*list_it);
		if (list_it != std::end(money_for_spec)) {
			list_it++;
		}
		iterator.second->selectFinalList();
		iterator.second->display(out, counter);
		if (list_it != std::end(money_for_spec)) {
			(*list_it) += iterator.second->getTotalSum();
		}
	}
}

void sma::ListOfPotentialScholarshipHolders::calculateDistribution
(std::unordered_map<sma::Triplet<std::string, std::string, unsigned int>, unsigned int, hash_triplet>& all_students)
{

	unsigned int no_students = 0;
	for (const auto& it : all_students) {
		no_students += it.second;
	}

	double amount_per_student = (double)total_sum / (double)no_students;
	
	std::unordered_map<std::string, unsigned int> specialization;
	std::unordered_map<std::string, std::vector<std::pair<unsigned int, double>>> map_students;

	for (auto&& it : *potentially_students) {
		specialization[it.first.second]++;
	}

	for (const auto& it : *potentially_students) {
		map_students[it.first.second].push_back(std::make_pair(it.second->getSize(), 
			(amount_per_student * (all_students[it.first] / specialization[it.first.second] ))));
	}
	
	double dif = 0.0;

	std::for_each(std::begin(*potentially_students), std::end(*potentially_students),
		[&](const auto& it) {
			auto& var = map_students[it.first.second];
			for (auto& iterator : var) {
				double number = amount_per_student * iterator.first;
				if (number < iterator.second) {
					dif += iterator.second - number;
					iterator.second = number + 0.1;
				} 
				else if (number > iterator.second && dif > 0.0) {
					if (dif < (number - iterator.second)) {
						iterator.second += dif;
						dif = 0.0;
					}
					else {
						dif += iterator.second, dif -= number;
						iterator.second = number + 0.1;
					}
				}
			}
			for (auto& iterator : var) {
				double number = amount_per_student * iterator.first;
				if (number > iterator.second && dif > 0) {
					if (dif < (number - iterator.second)) {
						iterator.second += dif;
						dif = 0.0;
					}
					else {
						dif += iterator.second, dif -= number;
						iterator.second = number + 0.1;
					}
				}
			}
		});

	for (const auto it : *potentially_students) {
		auto& var = map_students[it.first.second];
		for (const auto& iterator : var) {
			money_for_spec.push_back(iterator.second);
		}
	}

}

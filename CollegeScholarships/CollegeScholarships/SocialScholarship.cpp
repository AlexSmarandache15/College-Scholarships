//
// SocialScholarship.cpp
// CollegeScholarships
//
// Created by Alex Smarandache on 10/03/2021
// Copyright © Alex Smarandache. All rights reserved. 
//

#include "SocialScholarship.h"

namespace sma
{
	bool SocialScholarship::addStudent(const Student& student)
	{
		try {
			if (!student.isEligibleForSocial(max_income)) {
				throw student.getGDPR() + " connot apply for " + this->type;
			}
		}
		catch (std::string e) {
			std::cout << e << std::endl;
			return false;
		}

		int coef = -student.getIncome();

		if (student.isOrphan()) {
			coef += 10 * this->max_income;
		}
		else if (student.isSick()) {
			coef += 5 * this->max_income;
		}

		students.insert(std::make_pair(coef, student));

		return true;
	}

	void SocialScholarship::selectFinalList()
	{
		auto student = std::begin(students);
		for (; student != std::end(students) && total_sum >= amount; student++) {
			total_sum -= amount;
		}

		if (student != std::end(students)) {
			students.erase(student, std::end(students));
		}
	}

	void SocialScholarship::display(std::ostream& out, unsigned int& counter) const
	{
		for (auto student = std::begin(students); student != std::end(students); student++) {
			out << ++counter << "\t";
			student->second.printForSocial(out);
			out << '\n';
		}
	}
};

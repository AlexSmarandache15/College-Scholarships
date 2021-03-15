//
// Bursary.h
// CollegeScholarships
//
// Created by Alex Smarandache on 10/03/2021
// Copyright © Alex Smarandache. All rights reserved. 
//

#pragma once
#include "Student.h"
#include <map>

namespace sma
{
	class Bursary
	{
	public:
		Bursary(const unsigned int& amount = 0, const unsigned int total_sum = 0, const std::string& type = "") :
			amount(amount), total_sum(total_sum), type(type) { }
		const unsigned int& getAmount()  const { return this->amount; }
		const unsigned int& getTotalSum() const { return this->total_sum; }
		const unsigned int& getSize()     const { return std::size(students); }
		void setTotalSum(const unsigned int& total_sum) { this->total_sum = total_sum; }
		virtual bool addStudent(const Student&) = 0;
		virtual void selectFinalList() = 0;
		virtual void display(std::ostream&, unsigned int&) const = 0;
		virtual ~Bursary() {  }
	protected:
		unsigned int amount;
		unsigned int total_sum;
		std::string type;
		std::multimap<double, Student, std::greater<>> students;
	};
}



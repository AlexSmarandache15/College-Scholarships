//
// ListOfPotentialBursaryHolders.h
// CollegeScholarships
//
// Created by Alex Smarandache on 11/03/2021
// Copyright © Alex Smarandache. All rights reserved. 
//

#pragma once
#include "Bursary.h"
#include "triplet.h"

namespace sma
{
	class ListOfPotentialBursaryHolders
	{
	public:
		ListOfPotentialBursaryHolders(const unsigned int& amount, const unsigned int& total_sum, const std::string& type) :
			amount(amount), total_sum(total_sum), type(type) {
			potentially_students = std::make_unique<std::map<sma::Triplet<std::string, std::string,
				unsigned int>, std::shared_ptr<Bursary>>>();
		}
		virtual void add(const Student&) = 0;
		virtual void displayList(std::ostream&) = 0;
		const unsigned int& getTotalSum() const { return this->total_sum; }
		virtual ~ListOfPotentialBursaryHolders() {  }
	protected:
		std::unique_ptr<std::map<sma::Triplet<std::string, std::string, unsigned int>,
			std::shared_ptr<Bursary>>> potentially_students;
		unsigned int amount;
		unsigned int total_sum;
		std::string type;
	};
}



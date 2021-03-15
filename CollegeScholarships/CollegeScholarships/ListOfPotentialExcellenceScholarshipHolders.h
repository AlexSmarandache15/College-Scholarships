//
// ListOfPotentialExcellenceScholarshipHolders.h
// CollegeScholarships
//
// Created by Alex Smarandache on 11/03/2021
// Copyright © Alex Smarandache. All rights reserved. 
//

#pragma once
#include "ListOfPotentialBursaryHolders.h"
#include "ExcellenceScholarship.h"

namespace sma
{
	class ListOfPotentialExcellenceScholarshipHolders : public ListOfPotentialBursaryHolders
	{
	public:
		ListOfPotentialExcellenceScholarshipHolders(const unsigned int& amount, const unsigned int& total_sum, const std::string& type)
			: ListOfPotentialBursaryHolders(amount, total_sum, type) {
		}
		void add(const Student&) override;
		virtual void displayList(std::ostream&) override;
	};
}


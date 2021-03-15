//
// ListOfPotentialSocialScholarshipHolders.h
// CollegeScholarships
//
// Created by Alex Smarandache on 11/03/2021
// Copyright © Alex Smarandache. All rights reserved. 
//

#pragma once
#include "ListOfPotentialBursaryHolders.h"
#include "SocialScholarship.h"
#include <queue>

namespace sma
{
	class ListOfPotentialSocialScholarshipHolders : public ListOfPotentialBursaryHolders
	{
	public:
		ListOfPotentialSocialScholarshipHolders(const unsigned int& amount, const unsigned int& total_sum, const std::string& type, const unsigned int& max_income = 1000) :
			ListOfPotentialBursaryHolders(amount, total_sum, type), max_income(max_income) {
		}
		void add(const Student&) override;
		virtual void displayList(std::ostream&) override;
	private:
		struct comp
		{
			bool cond1(const Student& x, const Student& y) {
				return ((x.isOrphan() < y.isOrphan()) || ((x.isOrphan() == y.isOrphan()) && (x.isSick() < y.isSick())));
			}
			bool cond2(const Student& x, const Student& y) {
				return ( (x.isOrphan() == y.isOrphan()) && (x.isSick() == y.isSick()) && (x.getIncome() > y.getIncome()) );
			}

			bool operator()(const Student& x, const Student& y) {
				return cond1(x,y) || cond2(x,y);
			}
		};
		std::priority_queue<Student, std::vector<Student>, comp> selected_students;
		unsigned int max_income;
	};
}



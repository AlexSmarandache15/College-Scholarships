//
// Faculty.h
// CollegeScholarships
//
// Created by Alex Smarandache on 12/03/2021
// Copyright © Alex Smarandache. All rights reserved. 
//

#pragma once
#include "ListOfPotentialScholarshipHolders.h";
#include "ListOfPotentialExcellenceScholarshipHolders.h";
#include "ListOfPotentialSocialScholarshipHolders.h";
#include <stack>
#include <queue>
#include <deque>
#include <tuple>
#include <exception>
#define PERCENT 30

namespace sma
{
	class Faculty
	{
	public:
		Faculty(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);
		void importData() throw (std::exception);
		void exportScholarships();
	private:
		std::stack<Student> stack_of_social;
		std::queue<Student> queue_of_scholarship;
		std::deque<Student> deque_of_excellence;
		std::unique_ptr<ListOfPotentialScholarshipHolders> scholarship;
		std::unique_ptr<ListOfPotentialExcellenceScholarshipHolders> excellence;
		std::unique_ptr<ListOfPotentialSocialScholarshipHolders> social;
		std::unique_ptr<std::unordered_map<Triplet<std::string, std::string, unsigned int>, unsigned int, hash_triplet>> all_students;
		std::string students_input;
		std::string scholarships_input;
		std::tuple<std::string, std::string, std::string> types;
		std::tuple<std::string, std::string, std::string> outputs;
		std::tuple<unsigned int, unsigned int, unsigned int> amounts;
		double money;
		unsigned int max_income;
		double min_average;
	};
}



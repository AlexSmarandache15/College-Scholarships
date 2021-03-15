//
// Generator.cpp
// CollegeScholarships
//
// Created by Alex Smarandache on 12/03/2021
// Copyright © Alex Smarandache. All rights reserved. 
//

#include "Generator.h"

std::shared_ptr<sma::Generator> sma::Generator:: instance = nullptr;


std::shared_ptr<sma::Generator>& sma::Generator::getGenerator()
{
	if (Generator::instance == nullptr) {
		Generator::instance = std::shared_ptr<Generator>(new Generator());
	}
	return instance;
}

void sma::Generator::generateStudents(std::vector<MinimalStudent>& students, 
    std::map<std::string, std::vector<std::pair<std::string, std::vector<unsigned int>>>>& map_students)
{
    std::unordered_set<std::string> gdpr;
    std::for_each(std::begin(map_students), std::end(map_students), [&](const auto& map_it) {
        for (const auto itv1 : map_it.second) {
            auto displacement = std::begin(itv1.second);
            for (auto iterator = std::begin(itv1.second); iterator != std::end(itv1.second); iterator++) {
                unsigned long value;
                if (iterator == std::begin(itv1.second)) {
                    value = *iterator;
                }
                else {
                    value = (*iterator) - (*displacement);
                }
                displacement = iterator;
                while (value--) {
                    MinimalStudent my_student;
                    my_student.cycle = map_it.first;
                    my_student.specialization = itv1.first;
                    std::string str = generateString();
                    while (gdpr.find(str) != std::end(gdpr)) {
                        str = generateString();
                    }
                    gdpr.insert(str);
                    my_student.gdpr = str;
                    my_student.year = iterator - std::begin(itv1.second) + 1;
                    generateStudent(my_student);
                    students.push_back(my_student);
                }
            }
        }
        });
}

void sma::Generator::generateStudent(sma::MinimalStudent& student) 
{
    int num = generateInt(1, 10);
    student.tax = (num < 4) ? false : true;
    double grade = generateDouble(4, 10);
    student.averrage_grades = grade;
    student.integralist = (grade < 5) ? false : true;
    student.performance_dossier = (grade == 10.0) ? true : false;
    student.performances_points = (grade == 10.0) ? generateInt(30, 120) : 0;
    student.income = generateInt(0, 3350);
    student.social_dossier = (student.income > MAX_SALARY) ? false : true;
    student.age = generateInt(18, 40);
    num = generateInt(1, 10);
    student.orphan = (num > 8) ? true : false;
    num = generateInt(1, 10);
    student.sick = (num > 8) ? true : false;
}
#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>

struct Course {
    std::string courseNumber;
    std::string courseTitle;
    std::vector<std::string> prerequisites;

    Course() {}
    Course(std::string num, std::string title) : courseNumber(num), courseTitle(title) {}
};

// Function to load data from the file
void loadCourses(std::unordered_map<std::string, Course>& courses, bool& isLoaded) {
    const std::string filename = "Input.csv";  // Hardcoded filename
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cout << "Error: Could not open file " << filename << std::endl;
        return;
    }

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string courseNum, courseTitle, prereq;
        getline(ss, courseNum, ',');
        getline(ss, courseTitle, ',');

        Course course(courseNum, courseTitle);

        while (getline(ss, prereq, ',')) {
            course.prerequisites.push_back(prereq);
        }

        // Add the course to the map
        courses[courseNum] = course;
    }

    isLoaded = true;  // Set the flag to true once courses are loaded
    std::cout << "Courses loaded successfully from " << filename << ".\n";
}

// Function to print all courses in alphabetical order
void printAllCourses(const std::unordered_map<std::string, Course>& courses) {
    std::vector<Course> courseList;

    for (const auto& pair : courses) {
        courseList.push_back(pair.second);
    }

    // Sort courses alphabetically by course number
    std::sort(courseList.begin(), courseList.end(), [](const Course& a, const Course& b) {
        return a.courseNumber < b.courseNumber;
    });

    for (const auto& course : courseList) {
        std::cout << course.courseNumber << ", " << course.courseTitle << std::endl;
    }
}

// Function to print course information including prerequisites
void printCourseInfo(const std::unordered_map<std::string, Course>& courses, const std::string& courseNum) {
    auto it = courses.find(courseNum);

    if (it != courses.end()) {
        const Course& course = it->second;
        std::cout << "Course Number: " << course.courseNumber << std::endl;
        std::cout << "Course Title: " << course.courseTitle << std::endl;

        if (!course.prerequisites.empty()) {
            std::cout << "Prerequisites: ";
            for (const auto& prereq : course.prerequisites) {
                std::cout << prereq << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "No prerequisites" << std::endl;
        }
    } else {
        std::cout << "Course not found." << std::endl;
    }
}

// Function to display the menu and handle user choices
void displayMenu() {
    std::cout << "1. Load Data Structure\n";
    std::cout << "2. Print course list\n";
    std::cout << "3. Print course information\n";
    std::cout << "9. Exit\n";
    std::cout << "Enter option: ";
}

int main() {
    std::unordered_map<std::string, Course> courses;
    int choice;
    std::string courseNum;
    bool isLoaded = false;  // Flag to check if courses are loaded

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                loadCourses(courses, isLoaded);
                break;
            case 2:
                if (!isLoaded) {
                    std::cout << "Error: Please load the data structure first (option 1).\n";
                } else {
                    printAllCourses(courses);
                }
                break;
            case 3:
                if (!isLoaded) {
                    std::cout << "Error: Please load the data structure first (option 1).\n";
                } else {
                    std::cout << "Enter course number: ";
                    std::cin >> courseNum;
                    printCourseInfo(courses, courseNum);
                }
                break;
            case 9:
                std::cout << "Exiting program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid option. Please select one of the given options." << std::endl;
        }
    }

    return 0;
}


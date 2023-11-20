#include <iostream>
#include "Developer.h"
#include "Project.h"
#include "Company.h"

using namespace std;

int main() {
    /*Developer developer1("Dezso Szabolcs", 1000, MID);
    Developer developer2("Szasz Alpar", 1500, MID);
    cout<<developer1<<endl;
    cout<<developer2<<endl;

    Project project1("GraphSoft", 2003, 2015);
    Project project2("RobotiCS", 2003, 0);
    cout<<project1<<endl;
    cout<<project2<<endl;

    project1.addDeveloper(&developer1);
    project1.addDeveloper(&developer2);

    cout<<project1<<endl;*/

    Company company1("My first company");

    company1.readProjects("projects.txt");
    company1.printProjects();

    company1.readDevelopers("developers.txt");
    company1.printDevelopers();

    company1.readProjectDevelopers("projects_developers.txt");
    cout<<"After delegating the developers top the projects the projects of the company are:"<<endl;
    company1.printProjects();

    company1.printDevelopersOrderedBySalary();
    company1.printDevelopersOrderedByName();
    company1.printProjectsOrderedByStartYearAndName();

    cout<<"Developer with max project:"<<endl;
    company1.getDeveloperWithMaxProjects();

    return 0;
}

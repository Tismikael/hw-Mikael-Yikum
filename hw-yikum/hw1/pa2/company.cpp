#include "company.hpp"
#include <iostream>

// Initializes the tracker with n students and their 1-person companies.
CompanyTracker::CompanyTracker(int n)
{
    numCompanies = n;
    companies = new Company * [numCompanies];
    for (int i = 0; i < numCompanies; ++i)
        companies[i] = new Company();
}

// Deallocates all dynamically allocated memory.
CompanyTracker::~CompanyTracker()
{
    for (int i = 0; i < numCompanies; ++i){
        //Turn all the companies into individual companies
        split(i);    
        delete companies[i];
    }  
    delete[] companies;
}




void CompanyTracker::merge(int i, int j)
{
    
      //Check for bounds. If either i or j are out of range, merge doesn't do anything.
    if (i < 0 || i >= numCompanies) return;
    if (j < 0 || j >= numCompanies) return;

    //Create two Companies
    Company* company1 = helperLargestCompany(companies[i]);
    Company* company2 = helperLargestCompany(companies[j]);

    //Set these companies to their largest companies if applicable


    //Check if the two Companies are the same company. Don't do anything if true
    //If i and j already belong to the same company(or are the same), merge doesn't do
    //anything.
    if ((company1 == company2) || ((company1->parent == company2->parent) && (company1->parent != nullptr && company2->parent != nullptr))) return;

    //Otherwise, create a new company that will be the parent company
    
    Company* parentcompany = new Company();

    //Set company1 and company2 to be the subcompanies of parentcompany
    parentcompany->merge1 = company1;
    parentcompany->merge2 = company2;

    //Make parentcompany the parent for both companies
    company1->parent = parentcompany;
    company2->parent = parentcompany;
}



void CompanyTracker::split(int i)
{
  
       //Check for bounds. If i is out of range, do nothing.
    if (i < 0 || i >= numCompanies) return;

    //Find the largestcompany companies[i] belongs to
    Company* largestcompany = helperLargestCompany(companies[i]);

    // If i's largest company is a 1-person company, split doesn't do anything
    if ((largestcompany->merge1 == nullptr) && (largestcompany->merge2 == nullptr)) return;

    else
    {
        //set both subcompanies' parent to nullptr
        if (largestcompany->merge1 != nullptr){
            largestcompany->merge1->parent = nullptr;
        }

        if (largestcompany->merge2 != nullptr){
            largestcompany->merge2->parent = nullptr;
        }

        delete largestcompany;
    }

}



bool CompanyTracker::inSameCompany(int i, int j)
{
    
    //Return false if i or j (or both) is out of range.
    if (i < 0 || i >= numCompanies || j < 0 || j >= numCompanies) return false;

    //Return True of i == j
    if (i == j) return true;

    //Find the largest companies companies[i] and companies[j] belong to
    Company* company1 = helperLargestCompany(companies[i]);
    Company* company2 = helperLargestCompany(companies[j]);

    //check if company1 and company2 are the same
    if (company1 == company2) return true;
    else{
        return false;
    }

}

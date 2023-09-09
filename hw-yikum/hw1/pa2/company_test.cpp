#include <iostream>
#include "company.hpp"

void test(CompanyTracker& company, int comp1, int comp2, std::string result){

    std::cout << "For company {" << comp1 << "} and company {" << comp2 << "}\n";
    if (company.inSameCompany(comp1, comp2) == true){
        std::cout << "Expected result: " << result << "\n   Final result: Yes\n";  
    }

    else{
        std::cout << "Expected result: " << result << "\n   Final result: No\n";
    }

    std::cout << std::endl;
}


int main(int argc, char* argv[]){

    int num = 5;
    CompanyTracker tracker(num);

    std::cout << "Test suite for " << num << " companies: ";

    for (int i = 0; i < num; ++i){
        std::cout << "{" << i << "}";
    }

    std::cout << "\nIn same company? Yes if true, No if false\n";

    std::cout << "Case 1: OUT OF BOUNDS" << std::endl; 
    std::cout << "Merge(0, 5)   =>   {0}, {1}, {2}, {3}, {4}\n";
    tracker.merge(0, 5);
    test(tracker, 0, 5, "No");

    std::cout << "Merge(-1, 1)  =>   {0}, {1}, {2}, {3}, {4}\n";
    tracker.merge(-1, 1);
    test(tracker, -1, 1, "No");

    std::cout << "Split(-3)     =>   {0}, {1}, {2}, {3}, {4}\n";
    tracker.split(-3);
    test(tracker,-3, 0, "No");

    std::cout << "Split(2)      =>   {0}, {1}, {2}, {3}, {4}\n";
    tracker.split(2);
    test(tracker, 2, 2, "Yes");

    std::cout << "Case 2: SAME COMPANY" << std::endl;
    std::cout << "Merge(3, 3)   =>   {0}, {1}, {2}, {3}, {4}\n";
    tracker.merge(3,3);
    test(tracker, 3, 3, "Yes");

    std::cout << "Merge(2, 4)   =>   {0}, {1}, {{2}, {4}}, {3}\n";
    tracker.merge(2,4);
    test(tracker, 2, 4, "Yes");

    std::cout << "Merge(0, 1)   =>   {{0}, {1}}, {{2}, {4}}, {3}\n";
    tracker.merge(0, 1);
    test(tracker, 0, 1, "Yes");

    test(tracker, 0, 3, "No");
    test(tracker, 1, 2, "No");

    std::cout << "Merge(0, 3)   =>   { {{0}, {1}}, {3} }, {{2}, {4}}\n";
    tracker.merge(0, 3);
    test(tracker, 0, 3, "Yes");

    test(tracker, 1, 3, "Yes");
    test(tracker, 3, 4, "No");

    std::cout << "Merge(3, 2)   =>   { {{{0}, {1}}, {3}} , {{2}, {4}} }\n";
    tracker.merge(3,2);
    test(tracker, 3, 2, "Yes");
    test(tracker, 0, 4, "Yes");

    std::cout << "Case 3: SPLIT" << std::endl;
    std::cout << "Split(2)      =>   { {{0}, {1}}, {3} }, {{2}, {4}}\n";
    tracker.split(2);
    test(tracker, 2, 4, "Yes");

    std::cout << "Split(0)      =>   {{0}, {1}}, {3}, {2}, {4}\n";
    tracker.split(0);
    test(tracker, 0, 1, "Yes");
    test(tracker, 0, 3, "No");
    test(tracker, 1, 3, "No");

    std::cout << "Split(4)      =>   {{0}, {1}}, {3}, {2}, {4}\n";
    tracker.split(4);
    test(tracker, 0, 4, "No");
    test(tracker, 2, 4, "No");

    std::cout << "End of tests" << std::endl;

    return 0;
}
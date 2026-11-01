#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

// Step 1: Define Student class
class Student {
private:
    pair<int, int> name;
    bool vaccinated;

public:
    // Constructor
    Student(pair<int, int> n, bool v) : name(n), vaccinated(v) {}

    // Getters
    pair<int, int> get_name() const { 
        return name; 
    }
    
    bool is_vaccinated() const { 
        return vaccinated; 
    }

    // Step 2: Overload comparison operators
    bool operator==(const Student& p) const {
        return this->name == p.name;
    }

    bool operator<(const Student& p) const {
        return this->name < p.name;
    }

    bool operator>(const Student& p) const {
        return this->name > p.name;
    }
};

// Step 3: Helper function to generate a random Student
Student generate_random_Student(int size) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, size);
    uniform_int_distribution<int> bool_dist(0, 1);

    pair<int, int> random_name = {dist(gen), dist(gen)};
    bool random_vac = (bool_dist(gen) == 1);

    return Student(random_name, random_vac);
}

// Step 4: Check if student needs vaccination using Binary Search
bool needs_vaccination(const Student& target, const vector<Student>& people) {
    int low = 0;
    int high = people.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (people[mid] == target) {
            // Found in list -> needs vaccination if NOT already vaccinated
            return !people[mid].is_vaccinated();
        }
        else if (people[mid] < target) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }

    // Student not found in list -> requires vaccination
    return true;
}

// Step 5: Search test driver using std::chrono timing
void search_test(int size, const Student& p) {
    vector<Student> people;
    people.reserve(size);

    for (int i = 0; i < size; i++) {
        people.push_back(generate_random_Student(size));
    }

    sort(people.begin(), people.end());

    auto begin = chrono::steady_clock::now();
    bool search_result = needs_vaccination(p, people);
    auto end = chrono::steady_clock::now();

    cout << "Time taken to search = "
         << chrono::duration_cast<chrono::microseconds>(end - begin).count()
         << " microseconds" << endl;

    if (search_result) {
        cout << "Student (" << p.get_name().first << " " << p.get_name().second
             << ") needs vaccination." << endl;
    } else {
        cout << "Student (" << p.get_name().first << " " << p.get_name().second
             << ") does not need vaccination." << endl;
    }
}

// Step 6: Main execution
int main() {
    Student p = generate_random_Student(1000);

    search_test(1000, p);
    search_test(10000, p);
    search_test(100000, p);

    return 0;
}
#include <iostream>

using namespace std;

struct AddressBook
{
    struct BirthDay
    {
        int year, month, day;
    };

    char name[21];
    BirthDay birth;
    long long phonenum;
    char address[51];

    void init() {
        cin >> name >> birth.year >> birth.month >> birth.day >> phonenum; 
        cin >> ws; cin.getline(address, 51, '\n');
    }

    void disp() {
        printf("%s %d %d %d %lld %s\n", name, birth.year, birth.month, birth.day, phonenum, address);
    }

    int birthday() {
        // 辅助 sort
        return birth.year * 10000 + birth.month * 100 + birth.day;
    }
};


void bubbleSort(AddressBook* A, int n) {
    // sort by birthday
    
    for (int i=n-1; i>=0; --i) {
        bool exist_swap = false;
        for (int j=0; j<i; ++j) {
            if (A[j].birthday() < A[j+1].birthday()) swap(A[j], A[j+1]), exist_swap = true;
        }
        if (! exist_swap) break;
    }
}



int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    AddressBook books[10];

    for (int i=0; i<n; ++i) {
        books[i].init();
    }

    bubbleSort(books, n);
    
    for (int i=0; i<n; ++i) {
        books[i].disp();
    }
    

    return 0;
}

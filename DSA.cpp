#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Global variables declaration
int n;
string* A; // Declare a global pointer to a string array
string* originalA; // Declare another global pointer to store the original array
// Declaration of all function
void linear();
void SimpleSort();
void bubble();
void selection();
void binarySearch();
void insertion();

int main() {
    // Accept user input for array size
    cout << "Enter the size of the array: ";
    cin >> n;
    cin.ignore(); // Ignore the leftover newline character

    // Dynamically allocate memory for the array
    A = new string[n];
    originalA = new string[n]; // Allocate memory for the original array

    // Accept array elements from the user
    for (int i = 0; i < n; i++) {
        cout << "Enter the element of the array at index " << i << ": ";
        getline(cin, A[i]);
        originalA[i] = A[i]; // Copy elements to the original array
    }

    char cont;
    do {
        int opt,key;
        cout<<"\n what do you want? searching or sorting \n 1 : for searching \n 2: for sorting \n ";
        cout<<"enter your your choice : ";
        cin >> opt;
        cin.ignore();
        if(opt==1){
            cout<<"Enter your option number of the function you want \n 1: for linear \n 2: for binary search \n";
            cout<<" enter your choice : ";
            cin >> key;
            cin.ignore(); // Ignore the leftover newline character
             if (key == 1) {
               linear();
            } else if (key== 2 ) {
               binarySearch();
          }
         }

        else if(opt==2){
            cout<<"\n your option is sorting ";
            cout<<"Enter your option number of the function you want \n 1: for simple sort \n 2: for bubble \n 3: for selection \n 4: for insertion:\n ";
            cout<<"enter your choice : ";
            cin >>key;
            cin.ignore();
            if(key==1){
            SimpleSort();
           }else if (key == 2) {
            bubble();
           } else if (key==3) {
            selection();
           } else if (key==4) {
            insertion();
          }
          else
          {
          	     cout<<"you enter wrong key!!!";
          }

        }
        else{
            cout<<"you enter wrong key!!!";
        }


        cout << "Press (C) to continue function or press other key to stop: ";
        cin >> cont;
        cin.ignore(); // Ignore the leftover newline character
    } while (cont == 'c'||cont == 'C');

    // Clean up dynamically allocated memory
    delete[] A;
    delete[] originalA;

    return 0;
}

void linear() {
    string data;
        int loc = -1;
        cout << "Data to be searched: ";
        getline(cin, data);

        for (int i = 0; i < n; i++) {
            if (A[i] == data) {
                loc = i;
                break;
            }
        }

        if (loc != -1) {
            cout << data << " is found at index " << loc << endl;
        } else {
            cout << "\nData is not found" << endl;
        }



}
void binarySearch() {
    // Ensure the array is sorted before performing binary search
    sort(A, A + n);

    string data;
    char opt;
    do {
        int loc = -1;
        cout << "Data to be searched: ";
        getline(cin, data);

        int lb = 0, ub = n - 1, mid;

        while(lb <= ub) {
            mid = (lb + ub) / 2;
            if (A[mid] == data) {
                loc = mid;
                break;
            } else if (A[mid] < data) {
                lb = mid + 1;
            } else {
                ub = mid - 1;
            }
        }
            cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

        if (loc != -1) {
            cout << "\n" <<data << " is found at index " << loc << endl;
        } else {
            cout << "\nData is not found" << endl;
        }
        cout << "\nPress (Y) to search again, or press any other key to exit: ";
        cin >> opt;
        cin.ignore(); // Ignore the leftover newline character

    } while (opt == 'y' || opt == 'Y');

    // Restore the original order of the array
    for (int i = 0; i < n; i++) {
        A[i] = originalA[i];
    }
}

void SimpleSort()
{
  for(int i=0;i<n-1;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if(A[i]>A[j])
      {
        string temp=A[i];
        A[i]=A[j];
        A[j]=temp;
      }

    }
  }

  cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
        // Restore the original order of the array
    for (int i = 0; i < n; i++) {
        A[i] = originalA[i];
    }
}

void bubble() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                string temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
        // Restore the original order of the array
    for (int i = 0; i < n; i++) {
        A[i] = originalA[i];
    }
}

void selection() {
    for(int i = 0; i < n - 1; i++) {
        int sm = i;
        for(int j = i + 1; j < n; j++) {
            if(A[j] < A[sm]) {
                sm = j;
            }
        }
        string temp = A[sm];
        A[sm] = A[i];
        A[i] = temp;
    }

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
        // Restore the original order of the array
    for (int i = 0; i < n; i++) {
        A[i] = originalA[i];
    }
}

void insertion() {
    for (int i = 1; i < n; i++) {
        string data = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > data) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = data;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
        // Restore the original order of the array
    for (int i = 0; i < n; i++) {
        A[i] = originalA[i];
    }
}

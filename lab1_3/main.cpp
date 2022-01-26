#include <iostream>
#include "sequence.h"
#include "listsequence.h"
#include "listsequence.cpp"
#include "isorter.h"
#include "isorter.cpp"
#include <fstream>
#include "extrafunctions.h"
#include "graphtests.h"
#include <cstring>

using namespace std;

// Код из ArrayReversedBubbleSort.exe
// В *argv[] передаются: количество элементов; тип структуры, на которой
// строится последоватльность; тип генерируемых данных; тип сортировки

const char * MENU_SEQUENCE_TYPE[] = {"Sequence type:",
                                     "Exit",
                                     "Linked List",
                                     "Array Sequence"};
const int MENU_SEQUENCE_TYPE_SIZE = sizeof(MENU_SEQUENCE_TYPE) / sizeof(MENU_SEQUENCE_TYPE[0]);

const char * SORT_TYPE[] = {"Sort type:",
                            "Cancel",
                            "BubbleSort",
                            "ShakerSort",
                            "MergeSort",
                            "HeapSort",
                            "QuickSort"};
const int SORT_TYPE_SIZE = sizeof(SORT_TYPE) / sizeof(SORT_TYPE[0]);

const char * GENERATION_TYPE[] = {"Data type to generate:",
                                  "Cancel",
                                  "Sorted",
                                  "Reversed",
                                  "Random"};
const int GENERATION_TYPE_SIZE = sizeof(GENERATION_TYPE) / sizeof(GENERATION_TYPE[0]);

int dialog (const char *msgs[], int n);
void func_generate_type(Sequence<int> *seq, size_t num);
void func_sort_type(Sequence<int> *seq);

int main(int argc, char *argv[]) {
    size_t num;

    int SequenceType;

    Sequence<int> *seq = nullptr;
    do{
        cout << "Number of elements: ";
        cin >> num;

        SequenceType = dialog(MENU_SEQUENCE_TYPE, MENU_SEQUENCE_TYPE_SIZE);

        switch(SequenceType) {
            case 0:
                break;
            case 1:
                seq = (Sequence<int> *) new ListSequence<int>;
                func_generate_type(seq, num);
                break;
            case 2:
                seq = (Sequence<int> *) new ArraySequence<int>;
                func_generate_type(seq, num);
                break;

            default:
                break;
        }

        if (SequenceType == 0) return 0;

        seq->Sequence<int>::~Sequence();

        ifstream array("array.txt");
        ifstream sorted("sorted.txt");
        ifstream time("time.txt");

        int time_val;
        time >> time_val;
        cout << "\nTime: " << time_val;

        cout << "\nArray:\n";
        for (int elem; array >> elem; )
            cout << elem << " ";

        cout << "\nSorted:\n";
        for (int elem; sorted >> elem; )
            cout << elem << " ";
        cout << endl;

        array.close();
        sorted.close();
        time.close();

    } while (SequenceType != 0);

    return 0;
}

void func_generate_type(Sequence<int> *seq, size_t num) {

    int GenerationType;
    do{
        GenerationType = dialog(GENERATION_TYPE, GENERATION_TYPE_SIZE);

        switch(GenerationType) {
            case 0:
                break;
            case 1:
                generateSorted(seq, num);
                func_sort_type(seq);
                return;
            case 2:
                generateReversed(seq, num);
                func_sort_type(seq);
                 return;
            case 3:
                generateRand(seq, num, max((int)num, 100));
                func_sort_type(seq);
                 return;

            default:
                break;
        }
    } while (GenerationType != 0);

}

void func_sort_type(Sequence<int> *seq) {
    int SortType;
    do{
        SortType = dialog(SORT_TYPE, SORT_TYPE_SIZE);

        switch(SortType) {
            case 0:
                break;
            case 1:
                writeBubbleSortInFile(seq, cmp);
                return;
            case 2:
                writeShakerSortInFile(seq, cmp);
                return;
            case 3:
                writeMergeSortInFile(seq, cmp);
                return;
            case 4:
                writeHeapSortInFile(seq, cmp);
                return;
            case 5:
                writeQuickSortInFile(seq, cmp);
                return;

            default:
                break;
        }
    } while (SortType != 0);
}


void delay (int milli_seconds) {

    int nano_seconds = 1000 * milli_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + nano_seconds);
}
int dialog (const char *msgs[], int n) {
    int choice;
    char temp;
    int i;
    do {
        cout << endl;
        for ( i = 0; i < n; ++i)
            if ( i == 0 ) {
                cout <<msgs[i]<<endl;
            } else {
                cout << i - 1 <<". "<<msgs[i]<<endl;
            }

        printf("> ");

        do {
            temp = getchar();
        } while(temp == '\n');

        choice = temp - '0';
        while (getchar() != '\n');
        if (choice < 0 || choice >= n)
            printf("You're wrong. Try again!\n");

        delay(500);
        printf("\033[0d\033[2J");

    } while (choice < 0 || choice >= n);

    return choice;
}


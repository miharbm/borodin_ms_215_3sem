#include <iostream>

#include "tests/ready_hist_tests.hpp"
#include "tests/time_hist_test.hpp"
#include "keyboard.hpp"

int main() {

        int first = 0, second = 0, third = 0, fourth = 0;
        int fifth = 0, six = 0, seven = 0, eight = 0;
        int nine = 0, twelve = 0, thirteen = 0, ten = 0, eleven = 0;


        
        while (first != 3) {
        cout << endl << "Choose container:" << endl;
        cout << "1. Array" << endl << "2. List" << endl << "3. back" << endl;
        cin >> first;
        cout << "\n";
        switch (first) {
            default:break;
            case 1: {
                second = 0;
                while (second != 4) {
                    cout << endl << "Choose test type:" << endl;
                    cout << "1. Ready test" << endl << "2. Time test" << endl << "3. Keyboard test" << endl
                         << "4. Back"<<endl;
                    cin >> second;
                    cout << "\n";
                    switch(second){
                        case 1:{
                            ready_hist_int_array_test();
                            break;
                        }
                        case 2:{
                            print_result_time_for_hist(time_test_for_int_array(100));
                            break;
                        }
                        case 3:{
                            third = 0;
                            while(third != 5){
                                cout << endl << "Choose test type:" << endl;
                                cout << "1. Division by parts test" << endl << "2. Count elements test" << endl << "3. Count all elements in group test" << endl
                                     << "4. Count every elements in group test"<<endl<<"5. Back"<<endl;
                                cin >> third;
                                switch(third){
                                    case 1:{
                                        twelve = 0;
                                        while(twelve != 3){
                                            cout << endl << "Choose type:" << endl;
                                            cout << "1. Int" << endl << "2. Float" << endl << "3. Back" << endl;
                                            cin >> twelve;
                                            switch(twelve){
                                                case 1:{
                                                    keyboard_hist_parts_array<int>().print();
                                                    break;
                                                }
                                                case 2:{
                                                    keyboard_hist_parts_array<float>().print();
                                                    break;
                                                }
                                                case 3:{
                                                    break;
                                                }
                                                default:
                                                    cout<<"Enter a number from the list";
                                                    break;
                                            }
                                        }
                                        break;
                                    }
                                    case 2:{
                                        fourth = 0;
                                        while(fourth != 3){
                                            cout << endl << "Choose type:" << endl;
                                            cout << "1. Int" << endl << "2. Float" << endl << "3. Back" << endl;
                                            cin >> fourth;
                                            switch(fourth){
                                                case 1:{
                                                    keyboard_hist_count_elements_array<int>().print();
                                                    break;
                                                }
                                                case 2:{
                                                    keyboard_hist_count_elements_array<float>().print();
                                                    break;
                                                }
                                                case 3:{
                                                    break;
                                                }
                                                default:
                                                    cout<<"Enter a number from the list";
                                                    break;
                                            }
                                        }
                                        break;
                                    }
                                    case 3:{
                                        fifth = 0;
                                        while(fifth != 3){
                                            cout << endl << "Choose type:" << endl;
                                            cout << "1. Int" << endl << "2. Float" << endl << "3. Back" << endl;
                                            cin >> fifth;
                                            switch(fifth){
                                                case 1:{
                                                    hist_count_all_elements_in_group_keyboard_array<int>().print();
                                                    break;
                                                }
                                                case 2:{
                                                    hist_count_all_elements_in_group_keyboard_array<float>().print();
                                                    break;
                                                }
                                                case 3:{
                                                    break;
                                                }
                                                default:
                                                    cout<<"Enter a number from the list";
                                                    break;
                                            }
                                        }
                                        break;
                                    }
                                    case 4:{
                                        six = 0;
                                        while(six != 3){
                                            cout << endl << "Choose type:" << endl;
                                            cout << "1. Int" << endl << "2. Float" << endl << "3. Back" << endl;
                                            cin >> six;
                                            switch(six){
                                                case 1:{
                                                    hist_count_every_elements_in_group_keyboard_array<int>().print();
                                                    break;
                                                }
                                                case 2:{
                                                    hist_count_every_elements_in_group_keyboard_array<float>().print();
                                                    break;
                                                }
                                                case 3:{
                                                    break;
                                                }
                                                default:
                                                    cout<<"Enter a number from the list";
                                                    break;
                                            }
                                        }
                                        break;
                                    }
                                    case 5:{
                                        break;
                                    }
                                    default:
                                        cout<<"Enter a number from the list";
                                        break;
                                }
                            }
                            break;
                        }
                        case 4:{
                            break;
                        }
                        default:
                            cout<<"Enter a number from the list";

                    }
                }
                break;
            }
            case 2:{
                seven = 0;
                while(seven != 4){
                    cout << endl << "Choose test type:" << endl;
                    cout << "1. Ready test" << endl << "2. Time test" << endl << "3. Keyboard test" << endl
                         << "4. Back"<<endl;
                    cin >> seven;
                    cout << "\n";
                    switch(seven){
                        default: break;
                        case 1:{
                            ready_hist_int_list_test();
                            break;
                        }
                        case 2:{
                            print_result_time_for_hist(time_test_for_int_list(100));
                            break;
                        }
                        case 3:{
                            eight = 0;
                            while(eight != 5){
                                cout << endl << "Choose test type:" << endl;
                                cout << "1. Division by parts test" << endl << "2. Count elements test" << endl << "3. Count all elements in group test" << endl
                                     << "4. Count every elements in group test"<<endl<<"5. Back"<<endl;
                                cin >> eight;
                                switch(eight){
                                    case 1:{
                                        nine = 0;
                                        while(nine != 3){
                                            cout << endl << "Choose type:" << endl;
                                            cout << "1. Int" << endl << "2. Float" << endl << "3. Back" << endl;
                                            cin >> nine;
                                            switch(nine){
                                                case 1:{
                                                    keyboard_hist_parts_list<int>().print();
                                                    break;
                                                }
                                                case 2:{
                                                    keyboard_hist_parts_list<float>().print();
                                                    break;
                                                }
                                                case 3:{
                                                    break;
                                                }
                                                default:
                                                    cout<<"Enter a number from the list";
                                                    break;
                                            }
                                        }
                                        break;
                                    }
                                    case 2:{
                                        thirteen = 0;
                                        while(thirteen != 3){
                                            cout << endl << "Choose type:" << endl;
                                            cout << "1. Int" << endl << "2. Float" << endl << "3. Back" << endl;
                                            cin >> thirteen;
                                            switch(thirteen){
                                                case 1:{
                                                    keyboard_hist_count_elements_list<int>().print();
                                                    break;
                                                }
                                                case 2:{
                                                    keyboard_hist_count_elements_list<float>().print();
                                                    break;
                                                }
                                                case 3:{
                                                    break;
                                                }
                                                default:
                                                    cout<<"Enter a number from the list";
                                                    break;
                                            }
                                        }
                                        break;
                                    }
                                    case 3:{
                                        ten = 0;
                                        while(ten != 3){
                                            cout << endl << "Choose type:" << endl;
                                            cout << "1. Int" << endl << "2. Float" << endl << "3. Back" << endl;
                                            cin >> ten;
                                            switch(ten){
                                                case 1:{
                                                    hist_count_all_elements_in_group_keyboard_list<int>().print();
                                                    break;
                                                }
                                                case 2:{
                                                    hist_count_all_elements_in_group_keyboard_list<float>().print();
                                                    break;
                                                }
                                                case 3:{
                                                    break;
                                                }
                                                default:
                                                    cout<<"Enter a number from the list";
                                                    break;
                                            }
                                        }
                                        break;
                                    }
                                    case 4:{
                                        eleven = 0;
                                        while(eleven != 3){
                                            cout << endl << "Choose type:" << endl;
                                            cout << "1. Int" << endl << "2. Float" << endl << "3. Back" << endl;
                                            cin >> eleven;
                                            switch(eleven){
                                                case 1:{
                                                    hist_count_every_elements_in_group_keyboard_list<int>().print();
                                                    break;
                                                }
                                                case 2:{
                                                    hist_count_every_elements_in_group_keyboard_list<float>().print();
                                                    break;
                                                }
                                                case 3:{
                                                    break;
                                                }
                                                default:
                                                    cout<<"Enter a number from the list";
                                                    break;
                                            }
                                        }
                                        break;
                                    }
                                    case 5:{
                                        break;
                                    }
                                    default:
                                        cout<<"Enter a number from the list";
                                        break;
                                }
                            }
                            break;
                        }

                    }
                }
                break;
            }
        }
    }
}


#include <iostream>
#include "CellDatabase.h"

using std::endl;
using std::cout;

void test_CellData() {
    CellData cell1("180",12,1214.56,413.095,5910.62,405.097,421.092,5901,5920.25);
    CellData cell2("259",12,297.298,416.34,6078.29,412.765,419.915,6074.23,6082.35);

    cout << "Cell 1: " << cell1.fov << " " << cell1.id << endl;
    cout << "Cell 2: " << cell2.fov << " " << cell2.id << endl;
    if (cell1 < cell2) {
        cout << "Cell 1 < Cell 2" << endl;
    }
    else {
        cout << "Cell 2 < Cell 1" << endl;
    }
}
void test_insert() {
    LinkedList l;
    cout << "" << endl << endl;
    cout << "getHead Tests" << endl;
    if (l.getHead() == nullptr) {
        cout << ".getHead() == nullptr is supposed to be True, and it is True" << endl;
    }
    else {
        cout << ".getHead() == nullptr is supposed to be True, and it is False" << endl;
    }

    //insert when list is empty
    cout << "Inserting with Empty List Test" << endl;
    l.insert("35",1250,1955.35,7492.66,3355.61,7484.17,7501.15,3343.78,3367.45);
    if (l.getHead() == nullptr) {
        cout << ".getHead() == nullptr is supposed to be False, and it is True" << endl;
    }
    else {
        cout << ".getHead() == nullptr is supposed to be False, and it is False" << endl;
    }
    cout << "" << endl;

    Node* node = l.getHead();
    cout << "node->data.id is supposed to be 35: " << node->data.id << endl;
    cout << "node->data.fov is supposed to be 1250: " << node->data.fov << endl;
    cout << "node->data.volume is supposed to be 1955.35: " << node->data.volume << endl << endl;

    //insert head
    cout << "Inserting New Head Test" << endl;
    l.insert("807",12,297.298,416.34,6078.29,412.765,419.915,6074.23,6082.35);
    node = l.getHead();
    cout << "node->data.id is supposed to be 807: " << node->data.id << endl;
    cout << "node->data.fov is supposed to be 12: " << node->data.fov << endl << endl;

    node = node->next; //tail
    cout << "node->next->data.id is supposed to be 35: " << node->data.id << endl;
    cout << "node->next->data.fov is supposed to be 1250: " << node->data.fov << endl << endl;

    //insert in middle
    cout << "Inserting a Middle Test" << endl;
    l.insert("3226",13,425.921,404.352,5980.72,400.669,408.035,5975.09,5986.34);
    node = l.getHead();
    cout << "head->data.id is supposed to be 807: " << node->data.id << endl;
    cout << "head->data.fov is supposed to be 12: " << node->data.fov << endl << endl;
    node = node->next;

    cout << "head->next->data.id is supposed to be 3226: " << node->data.id << endl;
    cout << "head->next->data.fov is supposed to be 13: " << node->data.fov << endl << endl;
    node = node->next;
    cout << "tail->data.id is supposed to be 35: " << node->data.id << endl;
    cout << "tail->data.fov is supposed to be 1250: " << node->data.fov << endl << endl;

    //insert in tail
    cout << "Inserting New Tail Test" << endl;
    l.insert("2036",1251,1295.67,7412.53,3086.69,7405.01,7420.04,3074.86,3098.53);
    node = l.getHead();
    cout << "head->data.id is supposed to be 807: " << node->data.id << endl;
    cout << "head->data.fov is supposed to be 12: " << node->data.fov << endl << endl;

    cout << l.print() << endl;
    //l.remove("2036",1251,1295.67,7412.53,3086.69,7405.01,7420.04,3074.86,3098.53);
    
    cout << "Remove worked! Printing now" << endl;
    std::string print = l.print();
    cout << print << endl;
}

void average(){
    LinkedList l;
    l.insert("2036",1251,1222.67,7412.53,3086.69,7405.01,7420.04,3074.86,3098.53);
    l.insert("2036",1251,1295.67,7412.53,3086.69,7405.01,7420.04,3074.86,3098.53);
    l.insert("2036",1251,0,7412.53,3086.69,7405.01,7420.04,3074.86,3098.53);
    l.insert("2036",1251,23.67,7412.53,3086.69,7405.01,7420.04,3074.86,3098.53);
    double avg = l.average(1251);
    cout << "average: "<< avg << endl;
}
    

    //l.clear();
    //std::string print = l.print();
    //cout << print << endl;
    // cout << "should be empty: " << l << endl;

int main(int argc, char** argv) 
{
    //test_CellData();
    //test_insert();
    //average();
    
}
    // if (argc < 3) 
    // {
    //     cout << "Usage: " << argv[0] << " data_file query_file" << endl;
	// 	    return 1;
    // } 
    // else 
    // {
    //     CellDatabase database;
    //     database.loadData(argv[1]);
	// 	    database.performQuery(argv[2]); 
	//   	  database.outputData(argv[1]); 
    // }

    // return 0;


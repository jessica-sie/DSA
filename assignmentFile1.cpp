#include <iostream>
#include <array>
#include <string>
using namespace std;

class Node{
public: // TO DO- change to private
    // data fields
    int num;
    string name;
    string email;
    // link field
    Node* next;


    // add  new contact function
    Node* buildListForward(){
    Node *first, *newNode, *last;
    // initializing temp variables    
    int newNum;
    string newName, newEmail;
    // getting user inpt
    cout<<"enter new contact details: "<<endl;
    cout <<"name: ";
    cin >> newName;

    cout << "number: ";
    cin >>newNum;

    cout << "email: ";
    cin>> newEmail;


    first = NULL;
    
        //1. allocate memory
        newNode = new Node();
        // 2.populate data field 
        newNode->name = newName;
        newNode->num = newNum;
        newNode->email = newEmail;
        // 3. link 
        newNode->next = NULL;
        
        // list is empty
        if (first == NULL){
            // pointers reassign 
            first = newNode;
            last = newNode;
        }
        //list has elements
        else{
            last->next = newNode;
            last = newNode;
        }

        
        return first;
    }
    
    // search function - returns the pointer to the node containing the num
    Node* searchNode(Node* current, int numSearch){
        while(current!=NULL){
            if(current->num == numSearch){
                return current;    
            }
            current = current->next;    
        }

    }

    //delete function
    bool deleteNode(Node* current, Node* toDel){
        // transverse
        
        while(current != NULL){

            // if the current node links to the node to be deleted, node is previous (relative to delNode)
            if(current->next == toDel){
                cout<<"entered if statement"; //test
                cout << toDel->name;//test
                // reassign link field to next
                if (toDel->next != NULL){
                    cout<<"todel is not last"; //test
                    current->next = toDel->next;//problem heree whyyy!!!????
                    cout<<"reassign link"; //test
                } 
                
                
                
                // delete toDel node
                delete toDel;
                
                cout<<"deleted3"<<endl;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    
};



int main(){
    // initialize head pointer
    Node* head = NULL;

    // make an object 
    Node contact;

    while(true){
        // options
        cout<< "== contact book =="<< endl;
        cout<< "1. add new contact"<< endl;
        cout<< "2. delete contact"<< endl;
        cout<< "3. search contact"<< endl;
        cout<< "4. exit"<< endl;
        cout<< ">> ";

        // user input 
        int x;
        cin>> x;

        if (x == 1){
            // create new node 
            head = contact.buildListForward();
            cout<< "new contact added"<< endl;
            
            //test
            Node* temp =head;
            while (temp!=NULL){
                cout<< temp->name<< endl;;
                temp = temp->next;
            }
        }
        else if(x ==2){
            int numSearch;
            cout<< " number to delete: ";
            cin>> numSearch;
            // 1. search linked list
            Node* del = contact.searchNode(head,numSearch);

            // 2. delete the node
            contact.deleteNode(head, del);


            //test
            Node* temp = head;
            while (temp!=NULL){
                cout<< temp->name<< endl;;
                temp = temp->next;
            }

        }
        else if(x ==3){
            //search linked list
            int numSearch;
            cout<< " number to search for: ";
            cin>> numSearch;
            Node* foundNode =contact.searchNode(head, numSearch);
            // print
            cout<< "name: "<< foundNode->name<< endl;
            cout<< "number: "<< foundNode->num<< endl;
            cout<< "email: "<< foundNode->email<< endl;
            
            }
        else if(x==4){
            //quit function of while loop
            break;
        }

    }
    

}
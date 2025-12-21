#include <iostream>
#include <string>
using namespace std;

const int Max_Books= 2000;
string library_data[Max_Books][2];
int Book_availability[Max_Books];
int Book_Count=0;

void Display_Menu(){
    cout<<"\n_______Library maagement system_______\n";
    cout<<"1. Add a new book.\n ";
    cout<<"2. Find a book by title.\n ";
    cout<<"3. Borrow a book.\n ";
    cout<<"4. Return a book.\n ";
    cout<<"5. View all books.\n ";
    cout<<"6. Exit.\n ";
    cout<<"Enter your choice(1-6)";
}
int Find_Book_index(string title){
    for(int i=0; i<Book_Count; ++i){
        if(library_data[i][0]==title){
            return i;
        }
    }
    return -1;
}
void add_new_book(){
    if(Book_Count>=Max_Books){
        cout<<"I can't add more books, Maximum reached.\n";
         return;
    }
    string title, author;
    cout<<"Enter the title of the book:\n";
    cin>>title;
    cout<<"Enter the author's name:\n";
    cin>>author;
    library_data[Book_Count][0]=title;
    library_data[Book_Count][1]=author;
    Book_availability[Book_Count]=1;
    Book_Count++;
    cout<<"The book has been added succcessfully.\n ";   
}
void search_book_by_title(){
    string title;
    cout<<"Enter the title of the book you want to search for:\n";
    cin>>title;
    int index= Find_Book_index(title);
    if(index!=-1){
        char status=(Book_availability[index]==1);
        cout<<"The book has been found.\n";
        cout<<"The title: "<<library_data[index][0]<<"\n";
        cout<<"The author: "<<library_data[index][1]<<"\n";
        cout<<"the current situation: "<<status<<"\n";
    }
     else{
            cout<<"the book was not found. "<<"\n";
        }
    }
    void borrow_book(){
        string title;
        cout<<" Enter the title of the book to be borrowed: \n";
        cin>>title;
        int index=Find_Book_index(title);
        if(index!=-1){
            if(Book_availability[index]==1){
                Book_availability[index]=0;
                cout<<"the book has been borrowed.\n";
            }
        }
            else{
                cout<<" sorry, the book is currently borrowed.\n ";
            }
        }
        
        
    
    void return_book(){
        string title;
        cout<<"enter the title of the book you want to return.\n";
        cin >>title;
        int index= Find_Book_index(title);
        if(index!=-1){
                if (Book_availability[index]==0);
                Book_availability[index]=1;
                cout<<"the book has been successfully returned. thank you.\n";
        }
                else{
                    cout<<"the book was not borrowed.\n";
                }
            }
            void display_all_books(){
                cout<<"\n____List of all books_____\n";
                if(Book_Count==0){
                    cout<<"no books are currently registered.\n";
                    return;
                }
                for(int i=0; i<Book_Count; ++i){
                    string status;
                    if(Book_availability[i]==1){
                        status="available";
                    }
                    else{
                        status= "borrowed";
                    }
                    cout<<i+1<<"title: "<<library_data[i][0]<<"\t"<<library_data[i][1]<<"\t"<<status<<endl;

                }
            }
            int main(){
                int choice;
                do{
                    Display_Menu();
                    cout<<" enter your choice:\n";
                    cin>>choice;

                    switch(choice){
                        case 1:
                        add_new_book();
                        break;
                        case 2:
                        search_book_by_title();
                        break;
                        case 3:
                        borrow_book();
                        break;
                        case 4:
                        return_book();
                        break;
                        case 5:
                        display_all_books();
                        break;
                        case 6:
                        cout<<"exit\n";
                        cout<<" thank you for using library system.\n";
                        return 0;
                        default:
                        cout<<"invalid choice.\n";
                        break;
                    }

                }while(choice!=6);

                return 0;
            }
            
#include<iostream>
#include"Reference.h"
#include"Article.h"
#include"Book.h"
#include"TextBook.h"
#include"ReferenceManager.h"

using namespace std;

int main() {

	int capacity;

	cout << "===========================================" << endl;
	cout << "        WELCOME TO REFERENCE MANAGER" << endl;
	cout << "===========================================" << endl;

	cout << "Please enter the capacity of manager array (please input capacity >= 4 for the demo): ";
	cin >> capacity; // For the sake of this demo the capacity must be greater or equal to 4 because I added 4 elements to the array

//================================================================================   CREATING OBEJECTS OF EACH CLASS   ================================================================================

	Reference reference_1("Reference title 1", "John Wick", 2015);
	Article article_1("Article 1 information", 0, 8, "Reference title 2",
			"Barack Obama", 1999);
	Book book_1("Great Book Publisher", 888, "Reference title 3",
			"Liza Soberano", 2021);
	TextBook textbook_1("www.textbooklink.ca", "Bad Book Publisher", 888,
			"Reference title 4", "Rick Sanchez", 2000);
	ReferenceManager manager(capacity);

//================================================================================   TESTING REFERENCE CLASS FUNCTIONS   ================================================================================

	cout << "\n\n===========================================" << endl;
	cout << "           REFERENCE CLASS DEMO" << endl;
	cout << "===========================================" << endl;

	reference_1.print();

	Reference reference_2;
	reference_2 = reference_1;

	reference_2.setReferenceId(1000);
	reference_2.setReferenceTitle("Reference title 1000");
	reference_2.setReferenceAuthor("Sadman");
	reference_2.setPublicationYear(1988);

	cout << "\nReference Id: " << reference_2.getReferenceId() << endl;
	cout << "Reference Title: " << reference_2.getreferenceTitle() << endl;
	cout << "Reference Author: " << reference_2.getReferenceAuthor() << endl;
	cout << "Reference Publication Year: " << reference_2.getPublicationYear()
			<< endl << endl;

//================================================================================   TESTING ARTICLE CLASS FUNCTIONS   ================================================================================

	cout << "\n===========================================" << endl;
	cout << "            ARTICLE CLASS DEMO" << endl;
	cout << "===========================================" << endl;

	article_1.print();

	Article article_2;
	article_2 = article_1;

	article_2.setJournalInfo("Article 2 information");
	article_2.setStartPage(9);
	article_2.setEndPage(15);
	article_2.setReferenceId(2000);
	article_2.setReferenceTitle("Reference title 2000");
	article_2.setReferenceAuthor("Siam");
	article_2.setPublicationYear(1948);

	cout << "\nReference Id: " << article_2.getReferenceId() << endl;
	cout << "Reference Title: " << article_2.getreferenceTitle() << endl;
	cout << "Reference Author: " << article_2.getReferenceAuthor() << endl;
	cout << "Reference Publication Year: " << article_2.getPublicationYear()<< endl;
	cout << "Article Information: " << article_2.getJournalInfo() << endl;
	cout << "Article Start Page: " << article_2.getStartPage() << endl;
	cout << "Article End Page: " << article_2.getEndPage() << endl;
	cout << "Total Pages of Article: " << article_2.getNumberOfPages() << endl<< endl;

//================================================================================   TESTING BOOK CLASS FUNCTIONS   ================================================================================

	cout << "\n===========================================" << endl;
	cout << "              BOOK CLASS DEMO" << endl;
	cout << "===========================================" << endl;

	book_1.print();

	Book book_2;
	book_2 = book_1;

	book_2.setPublisher("Bad Book Publisher");
	book_2.setPagesOfBook(900);
	book_2.setReferenceId(3000);
	book_2.setReferenceTitle("Reference title 3000");
	book_2.setReferenceAuthor("Aryan");
	book_2.setPublicationYear(2016);

	cout << "\nReference Id: " << book_2.getReferenceId() << endl;
	cout << "Reference Title: " << book_2.getreferenceTitle() << endl;
	cout << "Reference Author: " << book_2.getReferenceAuthor() << endl;
	cout << "Reference Publication Year: " << book_2.getPublicationYear()
			<< endl;
	cout << "Publisher Name: " << book_2.getPublisher() << endl;
	cout << "Number of Pages in the Book: " << book_2.getNumberOfPages() << endl
			<< endl;

//================================================================================   TESTING TEXTBOOK CLASS FUNCTIONS   ================================================================================

	cout << "\n===========================================" << endl;
	cout << "            TEXTBOOK CLASS DEMO" << endl;
	cout << "===========================================" << endl;

	textbook_1.print();

	TextBook textbook_2;
	textbook_2 = textbook_1;

	textbook_2.setTextBookURL("www.masweb.ca");
	textbook_2.setPublisher("Not too Bad Book Publisher");
	textbook_2.setPagesOfBook(800);
	textbook_2.setReferenceId(4000);
	textbook_2.setReferenceTitle("Reference title 4000");
	textbook_2.setReferenceAuthor("Akib");
	textbook_2.setPublicationYear(2002);

	cout << "\nReference Id: " << textbook_2.getReferenceId() << endl;
	cout << "Reference Title: " << textbook_2.getreferenceTitle() << endl;
	cout << "Reference Author: " << textbook_2.getReferenceAuthor() << endl;
	cout << "Reference Publication Year: " << textbook_2.getPublicationYear() << endl;
	cout << "Publisher Name: " << textbook_2.getPublisher() << endl;
	cout << "Number of Pages in the Textbook: " << textbook_2.getNumberOfPages() << endl;
	cout << "The Link of the Textbook: " << textbook_2.getTextBookURL() << endl << endl;

//=============================================================================   TESTING REFERENCE MANAGER CLASS FUCNTION   =============================================================================

	cout << "\n===========================================" << endl;
	cout << "       REFERENCE MANAGER CLASS DEMO" << endl;
	cout << "===========================================" << endl;

	if (manager.addReference(reference_1) == true)
		cout << "Reference successfully added to the manager" << endl;
	else
		cout << "Manager at full capacity" << endl;

	if (manager.addReference(article_1) == true)
		cout << "Reference successfully added to the manager" << endl;
	else
		cout << "Manager at full capacity" << endl;

	if (manager.addReference(book_1) == true)
		cout << "Reference successfully added to the manager" << endl;
	else
		cout << "Manager at full capacity" << endl;

	if (manager.addReference(textbook_1) == true)
		cout << "Reference successfully added to the manager" << endl;
	else
		cout << "Manager at full capacity" << endl;


	cout << "\nReference Id of the given index: " << manager.getReference(3) <<endl;

	if (manager.deleteReference(2) == true)
		cout << "Reference deleted successfully" << endl;
	else
		cout << "Invalid index" << endl;

	if (manager.searchReference(8) == true)
		cout << "Reference with the given Id exists in the manager database" << endl;
	else
		cout << "Reference with the given Id do not exist inside the manger database" << endl;

	cout << "Number of References currently inside the manager array: " << manager.getSize() << endl << endl;

	cout << "Printing the manager database: " << endl;
	cout << "------------------------------" << endl;

	manager.print();

}

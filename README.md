# Library System
 > Your author list below should include links to all members GitHub (remove existing author).
 
 > You will be forming a group of **THREE** students and working on an interesting project. A list of proposed project ideas that have been successful in previous quarters is given in the project specifications link on iLearn. You can select an idea from the list, start thinking about the features you will implement, what design patterns can help you implement them, and why. If you want to propose your own original idea, you will have to contact an instructor to discuss the project and obtain written permission before you submit your project proposal. Your project needs to implement two design patterns.The project work should be divided almost equally among team members and each member is expected to work on at least one design pattern (more than one partner may work on a pattern) and some of its test cases. You can of course help each other, but it needs to be clear who will be responsible for which patterns and for which features.
 
 > ## Expectations
 > * Incorporate **at least two** distinct design patterns. You need to include at least *one* design pattern that we will teach this session:
 >   * Composite, Strategy, Abstract Factory, Visitor, or Decorator
 > * All design patterns need to be linked together (it can't be two distinct projects)
 > * Your project should be implemented in C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.
> * All project phases are to be submitted to this GitHub repository. You should modify this README file to reflect the different phases of the project. In addition, you should regularly hold sprint meetings with your group

 > Authors: Abhinav Allam(https://github.com/kineticdirt) Aung Thu Hein (https://github.com/aungthuhein13)   Daniel Ko(https://github.com/DanielKoKo)

## Project Description
 > * This project is interesting to us because the libary system is very similar to many other potential projects, such as retail inventory management or anything with user accounts and administrative privilege. Because of this, tackling this project can allow us to get more comfortable with similar systems we may implement in the future.
 > * The languages/tools we plan on using include:
 >   * [C++](https://www.cplusplus.com/) - We'll be using C++ to implement/code our system design.
 >   * [Git](https://git-scm.com/) - We'll be using Git to work on different parts of our projects simultaneously and update to our GitHub repository to keep track of our work.
 >   * [GoogleTest](https://github.com/google/googletest) - We'll be using googletest to perform unit tests for our program.
 >   * [Valgrind](https://valgrind.org/) - We'll be using Valgrind to check for any memory leaks or other problems that are otherwise hidden.
 > * The inputs and outputs of our project include:
 >   * Inputs: username, password, book ISBN, book title, author, genre, and sub-genre.
 >   * Outputs: list of books (sorted based on our search algorithms), books to display, and user/admin interfaces (screen for login, adding/deleting users, adding/deleting books, etc.).
 > * The design patterns we'll be using:
 >   * We’ll be using the Composite design pattern in order to compose Book objects into tree-like structures and treat Books and its composition uniformly. This way, we can represent books’ genres and subgenres as a hierarchy. We’ll implement a “BookComponent” class that will be the component of the Composite pattern, a “Book” class for a single Book that will act as the leaf of “BooksComponent”, and a  “BooksGroup” that will act as the Composite class, which is capable of editing the list of available books or a single book. A problem we anticipate encountering is creating a list of books where each book is part of a genre, but possibly also part of a subgenre. Naively implementing our library system will cause our Books class to become very unorganized and difficult to print the genres’ subgenres without some form of a tree-structure or hierarchy. This is why we believe that using the Composite design pattern is a good solution to our problem regarding Books.
 >   * We'll be using the Strategy design pattern to implement various book display functions, such as display by title, author, and genre/sub-genre. A problem we anticipate encountering is not being able to display books with a generalized display function, since we'll have to account for multiple ways of displays. This is because we're allowing users to display books using different methods, which can make a generalized display function very confusing and inefficient. The Strategy design pattern is a good solution to this problem because it allows us to create multiple display functions without affecting the general search result. The different display functions will take in different inputs, but will all function the same way by returning a title, author, or all books associated with a genre or subgenre.

## Class Diagram
 > ![Composite pattern](https://user-images.githubusercontent.com/32584958/117906849-87e38d00-b28a-11eb-9e5b-064251f3d48b.png)
> * The diagram above is our Composite pattern which describes the tree-like structure of our Books hierarchy. Our user/admin can point to BooksComponent and print a list of all books with their respective genres and subgenres. BooksComponent contains empty implementations for the add, remove, reorganize_books, and edit_books functions that will be overloaded by our Composite class BooksGroup. BooksComponent will also include the virtual function display that will call the display function for our leaf and composite classes in the BookComponent hierarchy by printing each genre’s books and its subgenre’s books as well. BookGroup will include the list of all books in a genre and have the ability to manipulate the list. Book is the leaf class and will be an instance of a single book with only the primitive ability to print its own information. 

 > ![Strategy Pattern](https://user-images.githubusercontent.com/32584958/119906158-8c52ab80-bf02-11eb-8d0f-0ff16d162a6e.png)
> * Our Strategy design pattern consists of the User/Admin object pointing to a "Context" class, which would include the vectors of books based on their genres. This allows the User/Admin to either display a specific title or author, and also display every book associated with a genre or subgenre. The Context would create an instance of the Search interface and point to it, allowing for our User/Admin to select which display function to use from the Strategy pattern. Each algorithm would function the same way, but with variations in their inputs and slight alterations in their search algorithms based on if we're displaying a single item or display an entire genre or subgenre.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 

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
 >   * [CMake](https://cmake.org/) - We'll be using CMake to compile our program.
 >   * [Git](https://git-scm.com/) - We'll be using Git to work on different parts of our projects simultaneously and update to our GitHub repository to keep track of our work.
 >   * [GoogleTest](https://github.com/google/googletest) - We'll be using googletest to perform unit tests for our program.
 >   * [Valgrind](https://valgrind.org/) - We'll be using Valgrind to check for any memory leaks or other problems that are otherwise hidden.
 > * The inputs and outputs of our project include:
 >   * Inputs: username, password, book ISBN, book title, author, genre, and sub-genre.
 >   * Outputs: list of books (based on our search algorithms), books to display (based on our display algorithms), user/admin interfaces (screen for login, adding/deleting users, adding/deleting books, etc.), and user information.
 > * The design patterns we'll be using:
 >   * We'll be using the Singleton design pattern in order to create a single book Catalog object that's ensured to be the only instance of itself. Our Catalog Singleton class will contain the entire list of books current available, and includes functions to manipulate the Book objects stored in a vector. A problem we anticipate in encountering is allowing multiple classes to access Catalog, which can cause many dependency and declaration issues because of the many moving parts. In our Library program, we have 3 classes capable of accessing Catalog: Library, Admin, and User. Because of this, having a single Catalog object instance that can be accessed by all 3 classes without creating new instances of itself is extremely useful. 
 >   * We'll be using the Strategy design pattern to implement various book display/search functions, such as display/search by title, author, and genre/sub-genre. A problem we anticipate encountering is not being able to display/search books with a generalized display/search function, since we'll have to account for multiple ways of displays/searches. This is because we're allowing users to display/search books using different methods, which can make a generalized display/search function very confusing and inefficient. The Strategy design pattern is a good solution to this problem because it allows us to create multiple display/search functions without affecting the general display/search result. The different display/search functions will take in different inputs, but will all function the same way by returning/displaying a title, author, or all books associated with a genre or subgenre.

## Class Diagram
 > ![Singleton Pattern](https://user-images.githubusercontent.com/32584958/120259836-871a9700-c249-11eb-9732-55305c18db9f.png)
> * The diagram above is our Singleton pattern which describes our single Catalog instance implementation. In our Library class, we initialize the single Catalog instance by calling its static "getInstance()", which ensures that Catalog will only have 1 instance in the duration of the program. Catalog is pointing to itself in the diagram in order to create an instance of itself using its private constructor and getInstance(). As we can see from the diagram, Book aggregates from Catalog. This allows Catalog to have access to each Book object in the vector of Books when it needs to manipulate one of them. The arrows pointing to Catalog from the left are Library, User, and Admin. Catalog is aggreggated from Library since it won't be created unless the Library class calls getInstance(). User/Admin is able to point to Catalog in order to access the vector of available Books. The two arrows on the right of the diagram are aggregations from Search and Display, since Catalog is responsible for creating the Search and Display objects.
 > ![Strategy Pattern](https://user-images.githubusercontent.com/32584958/120260899-a286a180-c24b-11eb-8a3c-85462438e796.png)
> * Our Strategy design pattern consists of the User/Admin object pointing to a "Context" (Catalog) class pointing to Display, which would include the vectors of books based on their genres. This allows the User/Admin to either display a specific title or author, and also display every book associated with a genre or subgenre. Catalog would create an instance of the Display interface and point to it, allowing for our User/Admin to select which display function to use from the Strategy pattern. Each algorithm would function the same way, but with variations in their inputs and slight alterations in their search algorithms based on if we're displaying a single item or display an entire genre or subgenre.
 > ![Strategy Pattern](https://user-images.githubusercontent.com/32584958/120261055-fb563a00-c24b-11eb-969a-7c52efc5c951.png)
> * We're also using the Strategy pattern to implement our Search class. It functions very similar to the Display class, where it consists of the User/Admin object pointing to a "Context" (Catalog) class pointing (arrow from the left) to Search. This allows the User/Admin to search a book by title, ISBN, or author. Similarly to the Display class, our Search class would consist of different search functions depending on how the User/Admin wants to search for a book, and they all output the same way, just with variations in their search algorithms.
> ![Project](https://user-images.githubusercontent.com/32584958/120391043-571fd200-c2e3-11eb-90c9-2d7cf59701a7.png)
> * This is our overarching OMT diagram for our entire program. It includes the strategy and singleton patterns and includes the interactions between them. This shows that how every diagram connects to the design pattern and the library interfact.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
>![display genre](https://user-images.githubusercontent.com/43799855/120387652-07d7a280-c2df-11eb-9697-5dbd9cef3ce0.png)
>![display subgenre](https://user-images.githubusercontent.com/43799855/120387686-11f9a100-c2df-11eb-9802-d9cfbddcdc38.png)
>![display title](https://user-images.githubusercontent.com/43799855/120387700-158d2800-c2df-11eb-91f3-b730fed1ef15.png)
>![display author](https://user-images.githubusercontent.com/43799855/120387710-18881880-c2df-11eb-8041-194187ca84d1.png)
>![borrowed books](https://user-images.githubusercontent.com/43799855/120387713-19b94580-c2df-11eb-8155-384753f80dc2.png)
>![view debt](https://user-images.githubusercontent.com/43799855/120387720-1c1b9f80-c2df-11eb-9588-5da5ffa813ea.png)
>![Quit](https://user-images.githubusercontent.com/43799855/120387734-2178ea00-c2df-11eb-861a-5638b0845fd9.png)

 ## Installation/Usage
 * Clone the repository onto your local Linux CLI environment.
 * Make sure you have [CMake](https://cmake.org/) installed.
 * Navigate to the local repository, and run "cmake ." to generate the necessary build files.
 * Run "make" to build the program.
 * Finally, run the command "./library" to run the program. The menu inputs consist of single characters, while inputting user or book information require a line. After every input, press "ENTER" to end the input and unpause the program.
 * To quit the program, navigate back to the main menu and enter "0". Alternatively, enter "CTRL + C" to kill the program.
 * To run tests, run the command "./tests".
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 > * We validated our project with Github Actions, which ensures that the project builds and compiles before we can merge the pull request to the master branch. 
 > * Our individual class tests are tested with GoogleTest's unit testing system.
 > * We tested our User class by testing different Users' "get" functions, and also their debt accumulation function when borrowing books. We also tested borrowing invalid books, which should not add to a User's debt and borrow history.
 > * We tested our Display class by creating a single instance of Catalog, and using that to read books.txt that can be used across all other test files. The Display tests test each of the genre, subgenre, author, and ISBN to see if they display properly.
 > * We tested our Search class by searching for author, ISBN, and title to see if they return the correct books. We check this with the "get" functions of the Book class.
 > * We tested our Book class by manually creating a Book object with its constructor, and checking if its "get" functions return the correct information we inputted in its constructor.
 > * v.1.0.0 Initial Stable Release

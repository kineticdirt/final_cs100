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
 >   * Outputs: list of books (sorted based on our search algorithms), matched book, and user/admin interfaces (screen for login, adding/deleting users, adding/deleting books, etc.).
 > * The design patterns we'll be using:
 >   * We'll be using the Composite design pattern to compose our Books class into a tree structure so we’ll be able to treat Books and its composition uniformly. We plan to use the Books class as the “component” of the composite design pattern and include virtual functions related to Books such as adding/removing a book, editing a book, borrowing a book, and displaying the books. By default, Books will display all books, its “leaf” will display the subgenre of books, and its “composite” will display the genre of books and have the implementation of virtual functions from Books to manipulate the Books object. A problem we anticipate encountering when implementing our project is that our design will become too bloated and convoluted when we treat a group of objects in their own separate ways while still having common operations. Since the composite pattern is able to compose objects into a tree-like structure and apply common operations uniformly, we decided this is the best way to solve our problem.
 >   * We'll be using the Strategy design pattern to implement various book search functions, such as search by ISBN, name, genre/sub-genre, and author. A problem we anticipate encountering is not being able to search books with a generalized search function. This is because we're allowing users to search with different inputs. The Strategy design pattern is a good solution to this problem because it allows us to create multiple search functions without affecting the general search result. The different search functions will take in different inputs, but will all function the same way by returning a matched book or genre.

 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `TODO` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 

 > ![Composite pattern](https://user-images.githubusercontent.com/32584958/117521451-ac75f700-af62-11eb-875b-f1e95a1dd9a7.png)

 > ![Strategy Pattern](https://user-images.githubusercontent.com/32584958/117520605-d547bd80-af5d-11eb-98f3-93abd5bb4045.png)

 > ![Program Diagram](https://user-images.githubusercontent.com/32584958/117520712-84849480-af5e-11eb-8278-8090cc364131.png)


 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

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
 

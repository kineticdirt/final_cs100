# Library System
 > Authors: \<[Abhinav Allam](https://github.com/kineticdirt)\> \<[Aung Thu Hein](https://github.com/aungthuhein13)\> \<[Daniel Ko](https://github.com/DanielKoKo)\>

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
 >   * We'll be using the Composite design pattern to break up our library system into smaller chunks in order to better structure our program. We plan to use this design pattern by having a "main" library class acting as the composite object, and then creating "children" classes that are used to implement the smaller functions of the library system broken into chunks. When discussing the Library System project, we realized that having multiple classes and functions (such as User, Admin, Book, Library, Account, etc.) can make our program harder to develop and lead to more bugs/problems in the end. Because the library system is 1 system with all of these classes/functions, we believe we can design our system in a tree like pattern, so the main library object will be on the top and all other objects will extend from it.
 >   * We'll be using the Strategy design pattern to implement various book search functions, such as search by ISBN, name, genre/sub-genre, and author. A problem we anticipate encountering is not being able to search books with a generalized search function. This is because we're allowing users to search with different inputs. The Strategy design pattern is a good solution to this problem because it allows us to create multiple search functions without affecting the general search result. The different search functions will take in different inputs, but will all function the same way by returning a matched book or genre.
 > * This description should be in enough detail that the TA/instructor can determine the complexity of the project and if it is sufficient for the team members to complete in the time allotted. 

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
 

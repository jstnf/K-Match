# K-Match
 > Your author list below should include links to all members GitHub and should begin with a "\<" (remove existing author).
 
 > Authors: \<[Andy Tran](https://github.com/ATranZone) [Justin Figueroa](https://github.com/jstnf) [Nathan Nguyen](https://github.com/nateknguyen)\> 
 
 > You will be forming a group of **THREE** students and work on an interesting project that you will propose yourself (in this `README.md` document). You can pick any project that you'd like, but it needs to implement three design patterns. Each of the members in a group is expected to work on at least one design pattern and its test cases. You can, of course, help each other, but it needs to be clear who will be responsible for which pattern and for which general project features.
 
 > ## Expectations
 > * Incorporate **three** distinct design patterns, *two* of the design patterns need to be taught in this course:
 >   * Composite, Strategy, Abstract Factory, Visitor1
 > * All three design patterns need to be linked together (it can't be three distinct projects)
 > * Your project should be implemented in C/C++. If you wish to choose another programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.

## Project Description
 > Your project description should summarize the project you are proposing. Be sure to include
 > * Why is it important or interesting to you?
  >   * All three of us have an interest in listening to K-pop which is Korean pop music. We wanted to create an application that would help new listeners discover Korean artists that are similar to their music taste.
 > * What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
 >   * [Microsoft Visual Studio Code](https://code.visualstudio.com/) - IDE for C++ and JavaScript
 >   *  C++ - for backend
 >   * JavaScript - for GUI(frontend)
 >   * MYSQL - for database management 
 > * What will be the input/output of your project?
 >   * The application takes in user submitted artists and genres that you like then recommends Korean pop music artists based off of the user inputted songs 
 > * What are the three design patterns you will be using. For each design pattern you must:
 >   * Explain in 3 - 5 sentences why you picked this pattern and what feature you will implement with it
 >   * 1) Strategy
	 >   a) We chose the strategy design pattern to have our clients not  know specifically how our C++ code would communicate with our database of recommended songs. The feature that we can implement with this design pattern allows us to establish relationships between songs even if the user does not know specific details about the songs that they provide to our program. Strategy allows the use of a context related request from a client to the proper algorithm to recommend similar songs to what the user has inputted. 
 >   * 2) Composite
	 >   a) We chose the composite design pattern to have a song group as our main composite which will then contain leaves and other song groups that can hold more precise information of the recommended songs. Subclasses of the song group can contain information like the band name, release year, and even song length to the user. We will a have a client that can manipulate objects through the interface.
 >   * 3) Chain of Responsibility
	 >   a) We chose chain of responsibility design pattern to have the user's input be received by the correct object to perform the correct actions on their input. This would allow our user interface to have buttons presented to the user then depending on which button is pressed can be passed on to the correct receiver to deal with user's request. This design pattern simplifies the objects interconnections to one another by having objects only have a single reference to their succeeding receiver. 
 

 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `Backlog` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 
 
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
 

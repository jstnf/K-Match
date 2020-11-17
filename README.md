# K-Match
**Authors:** [Andy Tran](https://github.com/ATranZone), [Justin Figueroa](https://github.com/jstnf), [Nathan Nguyen](https://github.com/nateknguyen) 

## Project Description
### Purpose
**K-Pop**, or Korean pop music, is an umbrella of various genres of pop music that originate from South Korea. Although K-Pop music is listened to very widely around the world, there are currently no music platforms that focus solely on this subset of music aside from all-encompassing platforms such as *Pandora* or *Spoify*. We wanted to create an application that would help new listeners catalogue and discover Korean music and artists that are similar to their tastes.
  
### Tools, Languages, and Technologies
 * [**Microsoft Visual Studio Code**](https://code.visualstudio.com/)
   * IDE used by all project members
 * **C++**
   * The backend of the project
   * In-charge of multiple tasks, including rendering JavaScript, performing algorithms for recommendations, and interacting with an online database
 * **JavaScript**
   * The frontend of the project (GUI)
   * Display user and song information to the user of the application
   * Contains buttons and elements that perform actions in the backend
 * MySQL
   * Stores all user information, including user's song lists, relationships between songs (we use these to create recommendations), and more
   * Contains songs grabbed from *Spotify* using Spotify's HTTP API

### Input/Output
Initial input is grabbed from large volumes of K-Pop music that are pre-catalogued in large release playlists on the platform *Spotify*. Song information from these lists is stored in our database for use by our application.

Using this information, users can create their own accounts on our application, granting them their own song list. Users will initially be asked to choose songs or artists that they like in order to further recommend the user more songs.

Our application will include three main displays - **search** for music in our database, **view user information** such as saved song and artist lists, and a **question-and-answer recommendation** page where users are asked questions in order to further recommend them new songs to listen to.

### Design Patterns
 1) **Strategy** -
	   We chose the strategy design pattern to have our clients not  know specifically how our C++ code would communicate with our database of recommended songs. The feature that we can implement with this design pattern allows us to establish relationships between songs even if the user does not know specific details about the songs that they provide to our program. Strategy allows the use of a context related request from a client to the proper algorithm to recommend similar songs to what the user has inputted. 
 2) **Composite** -
	     We chose the composite design pattern to have a song group as our main composite which will then contain leaves and other song groups that can hold more precise information of the recommended songs. Subclasses of the song group can contain information like the band name, release year, and even song length to the user. We will a have a client that can manipulate objects through the interface.
 3) **Chain of Responsibility** -
	    We chose chain of responsibility design pattern to have the user's input be received by the correct object to perform the correct actions on their input. This would allow our user interface to have buttons presented to the user then depending on which button is pressed can be passed on to the correct receiver to deal with user's request. This design pattern simplifies the objects interconnections to one another by having objects only have a single reference to their succeeding receiver. 
 

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
 

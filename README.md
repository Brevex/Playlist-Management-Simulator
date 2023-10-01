<h1 align = "center"> Playlist Manager Simulator </h1>

<br>

<h2> &#128269; About the project </h2>

<br>

<p> Project carried out during the Bachelor of Information Technology (BTI)
for the subject Programming Language I. This is a program made in C++ that simulates a playlist manager. The program 
does not deal with real music files, it just creates objects that represent a song using a title 
and the name of the artist/band. You can create playlist, manage music and run created playlists.</p>

<br>

<h2> &#128296; Dependencies and Execution </h2>

<br>

<p>To compile and run this program on your machine, you will need CMake and
the code compiler for C/C++, which can be gcc or g++. To create the executable
go to the "build" folder, right click and open the terminal
inside that folder. With the terminal open, type "cmake.." and press enter, then
type "make" and hit enter again. Finally, type "./manager" to run
the program.</p>

<br>

<h2> &#128302; Technologies Used </h2>

<br>

<p align="center">
  <a href="https://skillicons.dev">
    <img src="https://skillicons.dev/icons?i=cpp,cmake" />
  </a>
</p>

<br>

<h2> &#128161; Program Functions </h2>

<h3>A1 - If you are not logged in (As soon as you enter the system)</h3>

<details>
	<summary>create-user</summary>
	<br>
	Creates a new user in the system, receiving email, password and name as parameters. 
	Each user is unique, try to create a user with the same email/password as another 
	will result in an error, as will the lack of any of these parameters.<br><br>
	
	create-user julio.melo@imd.ufrn.br 12ab34cd Julio Melo
	User created
 
	create-user julio.melo@imd.ufrn.br 12ab34cd Julio Silva
	User already exists!
</details>

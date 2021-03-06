
<h1 align="center"> π‘ <a href="#"> Minitalk </a></h1>
<h3 align="center">My newest project as a cadet at Γcole 42. This is my own communication program in client and server form.</h3>
<h4 align="center">
	<b>Status</b>: Finished βπ (125%)
</h4>
<p align="center">
	<a href="#About">About</a> β’
	<a href="#How-it-works">How it works</a> β’ 
	<a href="#Author">Author</a>
</p>

## π» About <a name='About'></a>

π‘ The goal of this project was to create a communication program in the form of a client and server.

### π― Briefing

Part 				| Features
-------------------	| --------- 
Mandatory Function	| Create a communication program in the form of a client and server, the server must be launched first, and after being launched it must display its `PID`. The client will take as parameters: The `server PID` and The `string` that should be sent, the client must communicate the string passed as a parameter to the server. Once the string has been received, the server must display it (PS. The communication between your programs should ONLY be done using UNIX signals and you can only use the two signals SIGUSR1 and SIGUSR2).
Bonus 				| The server confirms every signal received by sending a signal to the client; support Unicode characters!.

---

## π How it works <a name='How-it-works'></a>

### Clone this repository
```git
git clone git@github.com:prmarquesz/minitalk.git
```
### Running Makefile
Go to the directory where you cloned and run the command
```Makefile
make
```
### Available Options
Command | Usage
------- | -----
`make` | Compile source files (equivalent to `make all`)
`make clean` | Removes the executable files (`server` and `client`)
`make re` | Invokes `fclean` rule and then `all`

### Starting the server
```c
./server
```
### Running the client program
```c
./client <SERVER_PID> <STRING_TO_PASS>
```

---

# π¨βπ Author <a name='Author'></a>

<a href="#">
 <img style="border-radius: 50%;" src="https://avatars.githubusercontent.com/u/69995036?v=4" width="100px;" alt=""/>
 <br />
 <sub><b>Paulo Roberto Marques</b></sub></a> <a href="#" title="Cadet">π</a>


Made with β€οΈ by Paulo Roberto Marques ππ½  Get in Touch!

[![Linkedin Badge](https://img.shields.io/badge/-Paulo-blue?style=flat-square&logo=Linkedin&logoColor=white&link=https://www.linkedin.com/in/prmarquesz/)](https://www.linkedin.com/in/prmarquesz/) 
[![Instagram Badge](https://img.shields.io/badge/-prmarquesz-red?style=flat-square&logo=Instagram&logoColor=white&link=https://www.instagram.com/prmarquesz/)](https://www.instagram.com/prmarquesz/)
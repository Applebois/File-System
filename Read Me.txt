Instruction from the beginning :

FileSystem -i : register new user with username and password (By default user clearance is level 2 )

FileSystem : login to the system with valid username and password

1. Register: using command FileSystem -i

2. Login : using command FileSystem

3. FileSystem -? , FileSystem ? or ? to prompt the help button 

------------------------------------------------------------------------------------------------------------------------------------------------------

Security level implemented:
	     User action is limit to their relative user clearance
	     0: read only user (only can read level 0,1 file)
	     1: write only user (only can write / create level 2 ,1 file)
	     2: read and write user(only can read and write / create to level 1 file)

------------------------------------------------------------------------------------------------------------------------------------------------------

Common Error
Error:1505 : Not able to edit logs.txt files
Error:1506 : File not found 
Error:1507 : Cannot write blacklist.txt , read able to make it , to remove blacklist user use un(B)anned .
Error 1054 : Use the wrong syntax to login
Error 1053 : Use the wrong syntax to register

------------------------------------------------------------------------------------------------------------------------------------------------------

Registration Instruction :
1.ID policy minimum 3 character and maximum 20 character
2.Password policy minimum 4 character and symbol such as ! # ' = - , are not allow
3.User Description : Enter your name or your nickname
4.Total of Group in this system : 2 groups only
5.1000 NORMAL USER , 500 ROOT
6.To register as a normal group enter 1000
7.To register as a ROOT group enter IAMTHEFUTURE

------------------------------------------------------------------------------------------------------------------------------------------------------

Total of user clearance 3
0 : Only able to write 
1 : Able to write and read
2 : Only able to read

------------------------------------------------------------------------------------------------------------------------------------------------------

Once log in
3. Create file : Create file and Folder with its security level base on user clearance
4. Read file : Enter folder name and file name (if the text files is not in folder just press enter when system prompt you to enter directories)
5. Write file: Enter folder name and file name (if the text files is not in folder just press enter when system prompt you to enter directories)
6. List file : list files based on user clearance (list what user can write or view)
7. Exit : Will prompt user do you want to exit (Y) or (N)

2 Condition will be happen in the menu page . 

Assume a user clearance level 1 login without a ROOT group . 
Menu will be "(C)reate , (W)rite , (R)ead , (L)ist , (S)wap Account or (E)xit"

Assume a user clearance level 1 login with a ROOT group . 
Menu will be "(C)reate , (W)rite , (R)ead , (L)ist , (S)wap Account , (G)roup or (E)xit"

------------------------------------------------------------------------------------------------------------------------------------------------------

ROOT GROUP USER
When they enter 'G' or 'g' will navigate to a validatation page which is to authenticate the user to use a files with md5 : 103120f58dc84267baca0c11ae8a7db9

Once login : 
They only have Read and Write rights 
Read able to read any single text files
Write able to write any single text file except Logs.txt

------------------------------------------------------------------------------------------------------------------------------------------------------



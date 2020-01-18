#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

	int main()
{
	ifstream pazýl,dict;
	string puzzle,sözlük;
	cout << "Please enter the name of the puzzle file: ";//name of the puzzle file taken as an input
	cin >> puzzle;

	pazýl.open(puzzle.c_str());

	while(pazýl.fail())
	{
		cout << "File could not be opened" << endl;
		cout << "Please enter the name of the puzzle file: ";
		cin >> puzzle;
		pazýl.open(puzzle.c_str());//choosen puzzle file opened
	}

	vector<vector<char>> matris;//main matrix which includes  the puzzles
	string s1;
	
		while(getline(pazýl,s1))//checking if the cell entry is char
		{
			istringstream iss4(s1);
			for (unsigned int index = 0; index < s1.length(); index++)
			{
				if( 96 < s1.at(index)  &&  s1.at(index) < 123 && index < s1.length()-1 )
				{
					if( (96 < s1.at(index+1)  && s1.at(index+1) < 123)  )
					{
						cout<<"Invalid matrix - cell entry is not a char" << endl;
						return 0;
					}
				}
			}
		}	pazýl.close();
			pazýl.open(puzzle.c_str());

	while(getline(pazýl,s1))
	{
		istringstream iss(s1);
		char ch;
		vector<char> temp;
			
			while(iss >> ch)
				temp.push_back(ch);

		matris.push_back(temp);//putting the info in puzzle to the matrix
	}pazýl.close();
	pazýl.open(puzzle.c_str());
		
		for(unsigned int x=0;x < matris.size();x++)
		{
			for(unsigned int y=1;y<matris.size()-1;y++)
			{
				if(matris[x].size()!=matris[y].size())
				{cout <<"Invalid matrix - inconsistent dimensions " << endl;
				return 0;
				}
			}
		}pazýl.close();
		pazýl.open(puzzle.c_str());

		while(getline(pazýl,s1))
		{
			for (unsigned int z = 0; z < s1.length(); z++)//checking if the puzzle in loweercase
			{
				char f= s1.at(z) ;
				if(s1.at(z) == 32 && f == '/t' && f == '/n')
				{
				if(!islower(f) )
				{
					cout << "Invalid matrix - char not lowercase letter	";
					return 0;
				}
				}
			}
		}pazýl.close();
		pazýl.open(puzzle.c_str());

		cout << "Please enter the name of the dictionary file: ";
		cin >> sözlük;

		dict.open(sözlük.c_str());

	while(dict.fail())//checking if dictionary file opened correctly
	{
		cout << "File could not be opened" << endl;
		cout << "Please enter the name of the dictionary file: ";
		cin >> sözlük;
		dict.open(sözlük.c_str());
	}
	cout <<endl;
	
		for(unsigned int i=0;i<matris.size();i++)//printng the puzzle
		{
			for(unsigned int k=0;k<matris[0].size();k++)
				cout<< matris[i][k] << " ";
			cout<<endl;
		}

		vector<string> dic;
		string s2;
		int total=0;
		while(getline(dict,s2))//putting dictionary info in to vector
		{
			dic.push_back(s2);
		}


			unsigned int xcor, ycor;
					   string word = "";
			vector<vector<char>> matrix;//copy matrix of puzzle matrix
			matrix = matris;
			
			bool check = true;
			bool check2 =true;
			cout << endl;
			while(check)
			{cout << "Enter the starting location for word (x,y): ";//x,y locations as input
			cin >> xcor >> ycor;
				bool check2 =true;
				if(xcor==-1 || ycor == -1)
				{cout <<"You didn't completely solve the puzzle." << endl;
				cout <<"Your final score is " << total << "."<< endl;
				return 0;
				}
		   while(xcor < 0 || xcor > matris.size() || ycor < 0 || ycor > matris[0].size() )
			{
				cout <<"Invalid coordinate - out of range" << endl;
			cout << "Enter the starting location for word (x, y): ";
			cin >> xcor >> ycor;
			}string pathh;
		   cout << "Enter the path: ";
		   cin >> pathh;
		   if(pathh.length()<2)
		   {cout<< "Invalid path - path too short" << endl;
		   for(unsigned int i=0;i<matrix.size();i++)
		{
			for(unsigned int k=0;k<matrix[0].size();k++)
				cout<< matrix[i][k] << " ";
			cout<<endl;
		   }cout << endl;
				
		   
		   cout << "Enter the starting location for word (x,y): ";
			cin >> xcor >> ycor;
				bool check2 =true;
				if(xcor==-1 || ycor == -1)
				{cout <<"You didn't completely solve the puzzle." << endl;
				cout <<"Your final score is " << total << "."<< endl;
				return 0;
				}
		   while(xcor < 0 || xcor > matris.size() || ycor < 0 || ycor > matris[0].size() )
			{
				cout <<"Invalid coordinate - out of range" << endl;
			cout << "Enter the starting location for word (x, y): ";
			cin >> xcor >> ycor;
			}pathh = "";
		   string pathh;
		   cout << "Enter the path: ";
		   cin >> pathh;
		   }
		   matrix[xcor][ycor]='_';
		   char ch;
		   istringstream isss(pathh);
		   word= word+matris[xcor][ycor];	
		   while(isss >> ch)
		   {
			   if(ch!='r' && ch!= 'u' && ch!='d' && ch!='l')
		{
			cout << " Invalid path - non-RLUD input " << endl;
		}
			   if(ch=='d')
			    { 
                word=word+matris [xcor+1][ycor];
				xcor++;
				matrix[xcor][ycor]='_';
				}
			   if(ch=='u')
			   { 
                word=word+matris [xcor-1][ycor];
				xcor--;
				matrix[xcor][ycor]='_';
			   }
				if(ch=='r')
			    { 
                word=word+matris [xcor][ycor+1];
				ycor++;
				matrix[xcor][ycor]='_';
				}	   
				if(ch=='l')
			    {
                word=word+matris [xcor][ycor-1];
				ycor--;
				 matrix[xcor][ycor]='_';
				}
		   }
				   for(unsigned int j=0;j < dic.size();j++)
			{
				if(word==dic[j] && check2)
				{
					cout << "Word found: " << word << endl;
					cout << "Word length: " << word.length() << endl;
					cout << "Points gained: " << word.length()*word.length() << endl;
					total = total+word.length()*word.length();
					cout << "Current score: " << total << endl<< endl;
					word="";
					matris=matrix;
					check2=false;
					for(unsigned int i=0;i<matrix.size();i++)
		{
			for(unsigned int k=0;k<matrix[0].size();k++)
				cout<< matrix[i][k] << " ";
			cout<<endl;
		}cout << endl;
				}
		   }if(check2==true)
				{
					matrix= matris;
					cout << "Invalid word - non-existent word " <<  word << endl;
					
					for(unsigned int i=0;i<matrix.size();i++)
		{
			for(unsigned int k=0;k<matrix[0].size();k++)
				cout<< matrix[i][k] << " ";
			cout<<endl;
		}cout <<endl;
				}
		   	
		   }
	
	
}
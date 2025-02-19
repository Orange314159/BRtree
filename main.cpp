/**
 * @class RBTree
 * @author J. Shockey
 * @date 30/03/20
 * @file main.cpp
 * @brief Main program to exercise advanced data structures.  This program takes information input
 * 			from stdin or a file.  The information is processed into operations necessary to
 * 			construct a data structure.  The input is one or more comma separated operation and
 * 			data pairs in the form <operation> : <data>.
 * 			where operations are:
 * 				'A' - add element to structure
 * 				'D' - Delete element from structure
 */

#include 	<iostream>
#include <string> 
#include <fstream>
#include <sstream>
#include <vector>

#include	"RBtree.h"

using namespace std;


struct ds_operation
{
	char	op;
	int		data;
};

/**
 * @brief Decode a single operation into a list of operations
 * @param str - a string of a single element in the form of <operation> : <data>
 * @return struct ds_operation -  the decoded string
 */
ds_operation decode(string str)
{
	char sep;
	ds_operation dsop;
	stringstream s_str(str);
	s_str >> skipws >> dsop.op >> skipws >> sep >> dsop.data;
	dsop.op = dsop.op & 0x5F;	//make uppercase
	if (sep != ':')
	{
		dsop.op = 'E';	//incorrectly formed operation
		dsop.data = -1;
	}
	return dsop;
}

/**
 * @brief segment a line of information, separated by commas, into single elements
 * 			that can be decoded.
 * @param str - a string containing one or more elements separated by commas
 * @return a vecor containg an ordered series of decoded operations
 */

vector<ds_operation> segment(string str)
{
	vector<ds_operation> result;
	stringstream s_stream(str); 		//create string stream from the string
	while(s_stream.good()) {
		string substr;
		getline(s_stream, substr, ','); //get first string delimited by comma
		//cout << substr << endl;
		if (substr != "")
		{
			ds_operation dsop = decode(substr);
			result.push_back(dsop);
		}
		else
			cout << "End of data" << endl;

	}
	
	return	result;
}

/**
 * @brief print a vector of ds_operations.
 * @param vector
 */


//void vprint(auto const &vector)

void vprint(vector<ds_operation> vec)
{
  cout << "size: " << vec.size() << endl;
	for (auto i: vec) {
		std::cout << i.op << " - " << i.data << endl;
	}

	std::cout << '\n';
}


int main(int argc, char **argv)
{
  std::cout << "Hello RB trees" << std::endl;
  
  RBtree rb;
	
	//ds_operation	dsop;
	vector<ds_operation> dsop_vec;
	// vector<string> inLine;
	vector<ds_operation> segments;
	int choice;
	string line;
	
	cout << "Enter 1 for stdin" << endl;
	cout << "Enter 2 for file" << endl;
	
	cin >> choice;
	cin.ignore();
	//getline(cin, choice); 
	
	cout << "choice: " << choice << endl;
	
	if (choice == 1)
	{
		do
		{
			getline(cin, line); 
			vector<ds_operation> x = segment(line);
			segments.insert(segments.end(), x.begin(), x.end());
		} while ((line != "") && (line != "END") && (line != "end"));
	}
	else if (choice == 2)
	{
	  string fileName = "data.txt";
		fstream fin;
		cout << "Enter File Name [" << fileName << "] > ";
		getline (cin, fileName);
		if (fileName == "")
  	  fileName = "data.txt";
		
		fin.open(fileName,ios::in);		// open a file to perform read operation using file object

		if (fin.is_open()){					//checking whether the file is open
			string line;
			while(getline(fin, line)){		//read data from file object and put it into string.
				//cout << line << "\n";			//print the data of the string
				vector<ds_operation> x = segment(line);
				segments.insert(segments.end(), x.begin(), x.end());
			}
			fin.close(); 					//close the file object.
		}
	}
	else
	{
		cout << "Nothing to process" << endl;
		return(0);
	}

	// vprint(segments);
	
  int sum = 0;
	for(unsigned int i = 0; i<segments.size(); i++) {
		
		switch (segments[i].op)
		{
			case 'A':
				cout << "Add [" << segments[i].op << "]: " << segments[i].data << endl;
				//rb.root = rb.insert(rb.root, segments[i].data);
				rb.insert(segments[i].data);
				sum += segments[i].data;
				break;
			case 'D':
				cout << "Delete [" << segments[i].op << "]: " << segments[i].data << endl;
				rb.remove(segments[i].data);
				sum -= segments[i].data;
				break;
			case 'E':
				cout << "Error in segment list" << endl;
				break;
			default:
				cout << "Empty data in segments list" << endl;
				break;
			
		}
		//rb.inorder(rb.root);
   }
   
    cout << endl << endl;
//    cout << "min level: " << avl.min_level(avl.root,0,9999) << endl;
//    cout << "max level: " << avl.max_level(avl.root,0,0) << endl;
	
    
		printf("\n\nDisplay\n");     
    cout << endl;
	
	//rb.printPretty(rb.root, 1, 0, std::cout, rb.NIL);
	rb.prettyPrint();
	cout << endl;

	
  return 0;
}



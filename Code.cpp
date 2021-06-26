#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

bool check (char ch ){
	if (ch=='w')return true;
	return false;
}

int whitecell (char **box,int row , int col , int size){
	if (row == 1 && col == 1 ){
		if (check(box[row][col]))return 1;
		else return 0;
	}
	else if (row == 1 && col > 1 ){
		if (check(box[row][col]))return 1+whitecell(box,row=size,col-1,size);
		return whitecell(box,row=size,col-1,size);
	}
	else {
		if (row != 0 && col != 0 && check(box[row][col])){
			return 1+whitecell(box,row-1,col,size);
		}
		return whitecell(box,row-1,col,size);
	}
}

void checkAdjecent (char **box,int row , int col , int size){
	if (row != 0 && col != 0 && row != size+2 && col != size+2 && check(box[row][col])){
		box[row][col]='!';
		
		if (col!=size && check(box[row][col+1])){
		checkAdjecent(box,row,col+1,size);
		}

		if (col!=0 && check (box[row][col-1])){

		checkAdjecent(box,row,col-1,size);
		}
		
		if (row!=0 && check(box[row-1][col])){
		checkAdjecent(box,row-1,col,size);
		}
		
		if (row!=size && check(box[row+1][col])){
		checkAdjecent(box,row+1,col,size); 
		}
	}
} 

int whitespace (char **box,int row , int col , int size){
	
	if (row == 1 && col == 1 ){
		if (check(box[row][col])){
			checkAdjecent(box,row,col,size);
			return 1;
		}
	}
	else if (row == 1 && col >1 ){
		if (check(box[row][col])){
			checkAdjecent(box,row,col,size);
			return 1+whitespace(box,row=size,col-1,size);
		}
		return whitespace(box,row=size,col-1,size);
	}
	else {
		if (check(box[row][col])){
			checkAdjecent(box,row,col,size);
			return 1+whitespace(box,row-1,col,size);
		}
		return whitespace(box,row-1,col,size);
	}
}


int main (){
	int n;
	ifstream ptr;
	ptr.open("input.txt");
	ptr >> n;
	n+=2;
	//________________________
	char **ch = new char*[n];
	for(int i = 0; i < n; ++i)
    	ch[i] = new char[n];
    //________________________
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			ptr >> ch[i][j];
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			cout << ch[i][j]<< " ";
		}
		cout << endl ;
	}
	cout << endl << endl ; 
	ptr.close();
	
	int wc = whitecell (ch,n-2,n-2,n-2);
	cout << "No. of white cells are : "<<wc << endl ;
	
	int ws = whitespace (ch,n-2,n-2,n-2);
	cout << "No. of white spaces are : "<< ws << endl ;
}

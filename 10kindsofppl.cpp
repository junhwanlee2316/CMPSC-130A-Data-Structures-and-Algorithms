/*
* Name: Junhwan Lee
* Date: 10/16/2022
* Project:10 Kinds of People, UCSB Kattis
* Approach: By using the floodFill algorithm, color all the nodes in the graph by coloring all the same type adjacent(no diagonals)
*           nodes recursively. At the end, check if the graph starting point(A) and end point(B) have same data type and check if they have
*           the same color. If they meet this condition, that means there is a path from A to B thus return the data type.
*/



#include <iostream>

using namespace std;

int colorBook[1005][1005];
int graph[1005][1005];

int r,c;


void floodFill(int x, int y, int newCol, int currCol) {

	// Base cases
    // If x or y is outside the screen, then return.
	if(x < 0 || x >= r || y < 0 || y >= c) return;
    // If the color of graph[x][y] is not same as current color, then return
	if(currCol != graph[x][y]) return;
    // If colored already, then return
	if(colorBook[x][y] != 0) return;
	
    // Give new color if survived base cases
	colorBook[x][y] = newCol;

    // Recursion to fill north,west,south,east
    floodFill(x-1, y, newCol, currCol);
	floodFill(x+1, y, newCol, currCol);
    floodFill(x, y-1, newCol, currCol);
    floodFill(x, y+1, newCol, currCol);

	return;
}

void findColor(int x, int y, int newColor){
    int currColor = colorBook[x][y];
    floodFill(x,y,currColor,newColor);
}


int main() {

	string seg;
	cin >> r >> c;


    // Construct the graph, intial color of all the nodes = 0
	for(int i = 0; i < r; i++) {
		cin >> seg;
		for(int j = 0; j < c; j++) {
			graph[i][j] = seg[j] - '0';
			colorBook[i][j] = 0;
		}
	}

    // Initialize new color
	int newColor = 1;

   
    // Floodfill the graph
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			if(colorBook[i][j] == 0) {
				newColor++;
				floodFill(i, j, newColor, graph[i][j]);
			}
		}
	}
    
    // Input number of query
	int n;
	cin >> n;
    if(n > 1000) {
        cout<<"Error Input size\n";
        return 0;
    }

    int x1, x2, y1, y2;

    bool bin;
    bool dec;

	for(int i = 0; i < n; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		x1--;
		x2--;
		y1--;
		y2--;

        dec = false;
		bin = false;

		// Return cases

        // Check if the inputs are of same type
        if(graph[x1][y1] == 0 && graph[x2][y2] == 0) {
            // If both have same color
		    if(colorBook[x1][y1] == colorBook[x2][y2]) bin = true;
	    }

        // Check if the inputs are of same type
        else if(graph[x1][y1] == 1 && graph[x2][y2] == 1) {
            // If both have same color
		    if(colorBook[x1][y1] == colorBook[x2][y2]) dec = true;
	    }

        if (bin == true) cout << "binary\n";
	    else if (dec == true) cout << "decimal\n";
        else cout<<"neither\n";

	}
    
	
	return 0;
}
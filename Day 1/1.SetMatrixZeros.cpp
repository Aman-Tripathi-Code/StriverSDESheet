void firstApproach(vector<vector<int>> &matrix){
	/*->if there exists a zero in the matrix marks each element in its row and col in the duplicate 
	matrix as -1
	->now again iterate throught entire matrix and mark the element with value zero
	->this approach fails if the matrix has an element as -1
	->TC - O(N*M) SC - O(N*M);*/
	int n = matrix.size(), m = matrix[0].size();
	vector<vector<int>> dupMatrix = matrix;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			if(matrix[i][j] == 0){
				for(int row = 0; row<n; row++){
					dupMatrix[row][j] = -1;
				}
				for(int col = 0; col<m; col++){
					dupMatrix[i][col] = -1;
				}
			}
		}
	}

	

	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			if(dupMatrix[i][j] == -1){
				matrix[i][j] = 0;
			}
		}
	}
}

void secondApproach(vector<vector<int>> &matrix){

	/*-> we will assign two vectors row and col to store the row and col number will need to be zero
	-> we will iterate over matrix and check if the element is zero then mark that row and column in row and 
		col vector as zero
	-> Now iterate over row and col vector and if the value of ith row is zero mark all the elements on that 
		row as zero and similarly for col vector
	-> TC - O(N*M) and SC - O(N + M)*/
	
	int n = matrix.size(), m = matrix[0].size();
	vector<int> row(n,1);
	vector<int> col(m,1);
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			if(matrix[i][j] == 0){
				row[i] = 0;
				col[j] = 0;
			}
		}
	}
	for(int i = 0; i<n; i++){
		if(row[i] == 0){
			for(int j = 0; j<m; j++){
				matrix[i][j] = 0;
			}
		}
	}

	for(int j = 0; j<m; j++){
		if(col[j] == 0){
			for(int i = 0; i<n; i++){
				matrix[i][j] = 0;
			}
		}
	}
}

void thirdApproach(vector<vector<int>> &matrix){
	/*-> We will use the first row and column to store the value of row and column that needs to be zero
	-> To avoid collision from the first row and first column we declare an additional variable flag which 
		will be set as 0 if any element is zero for first row element
	-> Now we will iterate for the first column and mark the 1st row 1st column cell as zero if any zero 
		exists
	-> We will start iteration from cell (1,1) to (N-1,M-1) and mark the 1st row jth column and ith row 1st 
		column element value as zero if the cell value is zero
	-> TC - O(N*M) SC- O(1)*/

	int n = matrix.size(), m = matrix[0].size();
	int flag = 1;
	for(int i = 0; i<m; i++){
		if(matrix[0][i] == 0){
			flag = 0;
			break;
		}
	}
	for(int i = 0; i<n; i++){
		if(matrix[i][0] == 0){
			matrix[0][0] = 0;
			break;
		}
	}
	for(int i = 1; i<n; i++){
		for(int j = 1; j<m; j++){
			if(matrix[i][j] == 0){
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	for(int i = 1; i<m; i++){
		if(matrix[0][i] == 0){
			for(int j = 1; j<n; j++){
				matrix[j][i] = 0;
			}
		}
	}
	for(int i = 1; i<n; i++){
		if(matrix[i][0] == 0){
			for(int j = 1; j<m; j++){
				matrix[i][j] = 0;
			}
		}
	}
	if(matrix[0][0] == 0){
		for(int i = 0; i<n; i++){
			matrix[i][0] = 0;
		}
	}
	if(flag == 0){
		for(int i = 0; i<m; i++){
			matrix[0][i] = 0;
		}
	}

}


void setZeros(vector<vector<int>> &matrix)
{
	thirdApproach(matrix);
}
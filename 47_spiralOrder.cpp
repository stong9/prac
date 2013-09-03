vector<int> spiralOrder(vector<vector<int> > &matrix) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<int> result;
	
	int row = matrix.size();
	if (row == 0){
		return result;
	}
	int col = matrix[0].size();
	if (col == 0){
		return result;
	}
	int n = min (row,col);
	
	int upper;
	
	if ( n%2 == 0){
		upper = n/2;
	}
	else{
		
		upper = (n-1)/2;
	}
	int layer = 0;
	for (; layer < upper; layer++){
	   
		for (int i = layer; i < (col-1-layer); i++){
			result.push_back(matrix[layer][i]);
		}
		for (int i = layer; i < (row -1 -layer); i++){
			result.push_back(matrix[i][col-1-layer]);
		}
		for (int i = (col-1-layer); i > layer; i--){
			result.push_back(matrix[row-1-layer][i]);
		}
		for (int i = row-1-layer; i > layer; i--){
			result.push_back(matrix[i][layer]);
		}
	}
	if (n%2==1){
		if (row < col){
			for (int i = layer; i<=col-1-layer;i++){
				result.push_back(matrix[layer][i]);
			}
		}
		else{
			for (int i = layer; i<=row-1-layer;i++){
				result.push_back(matrix[i][layer]);
			}
		}
	}
	return result;
	
}